<?php

/**
 * @file
 * dolce_fs_services.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dolce_fs_services_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'dolcevitadog_services';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Dolcevitadog services';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '--aucun--';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'plus';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Appliquer';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'col-xs-6 col-sm-3 col-md-3 col-lg-3';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Champ: Contenu : services_picto */
  $handler->display->display_options['fields']['field_services_picto']['id'] = 'field_services_picto';
  $handler->display->display_options['fields']['field_services_picto']['table'] = 'field_data_field_services_picto';
  $handler->display->display_options['fields']['field_services_picto']['field'] = 'field_services_picto';
  $handler->display->display_options['fields']['field_services_picto']['label'] = '';
  $handler->display->display_options['fields']['field_services_picto']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_services_picto']['element_type'] = '0';
  $handler->display->display_options['fields']['field_services_picto']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_services_picto']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_services_picto']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_services_picto']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_services_picto']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_services_picto']['settings'] = array(
    'url_type' => '1',
    'image_style' => 'thumbnail',
    'image_link' => '',
    'custom_link_to_entity' => 0,
    'custom_prefix' => '',
    'custom_suffix' => '',
    'custom_reverse' => 0,
    'custom_trim' => 0,
    'custom_strtolower' => 0,
    'custom_strtoupper' => 0,
    'custom_ucfirst' => 0,
    'custom_ucwords' => 0,
    'custom_strip_tags' => 0,
    'custom_strip_preserve' => '',
  );
  $handler->display->display_options['fields']['field_services_picto']['field_api_classes'] = TRUE;
  /* Champ: Contenu : Tooltip text */
  $handler->display->display_options['fields']['field_services_text']['id'] = 'field_services_text';
  $handler->display->display_options['fields']['field_services_text']['table'] = 'field_data_field_services_text';
  $handler->display->display_options['fields']['field_services_text']['field'] = 'field_services_text';
  $handler->display->display_options['fields']['field_services_text']['label'] = '';
  $handler->display->display_options['fields']['field_services_text']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_services_text']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_services_text']['element_type'] = '0';
  $handler->display->display_options['fields']['field_services_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_services_text']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_services_text']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_services_text']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_services_text']['settings'] = array(
    'custom_link_to_entity' => 0,
    'custom_prefix' => '',
    'custom_suffix' => '',
    'custom_reverse' => 0,
    'custom_trim' => 0,
    'custom_strtolower' => 0,
    'custom_strtoupper' => 0,
    'custom_ucfirst' => 0,
    'custom_ucwords' => 0,
    'custom_strip_tags' => 0,
    'custom_strip_preserve' => '',
  );
  $handler->display->display_options['fields']['field_services_text']['field_api_classes'] = TRUE;
  /* Champ: Contenu : Tooltip title */
  $handler->display->display_options['fields']['field_service_title']['id'] = 'field_service_title';
  $handler->display->display_options['fields']['field_service_title']['table'] = 'field_data_field_service_title';
  $handler->display->display_options['fields']['field_service_title']['field'] = 'field_service_title';
  $handler->display->display_options['fields']['field_service_title']['label'] = '';
  $handler->display->display_options['fields']['field_service_title']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_service_title']['element_type'] = '0';
  $handler->display->display_options['fields']['field_service_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_service_title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_service_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_service_title']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_service_title']['settings'] = array(
    'custom_link_to_entity' => 0,
    'custom_prefix' => '',
    'custom_suffix' => '',
    'custom_reverse' => 0,
    'custom_trim' => 0,
    'custom_strtolower' => 0,
    'custom_strtoupper' => 0,
    'custom_ucfirst' => 0,
    'custom_ucwords' => 0,
    'custom_strip_tags' => 0,
    'custom_strip_preserve' => '',
  );
  $handler->display->display_options['fields']['field_service_title']['field_api_classes'] = TRUE;
  /* Critère de tri: Contenu : Date de publication */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Critère de filtrage: Contenu : Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '0';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Critère de filtrage: Contenu : Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dolce_services' => 'dolce_services',
  );

  /* Display: Block Services */
  $handler = $view->new_display('block', 'Block Services', 'block');
  $translatables['dolcevitadog_services'] = array(
    t('Master'),
    t('--aucun--'),
    t('plus'),
    t('Appliquer'),
    t('Réinitialiser'),
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Block Services'),
  );
  $export['dolcevitadog_services'] = $view;

  return $export;
}
