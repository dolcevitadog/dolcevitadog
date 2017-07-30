<?php

/**
 * @file
 * The administrative pages for the commerce_shipping_quote_zone module.
 */

function commerce_shipping_quote_zones_admin() {
  return theme('commerce_shipping_quote_zones_admin');
}

/**
 * Theme zones admin form
 */

function theme_commerce_shipping_quote_zones_admin() {
  $output = '';
  $rows = array();

  //echo "<pre>";print_r($form);exit;
  $headers = array(t('Name'), t('Countries'), t('Regions'), t('Operations'));

  $result = db_select('commerce_shipping_quote_zones', 'csqz')
    ->fields('csqz')
    ->orderBy('name')
    ->execute()
    ->fetchAll();

  foreach ($result as $r) {
  //while ($r = db_fetch_object($result)) {
    $row = array();
    $zid = $r->zid;
    //$row[] = drupal_render($form['zones'][$zid]['delete']);
    $row[] = $r->name;
    $row[] = str_replace('|', ' ', $r->countries);
    if ($r->regions && count($r->regions)) {
      $row[] = str_replace('|', ' ', $r->regions);
    }
    else {
      $row[] = 'All';
    }
    $row[] = l('edit', 'admin/commerce/config/shipping-quote/zones/edit/' . $zid) . '&nbsp;' . l('delete', 'admin/commerce/config/shipping-quote/zones/delete/' . $zid);
    $rows[] = $row;
  }

  if (count($rows) == 0) {
    $rows[] = array(array(
      'data' => t('No zones found'),
      'colspan' => count($headers),
    ));
  }
  $output .= theme('table', array('header' => $headers, 'rows' => $rows));

  //$output .= drupal_render($form);

  return $output;
}

/*
 * commerce_shipping_quote_zones admin form
 */
function commerce_shipping_quote_zones_add($form, $form_state) {
  $form = array();
  $countries = array();

  /*$available_countries = array(
    '784' => 'United Arab Emirates',
    '48' => 'Bahrain',
    '512' => 'Oman',
    '634' => 'Qatar',
    '682' => 'Saudi Arabia',
    '414' => 'Kuwait',
  );*/
  //echo "<pre>";print_r(countries_get_countries('name'));exit;
  $countries = countries_get_countries('name');
  /*$available_countries = array(
      'United Arab Emirates' => 'United Arab Emirates',
      'Bahrain' => 'Bahrain',
      'Oman' => 'Oman',
      'Qatar' => 'Qatar',
      'Saudi Arabia' => 'Saudi Arabia',
      'Kuwait' => 'Kuwait',
  );
  foreach ($available_countries as $cid => $c) {
    //$countries[$c . ',' . $cid] = $c;
    $countries[$c] = $c;
  }*/
  //echo "<pre>";print_r($countries);exit;

  $form['zone'] = array(
    '#type' => 'fieldset',
    '#title' => t('Add new shipping zone'),
    '#description' => t('Shipping zone options'),
    '#collapsible' => FALSE,
    '#collapsed' => TRUE,
  );

  $form['zone']['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Zone name'),
    '#default_value' => '',
    '#size' => 40,
    '#description' => t('Name for the zone'),
  );

  $form['zone']['country'] = array(
    '#type' => 'select',
    '#title' => t('Countries'),
    '#options' => $countries,
    '#multiple' => TRUE,
    '#description' => t('Select all the countries of the zone. '), //. l('Add
    //countries', 'admin/store/settings/countries/edit'),
  );

  $form['buttons']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Add zone'),
  );
  $form['buttons']['cancel'] = array(
      '#markup' => l(t('Cancel'), 'admin/commerce/config/shipping-quote/zones'),
  );
  $form['#redirect'] = 'admin/commerce/config/shipping-quote/zones';
  //$form['#theme'] = 'commerce_shipping_quote_zones_admin';
  //return theme('commerce_shipping_quote_zones_admin', $form);

  return $form;
}

