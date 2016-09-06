<?php
/**
 * @file
 * pse__node_events_and_webinar.features.inc
 */

/**
 * Implements hook_node_info().
 */
function pse__node_events_and_webinar_node_info() {
  $items = array(
    'events_and_webinar' => array(
      'name' => t('Event or Webinar'),
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
