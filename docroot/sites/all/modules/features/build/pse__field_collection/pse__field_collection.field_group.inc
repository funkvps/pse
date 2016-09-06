<?php
/**
 * @file
 * pse__field_collection.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function pse__field_collection_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_video_1|field_collection_item|field_col_video_present|form';
  $field_group->group_name = 'group_video_1';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_col_video_present';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Video 1',
    'weight' => '1',
    'children' => array(
      0 => 'field_video_present_vid_url',
      1 => 'field_video_present_vid_title',
      2 => 'field_video_present_vid_speakers',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-video-1 field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_video_1|field_collection_item|field_col_video_present|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_video_2|field_collection_item|field_col_video_present|form';
  $field_group->group_name = 'group_video_2';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_col_video_present';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Video 2',
    'weight' => '2',
    'children' => array(
      0 => 'field_video_present_vid_url_2',
      1 => 'field_video_present_vid_title_2',
      2 => 'field_video_present_vid_speaker2',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-video-2 field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_video_2|field_collection_item|field_col_video_present|form'] = $field_group;

  return $export;
}
