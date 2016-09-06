<?php
/**
 * @file
 * Provides entity propperties used by invoices.
 */

/**
 * Implements hook_entity_property_info_alter().
 */
function commerce_order_invoice_entity_property_info_alter(&$info) {
  $info['commerce_product']['properties']['invoice'] = array(
    'label' => t('Invoice'),
    'description' => t('Defines whether or not the product should be part of an invoice.'),
    'type' => 'boolean',
    'schema field' => 'invoice',
  );

  $info['commerce_line_item']['properties']['invoice'] = array(
    'label' => t('Invoice'),
    'description' => t('Defines the line item as being part of an invoice.'),
    'type' => 'boolean',
    'schema field' => 'invoice',
  );
}
