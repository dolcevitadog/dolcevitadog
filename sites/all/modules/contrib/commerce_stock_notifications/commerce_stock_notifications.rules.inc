<?php

/**
 * @file
 * Commerce Stock Notifications rules integration.
 */

/**
 * Implements hook_rules_event_info().
 */
 function commerce_stock_notifications_rules_event_info() {
  $events = array();

  $events['commerce_stock_notifications_submit'] = array(
    'label' => t('A User wants to be notified'),
    'group' => t('Commerce Stock Notifications'),
    'variables' => array(
      'email' => array(
        'label' => t('Email address'),
        'type' => 'text',
      ),
      'commerce_product' => array(
        'label' => t('Commerce Product'),
        'type' => 'commerce_product'
      ),
    ),
  );

  return $events;
}

/**
 * Implements hook_rules_action_info().
 */
function commerce_stock_notifications_rules_action_info() {
  $actions = array();

  $actions['notify_on_override_change'] = array(
    'label' => t('Send notifications on stock override change'),
    'parameter' => array(
      'commerce_product' => array(
        'type' => 'commerce_product',
        'label' => t('Commerce Product'),
      ),
    ),
    'group' => t('Commerce Stock Notifications'),
    'callbacks' => array(
      'execute' => 'commerce_stock_notifications_notify_based_on_product_id',
    ),
  );

  return $actions;
}
