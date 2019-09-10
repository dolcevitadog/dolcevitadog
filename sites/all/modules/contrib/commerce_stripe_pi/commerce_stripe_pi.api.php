<?php

/**
 * @file
 * This code is never called, it's just information about to use the hooks.
 */

/**
 * Add information to the metadata sent to Stripe.
 */
function hook_commerce_stripe_pi_metadata($order) {
  return array(
    'order_number' => $order->order_number,
  );
}

/**
 * Add information to the payment intent sent to Stripe.
 */
function hook_commerce_stripe_pi_payment_intent_data_alter(array &$payment_intent_data, EntityMetadataWrapper $order_wrapper, array $payment_method, $cardonfile_id = NULL) {
  $payment_intent_data['description'] = sprintf('Order %s', $order_wrapper->order_id->value());
}
