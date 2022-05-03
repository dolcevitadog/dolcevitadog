<?php

/**
 * @file
 * Written by Henri MEDOT <henri.medot[AT]absyx[DOT]fr>
 * http://www.absyx.fr
 */

/**
 * Returns a settings form.
 */
function commerce_mondialrelay_settings_form() {
  $form['commerce_mondialrelay_brand'] = array(
    '#title' => t('Brand reference'),
    '#description' => t('Your 8-character brand reference.'),
    '#type' => 'textfield',
    '#default_value' => variable_get('commerce_mondialrelay_brand', ''),
    '#size' => 20,
    '#required' => TRUE,
  );

  $form['commerce_mondialrelay_key'] = array(
    '#title' => t('Private key'),
    '#description' => t('Your 8-character private key.'),
    '#type' => 'textfield',
    '#default_value' => variable_get('commerce_mondialrelay_key', ''),
    '#size' => 20,
    '#required' => TRUE,
  );

  $form['commerce_mondialrelay_brand_permalinks'] = array(
    '#title' => t('Brand reference for permalinks'),
    '#description' => t('Your 10-character brand reference.'),
    '#type' => 'textfield',
    '#default_value' => variable_get('commerce_mondialrelay_brand_permalinks', ''),
    '#size' => 20,
  );

  $form['commerce_mondialrelay_rates_text'] = array(
    '#type' => 'textarea',
    '#title' => t('Rates'),
    '#default_value' => variable_get('commerce_mondialrelay_rates_text', ''),
    '#description' => t('Format:<br /><em>Country code<br />Max weight in kg | Rate<br />Max weight in kg | Rate<br />etc.</em><br />Max weights must be declared in ascending order.'),
  );

  $form['commerce_mondialrelay_currency_code'] = array(
    '#type' => 'select',
    '#title' => t('Currency code'),
    '#options' => commerce_currency_get_code(TRUE),
    '#default_value' => variable_get('commerce_mondialrelay_currency_code', ''),
    '#empty_value' => '',
    '#required' => TRUE,
  );

  // Add support for included tax.
  if (module_exists('commerce_tax')) {
    $inclusive_types = array();
    foreach (commerce_tax_types() as $name => $tax_type) {
      if ($tax_type['display_inclusive']) {
        $inclusive_types[$name] = $tax_type['title'];
      }
    }

    $options = array();
    foreach (commerce_tax_rates() as $name => $tax_rate) {
      if (in_array($tax_rate['type'], array_keys($inclusive_types))) {
        $options[$inclusive_types[$tax_rate['type']]][$name] = $tax_rate['title'];
      }
    }

    $form['commerce_mondialrelay_included_tax'] = array(
      '#type' => 'select',
      '#title' => t('Included tax'),
      '#options' => count($options) == 1 ? reset($options) : $options,
      '#default_value' => variable_get('commerce_mondialrelay_included_tax', ''),
      '#empty_value' => '',
    );
  }

  $form['sender'] = array(
    '#type' => 'fieldset',
    '#title' => t('Sender'),
    '#collapsible' => TRUE,
  );
  $form['sender']['commerce_mondialrelay_sender_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#default_value' => variable_get('commerce_mondialrelay_sender_name', ''),
    '#required' => TRUE,
  );
  $form['sender']['commerce_mondialrelay_sender_address1'] = array(
    '#type' => 'textfield',
    '#title' => t('Address 1'),
    '#default_value' => variable_get('commerce_mondialrelay_sender_address1', ''),
    '#required' => TRUE,
  );
  $form['sender']['commerce_mondialrelay_sender_address2'] = array(
    '#type' => 'textfield',
    '#title' => t('Address 2'),
    '#default_value' => variable_get('commerce_mondialrelay_sender_address2', ''),
  );
  $form['sender']['commerce_mondialrelay_sender_postalcode'] = array(
    '#type' => 'textfield',
    '#title' => t('Postal code'),
    '#default_value' => variable_get('commerce_mondialrelay_sender_postalcode', ''),
    '#size' => 20,
    '#required' => TRUE,
  );
  $form['sender']['commerce_mondialrelay_sender_city'] = array(
    '#type' => 'textfield',
    '#title' => t('City'),
    '#default_value' => variable_get('commerce_mondialrelay_sender_city', ''),
    '#required' => TRUE,
  );
  $form['sender']['commerce_mondialrelay_sender_country'] = array(
    '#type' => 'select',
    '#title' => t('Country'),
    '#options' => commerce_mondialrelay_get_countries(),
    '#default_value' => variable_get('commerce_mondialrelay_sender_country', ''),
    '#empty_value' => '',
    '#required' => TRUE,
  );
  $form['sender']['commerce_mondialrelay_sender_phone'] = array(
    '#type' => 'textfield',
    '#title' => t('Phone number'),
    '#default_value' => variable_get('commerce_mondialrelay_sender_phone', ''),
  );

  $form['commerce_mondialrelay_no_gmap_api'] = array(
    '#type' => 'checkbox',
    '#title' => t('Do not include the Google Maps API'),
    '#description' => t('Check this box if the Google Maps API is already included by another module.'),
    '#default_value' => variable_get('commerce_mondialrelay_no_gmap_api', 0),
  );

  $form['#validate'][] = 'commerce_mondialrelay_settings_form_validate';
  $form['#submit'][] = 'commerce_mondialrelay_settings_form_submit';

  return system_settings_form($form);
}

