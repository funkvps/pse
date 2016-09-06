

<section id="content">
	<div id="my-pse-menu" class="row">
		<div class="col-xs-12 col-sm-5 col-md-5 col-lg-5 user-nav" style="float: right;">
			<?php include(drupal_get_path('module', 'fdc_membership_utils') . '/inc/menu.inc'); ?>
		</div>
		<div class="col-xs-12 col-sm-7 col-md-7 col-lg-7">
			<?php include(drupal_get_path('module', 'fdc_membership_utils') . '/inc/members_greetings.inc'); ?>
			<?php include(drupal_get_path('module', 'fdc_membership_utils') . '/inc/my_company.inc'); ?>
		</div>
	</div>

  <?php if (empty($results->my_company->company_name)): ?><div class="no-company-name"><?php endif; ?>
    <hr />
    <?php
      $block = block_load('views', 'pse_news-block_news_user_dash');
      $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
      $output = drupal_render($render_array);
      print $output;

      $block = block_load('views', 'pse_events-block_user_events');
      $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
      $output = drupal_render($render_array);
      print $output;

      $block = block_load('views', 'pse_training_courses-blck_dash');
      $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
      $output = drupal_render($render_array);
      print $output;
    ?>

    <section>
      <?php include(drupal_get_path('module', 'fdc_membership_utils') . '/inc/orders.inc'); ?>
    </section>

    <?php include(drupal_get_path('module', 'fdc_membership_utils') . '/inc/members.inc'); ?>

    <?php /* if ($results->show_all_training): ?>
    <hr />
      <?php include(drupal_get_path('module', 'fdc_membership_utils') . '/inc/training.inc'); ?>
      <p class="small_link"><a href="/services/training/training-courses">Find more courses</a></p>
    
    <?php else: ?>
    
      <?php include(drupal_get_path('module', 'fdc_membership_utils') . '/inc/user_related_training.inc'); ?>
      <p class="small_link"><a href="/services/training/training-courses">Find more courses</a></p>
    <?php endif; */ ?>

  <?php if (empty($results->my_company->company_name)): ?></div><?php endif; ?>

<?php
	global $user;
	if (!$user->uid) {
		drupal_goto('user');
	}
?>
    <?php /*
	<section>


		<ul id="doubleislands" class="equal_children_height row">
			<!-- news -->
			<li class="col-xs-12 col-sm-12 col-md-6 col-lg-6 left ">
				<div class="wrap setheight">
					<?php include(drupal_get_path('module', 'fdc_membership_utils') . '/inc/related_news.inc'); ?>
					<p class="small_link"><a href="/user/<?php echo fdc_membership_utils_get_uid();?>/edit">Edit my preferences</a></p>
				</div>
				
			</li>
			<!--training-->
			<!--<li class="col-xs-12 col-sm-12 col-md-4 col-lg-4  ">-->
			<?php // include(drupal_get_path('module', 'fdc_membership_utils') . '/inc/related_training.inc'); ?>

			<!--</li>-->
			<!-- events -->
			<li class="col-xs-12 col-sm-12 col-md-6 col-lg-6 right ">
				<div class="wrap setheight">
					<?php include(drupal_get_path('module', 'fdc_membership_utils') . '/inc/related_events.inc'); ?>
					<p class="small_link"><a href="/user/<?php echo fdc_membership_utils_get_uid();?>/edit">Edit my preferences</a></p>
				</div>
				
			</li>

		</ul>


	</section>

*/ ?>
