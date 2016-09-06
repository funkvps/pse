<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * @see bootstrap_preprocess_page()
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see bootstrap_process_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup themeable
 */

?>
<div class="website_frame container">
	<div class="website_pad">
		
		<?php if (empty($node) || $node->type != 'intranet_home_page') :?>
		<?php include_once($directory . '/templates/header.php'); ?>
		<?php endif;?>

		<div class="main-container">

		  <header role="banner" id="page-header">
		    <?php if (!empty($site_slogan)): ?>
		      <p class="lead"><?php print $site_slogan; ?></p>
		    <?php endif; ?>

		    <?php print render($page['header']); ?>
		  </header> <!-- /#page-header -->
      
      <?php if (!empty($page['before_sidebars'])) { ?>
        <div class="row region-before-sidebars">
          <?php print render($page['before_sidebars']); ?>
        </div><!-- /.region-before-sidebars -->
      <?php } ?>
        
      <div class="row">
        
        <?php if (!empty($page['sidebar_first'])): ?>
          <aside class="col-sm-3" role="complementary">
            <?php print render($page['sidebar_first']); ?>
          </aside>  <!-- /#sidebar-first -->
        <?php endif; ?>

		    <section<?php print $content_column_class; ?>>
		      <?php if (!empty($page['highlighted'])): ?>
		        <div class="highlighted jumbotron"><?php print render($page['highlighted']); ?></div>
		      <?php endif; ?>

          <?php 
          if (function_exists('fdc_pse_breadcrumbs')) {
            if (!empty($node->nid)) {
              $fdc_pse_breadcrumbs = fdc_pse_breadcrumbs($node->nid);
              if(!empty($fdc_pse_breadcrumbs)) {
                echo $fdc_pse_breadcrumbs;
              } elseif (!empty($breadcrumb)){ 
                print $breadcrumb;
              }
            } else if (!empty($breadcrumb)){ 
              print $breadcrumb; 
            }
          } 
          ?>

		      <a id="main-content"></a>

		      <?php print render($title_prefix); ?>
		      <?php if (!empty($title)): ?>
				<!-- <h1 class="page-header"><?php print $title; ?></h1> -->
		      <?php endif; ?>
		      <?php print render($title_suffix); ?>

		      <?php print $messages; ?>
		      <?php if (!empty($tabs)): ?>
		        <?php print render($tabs); ?>
		      <?php endif; ?>

		      <?php if (!empty($page['help'])): ?>
		        <?php print render($page['help']); ?>
		      <?php endif; ?>

		      <?php if (!empty($action_links)): ?>
		        <ul class="action-links"><?php print render($action_links); ?></ul>
		      <?php endif; ?>

				<!-- CUSTOM TEMPLATES -->
				<?php
				if (preg_match('/^\/node\/[0-9]{1,5}\/(edit|delete)/', $_SERVER['REQUEST_URI'])) {
					require_once($directory . '/templates/custom/default.php');
				} else {
					if (isset($node) && file_exists($directory . '/templates/custom/node--' . $node->type . '.php')) {
            print "\n" . '<!-- file ' . $directory . '/templates/custom/' . $node->type . '.php' . ' -->' . "\n";
            include_once($directory . '/templates/custom/node--' . $node->type . '.php');
            print "\n" . '<!-- end of file ' . $directory . '/templates/custom/node--' . $node->type . '.php' . ' -->' . "\n";
					} elseif (isset($node) && file_exists($directory . '/templates/custom/' . $node->type . '.php')) {
            print "\n" . '<!-- file ' . $directory . '/templates/custom/' . $node->type . '.php' . ' -->' . "\n";
            include_once($directory . '/templates/custom/' . $node->type . '.php');
            print "\n" . '<!-- end of file ' . $directory . '/templates/custom/' . $node->type . '.php' . ' -->' . "\n";
					} else {
            print "\n" . '<!-- file ' . $directory . '/templates/custom/default.php' . ' -->' . "\n";
            include_once($directory . '/templates/custom/default.php');
            print "\n" . '<!-- end of file ' . $directory . '/templates/custom/default.php' . ' -->' . "\n";
					}
				}
				?>
				<!-- END CUSTOM TEMPLATES -->

		    </section>
          
        <?php if (!empty($page['sidebar_second'])): ?>
          <aside class="col-sm-3" role="complementary">
            <?php print render($page['sidebar_second']); ?>
          </aside>  <!-- /#sidebar-second -->
        <?php endif; ?>
		</div><!-- /.row with content and sidebars -->
        
    <?php if (!empty($page['after_sidebars'])) { ?>
      <div class="row region-after-sidebars">
        <?php print render($page['after_sidebars']); ?>
      </div><!-- /.region-after-sidebars -->
    <?php } ?>

	</div>
  <?php if (empty($node) || $node->type != 'intranet_home_page') :?>
  <?php include_once($directory . '/templates/footer.php'); ?>
  <?php endif;?>





</div>



	<div class="wrapper_privacy_notice">
		<div class="privacy_notice">
			<div class="container">
				<div class="row">
					<div class="col-xs-12 col-sm-12 col-md-9 col-lg-9">
						<p>Our website uses cookies so that we can provide a better browsing experience. Continue to use the site as normal if you're happy with this or <a href="/misc/privacy">find out more about cookies</a></p>
					</div>
					<div class="col-xs-12 col-sm-12 col-md-3 col-lg-3">
						<p><span class="notice_close">OK</span></p>
					</div>
				</div>
			</div>
		</div>
	</div>

