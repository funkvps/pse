<?php
/**
 * @file
 * pse__taxonomy.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function pse__taxonomy_taxonomy_default_vocabularies() {
  return array(
    'destination' => array(
      'name' => 'Destination',
      'machine_name' => 'destination',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'event_category' => array(
      'name' => 'Event Category',
      'machine_name' => 'event_category',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'event_type' => array(
      'name' => 'Event Type',
      'machine_name' => 'event_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'events_location' => array(
      'name' => 'Events Location',
      'machine_name' => 'events_location',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'file_categories' => array(
      'name' => 'File Categories',
      'machine_name' => 'file_categories',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'involvement' => array(
      'name' => 'Involvement',
      'machine_name' => 'involvement',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'news_categories' => array(
      'name' => 'News Categories',
      'machine_name' => 'news_categories',
      'description' => 'A selection of categories used for News Articles',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'office_type' => array(
      'name' => 'Office type',
      'machine_name' => 'office_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'profile_countries' => array(
      'name' => 'Profile Countries',
      'machine_name' => 'profile_countries',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'role' => array(
      'name' => 'Role',
      'machine_name' => 'role',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'search_tags' => array(
      'name' => 'search tags',
      'machine_name' => 'search_tags',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'sector_tags' => array(
      'name' => 'Related Tags',
      'machine_name' => 'sector_tags',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'training_countries' => array(
      'name' => 'Training Countries',
      'machine_name' => 'training_countries',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
