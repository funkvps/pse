<?php
/**
 * @file
 * pse__node_training_course.features.inc
 */

/**
 * Implements hook_node_info().
 */
function pse__node_training_course_node_info() {
  $items = array(
    'training_course' => array(
      'name' => t('Training Course'),
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
