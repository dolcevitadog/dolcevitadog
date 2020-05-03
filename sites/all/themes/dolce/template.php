<?php
/**
 * @file
 * The primary PHP file for this theme.
 */

function dolce_form_element(&$variables) {
    $element = &$variables['element'];
    $name = !empty($element['#name']) ? $element['#name'] : FALSE;
    $type = !empty($element['#type']) ? $element['#type'] : FALSE;
    $checkbox = $type && $type === 'checkbox';
    $radio = $type && $type === 'radio';

    // Create an attributes array for the wrapping container.
    if (empty($element['#wrapper_attributes'])) {
        $element['#wrapper_attributes'] = array();
    }
    $wrapper_attributes = &$element['#wrapper_attributes'];

    // This function is invoked as theme wrapper, but the rendered form element
    // may not necessarily have been processed by form_builder().
    $element += array(
        '#title_display' => 'before',
    );

    // Add wrapper ID for 'item' type.
    if ($type && $type === 'item' && !empty($element['#markup']) && !empty($element['#id'])) {
        $wrapper_attributes['id'] = $element['#id'];
    }

    // Check for errors and set correct error class.
    if ((isset($element['#parents']) && form_get_error($element) !== NULL) || (!empty($element['#required']) && bootstrap_setting('forms_required_has_error'))) {
        $wrapper_attributes['class'][] = 'has-error';
    }

    // Add necessary classes to wrapper container.
    $wrapper_attributes['class'][] = 'form-item';
    if ($name) {
        $wrapper_attributes['class'][] = 'form-item-' . drupal_html_class($name);
    }
    if ($type) {
        $wrapper_attributes['class'][] = 'form-type-' . drupal_html_class($type);
    }
    if (!empty($element['#attributes']['disabled'])) {
        $wrapper_attributes['class'][] = 'form-disabled';
    }
    if (!empty($element['#autocomplete_path']) && drupal_valid_path($element['#autocomplete_path'])) {
        $wrapper_attributes['class'][] = 'form-autocomplete';
    }

    // Checkboxes and radios do no receive the 'form-group' class, instead they
    // simply have their own classes.
    if ($checkbox || $radio) {
        $wrapper_attributes['class'][] = drupal_html_class($type);
    }
    elseif ($type && $type !== 'hidden') {
        $wrapper_attributes['class'][] = 'form-group';
    }

    // Create a render array for the form element.
    $build = array(
        '#theme_wrappers' => array('container__form_element'),
        '#attributes' => $wrapper_attributes,
    );

    // Render the label for the form element.
    $build['label'] = array(
        '#markup' => theme('form_element_label', $variables),
        '#weight' => $element['#title_display'] === 'before' ? 0 : 2,
    );

    // Checkboxes and radios render the input element inside the label. If the
    // element is neither of those, then the input element must be rendered here.
    if (!$checkbox && !$radio) {
        $prefix = isset($element['#field_prefix']) ? $element['#field_prefix'] : '';
        $suffix = isset($element['#field_suffix']) ? $element['#field_suffix'] : '';
        if ((!empty($prefix) || !empty($suffix)) && (!empty($element['#input_group']) || !empty($element['#input_group_button']))) {
            if (!empty($element['#field_prefix'])) {
                $prefix = '<span class="input-group-' . (!empty($element['#input_group_button']) ? 'btn' : 'addon') . '">' . $prefix . '</span>';
            }
            if (!empty($element['#field_suffix'])) {
                $suffix = '<span class="input-group-' . (!empty($element['#input_group_button']) ? 'btn' : 'addon') . '">' . $suffix . '</span>';
            }

            // Add a wrapping container around the elements.
            $input_group_attributes = &_bootstrap_get_attributes($element, 'input_group_attributes');
            $input_group_attributes['class'][] = 'input-group';
            $prefix = '<div' . drupal_attributes($input_group_attributes) . '>' . $prefix;
            $suffix .= '</div>';
        }

        // Build the form element.
        $build['element'] = array(
            '#markup' => $element['#children'],
            '#prefix' => !empty($prefix) ? $prefix : NULL,
            '#suffix' => !empty($suffix) ? $suffix : NULL,
            '#weight' => 1,
        );
    }

    // Construct the element's description markup.
    if (!empty($element['#description'])) {
        $build['description'] = array(
            '#type' => 'container',
            '#attributes' => array(
                'class' => array('help-block', 'description'),
            ),
            '#weight' => isset($element['#description_display']) && $element['#description_display'] === 'before' ? 0 : 20,
            0 => array('#markup' => $element['#description']),
        );
    }
    // Render the form element build array.
    return drupal_render($build);
}

/**
 * Allows sub-themes to alter the array used for associating an icon with text.
 *
 * @param array $texts
 *   An associative array containing the text and icons to be matched, passed
 *   by reference.
 *
 * @see _bootstrap_iconize_text()
 */
function dolce_bootstrap_iconize_text_alter(&$texts) {
    $texts['matches'][t('Checkout')] = 'ok';
    $texts['matches'][t('Continue to next step')] = 'menu-right';
    $texts['matches'][t('Back to login')] = 'menu-left';
    $texts['matches'][t('Create an account')] = 'pencil';
    $texts['matches'][t('Create new account')] = 'pencil';
    $texts['matches'][t('E-mail new password')] = 'lock';
    $texts['matches'][t('Back to login')] = 'pencil';
    unset($texts['contains'][t('Update')]);

}

