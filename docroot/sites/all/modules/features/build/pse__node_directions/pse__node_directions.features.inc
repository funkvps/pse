<?php
/**
 * @file
 * pse__node_directions.features.inc
 */

/**
 * Implements hook_node_info().
 */
function pse__node_directions_node_info() {
  $items = array(
    'directions' => array(
      'name' => t('Directions'),
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
