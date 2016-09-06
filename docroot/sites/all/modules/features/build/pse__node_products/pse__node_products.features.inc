<?php
/**
 * @file
 * pse__node_products.features.inc
 */

/**
 * Implements hook_node_info().
 */
function pse__node_products_node_info() {
  $items = array(
    'products' => array(
      'name' => t('Products'),
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
