<?php
/**
 * @file
 * pse__node_publication.features.inc
 */

/**
 * Implements hook_node_info().
 */
function pse__node_publication_node_info() {
  $items = array(
    'publication' => array(
      'name' => t('Publication'),
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