/**
 * Allows sub-themes to alter the array used for colorizing text.
 *
 * @param array $texts
 *   An associative array containing the text and classes to be matched, passed
 *   by reference.
 *
 * @see _bootstrap_colorize_text()
 */
function dolce_bootstrap_colorize_text_alter(&$texts) {
    // This matches the exact string: "My Unique Button Text".
    $texts['matches'][t('Checkout')] = 'primary';
    $texts['matches'][t('Continue to next step')] = 'primary';
    $texts['matches'][t('Create an account')] = 'info';
    $texts['matches'][t('Create new account')] = 'primary';
    $texts['matches'][t('E-mail new password')] = 'primary';
    $texts['matches'][t('Back to login')] = 'primary';
    // Remove matching for strings that contain "apply":
    unset($texts['contains'][t('Update')]);
}

function dolce_preprocess_views_view_field(&$vars) {
    $vars['output'] = $vars['field']->advanced_render($vars['row']);
}


/**
 * Themes a price components table.
 *
 * @param $variables
 *   Includes the 'components' array and original 'price' array as well as display options.
 * I rebuild the whole theme, because i dont want a table but 3 distincts wrappers to easily place it with CSS
 */
function dolce_commerce_price_rrp_your_price($variables) {
    drupal_add_css(drupal_get_path('module', 'commerce_extra_price_formatters') . '/theme/your_price.theme.css');


    // Build table rows out of the components.
    $rows = array();

    $web_price = $variables['components']['commerce_price_rrp_your_price']['formatted_price'];
    $rrp = $variables['components']['base_price']['price']['amount'];

    if ($variables['options']['include_tax_in_rrp'] == TRUE) {
        foreach ($variables['components'] as $component_name => $component_value) {
            if (substr($component_name, 0, 3) == 'tax') {
                $rrp += $component_value['price']['amount'];
            }
        }
    }

    $whole_numbers_only = $variables['options']['whole_numbers_only'];

    if ($whole_numbers_only){
        $rrp = commerce_extra_price_no_decimal_currency_format($rrp, $variables['components']['base_price']['price']['currency_code']);
        $web_price = commerce_extra_price_no_decimal_currency_format($variables['components']['commerce_price_rrp_your_price']['price']['amount'], $variables['components']['commerce_price_rrp_your_price']['price']['currency_code']);
    } else {
        $rrp = commerce_currency_format($rrp, $variables['components']['base_price']['price']['currency_code']);
    }

    if (isset($variables['components']['discount']) && $whole_numbers_only){
        $saving = commerce_extra_price_no_decimal_currency_format(-$variables['components']['discount']['price']['amount'], $variables['components']['discount']['price']['currency_code']);
    } else if (isset($variables['components']['discount'])) {
        $saving = commerce_currency_format(-$variables['components']['discount']['price']['amount'], $variables['components']['discount']['price']['currency_code']);
    }

    $check_for_same_price = $variables['options']['check_for_same_price'];

    /* Adding Stuff */

    $html = '';

    if ($check_for_same_price == 1 && $web_price != $rrp) {

        $html .= '<div class="rrp-wrapper">';
        if (!empty(check_plain($variables['options']['rrp_label']))) {
            $html .= '<label class="rrp-title">'.check_plain($variables['options']['rrp_label']).'</label>';
        }
        $html .= '<span class="rrp-total">'.$rrp.'</span>';
        $html .= '</div>';
        $html .= '<div class="webprice-wrapper">';
        if (!empty(check_plain($variables['options']['offer_label']))) {
            $html .= '<label class="webprice-title">'.check_plain($variables['options']['offer_label']).'</label>';
        }
        $html .= '<span class="webprice-total">'.$web_price.'</span>';
        $html .= '</div>';
        $discountrprice = $variables['components']['commerce_price_rrp_your_price']['price']['amount'];
        $baseprice = $variables['components']['base_price']['price']['amount'];
        $discount = ($discountrprice - $baseprice);
        $saving_percentage = ($discount / $baseprice) * 100;
        $saving_percentage .= '%';
        if ($variables['options']['show_saving'] == 1 && isset($saving_percentage)) {

            $html .= '<div class="saving-wrapper">';
            if (!empty(check_plain($variables['options']['saving_label']))) {
                $html .= '<label class="saving-title">'.check_plain($variables['options']['saving_label']).'</label>';
            }
            $html .= '<span class="saving-title">'.$saving_percentage.'</span>';
            $html .= '</div>';
        }
    }

    else {
        $html .= '<div class="webprice-wrapper">';
        if (!empty(check_plain($variables['options']['offer_label']))) {
            $html .= '<label class="webprice-title">'.check_plain($variables['options']['offer_label']).'</label>';
        }
        $html .= '<span class="webprice-total">'.$web_price.'</span>';
        $html .= '</div>';
    }
    return $html;
}

/* Implement preprocess_node */
function dolce_preprocess_node(&$vars)
{
    $view_mode = $vars['view_mode'];
    $content_type = $vars['type'];
    $vars['theme_hook_suggestions'][] = 'node__' . $view_mode;
    $vars['theme_hook_suggestions'][] = 'node__' . $view_mode . '_' . $content_type;
}


/**
 * Returns HTML for the deactivation widget.
 *
 * @param $variables
 *   An associative array containing the keys 'text', 'path', and 'options'. See
 *   the l() function for information about these variables.
 *
 * @see l()
 * @see theme_facetapi_link_active()
 *
 * @ingroup themable
 */
function dolce_facetapi_deactivate_widget($variables) {
    return '<i class="far fa-minus-square"></i> ';
}