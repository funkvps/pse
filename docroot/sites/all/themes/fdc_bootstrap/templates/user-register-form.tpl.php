
<?php
global $user;
if ($user->uid) {
	drupal_goto("/user/dashboard");
}


if (function_exists('get_register_content')) {
	$register_content = get_register_content(46);
}
?>

<div class="user_registration">
	<?php if (!empty($register_content)): ?>
		<div class="row">
			<div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">

				<div class="panel panel-default">
					<div class="pad">
						<div >
							<?php echo $register_content; ?>
						</div>

					</div>
				</div>
			</div>
		</div>
	<?php endif; ?>
	<div class="row">
		<div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">

			<div class="panel panel-default">
				<div class="pad">
					<div id="user_challenger">
						<div class="register_form">
							<?php print drupal_render_children($form) ?>
						</div>
					</div>

				</div>
			</div>
		</div>
	</div>
</div>


<script>
if (jQuery('ul.tabs--primary li:nth-child(2) a').length > 0) {
		jQuery('ul.tabs--primary li:nth-child(2) a').html(
				jQuery('ul.tabs--primary li:nth-child(2) a').html().replace('Log in', 'Sign in')
				);

	}
	if (jQuery('#edit-submit').length > 0) {
		jQuery('#edit-submit').html(
				jQuery('#edit-submit').html().replace('Log in', 'Sign in')
				);

	}
</script>