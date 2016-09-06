
<?php if (function_exists('get_login_content')): ?>
	<?php $login_content = get_login_content(46); ?>

<?php endif; ?>

<div class="user_login">

	<?php if (!empty($login_content)): ?>
		<div class="row">
			<div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">
				<div class="panel panel-default">
					<div class="pad">
						<div>
							<?php echo $login_content; ?>
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
					<div class="user_login_form">
						<?php print drupal_render_children($form) ?>
					</div>
				</div>
			</div>
		</div>
	</div>
</div>



<script>
	$(function() {
		$('.user_login_form').append("<a href='/user/register' class='btn btn-default '>Create New Account</a>");
		$('.user_login_form').append("<a href='/user/password' class='btn btn-default '>Forgot Password ?</a>");
	})


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

//jQuery(document).ready(function() {
//
//		$("body").html($("body").html().replace(/Log in/g, 'Sign In'));
////		$("body").html($("body").html().replace(/Log out/g, 'Sign Out'));
//	});
</script>