<?php
/**
 * @file
 * pse__node_training_listings.features.inc
 */

/**
 * Implements hook_node_info().
 */
function pse__node_training_listings_node_info() {
  $items = array(
    'training_listings' => array(
      'name' => t('Training Lisitings'),
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
