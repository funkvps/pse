<?php
/**
 * @file
 * pse__panels.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function pse__panels_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'contentment_dashboard';
  $page->task = 'page';
  $page->admin_title = 'Contentment: Dashboard';
  $page->admin_description = 'Creates and arranges the main Contentment dashboard.';
  $page->path = 'contentment/dashboard';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access contentment dashboard',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'default tab',
    'title' => 'Dashboard',
    'name' => 'navigation',
    'weight' => '-5',
    'parent' => array(
      'type' => 'normal',
      'title' => 'Dashboard',
      'name' => 'management',
      'weight' => '-99',
    ),
  );
  $page->arguments = array();
  $page->conf = array();
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_contentment_dashboard_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'contentment_dashboard';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Default',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'contentment-dashboard',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Dashboard';
  $display->uuid = '13ca8f61-86bf-4817-aa85-0d1d704e6ba3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5bfda1b7-ac50-47cd-b80c-e5e7095de124';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'contentment_dashboard-activity';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5bfda1b7-ac50-47cd-b80c-e5e7095de124';
    $display->content['new-5bfda1b7-ac50-47cd-b80c-e5e7095de124'] = $pane;
    $display->panels['left'][0] = 'new-5bfda1b7-ac50-47cd-b80c-e5e7095de124';
    $pane = new stdClass();
    $pane->pid = 'new-262c78d9-28e9-4b1f-9ed9-0b7d8be13537';
    $pane->panel = 'right';
    $pane->type = 'contentment_links';
    $pane->subtype = 'contentment_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '262c78d9-28e9-4b1f-9ed9-0b7d8be13537';
    $display->content['new-262c78d9-28e9-4b1f-9ed9-0b7d8be13537'] = $pane;
    $display->panels['right'][0] = 'new-262c78d9-28e9-4b1f-9ed9-0b7d8be13537';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['contentment_dashboard'] = $page;

  return $pages;

}
