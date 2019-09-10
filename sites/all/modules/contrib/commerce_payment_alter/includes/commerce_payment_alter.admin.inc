<?php
/**
 * @file
 * Administration page for Commerce Payment Alter Module.
 */

require_once 'commerce_payment_alter.helper.inc';
/**
 * Generates the alter configuration form.
 *
 * @param array $form
 *   The form object to be generated.
 * @param array $form_state
 *   The form state of the form object to be generated.
 *
 * @return array
 *   Returns the generated form object.
 */
function commerce_payment_alter_admin_form(array $form, array &$form_state) {
  $form['commerce_payment_alter'] = array(
    '#type' => 'fieldset',
    '#tree' => TRUE,
  );
  _commerce_payment_alter_admin_form_translation_elements(
    $form,
    $form_state,
    _commerce_payment_alter_get_configuration()
  );

  return system_settings_form($form);
}

/**
 * Generates the form translation elements for the configuration form.
 *
 * @param array $form
 *   The form object to be generated.
 * @param array $form_state
 *   The form state of the form object to be generated.
 * @param array $defaults
 *   Contains the default values.
 */
function _commerce_payment_alter_admin_form_translation_elements(array &$form, array &$form_state, array $defaults) {
  $payment_methods = commerce_payment_methods();
  $languages = language_list();

  $form['commerce_payment_alter']['translations'] = array(
    '#type' => 'fieldset',
    '#title' => t('Translations'),
    '#description' => t(
      'Configure the translations of all the payment methods'
    ),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
  );

  foreach ($payment_methods as $key => $payment_method) {
    foreach ($languages as $language) {
      $display_title_identifier = _commerce_payment_alter_get_identifier(
        'display_title',
        $key,
        $language->language
      );

      $form['commerce_payment_alter']['translations'][$display_title_identifier] = array(
        '#type' => 'textfield',
        '#title' => t(
          '%language translation for %method',
          array(
            '%language' => $language->native,
            '%method' => $payment_method['title'],
          )
        ),
        '#default_value' => isset($defaults['translations'][$display_title_identifier]) ? $defaults['translations'][$display_title_identifier] : '',
      );
    }
  }
}
