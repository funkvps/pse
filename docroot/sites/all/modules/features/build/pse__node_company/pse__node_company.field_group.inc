<?php
/**
 * @file
 * pse__node_company.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function pse__node_company_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_company_associates|node|company|form';
  $field_group->group_name = 'group_company_associates';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'company';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Company Associates',
    'weight' => '3',
    'children' => array(
      0 => 'field_company_owner',
      1 => 'field_col_company_users',
      2 => 'field_company_type',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-company-associates field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_company_associates|node|company|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_company_information|node|company|form';
  $field_group->group_name = 'group_company_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'company';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Company Information',
    'weight' => '2',
    'children' => array(
      0 => 'field_company_logo',
      1 => 'field_company_name',
      2 => 'field_sage_id',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-company-information field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_company_information|node|company|form'] = $field_group;

  return $export;
}