function commerce_shipping_quote_zones_add_validate($form, &$form_state) {
  $values = $form_state['values'];

  if (!$values['name']) {
    form_set_error('name',   t('Enter a name for the zone'));
  }
  if (!is_array($values['country']) || count($values['country']) < 1) {
    form_set_error('country',   t('You must select a country for your zone'));
  }
  else {
    // Check overlapping zones.
    $zones = commerce_shipping_quote_zones_get();
    $cerror = array();
    $rerror = array();

    //echo "<pre>";print_r($zones);exit;
    foreach($values['country'] as $vc) {
      foreach ($zones as $zone) {
        if($values['name'] == $zone['name']) {
          form_set_error('name', t('The shipping zone already exists.'));
        }
        // Country defined in another zone
        elseif (in_array($vc, explode('|', $zone['countries']))){
          $cerror[] = $vc;
          // all regions
          /*if ($values['zone']['region'] == NULL ||
              $values['zone']['region'] == NULL) {
            $cerror[] = $vc;
          }*/
        }
      }
    }

    if (count($cerror)) {
      form_set_error('country',   t('The following countries are selected in other zones: %list', array('%list' => implode(', ', $cerror))));
    }
    if (count($rerror)) {
      form_set_error('region',   t('The following regions are selected in other zones: %list', array('%list' => implode(', ', $rerror))));
    }
  }
}

/*
 * Admin form submit
 */

function commerce_shipping_quote_zones_add_submit($form, &$form_state) {
  $values = $form_state['values'];

  foreach ($values['country'] as $iso2 => $country) {
    $country = country_load($country);
    $countries[] = $country->name . ',' . $iso2;
  }

  if ($values['name'] && is_array($values['country']) && count($values['country'])) {
    if(count($countries) == 1) {
      $countries = reset($countries);
    } else {
      $countries = implode('|', $countries);
    }

    $commerce_shipping_quote_zones_add = db_insert('commerce_shipping_quote_zones')
    ->fields(array(
      'name' => $values['name'],
      'countries' => $countries,
      'regions' => '',
    ))->execute();

    drupal_set_message(t('The new shipping zone "@name" has been added successfully.', array('@name' => $values['name'])), 'status');
  }
  $form_state['redirect'] = 'admin/commerce/config/shipping-quote/zones';
}

function commerce_shipping_quote_zones_edit($form, $form_state, $id) {
  $form = array();

  $zones = db_select('commerce_shipping_quote_zones', 'csqz')
    ->fields('csqz')
    ->condition('zid', $id)
    ->execute()
    ->fetchAll();

  foreach ($zones as $zone) {
    //echo "<pre>";print_r($zone);exit;
    // Edit the shipping zone.
    $edit = $zone;
    $countries_edit = explode('|', $zone->countries);
    foreach ($countries_edit as $country) {
      $country_arr = explode(',', $country);
      $countries_saved[] = $country_arr['1'];
    }
    //$edit->regions = explode('|', $zone->regions);
  }
  $countries = countries_get_countries('name');

  $form['zone'] = array(
    '#type' => 'fieldset',
    '#title' => t('Edit Shipping zone'),
    '#description' => t('Edit the Shipping zone'),
    '#collapsible' => FALSE,
    '#collapsed' => TRUE,
  );

  $form['zone']['zid'] = array(
    '#type' => 'hidden',
    '#value' => $edit->zid,
  );

  $form['zone']['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Zone name'),
    '#default_value' => '',
    '#default_value' => $edit->name,
    '#size' => 40,
    '#description' => t('Name for the zone.'),
  );

  $form['zone']['country'] = array(
    '#type' => 'select',
    '#title' => t('Countries'),
    '#options' => $countries,
    '#default_value' => $countries_saved,
    '#multiple' => TRUE,
    '#description' => t('Select all the countries of the zone.') //. l('Add countries', 'admin/store/settings/countries/edit'),
  );

  $form['buttons']['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Update zone'),
  );
  $form['buttons']['cancel'] = array(
      '#markup' => l(t('Cancel'), 'admin/commerce/config/shipping-quote/zones'),
  );
  $form['#redirect'] = 'admin/commerce/config/shipping-quote/zones';

  return $form;
}

