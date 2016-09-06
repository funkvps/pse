<?php
/**
 * @file
 * pse__node_sector.features.inc
 */

/**
 * Implements hook_node_info().
 */
function pse__node_sector_node_info() {
  $items = array(
    'sector' => array(
      'name' => t('Sector'),
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
