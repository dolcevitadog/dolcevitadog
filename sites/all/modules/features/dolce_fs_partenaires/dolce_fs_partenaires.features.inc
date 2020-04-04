<?php

/**
 * @file
 * dolce_fs_partenaires.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dolce_fs_partenaires_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function dolce_fs_partenaires_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function dolce_fs_partenaires_node_info() {
  $items = array(
    'partners' => array(
      'name' => t('Partners'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
