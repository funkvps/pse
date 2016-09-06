<div class="pull-right">
	<?php if (!empty($results->author_menu)): ?>
		<a class="btn btn-primary" href="/node/add">Add content</a>		 	
		<a class="btn btn-primary" href="/admin/content">View content</a>		 	
	<?php endif; ?>
	<?php if ($results->user_type == "company_admin"): ?>
		<a class="btn btn-primary" href="/node/<?php echo $results->user_company_nid;?>/edit">Edit my company</a>		 	
	<?php endif; ?>
	<!--<a class="btn btn-primary" href="/user/<?php // echo $GLOBALS['user']->uid;?>/orders">My Orders</a>-->		 	
	<a class="btn btn-primary" href="/user/<?php echo $GLOBALS['user']->uid;?>/edit">Edit my profile</a>		 	
  <?php if (user_access('customer area downloads access')): ?>
	  <a class="btn btn-primary" href="/customer-area">Downloads</a>		 	
  <?php endif; ?>
	<!-- <a class="btn btn-primary" href="/user/logout">Sign out</a> -->		 	
</div>