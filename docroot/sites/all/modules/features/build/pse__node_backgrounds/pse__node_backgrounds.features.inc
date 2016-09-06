<?php
/**
 * @file
 * pse__node_backgrounds.features.inc
 */

/**
 * Implements hook_node_info().
 */
function pse__node_backgrounds_node_info() {
  $items = array(
    'backgrounds' => array(
      'name' => t('Backgrounds'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
