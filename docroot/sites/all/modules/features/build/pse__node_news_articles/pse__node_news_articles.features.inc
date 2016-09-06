<?php
/**
 * @file
 * pse__node_news_articles.features.inc
 */

/**
 * Implements hook_node_info().
 */
function pse__node_news_articles_node_info() {
  $items = array(
    'news_articles' => array(
      'name' => t('News articles'),
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
