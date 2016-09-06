<?php
/**
 * @file
 * pse__node_office.features.inc
 */

/**
 * Implements hook_node_info().
 */
function pse__node_office_node_info() {
  $items = array(
    'office' => array(
      'name' => t('Office'),
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
