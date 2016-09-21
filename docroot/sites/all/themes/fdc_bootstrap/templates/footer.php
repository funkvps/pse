
<footer id="cta">

	<a href="/contact-pse">Contact us</a>

</footer>


<footer id="bottom"> 

	<!-- <div class="row visible-xs"><a href="#top" class="pull-right">Back to Top</a></div> -->

	<?php if (function_exists('get_footer_menu')): ?>
		<?php $get_footer_menu = get_footer_menu(); ?>
		<?php if (!empty($get_footer_menu)): ?>
			<div class="footer_strip_01">

				<div class="row equal_children_height">
					<div class="col-xs-12 col-sm-4 col-lg-4 col-lg-4 setheight footer_text">
						<?php if (!empty($get_footer_menu->field_left_footer_value)): ?>
							<?php // echo $get_footer_menu->field_left_footer_value; ?>
						<?php endif; ?>

					</div>
					<div class="col-xs-12 col-sm-8 col-lg-8 col-lg-8 setheight footer_destination_nav">
						<?php if (!empty($get_footer_menu->field_col_right_footer_value)): ?>
							<?php // echo $get_footer_menu->field_col_right_footer_value; ?>
						<?php endif; ?>

					</div>
				</div>

			</div>
		<?php endif; ?>
    
    <?php
      if (function_exists('fdc_pse_footer')) {
        $fdc_pse_footer = false; 
        if (!empty($node->nid)) {
          $fdc_pse_footer = fdc_pse_footer($node->nid); 
          if (!empty($fdc_pse_footer->footer_val)) {
            echo $fdc_pse_footer->footer_val;
          } else {
            $fdc_pse_footer = false;
          }
        }
        if ($fdc_pse_footer == false) {
          $fdc_pse_footer = fdc_pse_footer_default(161);
          echo $fdc_pse_footer->footer_val;
        }
      }
    ?>

		<p class="copyright">
			<span class="copyright">&copy; Process Systems Enterprise Limited</span>
			<a class="footer_link first" href="/misc/copyright">Copyright</a>
			<a class="footer_link" href="/misc/privacy">Privacy</a>
			<a class="footer_link" href="/misc/cookies">Cookies</a>
			<a class="footer_link" href="/misc/accessibility">Accessibility</a>
			<a class="footer_link" href="/misc/registration">Legal</a>
		</p>

	<?php endif; ?>

</footer>

<div class="megamenu_overlay"></div>

<div class="overlay" id="overlay_general">
	<div class="overlay_scroll">
		<div class="form_content"></div>	
	</div>
</div> 

<?php $modal_nid = 149; ?>
<?php
if (function_exists('fdc_pse_node_content')) {
	$modal_content = fdc_pse_node_content($modal_nid);
}
?>


<div class="modal fade" id="user_not_registered_modal" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="false" data-backdrop="static">
	<div class="modal-dialog">
		<div class="modal-content">
			<div class="modal-header">
				<button type="button" id="close_newsletter_btn" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
				<?php if (!empty($modal_content->heading)): ?>
					<h4 class="modal-title" id="myModalLabel"><?php echo $modal_content->heading; ?></h4>
				<?php endif; ?>
			</div>
			<div class="modal-body">
				<div class="row">
					<div class="col-xs-12 col-sm-12 col-md-6 col-lg-6">
						<div class="">
							<?php echo $modal_content->body; ?>
						</div>
						<div class="">
							<a  href="/user/login?destination=<?php echo current_path(); ?>" class="btn btn-default">Login</a> | 
							<a href="/user/register?destination=<?php echo current_path(); ?>" class="btn btn-default">Register</a>
						</div>

					</div>
					<div class="col-xs-12 col-sm-12 col-md-6 col-lg-6">
						<?php
						$webform_node = node_load(149);  //media file downloader
						if (!empty($webform_node)) {
							webform_node_view($webform_node, 'full');
							print theme_webform_view($webform_node->content);
						}
						?>

					</div>
				</div>
			</div>
		</div>
	</div>
</div>


<?php // if(function_exists('fdc_pse_get_presentation_form_contents')):?>
<?php // $presentation_webform_content = fdc_pse_get_presentation_form_contents();?>

<?php // endif;?>



