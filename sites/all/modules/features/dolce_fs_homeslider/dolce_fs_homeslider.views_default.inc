<?php

/**
 * @file
 * dolce_fs_homeslider.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dolce_fs_homeslider_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'homeslider';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Homeslider';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Homeslider';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
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
    'minSlides' => '1',
    'maxSlides' => '1',
    'moveSlides' => '0',
    'slideWidth' => '0',
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
    'field_homeslider_link' => 0,
    'field_homeslider_image' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_homeslider_link' => 0,
    'field_homeslider_image' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Champ: Contenu : Homeslider Link */
  $handler->display->display_options['fields']['field_homeslider_link']['id'] = 'field_homeslider_link';
  $handler->display->display_options['fields']['field_homeslider_link']['table'] = 'field_data_field_homeslider_link';
  $handler->display->display_options['fields']['field_homeslider_link']['field'] = 'field_homeslider_link';
  $handler->display->display_options['fields']['field_homeslider_link']['label'] = '';
  $handler->display->display_options['fields']['field_homeslider_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_homeslider_link']['element_type'] = '0';
  $handler->display->display_options['fields']['field_homeslider_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_homeslider_link']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_homeslider_link']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_homeslider_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_homeslider_link']['type'] = 'link_absolute';
  $handler->display->display_options['fields']['field_homeslider_link']['settings'] = array(
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
  $handler->display->display_options['fields']['field_homeslider_link']['field_api_classes'] = TRUE;
  /* Champ: Contenu : Homeslider_image */
  $handler->display->display_options['fields']['field_homeslider_image']['id'] = 'field_homeslider_image';
  $handler->display->display_options['fields']['field_homeslider_image']['table'] = 'field_data_field_homeslider_image';
  $handler->display->display_options['fields']['field_homeslider_image']['field'] = 'field_homeslider_image';
  $handler->display->display_options['fields']['field_homeslider_image']['label'] = '';
  $handler->display->display_options['fields']['field_homeslider_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_homeslider_image']['alter']['path'] = '[field_homeslider_link]';
  $handler->display->display_options['fields']['field_homeslider_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_homeslider_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_homeslider_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_homeslider_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_homeslider_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_homeslider_image']['settings'] = array(
    'image_style' => '',
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
  $handler->display->display_options['fields']['field_homeslider_image']['field_api_classes'] = TRUE;
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
    'homeslider' => 'homeslider',
  );

  /* Display: Block Homeslider */
  $handler = $view->new_display('block', 'Block Homeslider', 'block');
  $translatables['homeslider'] = array(
    t('Master'),
    t('Homeslider'),
    t('plus'),
    t('Appliquer'),
    t('Réinitialiser'),
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Block Homeslider'),
  );
  $export['homeslider'] = $view;

  return $export;
}
