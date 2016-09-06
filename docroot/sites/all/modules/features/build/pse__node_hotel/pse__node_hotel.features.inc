<?php
/**
 * @file
 * pse__node_hotel.features.inc
 */

/**
 * Implements hook_node_info().
 */
function pse__node_hotel_node_info() {
  $items = array(
    'hotel' => array(
      'name' => t('Hotel'),
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
