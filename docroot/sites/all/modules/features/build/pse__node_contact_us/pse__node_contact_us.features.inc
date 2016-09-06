<?php
/**
 * @file
 * pse__node_contact_us.features.inc
 */

/**
 * Implements hook_node_info().
 */
function pse__node_contact_us_node_info() {
  $items = array(
    'contact_us' => array(
      'name' => t('Form'),
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
