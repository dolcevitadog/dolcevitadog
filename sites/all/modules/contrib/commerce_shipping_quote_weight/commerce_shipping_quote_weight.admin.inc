<?php

/**
 * @file
 * The administrative pages for the commerce_shipping_quote_weight module.
 */

/**
 * Implements commerce_shipping_quote_weight_admin().
 */
function commerce_shipping_quote_weight_admin() {
  $output = '';
  $rows = array();

  $header = array(t('Quote Id'), t('Zone'), t('Minimum weight'), t('Maximum weight'), t('Shipping Rate'), t('Operations'));

  $query = db_select('commerce_shipping_quote_weight', 'csqw')
    ->extend('PagerDefault')
    ->extend('TableSort');
  $query->leftjoin('commerce_shipping_quote_zones', 'csqz', 'csqw.zid = csqz.zid');
  $result = $query->fields('csqw')
    ->fields('csqz', array('name'))
    ->orderBy('csqw.qid')
    ->limit(20)
    ->execute()->fetchAll();
  //echo "<pre>";print_r($result);exit;
  /*$result = db_query("SELECT qid,min,max,rate,
  {commerce_shipping_quote_weight}.zid,{commerce_shipping_quote_zones}
  .name as zone FROM {commerce_shipping_quote_weight} LEFT JOIN {commerce_shipping_quote_zones} ON
  {commerce_shipping_quote_zones}.zid = {commerce_shipping_quote_weight}.zid
  ORDER by zone, min");*/

  /*$currency = commerce_currency_load('AED');
  // Convert the price amount to a user friendly decimal value.
  $default_amount = commerce_currency_amount_to_decimal('20095', 'AED');
  $default_amount = number_format($default_amount, $currency['decimals'], '.', '');
  //print($default_amount);exit;*/

  //$price = commerce_currency_decimal_to_amount('200.00', 'AED');
  //$price = commerce_currency_amount_to_decimal('20000', 'AED');

  //while ($r = db_fetch_object($result)) {
  foreach ($result as $r) {
    //$rate = commerce_currency_amount_to_decimal($r->rate, 'AED');
    $row = array();
    $qid = $r->qid;
    $row[] = $qid;
    $row[] = ($r->name) ? $r->name : t('Zone Name not available');
    $row[] = number_format($r->minimum_weight, 2, '.', '');
    $row[] = number_format($r->maximum_weight, 2, '.', '');
    $row[] = ($r->rate > 0) ? number_format(commerce_currency_amount_to_decimal
      ($r->rate, $r->currency_code),2) . ' ' . $r->currency_code :  t('Currency code not found');
    //$row[] = drupal_render($form['rates'][$qid]['delete']);
    $row[] = l(t('edit'), 'admin/commerce/config/shipping-quote/quote/edit/' . $qid) .
      '&nbsp;' . l(t('delete'), 'admin/commerce/config/shipping-quote/quote/delete/' . $qid);
    $rows[] = $row;
  }

  if (count($rows) == 0) {
    $rows[] = array(array(
      'data' => t('No shipping rates found.'),
      'colspan' => count($header),
    ));
  }
  $output .= theme('table', array(
      'header' => $header,
      'rows' => $rows,
    )
  );
  $output .= theme('pager');

  return $output;
}

/**
 * Implements commerce_shipping_quote_weight_add().
 *
 * @param $form
 * @param $form_state
 * @return array
 */
