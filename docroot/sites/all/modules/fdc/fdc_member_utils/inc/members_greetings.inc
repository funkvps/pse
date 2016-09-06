
<?php if (function_exists('fdc_membership_utils_current_user_id')): ?>
	<?php
	$current_uid = fdc_membership_utils_current_user_id();
	if (!empty($current_uid)) {
		$user = fdc_membership_utils_user_profile($current_uid);
	}
	?>
	<?php if (!empty($user->first_name)): ?>
		<div id="my-pse-header"><h1>MyPSE</h1><h2><?php echo $user->first_name . ' ' . $user->last_name; ?></h2>
	<?php endif; ?>
<?php endif; ?>