<?php

/**
 * @file
 * dolce_fs_context.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function dolce_fs_context_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'homepage';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-homeslider-block' => array(
          'module' => 'views',
          'delta' => 'homeslider-block',
          'region' => 'highlighted',
          'weight' => '-10',
        ),
        'views-dolcevitadog_services-block' => array(
          'module' => 'views',
          'delta' => 'dolcevitadog_services-block',
          'region' => 'header',
          'weight' => '-10',
        ),
        'views-products_homepage-block' => array(
          'module' => 'views',
          'delta' => 'products_homepage-block',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-products_homepage-block_1' => array(
          'module' => 'views',
          'delta' => 'products_homepage-block_1',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-highlight-block' => array(
          'module' => 'views',
          'delta' => 'highlight-block',
          'region' => 'content',
          'weight' => '-8',
        ),
        'views-highlight-block_1' => array(
          'module' => 'views',
          'delta' => 'highlight-block_1',
          'region' => 'content',
          'weight' => '-7',
        ),
        'views-partners-block_1' => array(
          'module' => 'views',
          'delta' => 'partners-block_1',
          'region' => 'content',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['homepage'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'partners';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'partners:page' => 'partners:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-2' => array(
          'module' => 'block',
          'delta' => '2',
          'region' => 'content',
          'weight' => '-41',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['partners'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'product_display_detail';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'book' => 'book',
        'dvd' => 'dvd',
        'grossenbacher_harness' => 'grossenbacher_harness',
        'haqihana_harness' => 'haqihana_harness',
        'haqihana_leash' => 'haqihana_leash',
        'jacket' => 'jacket',
        'lead' => 'lead',
        'product_display' => 'product_display',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-suggested_product-block' => array(
          'module' => 'views',
          'delta' => 'suggested_product-block',
          'region' => 'content',
          'weight' => '3',
        ),
        'views-other_products-block' => array(
          'module' => 'views',
          'delta' => 'other_products-block',
          'region' => 'content',
          'weight' => '4',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['product_display_detail'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'dolce_discount-promotional_banner' => array(
          'module' => 'dolce_discount',
          'delta' => 'promotional_banner',
          'region' => 'zone_user',
          'weight' => '-10',
        ),
        'logo_block-logo' => array(
          'module' => 'logo_block',
          'delta' => 'logo',
          'region' => 'zone_user_first',
          'weight' => '-10',
        ),
        'dolce_user_links-dolce_user_links' => array(
          'module' => 'dolce_user_links',
          'delta' => 'dolce_user_links',
          'region' => 'zone_user_second',
          'weight' => '-10',
        ),
        'dolce_cart-dolce_cart_shopping_cart' => array(
          'module' => 'dolce_cart',
          'delta' => 'dolce_cart_shopping_cart',
          'region' => 'zone_user_second',
          'weight' => '-9',
        ),
        'tb_megamenu-main-menu' => array(
          'module' => 'tb_megamenu',
          'delta' => 'main-menu',
          'region' => 'navigation',
          'weight' => '-10',
        ),
        'mailchimp_signup-dolcevitadog_mailchimp' => array(
          'module' => 'mailchimp_signup',
          'delta' => 'dolcevitadog_mailchimp',
          'region' => 'footer',
          'weight' => '-10',
        ),
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
          'region' => 'footer',
          'weight' => '-9',
        ),
        'fb_likebox-0' => array(
          'module' => 'fb_likebox',
          'delta' => '0',
          'region' => 'footer',
          'weight' => '-8',
        ),
        'menu-menu-footer-navigation' => array(
          'module' => 'menu',
          'delta' => 'menu-footer-navigation',
          'region' => 'footer',
          'weight' => '-7',
        ),
        'menu-menu-payment-methods' => array(
          'module' => 'menu',
          'delta' => 'menu-payment-methods',
          'region' => 'footer_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['sitewide'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'user_profile';
  $context->description = 'Afficher sur la page profil utilisateur';
  $context->tag = 'user';
  $context->conditions = array(
    'user_page' => array(
      'values' => array(
        'view' => 'view',
      ),
      'options' => array(
        'mode' => 'all',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'dolce_user_links-dolce_user_logout' => array(
          'module' => 'dolce_user_links',
          'delta' => 'dolce_user_logout',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Afficher sur la page profil utilisateur');
  t('user');
  $export['user_profile'] = $context;

  return $export;
}
