<?php
/**
 * @file
 * pse__node_world_wide_contact.features.inc
 */

/**
 * Implements hook_node_info().
 */
function pse__node_world_wide_contact_node_info() {
  $items = array(
    'world_wide_contact' => array(
      'name' => t('World Wide Contact'),
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
