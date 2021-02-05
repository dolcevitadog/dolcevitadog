<?php

/**
 * @file
 * dolce_fs_qa.features.inc
 */

/**
 * Implements hook_views_api().
 */
function dolce_fs_qa_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_eck_bundle_info().
 */
function dolce_fs_qa_eck_bundle_info() {
  $items = array(
    'qa_qa' => array(
      'machine_name' => 'qa_qa',
      'entity_type' => 'qa',
      'name' => 'qa',
      'label' => 'qa',
      'config' => array(),
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function dolce_fs_qa_eck_entity_type_info() {
  $items = array(
    'qa' => array(
      'name' => 'qa',
      'label' => 'qa',
      'properties' => array(
        'uid' => array(
          'label' => 'Author',
          'type' => 'integer',
          'behavior' => 'author',
        ),
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
        ),
      ),
    ),
  );
  return $items;
}