/**
 * Validate handler for commerce_mondialrelay_settings_form().
 */
function commerce_mondialrelay_settings_form_validate($form, &$form_state) {
  $values = $form_state['values'];

  unset($error);
  $rates = commerce_mondialrelay_parse_rates($values['commerce_mondialrelay_rates_text'], $error);
  if ($rates === FALSE) {
    form_set_error('commerce_mondialrelay_rates_text', $error);
  }
  else {
    $form_state['commerce_mondialrelay_rates'] = $rates;
  }
}

/**
 * Submit handler for commerce_mondialrelay_settings_form().
 */
function commerce_mondialrelay_settings_form_submit($form, &$form_state) {
  variable_set('commerce_mondialrelay_rates', $form_state['commerce_mondialrelay_rates']);
}

/**
 * Displays a page to ship an order.
 */
function commerce_mondialrelay_order_ship_page($order) {
  $line_item = commerce_mondialrelay_get_line_item($order);

  // Display shipping information if existing.
  if (isset($line_item->data['mondialrelay']['labels'])) {
    $number = $line_item->data['mondialrelay']['shipping']->ExpeditionNum;
    $build['number'] = array(
      '#type' => 'item',
      '#title' => t('Shipping number'),
      '#markup' => l($number, 'http://www.mondialrelay.com/public/permanent/tracking.aspx', array(
        'query' => array('ens' => variable_get('commerce_mondialrelay_brand_permalinks', ''), 'exp' => $number),
        'attributes' => array('title' => t('Track parcel'), 'target' => '_blank'),
      )),
    );

    $labels = $line_item->data['mondialrelay']['labels'];
    $formats = array(
      'URL_PDF_A4' => t('A4 format'),
      'URL_PDF_A5' => t('A5 format'),
    );
    foreach ($formats as $key => $text) {
      $links[] = l($text, 'http://www.mondialrelay.fr' . $labels->$key);
    }
    $build['labels'] = array(
      '#type' => 'item',
      '#title' => t('Shipping labels'),
      '#markup' => theme('item_list', array('items' => $links)),
    );

    return $build;
  }

  // Otherwise, display a form to create shipping labels.
  return drupal_get_form('commerce_mondialrelay_order_ship_form', $order);
}

/**
 * Returns a form to create shipping labels.
 */
function commerce_mondialrelay_order_ship_form($form, &$form_state, $order) {
  $form_state['order'] = $order;
  $line_item = commerce_mondialrelay_get_line_item($order);

  // Add the weight form element.
  if (!isset($line_item->data['mondialrelay']['shipping'])) {
    $weight = commerce_physical_order_weight($order, 'g');
    $form['weight'] = array(
      '#type' => 'textfield',
      '#title' => t('Weight'),
      '#description' => t('The full weight of the parcel in grams.'),
      '#default_value' => round($weight['weight']),
      '#size' => 10,
      '#field_suffix' => 'g',
      '#required' => TRUE,
      '#element_validate' => array('commerce_mondialrelay_order_ship_form_validate_weight'),
    );
  }

  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array('#type' => 'submit', '#value' => t('Create shipping labels'));

  return $form;
}

