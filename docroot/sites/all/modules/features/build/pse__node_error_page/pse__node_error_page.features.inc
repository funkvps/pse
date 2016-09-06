<?php
/**
 * @file
 * pse__node_error_page.features.inc
 */

/**
 * Implements hook_node_info().
 */
function pse__node_error_page_node_info() {
  $items = array(
    'error_page' => array(
      'name' => t('Error Page'),
      'base' => 'node_content',
      'description' => t('A page set-up to handle various errors such as 403 and 404.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
