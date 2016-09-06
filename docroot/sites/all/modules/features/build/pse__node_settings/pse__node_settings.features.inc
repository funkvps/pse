<?php
/**
 * @file
 * pse__node_settings.features.inc
 */

/**
 * Implements hook_node_info().
 */
function pse__node_settings_node_info() {
  $items = array(
    'settings' => array(
      'name' => t('Settings'),
      'base' => 'node_content',
      'description' => t('Single Use Only'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
