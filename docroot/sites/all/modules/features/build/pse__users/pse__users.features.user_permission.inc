<?php
/**
 * @file
 * pse__users.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function pse__users_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(),
    'module' => 'views',
  );

  // Exported permission: 'access all webform results'.
  $permissions['access all webform results'] = array(
    'name' => 'access all webform results',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access checkout'.
  $permissions['access checkout'] = array(
    'name' => 'access checkout',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'commerce_checkout',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'PSE - Events Pages - Author' => 'PSE - Events Pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access contentment dashboard'.
  $permissions['access contentment dashboard'] = array(
    'name' => 'access contentment dashboard',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'contentment',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'access devel information'.
  $permissions['access devel information'] = array(
    'name' => 'access devel information',
    'roles' => array(),
    'module' => 'devel',
  );

  // Exported permission: 'access media browser'.
  $permissions['access media browser'] = array(
    'name' => 'access media browser',
    'roles' => array(),
    'module' => 'media',
  );

  // Exported permission: 'access own webform results'.
  $permissions['access own webform results'] = array(
    'name' => 'access own webform results',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access own webform submissions'.
  $permissions['access own webform submissions'] = array(
    'name' => 'access own webform submissions',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access private fields'.
  $permissions['access private fields'] = array(
    'name' => 'access private fields',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'access rules debug'.
  $permissions['access rules debug'] = array(
    'name' => 'access rules debug',
    'roles' => array(),
    'module' => 'rules',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'user',
  );

  // Exported permission: 'add invoices'.
  $permissions['add invoices'] = array(
    'name' => 'add invoices',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_invoices',
  );

  // Exported permission: 'add media from remote sources'.
  $permissions['add media from remote sources'] = array(
    'name' => 'add media from remote sources',
    'roles' => array(),
    'module' => 'media_internet',
  );

  // Exported permission: 'administer CAPTCHA settings'.
  $permissions['administer CAPTCHA settings'] = array(
    'name' => 'administer CAPTCHA settings',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'captcha',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer advanced pane settings'.
  $permissions['administer advanced pane settings'] = array(
    'name' => 'administer advanced pane settings',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer autoassignrole'.
  $permissions['administer autoassignrole'] = array(
    'name' => 'administer autoassignrole',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'autoassignrole',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(),
    'module' => 'block',
  );

  // Exported permission: 'administer checkout'.
  $permissions['administer checkout'] = array(
    'name' => 'administer checkout',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_checkout',
  );

  // Exported permission: 'administer commerce discounts'.
  $permissions['administer commerce discounts'] = array(
    'name' => 'administer commerce discounts',
    'roles' => array(),
    'module' => 'commerce_discount',
  );

  // Exported permission: 'administer commerce product invoicing'.
  $permissions['administer commerce product invoicing'] = array(
    'name' => 'administer commerce product invoicing',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_order_invoice',
  );

  // Exported permission: 'administer commerce_coupon entities'.
  $permissions['administer commerce_coupon entities'] = array(
    'name' => 'administer commerce_coupon entities',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_coupon',
  );

  // Exported permission: 'administer commerce_customer_profile entities'.
  $permissions['administer commerce_customer_profile entities'] = array(
    'name' => 'administer commerce_customer_profile entities',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
      'Website visitor - Company admin' => 'Website visitor - Company admin',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'administer commerce_order entities'.
  $permissions['administer commerce_order entities'] = array(
    'name' => 'administer commerce_order entities',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'administer commerce_product entities'.
  $permissions['administer commerce_product entities'] = array(
    'name' => 'administer commerce_product entities',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer coupon settings'.
  $permissions['administer coupon settings'] = array(
    'name' => 'administer coupon settings',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_coupon',
  );

  // Exported permission: 'administer coupon types'.
  $permissions['administer coupon types'] = array(
    'name' => 'administer coupon types',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_coupon',
  );

  // Exported permission: 'administer customer profile types'.
  $permissions['administer customer profile types'] = array(
    'name' => 'administer customer profile types',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
      'Website visitor - Company admin' => 'Website visitor - Company admin',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'administer fdc_newsletter module'.
  $permissions['administer fdc_newsletter module'] = array(
    'name' => 'administer fdc_newsletter module',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'fdc_newsletter',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'features',
  );

  // Exported permission: 'administer field collections'.
  $permissions['administer field collections'] = array(
    'name' => 'administer field collections',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'field_collection',
  );

  // Exported permission: 'administer field permissions'.
  $permissions['administer field permissions'] = array(
    'name' => 'administer field permissions',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'administer fieldgroups'.
  $permissions['administer fieldgroups'] = array(
    'name' => 'administer fieldgroups',
    'roles' => array(),
    'module' => 'field_group',
  );

  // Exported permission: 'administer file types'.
  $permissions['administer file types'] = array(
    'name' => 'administer file types',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer files'.
  $permissions['administer files'] = array(
    'name' => 'administer files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'administer google analytics'.
  $permissions['administer google analytics'] = array(
    'name' => 'administer google analytics',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'googleanalytics',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(),
    'module' => 'image',
  );

  // Exported permission: 'administer imce'.
  $permissions['administer imce'] = array(
    'name' => 'administer imce',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'imce',
  );

  // Exported permission: 'administer line item types'.
  $permissions['administer line item types'] = array(
    'name' => 'administer line item types',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_line_item',
  );

  // Exported permission: 'administer line items'.
  $permissions['administer line items'] = array(
    'name' => 'administer line items',
    'roles' => array(),
    'module' => 'commerce_line_item',
  );

  // Exported permission: 'administer mailsystem'.
  $permissions['administer mailsystem'] = array(
    'name' => 'administer mailsystem',
    'roles' => array(),
    'module' => 'mailsystem',
  );

  // Exported permission: 'administer media browser'.
  $permissions['administer media browser'] = array(
    'name' => 'administer media browser',
    'roles' => array(),
    'module' => 'media',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer module filter'.
  $permissions['administer module filter'] = array(
    'name' => 'administer module filter',
    'roles' => array(),
    'module' => 'module_filter',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer page manager'.
  $permissions['administer page manager'] = array(
    'name' => 'administer page manager',
    'roles' => array(),
    'module' => 'page_manager',
  );

  // Exported permission: 'administer pane access'.
  $permissions['administer pane access'] = array(
    'name' => 'administer pane access',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels layouts'.
  $permissions['administer panels layouts'] = array(
    'name' => 'administer panels layouts',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels styles'.
  $permissions['administer panels styles'] = array(
    'name' => 'administer panels styles',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer pathauto'.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'administer payment methods'.
  $permissions['administer payment methods'] = array(
    'name' => 'administer payment methods',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_payment',
  );

  // Exported permission: 'administer payments'.
  $permissions['administer payments'] = array(
    'name' => 'administer payments',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_payment',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer product pricing'.
  $permissions['administer product pricing'] = array(
    'name' => 'administer product pricing',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_product_pricing_ui',
  );

  // Exported permission: 'administer product types'.
  $permissions['administer product types'] = array(
    'name' => 'administer product types',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'administer rules'.
  $permissions['administer rules'] = array(
    'name' => 'administer rules',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer smtp module'.
  $permissions['administer smtp module'] = array(
    'name' => 'administer smtp module',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'smtp',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer taxes'.
  $permissions['administer taxes'] = array(
    'name' => 'administer taxes',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_tax_ui',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'path',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(),
    'module' => 'views',
  );

  // Exported permission: 'adminster commerce order invoices'.
  $permissions['adminster commerce order invoices'] = array(
    'name' => 'adminster commerce order invoices',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_order_invoice',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'system',
  );

  // Exported permission: 'bypass file access'.
  $permissions['bypass file access'] = array(
    'name' => 'bypass file access',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'bypass rules access'.
  $permissions['bypass rules access'] = array(
    'name' => 'bypass rules access',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'user',
  );

  // Exported permission: 'change layouts in place editing'.
  $permissions['change layouts in place editing'] = array(
    'name' => 'change layouts in place editing',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'user',
  );

  // Exported permission: 'choose htmlmail_plaintext'.
  $permissions['choose htmlmail_plaintext'] = array(
    'name' => 'choose htmlmail_plaintext',
    'roles' => array(),
    'module' => 'htmlmail',
  );

  // Exported permission: 'configure order settings'.
  $permissions['configure order settings'] = array(
    'name' => 'configure order settings',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'configure store'.
  $permissions['configure store'] = array(
    'name' => 'configure store',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce',
  );

  // Exported permission: 'create backgrounds content'.
  $permissions['create backgrounds content'] = array(
    'name' => 'create backgrounds content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create commerce_coupon entities'.
  $permissions['create commerce_coupon entities'] = array(
    'name' => 'create commerce_coupon entities',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_coupon',
  );

  // Exported permission: 'create commerce_coupon entities of bundle commerce_coupon_fixed'.
  $permissions['create commerce_coupon entities of bundle commerce_coupon_fixed'] = array(
    'name' => 'create commerce_coupon entities of bundle commerce_coupon_fixed',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_coupon',
  );

  // Exported permission: 'create commerce_coupon entities of bundle commerce_coupon_pct'.
  $permissions['create commerce_coupon entities of bundle commerce_coupon_pct'] = array(
    'name' => 'create commerce_coupon entities of bundle commerce_coupon_pct',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_coupon',
  );

  // Exported permission: 'create commerce_customer_profile entities'.
  $permissions['create commerce_customer_profile entities'] = array(
    'name' => 'create commerce_customer_profile entities',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'create commerce_customer_profile entities of bundle billing'.
  $permissions['create commerce_customer_profile entities of bundle billing'] = array(
    'name' => 'create commerce_customer_profile entities of bundle billing',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
      'Website visitor - Company admin' => 'Website visitor - Company admin',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'create commerce_order entities'.
  $permissions['create commerce_order entities'] = array(
    'name' => 'create commerce_order entities',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'create commerce_order entities of bundle commerce_order'.
  $permissions['create commerce_order entities of bundle commerce_order'] = array(
    'name' => 'create commerce_order entities of bundle commerce_order',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'create commerce_product entities'.
  $permissions['create commerce_product entities'] = array(
    'name' => 'create commerce_product entities',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'create commerce_product entities of bundle invoice'.
  $permissions['create commerce_product entities of bundle invoice'] = array(
    'name' => 'create commerce_product entities of bundle invoice',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'create commerce_product entities of bundle product'.
  $permissions['create commerce_product entities of bundle product'] = array(
    'name' => 'create commerce_product entities of bundle product',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'create commerce_product entities of bundle training'.
  $permissions['create commerce_product entities of bundle training'] = array(
    'name' => 'create commerce_product entities of bundle training',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'create company content'.
  $permissions['create company content'] = array(
    'name' => 'create company content',
    'roles' => array(
      'PSE - Company pages - Author' => 'PSE - Company pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create contact_us content'.
  $permissions['create contact_us content'] = array(
    'name' => 'create contact_us content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create customer_area_download content'.
  $permissions['create customer_area_download content'] = array(
    'name' => 'create customer_area_download content',
    'roles' => array(
      'PSE - Customer area download pages - Author' => 'PSE - Customer area download pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create customer_area_forms content'.
  $permissions['create customer_area_forms content'] = array(
    'name' => 'create customer_area_forms content',
    'roles' => array(
      'PSE - Customer area forms - Author' => 'PSE - Customer area forms - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create customer_area_page content'.
  $permissions['create customer_area_page content'] = array(
    'name' => 'create customer_area_page content',
    'roles' => array(
      'PSE - Customer area page - Author' => 'PSE - Customer area page - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create directions content'.
  $permissions['create directions content'] = array(
    'name' => 'create directions content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create director_listing content'.
  $permissions['create director_listing content'] = array(
    'name' => 'create director_listing content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create download_signup_form content'.
  $permissions['create download_signup_form content'] = array(
    'name' => 'create download_signup_form content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create error_page content'.
  $permissions['create error_page content'] = array(
    'name' => 'create error_page content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create events_and_webinar content'.
  $permissions['create events_and_webinar content'] = array(
    'name' => 'create events_and_webinar content',
    'roles' => array(
      'PSE - Events or webinar pages - Author' => 'PSE - Events or webinar pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create events_page content'.
  $permissions['create events_page content'] = array(
    'name' => 'create events_page content',
    'roles' => array(
      'PSE - Events Pages - Author' => 'PSE - Events Pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create faq_page content'.
  $permissions['create faq_page content'] = array(
    'name' => 'create faq_page content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create field_col_company_users'.
  $permissions['create field_col_company_users'] = array(
    'name' => 'create field_col_company_users',
    'roles' => array(
      'PSE - Company pages - Author' => 'PSE - Company pages - Author',
      'PSE - Company profile - Author' => 'PSE - Company profile - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_company_owner'.
  $permissions['create field_company_owner'] = array(
    'name' => 'create field_company_owner',
    'roles' => array(
      'PSE - Company pages - Author' => 'PSE - Company pages - Author',
      'PSE - Company profile - Author' => 'PSE - Company profile - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_permission'.
  $permissions['create field_permission'] = array(
    'name' => 'create field_permission',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create files'.
  $permissions['create files'] = array(
    'name' => 'create files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'create footer_blocks content'.
  $permissions['create footer_blocks content'] = array(
    'name' => 'create footer_blocks content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create home content'.
  $permissions['create home content'] = array(
    'name' => 'create home content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create hotel content'.
  $permissions['create hotel content'] = array(
    'name' => 'create hotel content',
    'roles' => array(
      'PSE - Hotel pages - Author' => 'PSE - Hotel pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create hotel_location content'.
  $permissions['create hotel_location content'] = array(
    'name' => 'create hotel_location content',
    'roles' => array(
      'PSE - Hotel pages - Author' => 'PSE - Hotel pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create intranet_home_page content'.
  $permissions['create intranet_home_page content'] = array(
    'name' => 'create intranet_home_page content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create menu_block content'.
  $permissions['create menu_block content'] = array(
    'name' => 'create menu_block content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create news_articles content'.
  $permissions['create news_articles content'] = array(
    'name' => 'create news_articles content',
    'roles' => array(
      'PSE - News pages - Author' => 'PSE - News pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create office content'.
  $permissions['create office content'] = array(
    'name' => 'create office content',
    'roles' => array(
      'PSE - Office pages - Author' => 'PSE - Office pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create page content'.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      'PSE - Pages - Author' => 'PSE - Pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create payments'.
  $permissions['create payments'] = array(
    'name' => 'create payments',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_payment',
  );

  // Exported permission: 'create presentation content'.
  $permissions['create presentation content'] = array(
    'name' => 'create presentation content',
    'roles' => array(
      'PSE - Presentation Page - Author' => 'PSE - Presentation Page - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create products content'.
  $permissions['create products content'] = array(
    'name' => 'create products content',
    'roles' => array(
      'PSE - Training products - Author' => 'PSE - Training products - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create publication content'.
  $permissions['create publication content'] = array(
    'name' => 'create publication content',
    'roles' => array(
      'PSE - Publications - Author' => 'PSE - Publications - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create sector content'.
  $permissions['create sector content'] = array(
    'name' => 'create sector content',
    'roles' => array(
      'PSE - Sector pages - Author' => 'PSE - Sector pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create sector_listing_page content'.
  $permissions['create sector_listing_page content'] = array(
    'name' => 'create sector_listing_page content',
    'roles' => array(
      'PSE - Sector pages - Author' => 'PSE - Sector pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create settings content'.
  $permissions['create settings content'] = array(
    'name' => 'create settings content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create testimonial content'.
  $permissions['create testimonial content'] = array(
    'name' => 'create testimonial content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create training_course content'.
  $permissions['create training_course content'] = array(
    'name' => 'create training_course content',
    'roles' => array(
      'PSE - Training course pages - Author' => 'PSE - Training course pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create training_listings content'.
  $permissions['create training_listings content'] = array(
    'name' => 'create training_listings content',
    'roles' => array(
      'PSE - Training course pages - Author' => 'PSE - Training course pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'path',
  );

  // Exported permission: 'create video_presentations content'.
  $permissions['create video_presentations content'] = array(
    'name' => 'create video_presentations content',
    'roles' => array(
      'PSE - Video presentation page - Author' => 'PSE - Video presentation page - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create webform content'.
  $permissions['create webform content'] = array(
    'name' => 'create webform content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create world_wide_contact content'.
  $permissions['create world_wide_contact content'] = array(
    'name' => 'create world_wide_contact content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete all webform submissions'.
  $permissions['delete all webform submissions'] = array(
    'name' => 'delete all webform submissions',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete any audio files'.
  $permissions['delete any audio files'] = array(
    'name' => 'delete any audio files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any backgrounds content'.
  $permissions['delete any backgrounds content'] = array(
    'name' => 'delete any backgrounds content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any company content'.
  $permissions['delete any company content'] = array(
    'name' => 'delete any company content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any contact_us content'.
  $permissions['delete any contact_us content'] = array(
    'name' => 'delete any contact_us content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any customer_area_download content'.
  $permissions['delete any customer_area_download content'] = array(
    'name' => 'delete any customer_area_download content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any customer_area_forms content'.
  $permissions['delete any customer_area_forms content'] = array(
    'name' => 'delete any customer_area_forms content',
    'roles' => array(
      'PSE - Customer area forms - Author' => 'PSE - Customer area forms - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any customer_area_page content'.
  $permissions['delete any customer_area_page content'] = array(
    'name' => 'delete any customer_area_page content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any directions content'.
  $permissions['delete any directions content'] = array(
    'name' => 'delete any directions content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any director_listing content'.
  $permissions['delete any director_listing content'] = array(
    'name' => 'delete any director_listing content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any document files'.
  $permissions['delete any document files'] = array(
    'name' => 'delete any document files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any download_signup_form content'.
  $permissions['delete any download_signup_form content'] = array(
    'name' => 'delete any download_signup_form content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any error_page content'.
  $permissions['delete any error_page content'] = array(
    'name' => 'delete any error_page content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any events_and_webinar content'.
  $permissions['delete any events_and_webinar content'] = array(
    'name' => 'delete any events_and_webinar content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any events_page content'.
  $permissions['delete any events_page content'] = array(
    'name' => 'delete any events_page content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any faq_page content'.
  $permissions['delete any faq_page content'] = array(
    'name' => 'delete any faq_page content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any footer_blocks content'.
  $permissions['delete any footer_blocks content'] = array(
    'name' => 'delete any footer_blocks content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any home content'.
  $permissions['delete any home content'] = array(
    'name' => 'delete any home content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any hotel content'.
  $permissions['delete any hotel content'] = array(
    'name' => 'delete any hotel content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any hotel_location content'.
  $permissions['delete any hotel_location content'] = array(
    'name' => 'delete any hotel_location content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any image files'.
  $permissions['delete any image files'] = array(
    'name' => 'delete any image files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any intranet_home_page content'.
  $permissions['delete any intranet_home_page content'] = array(
    'name' => 'delete any intranet_home_page content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any menu_block content'.
  $permissions['delete any menu_block content'] = array(
    'name' => 'delete any menu_block content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any news_articles content'.
  $permissions['delete any news_articles content'] = array(
    'name' => 'delete any news_articles content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any office content'.
  $permissions['delete any office content'] = array(
    'name' => 'delete any office content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any page content'.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any presentation content'.
  $permissions['delete any presentation content'] = array(
    'name' => 'delete any presentation content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any products content'.
  $permissions['delete any products content'] = array(
    'name' => 'delete any products content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any publication content'.
  $permissions['delete any publication content'] = array(
    'name' => 'delete any publication content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any sector content'.
  $permissions['delete any sector content'] = array(
    'name' => 'delete any sector content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any sector_listing_page content'.
  $permissions['delete any sector_listing_page content'] = array(
    'name' => 'delete any sector_listing_page content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any settings content'.
  $permissions['delete any settings content'] = array(
    'name' => 'delete any settings content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any testimonial content'.
  $permissions['delete any testimonial content'] = array(
    'name' => 'delete any testimonial content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any training_course content'.
  $permissions['delete any training_course content'] = array(
    'name' => 'delete any training_course content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any training_listings content'.
  $permissions['delete any training_listings content'] = array(
    'name' => 'delete any training_listings content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any video files'.
  $permissions['delete any video files'] = array(
    'name' => 'delete any video files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any video_presentations content'.
  $permissions['delete any video_presentations content'] = array(
    'name' => 'delete any video_presentations content',
    'roles' => array(
      'PSE - Video presentation page - Author' => 'PSE - Video presentation page - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any webform content'.
  $permissions['delete any webform content'] = array(
    'name' => 'delete any webform content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any world_wide_contact content'.
  $permissions['delete any world_wide_contact content'] = array(
    'name' => 'delete any world_wide_contact content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own audio files'.
  $permissions['delete own audio files'] = array(
    'name' => 'delete own audio files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own backgrounds content'.
  $permissions['delete own backgrounds content'] = array(
    'name' => 'delete own backgrounds content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own company content'.
  $permissions['delete own company content'] = array(
    'name' => 'delete own company content',
    'roles' => array(
      'PSE - Company pages - Author' => 'PSE - Company pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own contact_us content'.
  $permissions['delete own contact_us content'] = array(
    'name' => 'delete own contact_us content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own customer_area_download content'.
  $permissions['delete own customer_area_download content'] = array(
    'name' => 'delete own customer_area_download content',
    'roles' => array(
      'PSE - Customer area download pages - Author' => 'PSE - Customer area download pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own customer_area_forms content'.
  $permissions['delete own customer_area_forms content'] = array(
    'name' => 'delete own customer_area_forms content',
    'roles' => array(
      'PSE - Customer area forms - Author' => 'PSE - Customer area forms - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own customer_area_page content'.
  $permissions['delete own customer_area_page content'] = array(
    'name' => 'delete own customer_area_page content',
    'roles' => array(
      'PSE - Customer area page - Author' => 'PSE - Customer area page - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own directions content'.
  $permissions['delete own directions content'] = array(
    'name' => 'delete own directions content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own director_listing content'.
  $permissions['delete own director_listing content'] = array(
    'name' => 'delete own director_listing content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own document files'.
  $permissions['delete own document files'] = array(
    'name' => 'delete own document files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own download_signup_form content'.
  $permissions['delete own download_signup_form content'] = array(
    'name' => 'delete own download_signup_form content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own error_page content'.
  $permissions['delete own error_page content'] = array(
    'name' => 'delete own error_page content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own events_and_webinar content'.
  $permissions['delete own events_and_webinar content'] = array(
    'name' => 'delete own events_and_webinar content',
    'roles' => array(
      'PSE - Events or webinar pages - Author' => 'PSE - Events or webinar pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own events_page content'.
  $permissions['delete own events_page content'] = array(
    'name' => 'delete own events_page content',
    'roles' => array(
      'PSE - Events Pages - Author' => 'PSE - Events Pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own faq_page content'.
  $permissions['delete own faq_page content'] = array(
    'name' => 'delete own faq_page content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own footer_blocks content'.
  $permissions['delete own footer_blocks content'] = array(
    'name' => 'delete own footer_blocks content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own home content'.
  $permissions['delete own home content'] = array(
    'name' => 'delete own home content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own hotel content'.
  $permissions['delete own hotel content'] = array(
    'name' => 'delete own hotel content',
    'roles' => array(
      'PSE - Hotel pages - Author' => 'PSE - Hotel pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own hotel_location content'.
  $permissions['delete own hotel_location content'] = array(
    'name' => 'delete own hotel_location content',
    'roles' => array(
      'PSE - Hotel pages - Author' => 'PSE - Hotel pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own image files'.
  $permissions['delete own image files'] = array(
    'name' => 'delete own image files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own intranet_home_page content'.
  $permissions['delete own intranet_home_page content'] = array(
    'name' => 'delete own intranet_home_page content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own menu_block content'.
  $permissions['delete own menu_block content'] = array(
    'name' => 'delete own menu_block content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own news_articles content'.
  $permissions['delete own news_articles content'] = array(
    'name' => 'delete own news_articles content',
    'roles' => array(
      'PSE - News pages - Author' => 'PSE - News pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own office content'.
  $permissions['delete own office content'] = array(
    'name' => 'delete own office content',
    'roles' => array(
      'PSE - Office pages - Author' => 'PSE - Office pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own page content'.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      'PSE - Pages - Author' => 'PSE - Pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own presentation content'.
  $permissions['delete own presentation content'] = array(
    'name' => 'delete own presentation content',
    'roles' => array(
      'PSE - Presentation Page - Author' => 'PSE - Presentation Page - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own products content'.
  $permissions['delete own products content'] = array(
    'name' => 'delete own products content',
    'roles' => array(
      'PSE - Training products - Author' => 'PSE - Training products - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own publication content'.
  $permissions['delete own publication content'] = array(
    'name' => 'delete own publication content',
    'roles' => array(
      'PSE - Publications - Author' => 'PSE - Publications - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own sector content'.
  $permissions['delete own sector content'] = array(
    'name' => 'delete own sector content',
    'roles' => array(
      'PSE - Sector pages - Author' => 'PSE - Sector pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own sector_listing_page content'.
  $permissions['delete own sector_listing_page content'] = array(
    'name' => 'delete own sector_listing_page content',
    'roles' => array(
      'PSE - Sector pages - Author' => 'PSE - Sector pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own settings content'.
  $permissions['delete own settings content'] = array(
    'name' => 'delete own settings content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own testimonial content'.
  $permissions['delete own testimonial content'] = array(
    'name' => 'delete own testimonial content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own training_course content'.
  $permissions['delete own training_course content'] = array(
    'name' => 'delete own training_course content',
    'roles' => array(
      'PSE - Training course pages - Author' => 'PSE - Training course pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own training_listings content'.
  $permissions['delete own training_listings content'] = array(
    'name' => 'delete own training_listings content',
    'roles' => array(
      'PSE - Training course pages - Author' => 'PSE - Training course pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own video files'.
  $permissions['delete own video files'] = array(
    'name' => 'delete own video files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own video_presentations content'.
  $permissions['delete own video_presentations content'] = array(
    'name' => 'delete own video_presentations content',
    'roles' => array(
      'PSE - Video presentation page - Author' => 'PSE - Video presentation page - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own webform content'.
  $permissions['delete own webform content'] = array(
    'name' => 'delete own webform content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own webform submissions'.
  $permissions['delete own webform submissions'] = array(
    'name' => 'delete own webform submissions',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete own world_wide_contact content'.
  $permissions['delete own world_wide_contact content'] = array(
    'name' => 'delete own world_wide_contact content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete payments'.
  $permissions['delete payments'] = array(
    'name' => 'delete payments',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_payment',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in destination'.
  $permissions['delete terms in destination'] = array(
    'name' => 'delete terms in destination',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in event_category'.
  $permissions['delete terms in event_category'] = array(
    'name' => 'delete terms in event_category',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in event_type'.
  $permissions['delete terms in event_type'] = array(
    'name' => 'delete terms in event_type',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in events_location'.
  $permissions['delete terms in events_location'] = array(
    'name' => 'delete terms in events_location',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in file_categories'.
  $permissions['delete terms in file_categories'] = array(
    'name' => 'delete terms in file_categories',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in involvement'.
  $permissions['delete terms in involvement'] = array(
    'name' => 'delete terms in involvement',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in news_categories'.
  $permissions['delete terms in news_categories'] = array(
    'name' => 'delete terms in news_categories',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in office_type'.
  $permissions['delete terms in office_type'] = array(
    'name' => 'delete terms in office_type',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in profile_countries'.
  $permissions['delete terms in profile_countries'] = array(
    'name' => 'delete terms in profile_countries',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in role'.
  $permissions['delete terms in role'] = array(
    'name' => 'delete terms in role',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in search_tags'.
  $permissions['delete terms in search_tags'] = array(
    'name' => 'delete terms in search_tags',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in sector_tags'.
  $permissions['delete terms in sector_tags'] = array(
    'name' => 'delete terms in sector_tags',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in training_countries'.
  $permissions['delete terms in training_countries'] = array(
    'name' => 'delete terms in training_countries',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'display drupal links'.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'download any audio files'.
  $permissions['download any audio files'] = array(
    'name' => 'download any audio files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any document files'.
  $permissions['download any document files'] = array(
    'name' => 'download any document files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any image files'.
  $permissions['download any image files'] = array(
    'name' => 'download any image files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any video files'.
  $permissions['download any video files'] = array(
    'name' => 'download any video files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own audio files'.
  $permissions['download own audio files'] = array(
    'name' => 'download own audio files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own document files'.
  $permissions['download own document files'] = array(
    'name' => 'download own document files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own image files'.
  $permissions['download own image files'] = array(
    'name' => 'download own image files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own video files'.
  $permissions['download own video files'] = array(
    'name' => 'download own video files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit all webform submissions'.
  $permissions['edit all webform submissions'] = array(
    'name' => 'edit all webform submissions',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit any audio files'.
  $permissions['edit any audio files'] = array(
    'name' => 'edit any audio files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any backgrounds content'.
  $permissions['edit any backgrounds content'] = array(
    'name' => 'edit any backgrounds content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any commerce_coupon entity'.
  $permissions['edit any commerce_coupon entity'] = array(
    'name' => 'edit any commerce_coupon entity',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_coupon',
  );

  // Exported permission: 'edit any commerce_coupon entity of bundle commerce_coupon_fixed'.
  $permissions['edit any commerce_coupon entity of bundle commerce_coupon_fixed'] = array(
    'name' => 'edit any commerce_coupon entity of bundle commerce_coupon_fixed',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_coupon',
  );

  // Exported permission: 'edit any commerce_coupon entity of bundle commerce_coupon_pct'.
  $permissions['edit any commerce_coupon entity of bundle commerce_coupon_pct'] = array(
    'name' => 'edit any commerce_coupon entity of bundle commerce_coupon_pct',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_coupon',
  );

  // Exported permission: 'edit any commerce_customer_profile entity'.
  $permissions['edit any commerce_customer_profile entity'] = array(
    'name' => 'edit any commerce_customer_profile entity',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'edit any commerce_customer_profile entity of bundle billing'.
  $permissions['edit any commerce_customer_profile entity of bundle billing'] = array(
    'name' => 'edit any commerce_customer_profile entity of bundle billing',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'edit any commerce_order entity'.
  $permissions['edit any commerce_order entity'] = array(
    'name' => 'edit any commerce_order entity',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'edit any commerce_order entity of bundle commerce_order'.
  $permissions['edit any commerce_order entity of bundle commerce_order'] = array(
    'name' => 'edit any commerce_order entity of bundle commerce_order',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'edit any commerce_product entity'.
  $permissions['edit any commerce_product entity'] = array(
    'name' => 'edit any commerce_product entity',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit any commerce_product entity of bundle invoice'.
  $permissions['edit any commerce_product entity of bundle invoice'] = array(
    'name' => 'edit any commerce_product entity of bundle invoice',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit any commerce_product entity of bundle product'.
  $permissions['edit any commerce_product entity of bundle product'] = array(
    'name' => 'edit any commerce_product entity of bundle product',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit any commerce_product entity of bundle training'.
  $permissions['edit any commerce_product entity of bundle training'] = array(
    'name' => 'edit any commerce_product entity of bundle training',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit any company content'.
  $permissions['edit any company content'] = array(
    'name' => 'edit any company content',
    'roles' => array(
      'PSE - Company pages - Author' => 'PSE - Company pages - Author',
      'Site Maintainer' => 'Site Maintainer',
      'Website visitor - Company admin' => 'Website visitor - Company admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any contact_us content'.
  $permissions['edit any contact_us content'] = array(
    'name' => 'edit any contact_us content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any customer_area_download content'.
  $permissions['edit any customer_area_download content'] = array(
    'name' => 'edit any customer_area_download content',
    'roles' => array(
      'PSE - Customer area download pages - Author' => 'PSE - Customer area download pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any customer_area_forms content'.
  $permissions['edit any customer_area_forms content'] = array(
    'name' => 'edit any customer_area_forms content',
    'roles' => array(
      'PSE - Customer area forms - Author' => 'PSE - Customer area forms - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any customer_area_page content'.
  $permissions['edit any customer_area_page content'] = array(
    'name' => 'edit any customer_area_page content',
    'roles' => array(
      'PSE - Customer area page - Author' => 'PSE - Customer area page - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any directions content'.
  $permissions['edit any directions content'] = array(
    'name' => 'edit any directions content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any director_listing content'.
  $permissions['edit any director_listing content'] = array(
    'name' => 'edit any director_listing content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any document files'.
  $permissions['edit any document files'] = array(
    'name' => 'edit any document files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any download_signup_form content'.
  $permissions['edit any download_signup_form content'] = array(
    'name' => 'edit any download_signup_form content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any error_page content'.
  $permissions['edit any error_page content'] = array(
    'name' => 'edit any error_page content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any events_and_webinar content'.
  $permissions['edit any events_and_webinar content'] = array(
    'name' => 'edit any events_and_webinar content',
    'roles' => array(
      'PSE - Events or webinar pages - Author' => 'PSE - Events or webinar pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any events_page content'.
  $permissions['edit any events_page content'] = array(
    'name' => 'edit any events_page content',
    'roles' => array(
      'PSE - Events Pages - Author' => 'PSE - Events Pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any faq_page content'.
  $permissions['edit any faq_page content'] = array(
    'name' => 'edit any faq_page content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any footer_blocks content'.
  $permissions['edit any footer_blocks content'] = array(
    'name' => 'edit any footer_blocks content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any home content'.
  $permissions['edit any home content'] = array(
    'name' => 'edit any home content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any hotel content'.
  $permissions['edit any hotel content'] = array(
    'name' => 'edit any hotel content',
    'roles' => array(
      'PSE - Hotel pages - Author' => 'PSE - Hotel pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any hotel_location content'.
  $permissions['edit any hotel_location content'] = array(
    'name' => 'edit any hotel_location content',
    'roles' => array(
      'PSE - Hotel pages - Author' => 'PSE - Hotel pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any image files'.
  $permissions['edit any image files'] = array(
    'name' => 'edit any image files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any intranet_home_page content'.
  $permissions['edit any intranet_home_page content'] = array(
    'name' => 'edit any intranet_home_page content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any menu_block content'.
  $permissions['edit any menu_block content'] = array(
    'name' => 'edit any menu_block content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any news_articles content'.
  $permissions['edit any news_articles content'] = array(
    'name' => 'edit any news_articles content',
    'roles' => array(
      'PSE - News pages - Author' => 'PSE - News pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any office content'.
  $permissions['edit any office content'] = array(
    'name' => 'edit any office content',
    'roles' => array(
      'PSE - Office pages - Author' => 'PSE - Office pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any page content'.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      'PSE - Pages - Author' => 'PSE - Pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any presentation content'.
  $permissions['edit any presentation content'] = array(
    'name' => 'edit any presentation content',
    'roles' => array(
      'PSE - Presentation Page - Author' => 'PSE - Presentation Page - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any products content'.
  $permissions['edit any products content'] = array(
    'name' => 'edit any products content',
    'roles' => array(
      'PSE - Training products - Author' => 'PSE - Training products - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any publication content'.
  $permissions['edit any publication content'] = array(
    'name' => 'edit any publication content',
    'roles' => array(
      'PSE - Publications - Author' => 'PSE - Publications - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any sector content'.
  $permissions['edit any sector content'] = array(
    'name' => 'edit any sector content',
    'roles' => array(
      'PSE - Sector pages - Author' => 'PSE - Sector pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any sector_listing_page content'.
  $permissions['edit any sector_listing_page content'] = array(
    'name' => 'edit any sector_listing_page content',
    'roles' => array(
      'PSE - Sector pages - Author' => 'PSE - Sector pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any settings content'.
  $permissions['edit any settings content'] = array(
    'name' => 'edit any settings content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any testimonial content'.
  $permissions['edit any testimonial content'] = array(
    'name' => 'edit any testimonial content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any training_course content'.
  $permissions['edit any training_course content'] = array(
    'name' => 'edit any training_course content',
    'roles' => array(
      'PSE - Training course pages - Author' => 'PSE - Training course pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any training_listings content'.
  $permissions['edit any training_listings content'] = array(
    'name' => 'edit any training_listings content',
    'roles' => array(
      'PSE - Training course pages - Author' => 'PSE - Training course pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any video files'.
  $permissions['edit any video files'] = array(
    'name' => 'edit any video files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any video_presentations content'.
  $permissions['edit any video_presentations content'] = array(
    'name' => 'edit any video_presentations content',
    'roles' => array(
      'PSE - Video presentation page - Author' => 'PSE - Video presentation page - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any webform content'.
  $permissions['edit any webform content'] = array(
    'name' => 'edit any webform content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any world_wide_contact content'.
  $permissions['edit any world_wide_contact content'] = array(
    'name' => 'edit any world_wide_contact content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit field_col_company_users'.
  $permissions['edit field_col_company_users'] = array(
    'name' => 'edit field_col_company_users',
    'roles' => array(
      'PSE - Company pages - Author' => 'PSE - Company pages - Author',
      'PSE - Company profile - Author' => 'PSE - Company profile - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_company_owner'.
  $permissions['edit field_company_owner'] = array(
    'name' => 'edit field_company_owner',
    'roles' => array(
      'PSE - Company pages - Author' => 'PSE - Company pages - Author',
      'PSE - Company profile - Author' => 'PSE - Company profile - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_permission'.
  $permissions['edit field_permission'] = array(
    'name' => 'edit field_permission',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own audio files'.
  $permissions['edit own audio files'] = array(
    'name' => 'edit own audio files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own backgrounds content'.
  $permissions['edit own backgrounds content'] = array(
    'name' => 'edit own backgrounds content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own commerce_coupon entities'.
  $permissions['edit own commerce_coupon entities'] = array(
    'name' => 'edit own commerce_coupon entities',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_coupon',
  );

  // Exported permission: 'edit own commerce_coupon entities of bundle commerce_coupon_fixed'.
  $permissions['edit own commerce_coupon entities of bundle commerce_coupon_fixed'] = array(
    'name' => 'edit own commerce_coupon entities of bundle commerce_coupon_fixed',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_coupon',
  );

  // Exported permission: 'edit own commerce_coupon entities of bundle commerce_coupon_pct'.
  $permissions['edit own commerce_coupon entities of bundle commerce_coupon_pct'] = array(
    'name' => 'edit own commerce_coupon entities of bundle commerce_coupon_pct',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_coupon',
  );

  // Exported permission: 'edit own commerce_customer_profile entities'.
  $permissions['edit own commerce_customer_profile entities'] = array(
    'name' => 'edit own commerce_customer_profile entities',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'edit own commerce_customer_profile entities of bundle billing'.
  $permissions['edit own commerce_customer_profile entities of bundle billing'] = array(
    'name' => 'edit own commerce_customer_profile entities of bundle billing',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
      'Website visitor - Company admin' => 'Website visitor - Company admin',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'edit own commerce_order entities'.
  $permissions['edit own commerce_order entities'] = array(
    'name' => 'edit own commerce_order entities',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'edit own commerce_order entities of bundle commerce_order'.
  $permissions['edit own commerce_order entities of bundle commerce_order'] = array(
    'name' => 'edit own commerce_order entities of bundle commerce_order',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'edit own commerce_product entities'.
  $permissions['edit own commerce_product entities'] = array(
    'name' => 'edit own commerce_product entities',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit own commerce_product entities of bundle invoice'.
  $permissions['edit own commerce_product entities of bundle invoice'] = array(
    'name' => 'edit own commerce_product entities of bundle invoice',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit own commerce_product entities of bundle product'.
  $permissions['edit own commerce_product entities of bundle product'] = array(
    'name' => 'edit own commerce_product entities of bundle product',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit own commerce_product entities of bundle training'.
  $permissions['edit own commerce_product entities of bundle training'] = array(
    'name' => 'edit own commerce_product entities of bundle training',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit own company content'.
  $permissions['edit own company content'] = array(
    'name' => 'edit own company content',
    'roles' => array(
      'PSE - Company pages - Author' => 'PSE - Company pages - Author',
      'PSE - Company profile - Author' => 'PSE - Company profile - Author',
      'Site Maintainer' => 'Site Maintainer',
      'Website visitor - Company admin' => 'Website visitor - Company admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own contact_us content'.
  $permissions['edit own contact_us content'] = array(
    'name' => 'edit own contact_us content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own customer_area_download content'.
  $permissions['edit own customer_area_download content'] = array(
    'name' => 'edit own customer_area_download content',
    'roles' => array(
      'PSE - Customer area download pages - Author' => 'PSE - Customer area download pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own customer_area_forms content'.
  $permissions['edit own customer_area_forms content'] = array(
    'name' => 'edit own customer_area_forms content',
    'roles' => array(
      'PSE - Customer area forms - Author' => 'PSE - Customer area forms - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own customer_area_page content'.
  $permissions['edit own customer_area_page content'] = array(
    'name' => 'edit own customer_area_page content',
    'roles' => array(
      'PSE - Customer area page - Author' => 'PSE - Customer area page - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own directions content'.
  $permissions['edit own directions content'] = array(
    'name' => 'edit own directions content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own director_listing content'.
  $permissions['edit own director_listing content'] = array(
    'name' => 'edit own director_listing content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own document files'.
  $permissions['edit own document files'] = array(
    'name' => 'edit own document files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own download_signup_form content'.
  $permissions['edit own download_signup_form content'] = array(
    'name' => 'edit own download_signup_form content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own error_page content'.
  $permissions['edit own error_page content'] = array(
    'name' => 'edit own error_page content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own events_and_webinar content'.
  $permissions['edit own events_and_webinar content'] = array(
    'name' => 'edit own events_and_webinar content',
    'roles' => array(
      'PSE - Events or webinar pages - Author' => 'PSE - Events or webinar pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own events_page content'.
  $permissions['edit own events_page content'] = array(
    'name' => 'edit own events_page content',
    'roles' => array(
      'PSE - Events Pages - Author' => 'PSE - Events Pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own faq_page content'.
  $permissions['edit own faq_page content'] = array(
    'name' => 'edit own faq_page content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own field_col_company_users'.
  $permissions['edit own field_col_company_users'] = array(
    'name' => 'edit own field_col_company_users',
    'roles' => array(
      'PSE - Company pages - Author' => 'PSE - Company pages - Author',
      'PSE - Company profile - Author' => 'PSE - Company profile - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_company_owner'.
  $permissions['edit own field_company_owner'] = array(
    'name' => 'edit own field_company_owner',
    'roles' => array(
      'PSE - Company pages - Author' => 'PSE - Company pages - Author',
      'PSE - Company profile - Author' => 'PSE - Company profile - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_permission'.
  $permissions['edit own field_permission'] = array(
    'name' => 'edit own field_permission',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own footer_blocks content'.
  $permissions['edit own footer_blocks content'] = array(
    'name' => 'edit own footer_blocks content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own home content'.
  $permissions['edit own home content'] = array(
    'name' => 'edit own home content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own hotel content'.
  $permissions['edit own hotel content'] = array(
    'name' => 'edit own hotel content',
    'roles' => array(
      'PSE - Hotel pages - Author' => 'PSE - Hotel pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own hotel_location content'.
  $permissions['edit own hotel_location content'] = array(
    'name' => 'edit own hotel_location content',
    'roles' => array(
      'PSE - Hotel pages - Author' => 'PSE - Hotel pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own image files'.
  $permissions['edit own image files'] = array(
    'name' => 'edit own image files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own intranet_home_page content'.
  $permissions['edit own intranet_home_page content'] = array(
    'name' => 'edit own intranet_home_page content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own menu_block content'.
  $permissions['edit own menu_block content'] = array(
    'name' => 'edit own menu_block content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own news_articles content'.
  $permissions['edit own news_articles content'] = array(
    'name' => 'edit own news_articles content',
    'roles' => array(
      'PSE - News pages - Author' => 'PSE - News pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own office content'.
  $permissions['edit own office content'] = array(
    'name' => 'edit own office content',
    'roles' => array(
      'PSE - Office pages - Author' => 'PSE - Office pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own page content'.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      'PSE - Pages - Author' => 'PSE - Pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own presentation content'.
  $permissions['edit own presentation content'] = array(
    'name' => 'edit own presentation content',
    'roles' => array(
      'PSE - Presentation Page - Author' => 'PSE - Presentation Page - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own products content'.
  $permissions['edit own products content'] = array(
    'name' => 'edit own products content',
    'roles' => array(
      'PSE - Training products - Author' => 'PSE - Training products - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own publication content'.
  $permissions['edit own publication content'] = array(
    'name' => 'edit own publication content',
    'roles' => array(
      'PSE - Publications - Author' => 'PSE - Publications - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own sector content'.
  $permissions['edit own sector content'] = array(
    'name' => 'edit own sector content',
    'roles' => array(
      'PSE - Sector pages - Author' => 'PSE - Sector pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own sector_listing_page content'.
  $permissions['edit own sector_listing_page content'] = array(
    'name' => 'edit own sector_listing_page content',
    'roles' => array(
      'PSE - Sector pages - Author' => 'PSE - Sector pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own settings content'.
  $permissions['edit own settings content'] = array(
    'name' => 'edit own settings content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own testimonial content'.
  $permissions['edit own testimonial content'] = array(
    'name' => 'edit own testimonial content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own training_course content'.
  $permissions['edit own training_course content'] = array(
    'name' => 'edit own training_course content',
    'roles' => array(
      'PSE - Training course pages - Author' => 'PSE - Training course pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own training_listings content'.
  $permissions['edit own training_listings content'] = array(
    'name' => 'edit own training_listings content',
    'roles' => array(
      'PSE - Training course pages - Author' => 'PSE - Training course pages - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own video files'.
  $permissions['edit own video files'] = array(
    'name' => 'edit own video files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own video_presentations content'.
  $permissions['edit own video_presentations content'] = array(
    'name' => 'edit own video_presentations content',
    'roles' => array(
      'PSE - Video presentation page - Author' => 'PSE - Video presentation page - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own webform content'.
  $permissions['edit own webform content'] = array(
    'name' => 'edit own webform content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own webform submissions'.
  $permissions['edit own webform submissions'] = array(
    'name' => 'edit own webform submissions',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit own world_wide_contact content'.
  $permissions['edit own world_wide_contact content'] = array(
    'name' => 'edit own world_wide_contact content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in destination'.
  $permissions['edit terms in destination'] = array(
    'name' => 'edit terms in destination',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in event_category'.
  $permissions['edit terms in event_category'] = array(
    'name' => 'edit terms in event_category',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in event_type'.
  $permissions['edit terms in event_type'] = array(
    'name' => 'edit terms in event_type',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in events_location'.
  $permissions['edit terms in events_location'] = array(
    'name' => 'edit terms in events_location',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in file_categories'.
  $permissions['edit terms in file_categories'] = array(
    'name' => 'edit terms in file_categories',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in involvement'.
  $permissions['edit terms in involvement'] = array(
    'name' => 'edit terms in involvement',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in news_categories'.
  $permissions['edit terms in news_categories'] = array(
    'name' => 'edit terms in news_categories',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in office_type'.
  $permissions['edit terms in office_type'] = array(
    'name' => 'edit terms in office_type',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in profile_countries'.
  $permissions['edit terms in profile_countries'] = array(
    'name' => 'edit terms in profile_countries',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in role'.
  $permissions['edit terms in role'] = array(
    'name' => 'edit terms in role',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in search_tags'.
  $permissions['edit terms in search_tags'] = array(
    'name' => 'edit terms in search_tags',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in sector_tags'.
  $permissions['edit terms in sector_tags'] = array(
    'name' => 'edit terms in sector_tags',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in training_countries'.
  $permissions['edit terms in training_countries'] = array(
    'name' => 'edit terms in training_countries',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit webform components'.
  $permissions['edit webform components'] = array(
    'name' => 'edit webform components',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'execute php code'.
  $permissions['execute php code'] = array(
    'name' => 'execute php code',
    'roles' => array(),
    'module' => 'devel',
  );

  // Exported permission: 'fdc utils'.
  $permissions['fdc utils'] = array(
    'name' => 'fdc utils',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'fdc_membership_utils',
  );

  // Exported permission: 'flush caches'.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'features',
  );

  // Exported permission: 'import users'.
  $permissions['import users'] = array(
    'name' => 'import users',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'user_import',
  );

  // Exported permission: 'limited user import'.
  $permissions['limited user import'] = array(
    'name' => 'limited user import',
    'roles' => array(),
    'module' => 'user_import',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'features',
  );

  // Exported permission: 'manage invoices'.
  $permissions['manage invoices'] = array(
    'name' => 'manage invoices',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_invoices',
  );

  // Exported permission: 'notify of path changes'.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(),
    'module' => 'pathauto',
  );

  // Exported permission: 'opt-in or out of tracking'.
  $permissions['opt-in or out of tracking'] = array(
    'name' => 'opt-in or out of tracking',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'googleanalytics',
  );

  // Exported permission: 'payment.global.administer'.
  $permissions['payment.global.administer'] = array(
    'name' => 'payment.global.administer',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'payment',
  );

  // Exported permission: 'payment.payment.administer'.
  $permissions['payment.payment.administer'] = array(
    'name' => 'payment.payment.administer',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'payment',
  );

  // Exported permission: 'payment.payment.delete.any'.
  $permissions['payment.payment.delete.any'] = array(
    'name' => 'payment.payment.delete.any',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'payment',
  );

  // Exported permission: 'payment.payment.delete.own'.
  $permissions['payment.payment.delete.own'] = array(
    'name' => 'payment.payment.delete.own',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'payment',
  );

  // Exported permission: 'payment.payment.update.any'.
  $permissions['payment.payment.update.any'] = array(
    'name' => 'payment.payment.update.any',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'payment',
  );

  // Exported permission: 'payment.payment.update.own'.
  $permissions['payment.payment.update.own'] = array(
    'name' => 'payment.payment.update.own',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'payment',
  );

  // Exported permission: 'payment.payment.view.any'.
  $permissions['payment.payment.view.any'] = array(
    'name' => 'payment.payment.view.any',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'payment',
  );

  // Exported permission: 'payment.payment.view.own'.
  $permissions['payment.payment.view.own'] = array(
    'name' => 'payment.payment.view.own',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'payment',
  );

  // Exported permission: 'payment.payment_method.create.PaymentMethodBasicController'.
  $permissions['payment.payment_method.create.PaymentMethodBasicController'] = array(
    'name' => 'payment.payment_method.create.PaymentMethodBasicController',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'payment',
  );

  // Exported permission: 'payment.payment_method.delete.any'.
  $permissions['payment.payment_method.delete.any'] = array(
    'name' => 'payment.payment_method.delete.any',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'payment',
  );

  // Exported permission: 'payment.payment_method.delete.own'.
  $permissions['payment.payment_method.delete.own'] = array(
    'name' => 'payment.payment_method.delete.own',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'payment',
  );

  // Exported permission: 'payment.payment_method.update.any'.
  $permissions['payment.payment_method.update.any'] = array(
    'name' => 'payment.payment_method.update.any',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'payment',
  );

  // Exported permission: 'payment.payment_method.update.own'.
  $permissions['payment.payment_method.update.own'] = array(
    'name' => 'payment.payment_method.update.own',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'payment',
  );

  // Exported permission: 'payment.payment_method.view.any'.
  $permissions['payment.payment_method.view.any'] = array(
    'name' => 'payment.payment_method.view.any',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'payment',
  );

  // Exported permission: 'payment.payment_method.view.own'.
  $permissions['payment.payment_method.view.own'] = array(
    'name' => 'payment.payment_method.view.own',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'payment',
  );

  // Exported permission: 'payment.payment_status.view'.
  $permissions['payment.payment_status.view'] = array(
    'name' => 'payment.payment_status.view',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'payment',
  );

  // Exported permission: 'payment.rules.administer'.
  $permissions['payment.rules.administer'] = array(
    'name' => 'payment.rules.administer',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'payment',
  );

  // Exported permission: 'payment_commerce.administer'.
  $permissions['payment_commerce.administer'] = array(
    'name' => 'payment_commerce.administer',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'payment_commerce',
  );

  // Exported permission: 'rename features'.
  $permissions['rename features'] = array(
    'name' => 'rename features',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'features',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'skip CAPTCHA'.
  $permissions['skip CAPTCHA'] = array(
    'name' => 'skip CAPTCHA',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
      'Website visitor - Company admin' => 'Website visitor - Company admin',
    ),
    'module' => 'captcha',
  );

  // Exported permission: 'switch users'.
  $permissions['switch users'] = array(
    'name' => 'switch users',
    'roles' => array(),
    'module' => 'devel',
  );

  // Exported permission: 'update payments'.
  $permissions['update payments'] = array(
    'name' => 'update payments',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_payment',
  );

  // Exported permission: 'use PHP for tracking visibility'.
  $permissions['use PHP for tracking visibility'] = array(
    'name' => 'use PHP for tracking visibility',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'googleanalytics',
  );

  // Exported permission: 'use ctools import'.
  $permissions['use ctools import'] = array(
    'name' => 'use ctools import',
    'roles' => array(),
    'module' => 'ctools',
  );

  // Exported permission: 'use ipe with page manager'.
  $permissions['use ipe with page manager'] = array(
    'name' => 'use ipe with page manager',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use page manager'.
  $permissions['use page manager'] = array(
    'name' => 'use page manager',
    'roles' => array(),
    'module' => 'page_manager',
  );

  // Exported permission: 'use panels caching features'.
  $permissions['use panels caching features'] = array(
    'name' => 'use panels caching features',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels dashboard'.
  $permissions['use panels dashboard'] = array(
    'name' => 'use panels dashboard',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels in place editing'.
  $permissions['use panels in place editing'] = array(
    'name' => 'use panels in place editing',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels locks'.
  $permissions['use panels locks'] = array(
    'name' => 'use panels locks',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use text format full_editor'.
  $permissions['use text format full_editor'] = array(
    'name' => 'use text format full_editor',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'view any commerce_coupon entity'.
  $permissions['view any commerce_coupon entity'] = array(
    'name' => 'view any commerce_coupon entity',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_coupon',
  );

  // Exported permission: 'view any commerce_coupon entity of bundle commerce_coupon_fixed'.
  $permissions['view any commerce_coupon entity of bundle commerce_coupon_fixed'] = array(
    'name' => 'view any commerce_coupon entity of bundle commerce_coupon_fixed',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_coupon',
  );

  // Exported permission: 'view any commerce_coupon entity of bundle commerce_coupon_pct'.
  $permissions['view any commerce_coupon entity of bundle commerce_coupon_pct'] = array(
    'name' => 'view any commerce_coupon entity of bundle commerce_coupon_pct',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_coupon',
  );

  // Exported permission: 'view any commerce_customer_profile entity'.
  $permissions['view any commerce_customer_profile entity'] = array(
    'name' => 'view any commerce_customer_profile entity',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'view any commerce_customer_profile entity of bundle billing'.
  $permissions['view any commerce_customer_profile entity of bundle billing'] = array(
    'name' => 'view any commerce_customer_profile entity of bundle billing',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'view any commerce_order entity'.
  $permissions['view any commerce_order entity'] = array(
    'name' => 'view any commerce_order entity',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'view any commerce_order entity of bundle commerce_order'.
  $permissions['view any commerce_order entity of bundle commerce_order'] = array(
    'name' => 'view any commerce_order entity of bundle commerce_order',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'view any commerce_product entity'.
  $permissions['view any commerce_product entity'] = array(
    'name' => 'view any commerce_product entity',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view any commerce_product entity of bundle invoice'.
  $permissions['view any commerce_product entity of bundle invoice'] = array(
    'name' => 'view any commerce_product entity of bundle invoice',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view any commerce_product entity of bundle product'.
  $permissions['view any commerce_product entity of bundle product'] = array(
    'name' => 'view any commerce_product entity of bundle product',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view any commerce_product entity of bundle training'.
  $permissions['view any commerce_product entity of bundle training'] = array(
    'name' => 'view any commerce_product entity of bundle training',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view field_col_company_users'.
  $permissions['view field_col_company_users'] = array(
    'name' => 'view field_col_company_users',
    'roles' => array(
      'PSE - Company pages - Author' => 'PSE - Company pages - Author',
      'PSE - Company profile - Author' => 'PSE - Company profile - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_company_owner'.
  $permissions['view field_company_owner'] = array(
    'name' => 'view field_company_owner',
    'roles' => array(
      'PSE - Company pages - Author' => 'PSE - Company pages - Author',
      'PSE - Company profile - Author' => 'PSE - Company profile - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_permission'.
  $permissions['view field_permission'] = array(
    'name' => 'view field_permission',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view files'.
  $permissions['view files'] = array(
    'name' => 'view files',
    'roles' => array(
      'PSE - Company pages - Author' => 'PSE - Company pages - Author',
      'PSE - Company profile - Author' => 'PSE - Company profile - Author',
      'PSE - Customer area page - Author' => 'PSE - Customer area page - Author',
      'PSE - Events Pages - Author' => 'PSE - Events Pages - Author',
      'PSE - Events or webinar pages - Author' => 'PSE - Events or webinar pages - Author',
      'PSE - Hotel pages - Author' => 'PSE - Hotel pages - Author',
      'PSE - News pages - Author' => 'PSE - News pages - Author',
      'PSE - Office pages - Author' => 'PSE - Office pages - Author',
      'PSE - Pages - Author' => 'PSE - Pages - Author',
      'PSE - Publications - Author' => 'PSE - Publications - Author',
      'PSE - Sector pages - Author' => 'PSE - Sector pages - Author',
      'PSE - Training course pages - Author' => 'PSE - Training course pages - Author',
      'PSE - Training products - Author' => 'PSE - Training products - Author',
      'Site Maintainer' => 'Site Maintainer',
      'Website visitor - Company admin' => 'Website visitor - Company admin',
      'Website visitor - Ecommerce customer' => 'Website visitor - Ecommerce customer',
      'Website visitor - Marketing material - View and download' => 'Website visitor - Marketing material - View and download',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own commerce_coupon entities'.
  $permissions['view own commerce_coupon entities'] = array(
    'name' => 'view own commerce_coupon entities',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_coupon',
  );

  // Exported permission: 'view own commerce_coupon entities of bundle commerce_coupon_fixed'.
  $permissions['view own commerce_coupon entities of bundle commerce_coupon_fixed'] = array(
    'name' => 'view own commerce_coupon entities of bundle commerce_coupon_fixed',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_coupon',
  );

  // Exported permission: 'view own commerce_coupon entities of bundle commerce_coupon_pct'.
  $permissions['view own commerce_coupon entities of bundle commerce_coupon_pct'] = array(
    'name' => 'view own commerce_coupon entities of bundle commerce_coupon_pct',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_coupon',
  );

  // Exported permission: 'view own commerce_customer_profile entities'.
  $permissions['view own commerce_customer_profile entities'] = array(
    'name' => 'view own commerce_customer_profile entities',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
      'Website visitor - Company admin' => 'Website visitor - Company admin',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'view own commerce_customer_profile entities of bundle billing'.
  $permissions['view own commerce_customer_profile entities of bundle billing'] = array(
    'name' => 'view own commerce_customer_profile entities of bundle billing',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
      'Website visitor - Company admin' => 'Website visitor - Company admin',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'view own commerce_order entities'.
  $permissions['view own commerce_order entities'] = array(
    'name' => 'view own commerce_order entities',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
      'Website visitor - Ecommerce customer' => 'Website visitor - Ecommerce customer',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'view own commerce_order entities of bundle commerce_order'.
  $permissions['view own commerce_order entities of bundle commerce_order'] = array(
    'name' => 'view own commerce_order entities of bundle commerce_order',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
      'Website visitor - Ecommerce customer' => 'Website visitor - Ecommerce customer',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'view own commerce_product entities'.
  $permissions['view own commerce_product entities'] = array(
    'name' => 'view own commerce_product entities',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view own commerce_product entities of bundle invoice'.
  $permissions['view own commerce_product entities of bundle invoice'] = array(
    'name' => 'view own commerce_product entities of bundle invoice',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view own commerce_product entities of bundle product'.
  $permissions['view own commerce_product entities of bundle product'] = array(
    'name' => 'view own commerce_product entities of bundle product',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view own commerce_product entities of bundle training'.
  $permissions['view own commerce_product entities of bundle training'] = array(
    'name' => 'view own commerce_product entities of bundle training',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view own field_col_company_users'.
  $permissions['view own field_col_company_users'] = array(
    'name' => 'view own field_col_company_users',
    'roles' => array(
      'PSE - Company pages - Author' => 'PSE - Company pages - Author',
      'PSE - Company profile - Author' => 'PSE - Company profile - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_company_owner'.
  $permissions['view own field_company_owner'] = array(
    'name' => 'view own field_company_owner',
    'roles' => array(
      'PSE - Company pages - Author' => 'PSE - Company pages - Author',
      'PSE - Company profile - Author' => 'PSE - Company profile - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_permission'.
  $permissions['view own field_permission'] = array(
    'name' => 'view own field_permission',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own files'.
  $permissions['view own files'] = array(
    'name' => 'view own files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own private files'.
  $permissions['view own private files'] = array(
    'name' => 'view own private files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view pane admin links'.
  $permissions['view pane admin links'] = array(
    'name' => 'view pane admin links',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'view payments'.
  $permissions['view payments'] = array(
    'name' => 'view payments',
    'roles' => array(
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'commerce_payment',
  );

  // Exported permission: 'view private files'.
  $permissions['view private files'] = array(
    'name' => 'view private files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'PSE - Company pages - Author' => 'PSE - Company pages - Author',
      'PSE - Events Pages - Author' => 'PSE - Events Pages - Author',
      'PSE - Events or webinar pages - Author' => 'PSE - Events or webinar pages - Author',
      'PSE - Hotel pages - Author' => 'PSE - Hotel pages - Author',
      'PSE - News pages - Author' => 'PSE - News pages - Author',
      'PSE - Office pages - Author' => 'PSE - Office pages - Author',
      'PSE - Pages - Author' => 'PSE - Pages - Author',
      'PSE - Publications - Author' => 'PSE - Publications - Author',
      'PSE - Sector pages - Author' => 'PSE - Sector pages - Author',
      'PSE - Training course pages - Author' => 'PSE - Training course pages - Author',
      'PSE - Training products - Author' => 'PSE - Training products - Author',
      'Site Maintainer' => 'Site Maintainer',
    ),
    'module' => 'system',
  );

  return $permissions;
}
