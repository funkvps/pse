
<link type="text/css" rel="stylesheet" href="/sites/all/themes/fdc_bootstrap/css/home.css" media="all" />


<?php
//meta stuff /sites/all/modules/fdc/fdc_meta/fdc_meta.module

if (function_exists('fdc_meta_add')) {
	fdc_meta_add($node->nid);
}

/**
 * @surf
 * the following methods can be found in /sites/all/modules/fdc/fdc_pse/fdc_pse_func.func
 */
if (function_exists('fdc_pse_banner')) {
	$page_banner = fdc_pse_banner($node->nid);
}
if (function_exists('fdc_pse_node_content')) {
	$content = fdc_pse_node_content($node->nid);
}
if (function_exists('fdc_pse_get_node_testimonial')) {
	$testimonials = fdc_pse_get_node_testimonial($node->nid);
}
if (function_exists('fdc_pse_get_cta')) {
	$call_to_action = fdc_pse_get_cta($node->nid);
}
//if (function_exists('fdc_pse_get_sectors_reference')) {
//	$sectors = fdc_pse_get_sectors_reference($node->nid);
//}
?>

<section id="content">

<div class="row">
	<div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">
		<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/home_page_banner.inc'; ?>
	</div>
</div>


<div id="sectorbar">
	<ul class="sectors">
		<li><a href="/sectors/chemicals">Chemicals &amp;<br /> Petrochemicals</a></li>
		<li><a href="/sectors/oil-and-gas">Oil &amp; Gas</a></li>
		<li><a href="/sectors/life-sciences">Life Sciences</a></li>
		<li><a href="/sectors/power">Power &amp; CSS</a></li>
		<li><a href="/sectors/fuelcell">Fuel Cells &amp;<br /> Batteries</a></li>
		<li><a href="/sectors/consumer">Food &amp;<br /> Consumer</a></li>
		<li><a href="/sectors/specialty-chem">Specialty &amp;<br /> Agrochemicals</a></li>
		<li><a href="/sectors/wastewater">Wastewater<br /> Treatment</a></li>
		<li><a href="/sectors/academic">Academic</a></li>

<!-- 	<?php // if (!empty($sectors)): ?>
		<?php // foreach ($sectors as $s): ?>
			<li>
				<a href="<?php // echo url('node/' . $s->nid); ?>">
					<img 
						src="<?php // echo image_style_url('', $s->img_path); ?>" 
						title="<?php // if (!empty($s->img_title)): ?><?php // echo $s->img_title; ?><?php // else: ?><?php // echo $node->title; ?><?php // endif; ?>" 
						alt="<?php // if (!empty($s->img_alt)): ?><?php // echo $s->img_alt; ?><?php // else: ?><?php // echo $node->title; ?><?php // endif; ?>" 
						class="img-responsive" 
					/>
					<?php // echo $s->title; ?>
				</a>

			</li>
		<?php // endforeach; ?> 
	<?php // endif; ?>-->
	</ul>
</div>


<ul class="row" id="introislands">
	<li class="col-xs-12 col-sm-8 col-md-8 col-lg-8 col-introtext">
		<article>
			<header>
				<?php if (!empty($content)): ?>
					<?php if (!empty($content->heading)): ?>
						<h1> <?php echo $content->heading; ?></h1>
					<?php endif; ?>  
					<?php if (!empty($content->body)): ?>
						<?php echo $content->body; ?>
					<?php endif; ?>  
				<?php endif; ?>
			</header>
			<footer><a href="/">More about PSE</a></footer>
		</article>
	</li>
	<li class="col-xs-12 col-sm-4 col-md-4 col-lg-4 col-testimonial pull-right">
		<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/testimonials.inc'; ?>
	</li>
</ul>


<?php // call to action with 3 rows ?>
<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/row3.inc'; ?>

<?php // call to action with 4 rows ?>
<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/row4.inc'; ?>




<ul id="doubleislands" class="equal_children_height row">
	<!-- news -->
	<li class="col-xs-12 col-sm-12 col-md-6 col-lg-6 left setheight">
		<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/news.inc'; ?>

	</li>
	<!-- events -->
	<li class="col-xs-12 col-sm-12 col-md-6 col-lg-6 right setheight">
		<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/events.inc'; ?>
	</li>

</ul>

</section>





