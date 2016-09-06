<?php
/**
 * @file
 * pse__node_menu_block.features.inc
 */

/**
 * Implements hook_node_info().
 */
function pse__node_menu_block_node_info() {
  $items = array(
    'menu_block' => array(
      'name' => t('Custom Menu Block'),
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
