<?php

/**
 * @file
 * dolce_fs_highlight.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dolce_fs_highlight_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'highlight';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Highlight';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Interview';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'col-lg-4 col-sm-12 col-xs-12 col-md-4';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Champ: Contenu : Link */
  $handler->display->display_options['fields']['field_highlight_link']['id'] = 'field_highlight_link';
  $handler->display->display_options['fields']['field_highlight_link']['table'] = 'field_data_field_highlight_link';
  $handler->display->display_options['fields']['field_highlight_link']['field'] = 'field_highlight_link';
  $handler->display->display_options['fields']['field_highlight_link']['label'] = '';
  $handler->display->display_options['fields']['field_highlight_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_highlight_link']['element_type'] = '0';
  $handler->display->display_options['fields']['field_highlight_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_highlight_link']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_highlight_link']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_highlight_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_highlight_link']['type'] = 'link_absolute';
  $handler->display->display_options['fields']['field_highlight_link']['settings'] = array(
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
  $handler->display->display_options['fields']['field_highlight_link']['field_api_classes'] = TRUE;
  /* Champ: Contenu : Tous les termes de taxonomie */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['text'] = '<span class="interview-picto"><i class="fas fa-microphone"></i></span>';
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'collection' => 0,
    'confort_size' => 0,
    'haqihana_color' => 0,
    'haqihana_harness_size' => 0,
    'haqihana_leash_size' => 0,
    'highlight' => 0,
    'product_category' => 0,
  );
  /* Champ: Contenu : highlight image */
  $handler->display->display_options['fields']['field_highlight_image']['id'] = 'field_highlight_image';
  $handler->display->display_options['fields']['field_highlight_image']['table'] = 'field_data_field_highlight_image';
  $handler->display->display_options['fields']['field_highlight_image']['field'] = 'field_highlight_image';
  $handler->display->display_options['fields']['field_highlight_image']['label'] = '';
  $handler->display->display_options['fields']['field_highlight_image']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_highlight_image']['alter']['text'] = '[field_highlight_image] 
[term_node_tid]';
  $handler->display->display_options['fields']['field_highlight_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_highlight_image']['alter']['path'] = '[field_highlight_link]';
  $handler->display->display_options['fields']['field_highlight_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_highlight_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_highlight_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_highlight_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_highlight_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_highlight_image']['settings'] = array(
    'image_style' => 'product_medium',
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
  $handler->display->display_options['fields']['field_highlight_image']['field_api_classes'] = TRUE;
  /* Champ: Contenu : Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_highlight_link]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Critère de tri: Contenu : Date de publication */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Critère de filtrage: Contenu : Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Critère de filtrage: Contenu : Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'highlight' => 'highlight',
  );
  /* Critère de filtrage: Contenu : Promu en page d'accueil */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  /* Critère de filtrage: Contenu : Possède un terme de la taxonomie */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    62 => '62',
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'highlight';

  /* Display: Block Highlight Interview */
  $handler = $view->new_display('block', 'Block Highlight Interview', 'block');

  /* Display: Bloc Highlight informations */
  $handler = $view->new_display('block', 'Bloc Highlight informations', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Informations';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Champ: Contenu : Link */
  $handler->display->display_options['fields']['field_highlight_link']['id'] = 'field_highlight_link';
  $handler->display->display_options['fields']['field_highlight_link']['table'] = 'field_data_field_highlight_link';
  $handler->display->display_options['fields']['field_highlight_link']['field'] = 'field_highlight_link';
  $handler->display->display_options['fields']['field_highlight_link']['label'] = '';
  $handler->display->display_options['fields']['field_highlight_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_highlight_link']['element_type'] = '0';
  $handler->display->display_options['fields']['field_highlight_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_highlight_link']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_highlight_link']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_highlight_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_highlight_link']['type'] = 'link_absolute';
  $handler->display->display_options['fields']['field_highlight_link']['settings'] = array(
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
  $handler->display->display_options['fields']['field_highlight_link']['field_api_classes'] = TRUE;
  /* Champ: Contenu : Tous les termes de taxonomie */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['text'] = '<span class="information-picto"><i class="fas fa-info"></i></span>';
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'collection' => 0,
    'confort_size' => 0,
    'haqihana_color' => 0,
    'haqihana_harness_size' => 0,
    'haqihana_leash_size' => 0,
    'highlight' => 0,
    'product_category' => 0,
  );
  /* Champ: Contenu : highlight image */
  $handler->display->display_options['fields']['field_highlight_image']['id'] = 'field_highlight_image';
  $handler->display->display_options['fields']['field_highlight_image']['table'] = 'field_data_field_highlight_image';
  $handler->display->display_options['fields']['field_highlight_image']['field'] = 'field_highlight_image';
  $handler->display->display_options['fields']['field_highlight_image']['label'] = '';
  $handler->display->display_options['fields']['field_highlight_image']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_highlight_image']['alter']['text'] = '[field_highlight_image]
[term_node_tid]';
  $handler->display->display_options['fields']['field_highlight_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_highlight_image']['alter']['path'] = '[field_highlight_link]';
  $handler->display->display_options['fields']['field_highlight_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_highlight_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_highlight_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_highlight_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_highlight_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_highlight_image']['settings'] = array(
    'image_style' => 'product_medium',
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
  $handler->display->display_options['fields']['field_highlight_image']['field_api_classes'] = TRUE;
  /* Champ: Contenu : Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_highlight_link]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Critère de filtrage: Contenu : Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Critère de filtrage: Contenu : Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'highlight' => 'highlight',
  );
  /* Critère de filtrage: Contenu : Promu en page d'accueil */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  /* Critère de filtrage: Contenu : Possède un terme de la taxonomie */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    63 => '63',
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'highlight';
  $translatables['highlight'] = array(
    t('Master'),
    t('Interview'),
    t('plus'),
    t('Appliquer'),
    t('Réinitialiser'),
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('<span class="interview-picto"><i class="fas fa-microphone"></i></span>'),
    t('[field_highlight_image] 
[term_node_tid]'),
    t('Block Highlight Interview'),
    t('Bloc Highlight informations'),
    t('Informations'),
    t('<span class="information-picto"><i class="fas fa-info"></i></span>'),
    t('[field_highlight_image]
[term_node_tid]'),
  );
  $export['highlight'] = $view;

  return $export;
}