function commerce_shipping_quote_weight_add($form, &$form_state) {
  // Get the available zones.
  $zones = commerce_shipping_quote_zones_get_select();

  if (empty($zones)) {
    $form['zone_not_available'] = array(
      '#type' => 'fieldset',
      '#title' => 'Shipping zones not available',
    );
    $form['zone_not_available']['no_zones'] = array(
      '#markup' => 'It seems that there are no shipping zones configured. ' . l('Manage zones', 'admin/commerce/config/shipping-quote/zones'),
    );

    return $form;
  }
  // To get the active currencies of the site.
  foreach (commerce_currencies(TRUE) as $currency_code => $currency) {
    $currencies[$currency_code] = t('@code', array('@code' => $currency['code']));
  }
  $form['quote'] = array(
    '#type' => 'fieldset',
    '#title' => t('Add new shipping quote'),
    '#description' => t('Defines a range of weights for the order total weight.'),
    '#collapsible' => FALSE,
    '#collapsed' => TRUE,
  );
  $form['quote']['minimum_weight'] = array(
    '#type' => 'textfield',
    '#title' => t('Minimum weight'),
    '#size' => 12,
    '#description' => t('Minimum order weight in %unit',
      array('%unit' => variable_get('shipping_global_quote_weight_unit', 'kg'))),
  );
  $form['quote']['maximum_weight'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum weight'),
    '#size' => 12,
    '#description' => t('Maximum order weight in %unit',
      array('%unit' => variable_get('shipping_global_quote_weight_unit', 'kg'))),
  );
  $form['quote']['quote_rate'] = array(
    '#type' => 'textfield',
    '#title' => t('Shipping Rate'),
    '#size' => 12,
    '#description' => t('Shipping rate for the weight'),
  );
  $form['quote']['currency_code'] = array(
    '#type' => 'select',
    '#title' => t('Currency'),
    '#options' => $currencies,
    '#default_value' => commerce_default_currency() ? commerce_default_currency() : reset($currencies),
    '#description' => 'Shipping rate currency',
  );
  $form['quote']['quote_zone'] = array(
    '#type' => 'select',
    '#title' => t('Shipping zone'),
    '#options' => $zones,
    '#multiple' => FALSE,
    '#description' => t('Select a shipping zone for this rate. ') . l('Manage zones', 'admin/commerce/config/shipping-quote/zones'),
  );
  $form['buttons']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Add quote'),
  );
  $form['buttons']['cancel'] = array(
    '#markup' => l(t('Cancel'), 'admin/commerce/config/shipping-quote/quote'),
  );
  $form['#redirect'] = 'admin/commerce/config/shipping-quote/quote';

  return $form;
}

/**
 * Validation function for the commerce_shipping_quote_weight_add().
 *
 * @param $form
 * @param $form_state
 */
function commerce_shipping_quote_weight_add_validate($form, &$form_state) {
  $values = $form_state['values'];

  // check if everything is a number greater than or equal to 0
  if ($values['minimum_weight'] < 0 || !is_numeric($values['minimum_weight'])) {
    form_set_error('minimum_weight', t('The minimum value must be a number not less than 0.'));
  }
  if ($values['maximum_weight'] < 0 || !is_numeric($values['maximum_weight'])) {
    form_set_error('maximum_weight', t('The maximum value must be a number greater than 0.'));
  }
  if (($values['quote_rate'] < 0) || (!is_numeric($values['quote_rate']))) {
    form_set_error('quote_rate', t('Shipping rate must be a number not less than 0.'));
  }

  // check that max weight is bigger than min weight.
  if ($values['maximum_weight'] && $values['maximum_weight'] <= $values['minimum_weight']) {
    form_set_error('maximum_weight', t('The maximum value must be greater than the minumum value.'));
  }

  if (!$values['quote_zone']) {
    form_set_error('quote_zone', t('You must select a shipping zone.'));
  }

  //check for weight range overlapping in the zone.
  $query = db_select('commerce_shipping_quote_weight', 'csqw')
    ->fields('csqw')
    ->condition('zid', $values['quote_zone'])
    ->orderBy('minimum_weight')
    ->execute()
    ->fetchAll();
  foreach ($query as $result) {
    if($values['minimum_weight'] >= $result->minimum_weight &&
        $values['minimum_weight'] < $result->maximum_weight) {
      form_set_error('minimum_weight', t('The weight range falls in the existing range.'));
    }
    if($values['maximum_weight'] > $result->minimum_weight && $values['maximum_weight'] <= $result->maximum_weight) {
      form_set_error('maximum_weight', t('The weight range falls in the existing range.'));
    }
    //echo "<pre>";print_r($result);exit;
  }

}

/**
 * Submit handler commerce_shipping_quote_weight_add().
 *
 * @param $form
 * @param $form_state
 */
