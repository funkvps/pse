<?php
/**
 * @file
 * Alter handlers for commerce fields.
 */

/**
 * Implements function hook_views_data_alter().
 *
 * Set the handler for the line item delete field to our custom handler.
 */
function commerce_order_invoice_views_data_alter(&$data) {
  $data['commerce_line_item']['edit_delete']['field']['handler'] = 'commerce_order_invoice_line_item_handler_field_edit_delete';
}
