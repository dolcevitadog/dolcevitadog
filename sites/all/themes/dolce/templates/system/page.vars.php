<?php
/**
 * @file
 * Stub file for "page" theme hook [pre]process functions.
 */

/**
 * Pre-processes variables for the "page" theme hook.
 *
 * See template for list of available variables.
 *
 * @see page.tpl.php
 *
 * @ingroup theme_preprocess
 */
function dolce_preprocess_page(&$vars) {
  // Add information about the number of sidebars.
  $vars['zone_user_first_classes'] = 'col-md-7 col-lg-7 col-sm-6 col-xs-12';
  $vars['zone_user_second_classes'] = 'col-md-5 col-lg-5 col-sm-6 col-xs-12';

  // Add responsive tables for Cart and Checkout
    $arg = arg();
    if (($arg[0] == 'cart') || ($arg[0] == 'checkout')) {
        drupal_add_css(drupal_get_path('theme', 'dolce') . '/css/responsive_table.css');
        drupal_add_js(drupal_get_path('theme', 'dolce') . '/js/ngtables/ng_responsive_tables.js');
        drupal_add_js(drupal_get_path('theme', 'dolce') . '/js/responsive_cart.js');
    }

}

/**
 * Processes variables for the "page" theme hook.
 *
 * See template for list of available variables.
 *
 * @see page.tpl.php
 *
 * @ingroup theme_process
 */
function dolce_process_page(&$variables) {
  $variables['navbar_classes'] = implode(' ', $variables['navbar_classes_array']);
}
