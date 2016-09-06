<?php
/**
 * @file
 * Commerce hook implementations for the Commerce Order Invoice module.
 */

/**
 * Implements hook_commerce_order_state_info().
 */
function commerce_order_invoice_commerce_order_state_info() {
  return array(
    'invoice' => array(
      'name' => 'invoice',
      'title' => t('Invoice'),
      'description' => t('Orders in this state can not be deleted and can only have optional, non-invoice line items removed.'),
      'weight' => 0,
      'default_status' => 'invoice',
    ),
  );
}

/**
 * Implements hook_commerce_order_status_info().
 */
function commerce_order_invoice_commerce_order_status_info() {
  return array(
    'invoice' => array(
      'name' => 'invoice',
      'title' => t('Invoice'),
      'state' => 'invoice',
    ),
  );
}

/**
 * Implements hook_commerce_entity_create_alter().
 */
function commerce_order_invoice_commerce_entity_create_alter($entity_type, $entity) {
  // If the entity is a commerce product and the inovice property has not
  // already been set then we should set it to the product type's default.
  if ('commerce_product' == $entity_type && !isset($entity->invoice)) {
    $product_type = commerce_product_type_load($entity->type);
    $entity->invoice = $product_type['invoice'];
  }
}

/**
 * Implements hook_commerce_order_presave().
 *
 * Set due_date value if needed.
 */
function commerce_order_invoice_commerce_order_presave($order) {
  // Check to see if 'commerce_order_invoice_due_date' is on the
  // 'commerce_order' bundle.
  $due_date_instance = field_info_instance('commerce_order', 'commerce_order_invoice_due_date', 'commerce_order');
  if (is_array($due_date_instance)) {
    $order_has_invoice_items = commerce_order_invoice_order_has_invoice_items($order);
    // If the order has invoice line items and no due date is already set on
    // the order, set the due date.
    if ($order_has_invoice_items && empty($order->commerce_order_invoice_due_date)) {
      if (!empty($order->original->commerce_order_invoice_due_date)) {
        $order->commerce_order_invoice_due_date = $order->original->commerce_order_invoice_due_date;
      }
      else {
        $default_timestamp = mktime(0, 0, 0);
        $order_wrapper = entity_metadata_wrapper($type = 'commerce_order', $entity = $order);
        $order_wrapper->commerce_order_invoice_due_date->set($default_timestamp);
      }
    }
  }
}

/**
 * Implements hook_commerce_line_item_delete().
 *
 * Deletes an invoice if all line items have been removed.
 *
 * @todo Make invoices a seperate bundle and move to hook_commerce_order_update().
 */
function commerce_order_invoice_commerce_line_item_delete($line_item) {
  // If the line item's order is an invoice and no line items remain on the
  // order then delete it. We need to check $line_item->invoice in case there
  // are no remaining line items and the order is not currently in the invoice
  // state.
  $order = commerce_order_load($line_item->order_id);
  if ((commerce_order_invoice_is_invoice($order) || $line_item->invoice) && empty($order->commerce_line_items)) {
    commerce_order_delete($line_item->order_id);
  }
}
