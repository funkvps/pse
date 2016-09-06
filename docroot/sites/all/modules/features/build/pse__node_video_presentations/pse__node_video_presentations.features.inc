<?php
/**
 * @file
 * pse__node_video_presentations.features.inc
 */

/**
 * Implements hook_node_info().
 */
function pse__node_video_presentations_node_info() {
  $items = array(
    'video_presentations' => array(
      'name' => t('Video Presentations'),
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
