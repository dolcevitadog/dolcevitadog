<?php

/**
 * @file
 * dolce_fs_partenaires.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dolce_fs_partenaires_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'partners';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Partners';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Nos partenaires';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'Voir tous les partenaires';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Appliquer';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns_horizontal'] = '-1';
  $handler->display->display_options['style_options']['columns_vertical'] = '4';
  $handler->display->display_options['style_options']['columns_xs'] = '12';
  $handler->display->display_options['style_options']['columns_sm'] = '12';
  $handler->display->display_options['style_options']['columns_md'] = '6';
  $handler->display->display_options['style_options']['columns_lg'] = '3';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Champ: Contenu : Logo */
  $handler->display->display_options['fields']['field_partners_logo']['id'] = 'field_partners_logo';
  $handler->display->display_options['fields']['field_partners_logo']['table'] = 'field_data_field_partners_logo';
  $handler->display->display_options['fields']['field_partners_logo']['field'] = 'field_partners_logo';
  $handler->display->display_options['fields']['field_partners_logo']['label'] = '';
  $handler->display->display_options['fields']['field_partners_logo']['element_type'] = '0';
  $handler->display->display_options['fields']['field_partners_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_partners_logo']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_partners_logo']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_partners_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_partners_logo']['settings'] = array(
    'image_style' => 'medium',
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
  $handler->display->display_options['fields']['field_partners_logo']['field_api_classes'] = TRUE;
  /* Champ: Contenu : Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Champ: Contenu : Website */
  $handler->display->display_options['fields']['field_partners_website']['id'] = 'field_partners_website';
  $handler->display->display_options['fields']['field_partners_website']['table'] = 'field_data_field_partners_website';
  $handler->display->display_options['fields']['field_partners_website']['field'] = 'field_partners_website';
  $handler->display->display_options['fields']['field_partners_website']['label'] = '';
  $handler->display->display_options['fields']['field_partners_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_partners_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_partners_website']['settings'] = array(
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
  /* Champ: Contenu : Address */
  $handler->display->display_options['fields']['field_partners_address']['id'] = 'field_partners_address';
  $handler->display->display_options['fields']['field_partners_address']['table'] = 'field_data_field_partners_address';
  $handler->display->display_options['fields']['field_partners_address']['field'] = 'field_partners_address';
  $handler->display->display_options['fields']['field_partners_address']['label'] = '';
  $handler->display->display_options['fields']['field_partners_address']['element_type'] = '0';
  $handler->display->display_options['fields']['field_partners_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_partners_address']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_partners_address']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_partners_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_partners_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
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
  $handler->display->display_options['fields']['field_partners_address']['field_api_classes'] = TRUE;
  /* Critère de tri: Global : Au hasard */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
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
    'partners' => 'partners',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'partenaires';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Partenaires';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Bloc Partenaires Footer */
  $handler = $view->new_display('block', 'Bloc Partenaires Footer', 'block_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'partners-bloc-homepage';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['bxslider_views_slideshow']['general'] = array(
    'mode' => 'horizontal',
    'speed' => '500',
    'slideMargin' => '0',
    'startSlide' => '0',
    'randomStart' => 0,
    'infiniteLoop' => 1,
    'hideControlOnEnd' => 0,
    'captions' => 0,
    'ticker' => 0,
    'tickerHover' => 0,
    'adaptiveHeight' => 0,
    'adaptiveHeightSpeed' => '500',
    'video' => 0,
    'touchEnabled' => 1,
    'preloadImages' => 'all',
    'disable_standard_css' => 0,
    'useCSS' => 1,
    'align_image' => 'left',
    'align_caption' => 'left',
    'swipeThreshold' => '50',
    'oneToOneTouch' => 1,
    'preventDefaultSwipeX' => 1,
    'preventDefaultSwipeY' => 0,
    'color_caption' => '80, 80, 80, 0.75',
  );
  $handler->display->display_options['style_options']['bxslider_views_slideshow']['controlsfieldset'] = array(
    'controls' => 1,
    'nextText' => '',
    'prevText' => '',
    'startText' => '',
    'stopText' => '',
    'autoControls' => 0,
    'autoControlsCombine' => 0,
  );
  $handler->display->display_options['style_options']['bxslider_views_slideshow']['pagerfieldset'] = array(
    'pager' => 0,
    'pagerType' => 'full',
    'pagerShortSeparator' => ' / ',
    'pagerCustom' => '',
  );
  $handler->display->display_options['style_options']['bxslider_views_slideshow']['autofieldset'] = array(
    'pause' => '4000',
    'autoStart' => 1,
    'auto' => 1,
    'autoHover' => '0',
    'autoDelay' => '0',
    'autoDirection' => 'next',
  );
  $handler->display->display_options['style_options']['bxslider_views_slideshow']['carousel'] = array(
    'minSlides' => '3',
    'maxSlides' => '7',
    'moveSlides' => '0',
    'slideWidth' => '120',
  );
  $handler->display->display_options['style_options']['bxslider_views_slideshow']['callback'] = array(
    'onSliderLoad' => '',
    'onSlideBefore' => '',
    'onSlideAfter' => '',
    'onSlideNext' => '',
    'onSlidePrev' => '',
  );
  $handler->display->display_options['style_options']['slideshow_type'] = 'bxslider_views_slideshow';
  $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
  $handler->display->display_options['style_options']['skin_info'] = array(
    'class' => 'default',
    'name' => 'Par défaut',
    'module' => 'views_slideshow',
    'path' => '',
    'stylesheets' => array(),
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_partners_website' => 0,
    'field_partners_logo' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_partners_website' => 0,
    'field_partners_logo' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Champ: Contenu : Website */
  $handler->display->display_options['fields']['field_partners_website']['id'] = 'field_partners_website';
  $handler->display->display_options['fields']['field_partners_website']['table'] = 'field_data_field_partners_website';
  $handler->display->display_options['fields']['field_partners_website']['field'] = 'field_partners_website';
  $handler->display->display_options['fields']['field_partners_website']['label'] = '';
  $handler->display->display_options['fields']['field_partners_website']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_partners_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_partners_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_partners_website']['type'] = 'link_absolute';
  $handler->display->display_options['fields']['field_partners_website']['settings'] = array(
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
  /* Champ: Contenu : Logo */
  $handler->display->display_options['fields']['field_partners_logo']['id'] = 'field_partners_logo';
  $handler->display->display_options['fields']['field_partners_logo']['table'] = 'field_data_field_partners_logo';
  $handler->display->display_options['fields']['field_partners_logo']['field'] = 'field_partners_logo';
  $handler->display->display_options['fields']['field_partners_logo']['label'] = '';
  $handler->display->display_options['fields']['field_partners_logo']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_partners_logo']['alter']['path'] = '[field_partners_website]';
  $handler->display->display_options['fields']['field_partners_logo']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_partners_logo']['element_type'] = '0';
  $handler->display->display_options['fields']['field_partners_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_partners_logo']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_partners_logo']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_partners_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_partners_logo']['settings'] = array(
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
  $handler->display->display_options['fields']['field_partners_logo']['field_api_classes'] = TRUE;
  $translatables['partners'] = array(
    t('Master'),
    t('Nos partenaires'),
    t('Voir tous les partenaires'),
    t('Appliquer'),
    t('Réinitialiser'),
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Page'),
    t('plus'),
    t('Bloc Partenaires Footer'),
  );
  $export['partners'] = $view;

  return $export;
}
