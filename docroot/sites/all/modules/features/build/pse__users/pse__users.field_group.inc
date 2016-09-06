<?php
/**
 * @file
 * pse__users.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function pse__users_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_company_details|user|user|form';
  $field_group->group_name = 'group_company_details';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Company Details',
    'weight' => '5',
    'children' => array(
      0 => 'field_profile_country',
      1 => 'field_profile_company',
      2 => 'field_profile_position',
      3 => 'field_profile_department',
      4 => 'field_profile_division',
      5 => 'field_profile_street',
      6 => 'field_profile_city',
      7 => 'field_profile_state',
      8 => 'field_profile_postcode',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-company-details field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_company_details|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_personal_details|user|user|form';
  $field_group->group_name = 'group_personal_details';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Personal Details',
    'weight' => '4',
    'children' => array(
      0 => 'field_profile_first_name',
      1 => 'field_profile_last_name',
      2 => 'field_permission',
      3 => 'field_profile_mobile',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-personal-details field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_personal_details|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_preferences|user|user|form';
  $field_group->group_name = 'group_preferences';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Preferences',
    'weight' => '6',
    'children' => array(
      0 => 'field_profile_sector_interest',
      1 => 'field_profile_mailing_list',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-preferences field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_preferences|user|user|form'] = $field_group;

  return $export;
}
