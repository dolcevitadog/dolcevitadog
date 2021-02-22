<?php

/**
 * @file
 * The 'Force Logout' module forms.
 */

/**
 * Force logout settings form.
 */
function force_logout_admin($form, &$form_state) {
  global $user;

  $form['force_logout_status'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Force Logout.'),
    '#default_value' => variable_get('force_logout_status', FALSE),
  );

  $form['force_logout_login_message'] = array(
    '#type' => 'textarea',
    '#title' => t('Force logout message'),
    '#default_value' => variable_get('force_logout_login_message', 'Sorry you can not login now, please try to login again in the next a few hours.'),
    '#description' => t('The message that will show if the user tried to login while force logout is enabled and this user who does not have permission to bypass this force logout.'),
  );

  $form['truncate_all_sessions'] = array(
    '#type' => 'checkbox',
    '#title' => t('Delete all sessions by TRUNCATE sessions table (This will not delete your current session and you will not be logged-out).'),
    '#default_value' => 0,
  );
  $form['truncate'] = array('#type' => 'submit', '#value' => t('Delete all sessions'));
  $form['truncate']['#submit'] = array('force_logout_truncate_sessions');

  $sessions_count = db_query("SELECT COUNT(sid) AS count FROM {sessions}")->fetchField();
  $my_sessions_count = db_query("SELECT COUNT(sid) AS count FROM {sessions} WHERE uid = :uid", array(':uid'=>$user->uid))->fetchField();
  $form['truncate_note']['#markup'] = t('Current saved sessions is @count (@my_count of them related to your current user).', array('@count'=>$sessions_count, '@my_count'=>$my_sessions_count));

  return system_settings_form($form);

}

/**
 * TRUNCATE sessions table.
 */
function force_logout_truncate_sessions($form, &$form_state) {
  global $user;

  if($form_state['values']['truncate_all_sessions'] == 1){
    // Get all sessions count.
    $num_deleted = db_query("SELECT COUNT(sid) AS count FROM {sessions}")->fetchField();

    // This will do real truncate and will delete other sessions of current user.
    // But current session will not be deleted.
    db_truncate('sessions')->execute();
    $num_deleted = $num_deleted - 1;
  }else{
    // Delete all sessions except current user (action taker).
    $num_deleted = db_delete('sessions')
      ->condition('uid', $user->uid, '<>') // Avoid delete current user sessions.
      ->execute();
  }

  drupal_set_message(t('Now @count sessions has been deleted from sessions table.', array('@count'=>$num_deleted)), 'status');
}
