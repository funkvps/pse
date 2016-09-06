<?php
/**
 * @file
 * Default theme implementation to display the basic html structure of a single
 * Drupal page.
 *
 * Variables:
 * - $css: An array of CSS files for the current page.
 * - $language: (object) The language the site is being displayed in.
 *   $language->language contains its textual representation.
 *   $language->dir contains the language direction. It will either be 'ltr' or
 *   'rtl'.
 * - $rdf_namespaces: All the RDF namespace prefixes used in the HTML document.
 * - $grddl_profile: A GRDDL profile allowing agents to extract the RDF data.
 * - $head_title: A modified version of the page title, for use in the TITLE
 *   tag.
 * - $head_title_array: (array) An associative array containing the string parts
 *   that were used to generate the $head_title variable, already prepared to be
 *   output as TITLE tag. The key/value pairs may contain one or more of the
 *   following, depending on conditions:
 *   - title: The title of the current page, if any.
 *   - name: The name of the site.
 *   - slogan: The slogan of the site, if any, and if there is no title.
 * - $head: Markup for the HEAD section (including meta tags, keyword tags, and
 *   so on).
 * - $styles: Style tags necessary to import all CSS files for the page.
 * - $scripts: Script tags necessary to load the JavaScript files and settings
 *   for the page.
 * - $page_top: Initial markup from any modules that have altered the
 *   page. This variable should always be output first, before all other dynamic
 *   content.
 * - $page: The rendered page content.
 * - $page_bottom: Final closing markup from any modules that have altered the
 *   page. This variable should always be output last, after all other dynamic
 *   content.
 * - $classes String of classes that can be used to style contextually through
 *   CSS.
 *
 * @see bootstrap_preprocess_html()
 * @see template_preprocess()
 * @see template_preprocess_html()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML+RDFa 1.0//EN" "http://www.w3.org/MarkUp/DTD/xhtml-rdfa-1.dtd">

<html lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces; ?>>
	<head profile="<?php print $grddl_profile; ?>">
		<meta charset="utf-8">
		<meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no" />

		<title><?php print $head_title; ?></title>

		<!-- FONTS -->
		<link href='http://fonts.googleapis.com/css?family=News+Cycle:400,700' rel='stylesheet' type='text/css'>
		<!-- dev type kit -->
    <script src="https://use.typekit.net/rxy1gne.js"></script>
    <script>try{Typekit.load({ async: true });}catch(e){}</script>

		<!-- FONTS -->

		<?php print $head; ?>

		<link rel="apple-touch-icon" sizes="57x57" href="/apple-touch-icon-57x57.png?v=alBxmp256o">
		<link rel="apple-touch-icon" sizes="60x60" href="/apple-touch-icon-60x60.png?v=alBxmp256o">
		<link rel="apple-touch-icon" sizes="72x72" href="/apple-touch-icon-72x72.png?v=alBxmp256o">
		<link rel="apple-touch-icon" sizes="76x76" href="/apple-touch-icon-76x76.png?v=alBxmp256o">
		<link rel="apple-touch-icon" sizes="114x114" href="/apple-touch-icon-114x114.png?v=alBxmp256o">
		<link rel="apple-touch-icon" sizes="120x120" href="/apple-touch-icon-120x120.png?v=alBxmp256o">
		<link rel="apple-touch-icon" sizes="144x144" href="/apple-touch-icon-144x144.png?v=alBxmp256o">
		<link rel="apple-touch-icon" sizes="152x152" href="/apple-touch-icon-152x152.png?v=alBxmp256o">
		<link rel="apple-touch-icon" sizes="180x180" href="/apple-touch-icon-180x180.png?v=alBxmp256o">

		<link rel="icon" type="image/png" href="/android-chrome-192x192.png?v=alBxmp256o" sizes="192x192">
		<link rel="icon" type="image/png" href="/favicon-96x96.png?v=alBxmp256o" sizes="96x96">
		<link rel="icon" type="image/png" href="/favicon-16x16.png?v=alBxmp256o" sizes="16x16">
		<link rel="icon" type="image/png" href="/favicon-32x32.png?v=alBxmp256o" sizes="32x32">
		<link rel="manifest" href="/manifest.json?v=alBxmp256o">
		<link rel="shortcut icon" href="/favicon.ico?v=alBxmp256o">
		<meta name="msapplication-TileColor" content="#ffffff">
		<meta name="msapplication-TileImage" content="/mstile-144x144.png?v=alBxmp256o">
		<meta name="theme-color" content="#ffffff">


		<?php print $styles; ?>
		<!-- HTML5 element support for IE6-8 -->
		<!--[if lt IE 9]>
		  <script src="//html5shiv.googlecode.com/svn/trunk/html5.js"></script>
		<![endif]-->
		<?php print $scripts; ?>

	</head>

	<?php
	/**
	 * the following determines the user theme.
	 * it is important that when a user logs in, they are redirected to /user/dashboard
	 * at this stage the variable_set('user_theme'....    is set
	 * /sites/all/modules/fdc/fdc_member_utils/fdc_membership_utils.module
	 */
	global $user;
	if (!$user->uid) {

		$theme = 'normal_theme';
	}
	else {
		$theme = variable_get('user_theme', 'normal_theme');
	}
	?>


	<body class="<?php print $classes; ?> <?php if (!empty($theme)): ?> <?php echo $theme; ?><?php endif; ?>" <?php print $attributes; ?> id="<?php if (strpos($classes, 'front') !== false) {
		echo 'hub';
	} ?>">
		<div class="
		<?php if (strpos($classes, 'node-type-page') !== false) {
			echo 'text';
		} ?> 
		<?php if (strpos($classes, 'node-type-product') !== false) {
			echo 'product';
		} ?> 
		<?php if (strpos($classes, 'node-type-home') !== false) {
			echo 'home';
		} ?> 
		<?php if (strpos($classes, 'node-type-director-listing') !== false) {
			echo 'text';
		} ?> 
		<?php if (strpos($classes, 'node-type-sector') !== false) {
			echo 'text';
		} ?> 
		<?php if (strpos($classes, 'node-type-contact-us') !== false) {
			echo 'text';
		} ?> 
					<?php if (strpos($classes, 'node-type-training-course') !== false) {
						echo 'text';
					} ?> 
		<?php if (strpos($classes, 'node-type-news-articles') !== false) {
			echo 'text';
		} ?> 
		<?php if (strpos($classes, 'page-news') !== false) {
			echo 'text';
		} ?> 
		<?php if (strpos($classes, 'page-events') !== false) {
			echo 'text';
		} ?> 
		<?php if (strpos($classes, 'node-type-hotel-location') !== false) {
			echo 'text';
		} ?> 
		<?php if (strpos($classes, 'node-type-events-and-webinar') !== false) {
			echo 'text';
		} ?>
		<?php if (strpos($classes, 'node-type-directions') !== false) {
			echo 'text';
		} ?>  
		<?php if (strpos($classes, 'node-type-customer-area-page') !== false) {
			echo 'text';
		} ?> 
		<?php if (strpos($classes, 'node-type-customer-area-download') !== false) {
			echo 'text';
		} ?> 
		<?php if (strpos($classes, 'node-type-customer-area-form') !== false) {
			echo 'text';
		} ?> 
		<?php if (strpos($classes, 'node-type-intranet-home-page') !== false) {
			echo 'text intranet';
		} ?> 
			 "> 


			<div id="skip-link">
				<a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
			</div>

<?php print $page_top; ?>
<?php print $page; ?>
<?php print $page_bottom; ?>

		</div>
	</body>
	<?php /*<script>
		 (function() {
		 	var cx = '001756475708681791441:th5hrxnqcha';
		 	var gcse = document.createElement('script');
		 	gcse.type = 'text/javascript';
		 	gcse.async = true;
		 	gcse.src = (document.location.protocol == 'https:' ? 'https:' : 'http:') +
		 			'//www.google.com/cse/cse.js?cx=' + cx;
		 	var s = document.getElementsByTagName('script')[0];
		 	s.parentNode.insertBefore(gcse, s);
		 })();
	</script>
*/?>
</html>
