<?php

/**
 * @file
 * dolce_fs_highlight.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function dolce_fs_highlight_taxonomy_default_vocabularies() {
  return array(
    'highlight' => array(
      'name' => 'Highlight',
      'machine_name' => 'highlight',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
  );
}