/**
 * Validates the weight form element.
 */
function commerce_mondialrelay_order_ship_form_validate_weight($element, &$form_state, $form) {
  $value = $element['#value'];
  if (strlen($value) && !preg_match('`^[1-9]\d*$`', $value)) {
    form_error($element, t('Please enter a valid value for field %field.', array('%field' => $element['#title'])));
  }
}

/**
 * Submit handler for commerce_mondialrelay_order_ship_form().
 */
function commerce_mondialrelay_order_ship_form_submit($form, &$form_state) {
  $order = $form_state['order'];
  commerce_mondialrelay_force_redirect('admin/commerce/orders/' . $order->order_id . '/mondialrelay', $form_state);
  $order_wrapper = entity_metadata_wrapper('commerce_order', $order);
  $customer_address = $order_wrapper->commerce_customer_shipping->commerce_customer_address->value();
  $line_item = commerce_mondialrelay_get_line_item($order);

  // Register shipping.
  if (!isset($line_item->data['mondialrelay']['shipping'])) {
    $parcelshop = $line_item->data['mondialrelay']['parcelshop'];

    $params = array(
      'Enseigne' => variable_get('commerce_mondialrelay_brand', ''),
      'ModeCol' => 'CCC',
      'ModeLiv' => '24R',
      'Expe_Langage' => 'FR',
      'Expe_Ad1' => variable_get('commerce_mondialrelay_sender_name', ''),
      'Expe_Ad3' => variable_get('commerce_mondialrelay_sender_address1', ''),
      'Expe_Ad4' => variable_get('commerce_mondialrelay_sender_address2', ''),
      'Expe_Ville' => variable_get('commerce_mondialrelay_sender_city', ''),
      'Expe_CP' => variable_get('commerce_mondialrelay_sender_postalcode', ''),
      'Expe_Pays' => variable_get('commerce_mondialrelay_sender_country', ''),
      'Expe_Tel1' => variable_get('commerce_mondialrelay_sender_phone', ''),
      'Dest_Langage' => 'FR',
      'Dest_Ad1' => $customer_address['name_line'],
      'Dest_Ad2' => $customer_address['organisation_name'],
      'Dest_Ad3' => $customer_address['thoroughfare'],
      'Dest_Ad4' => $customer_address['premise'],
      'Dest_Ville' => $customer_address['locality'],
      'Dest_CP' => $customer_address['postal_code'],
      'Dest_Pays' => $customer_address['country'],
      'Dest_Tel1' => $customer_address['phone_number'],
      'Poids' => $form_state['values']['weight'],
      'NbColis' => '1',
      'CRT_Valeur' => '0',
      'LIV_Rel_Pays' => $parcelshop['Pays'],
      'LIV_Rel' => $parcelshop['ID'],
    );

    $result = commerce_mondialrelay_call('WSI2_CreationExpedition', $params);
    if ($result) {
      $line_item->data['mondialrelay']['shipping'] = $result;
      commerce_line_item_save($line_item);
    }
    else {
      drupal_set_message(t('Failed registering shipping.'), 'error');
      return;
    }
  }

  // Create shipping labels.
  $params = array(
    'Enseigne' => variable_get('commerce_mondialrelay_brand', ''),
    'Expeditions' => $line_item->data['mondialrelay']['shipping']->ExpeditionNum,
    'Langue' => 'FR',
  );

  $result = commerce_mondialrelay_call('WSI2_GetEtiquettes', $params);
  if ($result) {
    $line_item->data['mondialrelay']['labels'] = $result;
    commerce_line_item_save($line_item);
  }
  else {
    drupal_set_message(t('Failed creating shipping labels.'), 'error');
  }
}
