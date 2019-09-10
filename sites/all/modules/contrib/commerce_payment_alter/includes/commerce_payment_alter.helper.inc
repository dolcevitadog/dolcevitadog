<?php
/**
 * @file
 * Helper functions for Commerce Payment Alter Module.
 */

/**
 * Retrieve the configuration saved in a variable.
 *
 * @return array
 *   Returns an array with the commerce_payment_alter configuration.
 */
function _commerce_payment_alter_get_configuration() {
  $configuration = variable_get('commerce_payment_alter');

  if (!is_array($configuration)) {
    return array();
  }

  return $configuration;
}

/**
 * Build the identifier by type, method and language.
 *
 * @param string $type
 *   Contains the type of element.
 * @param string $method
 *   Contains the payment method type.
 * @param string $language
 *   Contains the language code.
 *
 * @return string
 *   Returns a, by underscores, concatenated string of all the parameters.
 */
function _commerce_payment_alter_get_identifier($type, $method, $language) {
  return implode(
    '_',
    array($type, $method, $language)
  );
}
