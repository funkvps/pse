<?php
/**
 * @file
 * pse__node_director_listing.features.inc
 */

/**
 * Implements hook_node_info().
 */
function pse__node_director_listing_node_info() {
  $items = array(
    'director_listing' => array(
      'name' => t('Directors'),
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
