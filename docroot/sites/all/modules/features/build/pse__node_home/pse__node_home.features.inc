<?php
/**
 * @file
 * pse__node_home.features.inc
 */

/**
 * Implements hook_node_info().
 */
function pse__node_home_node_info() {
  $items = array(
    'home' => array(
      'name' => t('Home'),
      'base' => 'node_content',
      'description' => t('<b>Single Use</b>'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
