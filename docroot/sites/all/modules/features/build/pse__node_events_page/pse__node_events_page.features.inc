<?php
/**
 * @file
 * pse__node_events_page.features.inc
 */

/**
 * Implements hook_node_info().
 */
function pse__node_events_page_node_info() {
  $items = array(
    'events_page' => array(
      'name' => t('Events Page'),
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
