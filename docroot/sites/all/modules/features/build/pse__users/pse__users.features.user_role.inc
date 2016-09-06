<?php
/**
 * @file
 * pse__users.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function pse__users_user_default_roles() {
  $roles = array();

  // Exported role: PSE - Company pages - Author.
  $roles['PSE - Company pages - Author'] = array(
    'name' => 'PSE - Company pages - Author',
    'weight' => 11,
  );

  // Exported role: PSE - Company profile - Author.
  $roles['PSE - Company profile - Author'] = array(
    'name' => 'PSE - Company profile - Author',
    'weight' => 12,
  );

  // Exported role: PSE - Customer area download pages - Author.
  $roles['PSE - Customer area download pages - Author'] = array(
    'name' => 'PSE - Customer area download pages - Author',
    'weight' => 13,
  );

  // Exported role: PSE - Customer area forms - Author.
  $roles['PSE - Customer area forms - Author'] = array(
    'name' => 'PSE - Customer area forms - Author',
    'weight' => 14,
  );

  // Exported role: PSE - Customer area page - Author.
  $roles['PSE - Customer area page - Author'] = array(
    'name' => 'PSE - Customer area page - Author',
    'weight' => 15,
  );

  // Exported role: PSE - Events Pages - Author.
  $roles['PSE - Events Pages - Author'] = array(
    'name' => 'PSE - Events Pages - Author',
    'weight' => 16,
  );

  // Exported role: PSE - Events or webinar pages - Author.
  $roles['PSE - Events or webinar pages - Author'] = array(
    'name' => 'PSE - Events or webinar pages - Author',
    'weight' => 17,
  );

  // Exported role: PSE - Hotel pages - Author.
  $roles['PSE - Hotel pages - Author'] = array(
    'name' => 'PSE - Hotel pages - Author',
    'weight' => 18,
  );

  // Exported role: PSE - News pages - Author.
  $roles['PSE - News pages - Author'] = array(
    'name' => 'PSE - News pages - Author',
    'weight' => 19,
  );

  // Exported role: PSE - Office pages - Author.
  $roles['PSE - Office pages - Author'] = array(
    'name' => 'PSE - Office pages - Author',
    'weight' => 20,
  );

  // Exported role: PSE - Pages - Author.
  $roles['PSE - Pages - Author'] = array(
    'name' => 'PSE - Pages - Author',
    'weight' => 23,
  );

  // Exported role: PSE - Presentation Page - Author.
  $roles['PSE - Presentation Page - Author'] = array(
    'name' => 'PSE - Presentation Page - Author',
    'weight' => 26,
  );

  // Exported role: PSE - Publications - Author.
  $roles['PSE - Publications - Author'] = array(
    'name' => 'PSE - Publications - Author',
    'weight' => 21,
  );

  // Exported role: PSE - Sector pages - Author.
  $roles['PSE - Sector pages - Author'] = array(
    'name' => 'PSE - Sector pages - Author',
    'weight' => 24,
  );

  // Exported role: PSE - Training course pages - Author.
  $roles['PSE - Training course pages - Author'] = array(
    'name' => 'PSE - Training course pages - Author',
    'weight' => 25,
  );

  // Exported role: PSE - Training products - Author.
  $roles['PSE - Training products - Author'] = array(
    'name' => 'PSE - Training products - Author',
    'weight' => 22,
  );

  // Exported role: PSE - Video presentation page - Author.
  $roles['PSE - Video presentation page - Author'] = array(
    'name' => 'PSE - Video presentation page - Author',
    'weight' => 27,
  );

  // Exported role: Site Maintainer.
  $roles['Site Maintainer'] = array(
    'name' => 'Site Maintainer',
    'weight' => 2,
  );

  // Exported role: Website visitor - Company admin.
  $roles['Website visitor - Company admin'] = array(
    'name' => 'Website visitor - Company admin',
    'weight' => 5,
  );

  // Exported role: Website visitor - Ecommerce customer.
  $roles['Website visitor - Ecommerce customer'] = array(
    'name' => 'Website visitor - Ecommerce customer',
    'weight' => 3,
  );

  // Exported role: Website visitor - Marketing material - View and download.
  $roles['Website visitor - Marketing material - View and download'] = array(
    'name' => 'Website visitor - Marketing material - View and download',
    'weight' => 4,
  );

  // Exported role: Website visitor - Presentations - View & Download.
  $roles['Website visitor - Presentations - View & Download'] = array(
    'name' => 'Website visitor - Presentations - View & Download',
    'weight' => 9,
  );

  // Exported role: Website visitor - Presentations - View Videos.
  $roles['Website visitor - Presentations - View Videos'] = array(
    'name' => 'Website visitor - Presentations - View Videos',
    'weight' => 10,
  );

  // Exported role: Website visitor - View customer area downloads.
  $roles['Website visitor - View customer area downloads'] = array(
    'name' => 'Website visitor - View customer area downloads',
    'weight' => 6,
  );

  // Exported role: Website visitor - View customer area forms.
  $roles['Website visitor - View customer area forms'] = array(
    'name' => 'Website visitor - View customer area forms',
    'weight' => 8,
  );

  // Exported role: Website visitor - View customer area pages.
  $roles['Website visitor - View customer area pages'] = array(
    'name' => 'Website visitor - View customer area pages',
    'weight' => 7,
  );

  return $roles;
}
