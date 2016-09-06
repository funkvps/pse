<?php
/**
 * @file
 * pse__node_sector_listing_page.features.inc
 */

/**
 * Implements hook_node_info().
 */
function pse__node_sector_listing_page_node_info() {
  $items = array(
    'sector_listing_page' => array(
      'name' => t('Sector Listing Page'),
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
