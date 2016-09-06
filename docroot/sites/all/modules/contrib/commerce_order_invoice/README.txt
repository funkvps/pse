Provides invoicing features for Drupal Commerce using Orders. This differs from
Commerce Invoice (http://drupal.org/project/commerce_invoice) in that it uses
existing entity types rather than introducing a new "invoice" entity type; this
results in less complexity and less duplicated code.

This module introduces a new "Invoice" state for orders as well as an invoice
property for products and line items. Products can be configured to default to
an invoice product by product type. Line items will be considered to be part of
an invoice if their invoice property is set. By default, the invoice property on
line items will be the same as the product that they reference. However, the
line item can be updated to override the value on the product.

If the invoice property of a line item is set, the quantity field will be
disabled for users that do not have permission to administer invoices and the
delete/remove button will convert the order back to an invoice. The conversion
involves removing all non-invoice line items and setting the order's status to
"Invoice".

This project is sponsored by AllPlayers.com (http://www.allplayers.com).

Configuration
=============
After enabeling commerce_order_invoice, you can configure what product types
should default to being invoiced at /admin/commerce/products/types.
