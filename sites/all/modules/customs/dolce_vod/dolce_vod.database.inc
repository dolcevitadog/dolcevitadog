<?php

function dolce_vod_set_vid($uid, $orderid, $pid, $time, $increment) {
  db_insert('dolce_vod')->fields(array(
    'uid' => $uid,
    'orderid' => $orderid,
    'pid' => $pid,
    'start' => $time,
    'end' => $time+$increment
  ))->execute();
}

/* On recupere l'integralite des videos achetes par l'utilisateur */
function dolce_vod_get_videos_by_user($uid) {
  $result = db_select('dolce_vod', 'vod')
    ->fields('vod')
    ->condition('uid', $uid, '=')
    ->execute()
    ->fetchAllAssoc();
  return $result;
}

/* On check si l'utilisateur a bien acheté cette video */
function dolce_vod_user_purchase_pid($uid, $pid) {
  $query = db_select('dolce_vod', 'vod')
    ->fields('vod')
    ->condition('uid', $uid, '=')
    ->condition('pid', $pid, '=')
    ->execute();
  $result = $query->fetchAll();
  return $result;
}

/* On recupere l'integralite des videos valides achetes par l'utilisateur */
function dolce_vod_get_valid_videos_by_user($uid) {
  $timestamp = time();
  $query = db_select('dolce_vod', 'vod')
    ->fields('vod')
    ->condition('uid', $uid, '=')
    ->condition('start', $timestamp, '<')
    ->condition('end', $timestamp, '>')
    ->groupBy('pid')
    ->execute();
    $result = $query->fetchAll();
  return $result;
}


