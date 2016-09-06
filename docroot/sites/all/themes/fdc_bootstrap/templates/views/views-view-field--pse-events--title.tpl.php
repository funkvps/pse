<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
//dsm('row');
//dsm($row);
//dsm('field');
//dsm($field);

if (!empty($row->_entity_properties['entity object']->field_events_type['und'][0]['tid'])) {
  $tid = $row->_entity_properties['entity object']->field_events_type['und'][0]['tid'];
  $term = taxonomy_term_load($tid);
  $event_type = $term->name;
}
if (!empty($row->_entity_properties['entity object']->field_event_no_link['und'][0]['value'])) {
  $output = $event_type . ': ' . $output;
} elseif (!empty($row->_entity_properties['entity object']->field_event_external['und'][0]['safe_value'])) {
  $url = $row->_entity_properties['entity object']->field_event_external['und'][0]['safe_value'];
  $output = htmlspecialchars_decode($output);
  $output = htmlspecialchars_decode($output);
  $output = $event_type . ': <a href="' . $url . '" target="_blank">' . htmlspecialchars($output) . '</a>';
} elseif (!empty($row->_entity_properties['entity object']->nid)) {
  $output = htmlspecialchars_decode($output);
  $output = htmlspecialchars_decode($output);
  $output = $event_type . ': ' . l($output, 'node/' . $row->_entity_properties['entity object']->nid);
}
if (!empty($row->_entity_properties['entity object']->field_event_page_ref['und'][0]['target_id'])) {
  $page_ref = $row->_entity_properties['entity object']->field_event_page_ref['und'][0]['target_id'];
  $output = $event_type . ': ' . l($row->_entity_properties['entity object']->title, 'node/' . $page_ref);
}

//dsm('output');
//dsm(htmlspecialchars($output));
?>
<?php print $output; ?>
