<?php
/**
 * @file
 * pse__node_footer_blocks.features.inc
 */

/**
 * Implements hook_node_info().
 */
function pse__node_footer_blocks_node_info() {
  $items = array(
    'footer_blocks' => array(
      'name' => t('Footer Blocks'),
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