function commerce_shipping_quote_weight_add_submit($form, &$form_state) {
  $values = $form_state['values'];

  // check for and insert new rate quote
  $quote_rate = commerce_currency_decimal_to_amount($values['quote_rate'], $values['currency_code']);

  if ($values['maximum_weight'] > $values['minimum_weight'] &&
    $values['maximum_weight'] > 0) {
    $quote_add = db_insert('commerce_shipping_quote_weight')
      ->fields(array(
        'zid' => $values['quote_zone'],
        'minimum_weight' => $values['minimum_weight'],
        'maximum_weight' => $values['maximum_weight'],
        'rate' => $quote_rate,
        'currency_code' => $values['currency_code'],
      ))->execute();
    drupal_set_message(t('The new shipping quote has been added successfully.'), 'status');
  }
  $form_state['redirect'] = 'admin/commerce/config/shipping-quote/quote';
}

/**
 * Implements commerce_shipping_quote_weight_edit().
 *
 * @param $form
 * @param $form_state
 * @param $id
 *
 * @return array $form
 */
function commerce_shipping_quote_weight_edit($form, $form_state, $id) {
  $form = array();

  // To get the active currencies of the site.
  foreach (commerce_currencies(TRUE) as $currency_code => $currency) {
    $currencies[$currency_code] = t('@code', array('@code' => $currency['code']));
  }

  $edit = db_select('commerce_shipping_quote_weight', 'csqw')
    ->fields('csqw')
    ->condition('qid', $id)
    ->execute()
    ->fetchObject();

  $edit->rate = commerce_currency_amount_to_decimal($edit->rate, $edit->currency_code);

  // Get zones
  $zones = commerce_shipping_quote_zones_get_select();
  //echo "<pre>";print_r($zones);exit;
  $form['quote'] = array(
    '#type' => 'fieldset',
    '#title' => t('Edit global quote'),
    '#description' => t('Defines a range of weights for the order total weight.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['quote']['qid'] = array(
    '#type' => 'hidden',
    '#value' => $edit->qid,
  );
  $form['quote']['minimum_weight'] = array(
    '#type' => 'textfield',
    '#title' => t('Minimum weight'),
    '#default_value' => number_format($edit->minimum_weight, 2, '.', ''),
    '#size' => 12,
    '#description' => t('minimum order weight in %unit',
      array('%unit' => 'kg')),
  );
  $form['quote']['maximum_weight'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum weight'),
    '#default_value' => number_format($edit->maximum_weight, 2, '.', ''),
    '#size' => 12,
    '#description' => t('maximum order weight in %unit',
      array('%unit' => 'kg')),
  );
  $form['quote']['quote_rate'] = array(
    '#type' => 'textfield',
    '#title' => t('Shipping Rate'),
    '#default_value' => number_format($edit->rate, 2, '.', ''),
    '#size' => 12,
    '#description' => t('Shipping rate for the quote'),
  );
  $form['quote']['currency_code'] = array(
    '#type' => 'select',
    '#title' => t('Currency'),
    '#options' => $currencies,
    '#default_value' => $edit->currency_code,
    '#description' => 'Shipping rate currency',
  );
  $form['quote']['quote_zone'] = array(
    '#type' => 'select',
    '#title' => t('Shipping zone'),
    '#options' => $zones,
    '#default_value' => $edit->zid,
    '#multiple' => FALSE,
    '#description' => t('Select a zone for this rate. ') . l('edit/add zones', 'admin/commerce/config/shipping-quote/zones'),
  );
  $form['buttons']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Update quote'),
  );
  $form['buttons']['cancel'] = array(
    '#markup' => l('Cancel', 'admin/commerce/config/shipping-quote/quote'),
  );
  $form['#redirect'] = 'admin/commerce/config/shipping-quote/quote';

  return $form;
}

/**
 * Validation function for the shipping quote edit form.
 */
