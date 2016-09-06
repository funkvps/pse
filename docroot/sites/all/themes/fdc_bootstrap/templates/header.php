<?php global $user; ?>


<header id="top" role="banner" class="navbar navbar-default">
	<div class="row">

		<div class="col-xs-3 col-sm-2 col-md-2 col-lg-1 col-logo" style="z-index:999">
			<?php if ($logo): ?>
				<a class="logo navbar-btn" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
					<img src="/<?php echo $directory ?>/logo.svg" alt="<?php print t('Home'); ?>" class="img-responsive" />
				</a>
			<?php endif; ?>
		</div>

		<div class="col-xs-12 col-sm-10 col-md-10 col-lg-11 col-nav">

			<div class="hidden-xs">
				<div class="header_search gsc-search-box pull-right">
					<div id="multiple-datasets" class="gsc-input">
						<form action="/search/results">
							<input id="search_input" name="search_input" class="typeahead gsc-input" type="text" placeholder="Search">
							<input value="" type="submit" class="btn btn-primary btn-search"/>
						</form>
					</div>
					<div id ="search_results"></div>
				</div>
				<!--<div class="google_search"><gcse:search></gcse:search></div>-->
			</div>

			<ul class="user-mini-nav">
				<?php if($user->uid):?>
					<li><a href="/user/dashboard">MyPSE</a></li>
					<li><a href="/cart"><span id="fdc_ecommerce_product_top_cart">Basket <?php if(fdc_pse_quote_output($user) > 0):?> (<?php print fdc_pse_quote_output($user); ?>)<?php endif;?></span></a></li>
					<li><a href="/user/logout">Sign out</a></li>
				<?php else : ?>
					<li><a  href="/user">Sign in / Register</a></li>
					<li>
						<a id="user_cart" href="<?php echo '/cart'; ?>"><span id="fdc_ecommerce_product_top_cart">Basket <?php if(fdc_pse_quote_output($user) > 0):?> (<?php print fdc_pse_quote_output_guest(); ?>)<?php endif;?></span></a>
					</li>
					<?php // if (fdc_pse_quote_output($user) != 0) : ?>
					<!--<li>-->
						<!--<a id="user_cart" href="<?php // echo '/cart'; ?>"><span id="fdc_ecommerce_product_top_cart">Basket</span>-->
							<?php // print fdc_pse_quote_output($user); ?>
						<!--</a>-->
					<!--</li>-->
					<?php // endif; ?>
				<?php endif; ?>
			</ul>


			<?php if (function_exists('fdc_pse_get_top_menu')): ?>
				<?php echo fdc_pse_get_top_menu(); ?>
			<?php endif; ?>

			<?php //include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/temp_top_nav.inc';  ?>

			<div class="visible-xs">
				<div class="navbar-header">
					<!-- .btn-navbar is used as the toggle for collapsed navbar content -->
					<button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
						<span class="sr-only">Toggle navigation</span>
						<span class="icon-bar"></span>
						<span class="icon-bar"></span>
						<span class="icon-bar"></span>
					</button>
				</div>
				<?php // if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
				<div class="navbar-collapse collapse">
					<nav role="navigation">
						<?php  if (!empty($primary_nav)): ?>
						<?php  print render($primary_nav); ?>
						<?php  endif; ?>
						<?php // if (!empty($secondary_nav)): ?>
						<?php // print render($secondary_nav); ?>
						<?php // endif; ?>
						<?php // if (!empty($page['navigation'])): ?>
						<?php // print render($page['navigation']); ?>
						<?php // endif; ?>
					</nav>
				</div>
				<?php // endif; ?>
			</div>

			
			<div class="strap">The power to be certain</div>

		</div>

	</div>
</header>


<?php if(function_exists('fdc_pse_get_content_menu')):?>
<div class="hidden-xs">
		<?php echo fdc_pse_get_content_menu(); ?>
	
<!-- 		<div id="div7">
			<?php global $user;?>
			<?php if($user->uid):?>
			<div class="user_menu">
				<ul class="nav navbar-nav">
					<li class="dropdown"> -->
						<!--<a href="#" class="dropdown-toggle" data-toggle="dropdown">-->
							<!--<span class="glyphicon glyphicon-user "></span>--> 
							<!--Menu-->

						<!--</a>-->
						<!--<ul class="dropdown-menu">-->
							<?php // if (fdc_membership_utils_isAdmin()): ?>
								<!--<li><a href='/admin/commerce/products/add'><span class="glyphicon glyphicon-plus"></span> Add Products </a></li>-->

								<!--<li><a href='/admin/commerce/products'><span class="glyphicon glyphicon-eye-open"></span> View Products </a></li>-->
								<!--<li class="divider"></li>-->
							<?php // endif; ?>
						

							<!--<li class="divider"></li>-->
							<!--<li><a href="/user/logout"> <span class="glyphicon glyphicon-log-out"></span> Sign Out</a></li>-->
						<!--</ul>-->
					<!-- </li>
					<li class="divider"></li>
				</ul>
			</div>
			<li><a href="/user/dashboard">MyPSE</a></li>
			<?php else:?>
			<a  href="/user"> <span class="glyphicon glyphicon-log-in"></span> Sign In</a>

			<?php endif;?>

			<div class="basket">
				<div id='fdc_ecommerce_product_top_cart'>
					<?php // if (fdc_pse_quote_output($user) != 0) : ?>
						Your Basket contains <a id="user_cart" href="<?php // echo '/cart'; ?>">
							<?php // print fdc_pse_quote_output($user); ?>
						</a>
					<?php // else: ?>
						Your Basket is empty
					<?php // endif; ?>
				</div>
			</div>

			<div class="close"><a class="button" id="hidediv7"><img src="http://www.psenterprise.com/_assets/img/menuclose.png"></a></div>
		</div>
 -->

</div>
<?php endif;?>
<?php // include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/temp_top_nav_contents.inc';  ?>