function commerce_shipping_quote_zones_edit_validate($form, &$form_state) {
  //echo "<pre>";print_r($form_state);exit;
  $values = $form_state['values'];

  if (!$values['name']) {
    form_set_error('name', t('Enter a name for the zone'));
  }
  if (!is_array($values['country']) || count($values['country']) < 1) {
    form_set_error('country',   t('You must select a country for your zone'));
  }
  else {
    // Check overlapping zones.
    $zones = commerce_shipping_quote_zones_get();
    $cerror = array();
    $rerror = array();

    //echo "<pre>";print_r($zones);exit;
    foreach($values['country'] as $vc) {
      foreach ($zones as $zone) {
        if($values['name'] == $zone['name'] && $values['zid'] != $zone['zid']) {
          form_set_error('name', t('The shipping zone already exists.'));
        }
        // Country defined in another zone
        $countries_edit = explode('|', $zone['countries']);
        foreach ($countries_edit as $country) {
          $country_arr = explode(',', $country);
          $countries_saved[] = $country_arr['1'];

        }
        //echo "<pre>";print_r($countries_edit);exit;
        if (in_array($vc, $countries_saved)){
          $cerror[] = $vc;
          // all regions
          /*if ($values['zone']['region'] == NULL ||
              $values['zone']['region'] == NULL) {
            $cerror[] = $vc;
          }*/
        }
      }
    }

    if (count($cerror)) {
      form_set_error('country',   t('The following countries are selected in other zones: %list', array('%list' => implode(', ', $cerror))));
    }
    if (count($rerror)) {
      form_set_error('region',   t('The following regions are selected in other zones: %list', array('%list' => implode(', ', $rerror))));
    }
  }
}

/*
 * Admin form submit
 */

function commerce_shipping_quote_zones_edit_submit($form, &$form_state) {
  $values = $form_state['values'];
  $zid = $values['zid'];

  if ($values['name'] && is_array($values['country']) && count($values['country'])) {
    foreach ($values['country'] as $iso2 => $country) {
      $country = country_load($country);
      $countries[] = $country->name . ',' . $iso2;
    }

    if(count($countries) == 1) {
      $countries = reset($countries);
    } else {
      $countries = implode('|', $countries);
    }


    $commerce_shipping_quote_zones_add = db_update('commerce_shipping_quote_zones')
      ->fields(array(
        'name' => $values['name'],
        'countries' => $countries,
        'regions' => '',
      ))
      ->condition('zid', $zid)
      ->execute();

    drupal_set_message(t('The new shipping zone "@name" has been updated successfully.', array('@name' => $values['name'])), 'status');
  }
  $form_state['redirect'] = 'admin/commerce/config/shipping-quote/zones';
}

function commerce_shipping_quote_zones_delete($form, $form_state, $id) {
  $form = array();
  $zone_name = db_select('commerce_shipping_quote_zones', 'sz')
      ->fields('sz', array('name'))
      ->condition('zid', $id)
      ->execute()->fetchField();

  $form['zid'] = array(
      '#type' => 'hidden',
      '#value' => $id,
  );
  $form['zname'] = array(
      '#type' => 'hidden',
      '#value' => $zone_name,
  );

  $form['#redirect'] = 'admin/commerce/config/shipping-quote/zones';
  return confirm_form($form, t('Are you sure you want to delete the shipping zone "@name"?', array('@name' => $zone_name)), 'admin/commerce/config/shipping-quote/zones',
    'This will delete the shipping zone which may affect the checkout process.' ,'Yes', 'Cancel', 'confirm_commerce_shipping_quote_zones_delete');
}

function commerce_shipping_quote_zones_delete_submit($form, $form_state) {
  $name = $form_state['values']['zname'];
  $zone_deleted = db_delete('commerce_shipping_quote_zones')
    ->condition('zid', $form_state['values']['zid'])
    ->execute();
  drupal_set_message(t('The shipping zone "@name" has been deleted successfully.', array('@name' => $name)), 'status');
  drupal_goto('admin/commerce/config/shipping-quote/zones');
}