function commerce_shipping_quote_weight_edit_validate($form, &$form_state) {
  $values = $form_state['values'];
  //echo "<pre>";print_r($values);exit;

  // check if everything is a number greater than or equal to 0
  if ($values['minimum_weight'] < 0 || !is_numeric($values['minimum_weight'])) {
    form_set_error('minimum_weight', t('The minimum value must be a number not less than 0.'));
  }
  if ($values['maximum_weight'] < 0 || !is_numeric($values['maximum_weight'])) {
    form_set_error('maximum_weight', t('The maximum value must be a number greater than 0.'));
  }
  if (($values['quote_rate'] < 0) || (!is_numeric($values['quote_rate']))) {
    form_set_error('quote_rate', t('Shipping rate must be a number not less than 0.'));
  }

  // check that max is bigger than minimum_weight
  if ($values['maximum_weight'] && $values['maximum_weight'] <= $values['minimum_weight']) {
    form_set_error('maximum_weight', t('The maximum value must be greater than the minumum value.'));
  }

  if (!$values['quote_zone']) {
    form_set_error('minimum_weight', t('You must select a shipping zone.'));
  }

  //check for weight range overlapping in the zone.
  $query = db_select('commerce_shipping_quote_weight', 'csqw')
    ->fields('csqw')
    ->condition('zid', $values['quote_zone'])
    ->condition('qid', $values['qid'], '!=')
    ->orderBy('minimum_weight')
    ->execute()
    ->fetchAll();
  //echo "<pre>";print_r($values);print_r($query);exit;
  foreach ($query as $result) {
    if($values['minimum_weight'] > $result->minimum_weight && $values['minimum_weight'] <= $result->maximum_weight) {
      form_set_error('minimum_weight', t('The weight range falls in the existing range.'));
    }
    if($values['maximum_weight'] > $result->minimum_weight && $values['maximum_weight'] <= $result->maximum_weight) {
      form_set_error('maximum_weight', t('The weight range falls in the existing range.'));
    }
  }
}

/**
 * Submit handler for the shipping quote edit form.
 */
function commerce_shipping_quote_weight_edit_submit($form, &$form_state) {
  $values = $form_state['values'];
  //echo "<pre>";print_r($values);exit;

  // check for and insert new rate quote

  $quote_rate = commerce_currency_decimal_to_amount($values['quote_rate'], $values['currency_code']);

  if ($values['maximum_weight'] > $values['minimum_weight'] && $values['maximum_weight'] > 0) {
    $quote_add = db_update('commerce_shipping_quote_weight')
      ->fields(array(
        'zid' => $values['quote_zone'],
        'minimum_weight' => $values['minimum_weight'],
        'maximum_weight' => $values['maximum_weight'],
        //'rate' => $values['quote_rate'],
        'rate' => $quote_rate,
        'currency_code' => $values['currency_code'],
      ))
      ->condition('qid', $values['qid'])
      ->execute();
    drupal_set_message(t('The new shipping quote has been added successfully.'), 'status');
  }
  $form_state['redirect'] = 'admin/commerce/config/shipping-quote/quote';
}

/**
 * Implements commerce_shipping_quote_weight_delete().
 *
 * @param $form
 * @param $form_state
 * @param $id
 *
 * @return mixed confirm_form
 */
function commerce_shipping_quote_weight_delete($form, $form_state, $id) {
  $form = array();

  $form['qid'] = array(
    '#type' => 'hidden',
    '#value' => $id,
  );

  $form['#redirect'] = 'admin/commerce/config/shipping-quote/quote';

  return confirm_form($form, t('Are you sure you want to delete the shipping quote "!name"?', array('!name' => $id)),
    'admin/commerce/config/shipping-quote/quote', t('This will delete the shipping quote which may affect the checkout process.'), 'Yes', 'Cancel', 'confirm_shipping_quote_delete');
}

/**
 * Submit handler for the commerce_shipping_quote_weight_delete form.
 * @param $form
 * @param $form_state
 */
function commerce_shipping_quote_weight_delete_submit($form, $form_state) {
  $qid = $form_state['values']['qid'];

  $quote_delete = db_delete('commerce_shipping_quote_weight')
    ->condition('qid', $form_state['values']['qid'])
    ->execute();
  drupal_set_message(t('The shipping quote "!name" has been deleted successfully.', array('!name' => $qid)), 'status');
  drupal_goto('admin/commerce/config/shipping-quote/quote');
}