<?php $modal_nopermi_nid = 714; ?>
<?php
if (function_exists('fdc_pse_node_content')) {
	$modal_nopermi_content = fdc_pse_node_content($modal_nopermi_nid);
}
?>
<div class="modal fade" id="user_has_no_permissions" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="false" data-backdrop="static">
	<div class="modal-dialog">
		<div class="modal-content">
			<div class="modal-header">
				<button type="button" id="close_newsletter_btn" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
				<h4 class="modal-title" id="myModalLabel"><?php if (!empty($modal_nopermi_content->heading)): ?><?php echo $modal_nopermi_content->heading; ?><?php endif; ?></h4>
			</div>
			<div class="modal-body">
				<div class="row">
					<div class="col-xs-12 col-sm-12 col-md-6 col-lg-6">
						<div class="">
							<p><?php if (!empty($modal_nopermi_content->body)): ?><?php echo $modal_nopermi_content->body; ?><?php endif; ?></p>
						</div>

						<div class="">
							<?php if ($user->uid): ?>
								<a  href="#"  class="disabled btn btn-default">Logged In</a> 
								<!--|--> 
								<!--<a href="#" class="disabled btn btn-default">Registered</a>-->

							<?php else: ?>
								<a  href="/user/login?destination=<?php echo current_path(); ?>" class="btn btn-default">Login</a> 
								<!--|--> 
								<!--<a href="/user/register?destination=<?php echo current_path(); ?>" class="btn btn-default">Register</a>-->
							<?php endif; ?>
						</div>

					</div>
					<div class="col-xs-12 col-sm-12 col-md-6 col-lg-6">
						<?php
						$webform_node = node_load($modal_nopermi_nid);
						if (!empty($webform_node)) {
							webform_node_view($webform_node, 'full');
							print theme_webform_view($webform_node->content);
						}
						?>

					</div>
				</div>
			</div>
		</div>
	</div>
</div>



<div class="modal fade" id="user_not_loggedin" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="false" data-backdrop="static">
	<div class="modal-dialog">
		<div class="modal-content">
			<div class="modal-header">
				<button type="button" id="close_nt_btn" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
				<h4 class="modal-title" id="myModalLabel"></h4>
			</div>
			<div class="modal-body">
				<div class="row">
					<div class="col-xs-12 col-sm-12 col-md-6 col-lg-6">
						<a  href="/user/login?destination=cart" class="btn btn-default">Login</a> 
					</div>
					<div class="col-xs-12 col-sm-12 col-md-6 col-lg-6">
						<a id="continue_guest" href="/cart" class="btn btn-default">Continue as a guest</a>
					</div>
				</div>
			</div>
		</div>
	</div>
</div>








<!-- Go to www.addthis.com/dashboard to customize your tools -->
<script type="text/javascript" src="//s7.addthis.com/js/300/addthis_widget.js#pubid=ra-55841db216f9ca3a" async="async"></script>




<?php global $user; ?>
<?php if (!$user->uid): ?>

	<script>
		jQuery(function() {
			jQuery('#user_cart').click(function(e)
			{

				var x = readCookie('login_cookie');
				if (x == 'true') {

				} else {
					jQuery('#user_not_loggedin').modal('show');
					e.preventDefault();
				}
			});
			jQuery('#continue_guest').click(function(e)
			{
				createCookie('login_cookie', 'true', 1);
				window.location = "/cart";
			})
		});
	</script>

<?php endif; ?>



<?php if (function_exists('fdc_tokens_get_full_name')): ?>
	<script>
		if ($('#edit-customer-profile-billing-commerce-customer-address-und-0-name-line').length > 0)
		{
	<?php $full_name = fdc_tokens_get_full_name(); ?>
	<?php if (!empty($full_name)): ?>
				$('#edit-customer-profile-billing-commerce-customer-address-und-0-name-line').val('<?php echo $full_name; ?>');
	<?php endif; ?>

		}

		if ($('#edit-customer-profile-billing-commerce-customer-address-und-0-thoroughfare').length > 0)
		{
	<?php $street = fdc_tokens_get_street(); ?>
	<?php if (!empty($street)): ?>
				$('#edit-customer-profile-billing-commerce-customer-address-und-0-thoroughfare').val('<?php echo $street; ?>');
	<?php endif; ?>
		}

		if ($('#edit-customer-profile-billing-commerce-customer-address-und-0-locality').length > 0)
		{
	<?php $city = fdc_tokens_get_city(); ?>
	<?php if (!empty($city)): ?>
				$('#edit-customer-profile-billing-commerce-customer-address-und-0-locality').val('<?php echo $city; ?>');
	<?php endif; ?>
		}
		if ($('#edit-customer-profile-billing-commerce-customer-address-und-0-postal-code').length > 0)
		{
	<?php $postcode = fdc_tokens_get_postcode(); ?>
	<?php if (!empty($postcode)): ?>
				$('#edit-customer-profile-billing-commerce-customer-address-und-0-postal-code').val('<?php echo $postcode; ?>');
	<?php endif; ?>
		}



	</script>
<?php endif; ?>



<?php /*
<!-- Google analytics code -->
<script type="text/javascript">
  var _gaq = _gaq || [];
  _gaq.push(['_setAccount', 'UA-1072168-1']);
  _gaq.push(['_trackPageview']);
  (function() {
    var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
	ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
	var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
})();

</script>
 * 
 */?>
 
<!--Clicky code -->
 
<script src="https://static.getclicky.com/13584.js" type="text/javascript"></script>
 
<noscript><p><img alt="Clicky" src="https://static.getclicky.com/13584ns.gif" /></p></noscript>

<!-- Lead Vision analytics code
 
<script type="text/javascript">
   document.write(unescape("%3Cscript src='" + (("https:" == document.location.protocol) ? "https" : "http") + "://leadvision.dotmailer.co.uk/_dm_lt.js' type='text/javascript'%3E%3C/script%3E"));
</script> -->




