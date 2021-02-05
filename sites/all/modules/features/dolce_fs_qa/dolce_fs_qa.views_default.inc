<?php

/**
 * @file
 * dolce_fs_qa.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dolce_fs_qa_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'qa';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_qa';
  $view->human_name = 'Q&A';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Q&A';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'plus';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Appliquer';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Éléments par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« premier';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ précédent';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'suivant ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'dernier »';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Champ: Qa : Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_qa';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = 'Identifiant (ID)';
  /* Champ: qa : Name */
  $handler->display->display_options['fields']['field_qa_name']['id'] = 'field_qa_name';
  $handler->display->display_options['fields']['field_qa_name']['table'] = 'field_data_field_qa_name';
  $handler->display->display_options['fields']['field_qa_name']['field'] = 'field_qa_name';
  $handler->display->display_options['fields']['field_qa_name']['label'] = 'Nom';
  $handler->display->display_options['fields']['field_qa_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_qa_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_qa_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_qa_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_qa_name']['settings'] = array(
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
  $handler->display->display_options['fields']['field_qa_name']['field_api_classes'] = TRUE;
  /* Champ: qa : Questions */
  $handler->display->display_options['fields']['field_qa_questions']['id'] = 'field_qa_questions';
  $handler->display->display_options['fields']['field_qa_questions']['table'] = 'field_data_field_qa_questions';
  $handler->display->display_options['fields']['field_qa_questions']['field'] = 'field_qa_questions';
  $handler->display->display_options['fields']['field_qa_questions']['element_type'] = '0';
  $handler->display->display_options['fields']['field_qa_questions']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_qa_questions']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_qa_questions']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_qa_questions']['settings'] = array(
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
  $handler->display->display_options['fields']['field_qa_questions']['field_api_classes'] = TRUE;
  /* Critère de filtrage: Qa : qa type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_qa';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'qa' => 'qa',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'qa';
  $translatables['qa'] = array(
    t('Master'),
    t('Q&A'),
    t('plus'),
    t('Appliquer'),
    t('Réinitialiser'),
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Éléments par page'),
    t('- Tout -'),
    t('Décalage'),
    t('« premier'),
    t('‹ précédent'),
    t('suivant ›'),
    t('dernier »'),
    t('Identifiant (ID)'),
    t('.'),
    t(','),
    t('Nom'),
    t('Questions'),
    t('Page'),
  );
  $export['qa'] = $view;

  return $export;
}
