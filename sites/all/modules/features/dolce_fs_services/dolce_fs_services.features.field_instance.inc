<?php

/**
 * @file
 * dolce_fs_services.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function dolce_fs_services_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-dolce_services-field_service_title'.
  $field_instances['node-dolce_services-field_service_title'] = array(
    'bundle' => 'dolce_services',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'custom_link_to_entity' => '',
          'custom_prefix' => '',
          'custom_reverse' => '',
          'custom_strip_preserve' => '',
          'custom_strip_tags' => '',
          'custom_strtolower' => '',
          'custom_strtoupper' => '',
          'custom_suffix' => '',
          'custom_trim' => '',
          'custom_ucfirst' => '',
          'custom_ucwords' => '',
        ),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'product_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'div_div_div',
    'field_name' => 'field_service_title',
    'label' => 'Tooltip title',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 34,
    ),
  );

  // Exported field_instance: 'node-dolce_services-field_services_picto'.
  $field_instances['node-dolce_services-field_services_picto'] = array(
    'bundle' => 'dolce_services',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'custom_link_to_entity' => '',
          'custom_prefix' => '',
          'custom_reverse' => '',
          'custom_strip_preserve' => '',
          'custom_strip_tags' => '',
          'custom_strtolower' => '',
          'custom_strtoupper' => '',
          'custom_suffix' => '',
          'custom_trim' => '',
          'custom_ucfirst' => '',
          'custom_ucwords' => '',
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 2,
      ),
      'product_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'div_div_div',
    'field_name' => 'field_services_picto',
    'label' => 'services_picto',
    'required' => 1,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'entity_translation_sync' => FALSE,
      'file_directory' => 'picto_services',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 32,
    ),
  );

  // Exported field_instance: 'node-dolce_services-field_services_text'.
  $field_instances['node-dolce_services-field_services_text'] = array(
    'bundle' => 'dolce_services',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'custom_link_to_entity' => '',
          'custom_prefix' => '',
          'custom_reverse' => '',
          'custom_strip_preserve' => '',
          'custom_strip_tags' => '',
          'custom_strtolower' => '',
          'custom_strtoupper' => '',
          'custom_suffix' => '',
          'custom_trim' => '',
          'custom_ucfirst' => '',
          'custom_ucwords' => '',
        ),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'product_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'div_div_div',
    'field_name' => 'field_services_text',
    'label' => 'Tooltip text',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 33,
    ),
  );

  // Exported field_instance: 'node-dolce_services-title_field'.
  $field_instances['node-dolce_services-title_field'] = array(
    'bundle' => 'dolce_services',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'product_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'title_field',
    'label' => 'Titre',
    'required' => TRUE,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'hide_label' => array(
        'entity' => 'entity',
        'page' => 0,
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => -5,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Titre');
  t('Tooltip text');
  t('Tooltip title');
  t('services_picto');

  return $field_instances;
}
