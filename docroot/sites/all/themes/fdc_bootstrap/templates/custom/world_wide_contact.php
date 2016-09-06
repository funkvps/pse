<?php
//meta stuff /sites/all/modules/fdc/fdc_meta/fdc_meta.module

if (function_exists('fdc_meta_add')) {
	fdc_meta_add($node->nid);
}



/**
 * @surf
 * the following methods can be found in /sites/all/modules/fdc/fdc_pse/fdc_pse_func.func
 */
if (function_exists('fdc_pse_node_content')) {
	$content = fdc_pse_node_content($node->nid);
}

/**
 * @surf
 * the following methods can be found in /sites/all/modules/fdc/fdc_pse/fdc_pse_world_wide.inc
 */
if (function_exists('fdc_pse_world_wide_location')) {
	$results = fdc_pse_world_wide_location();
	$googleMap = $results->googleMap;
}


/**
 * drupal function found in /sites/all/themes/fdc_bootstrap/template.php
 */
$content_menu = child_sibling_menu($node->nid);


?>


<div class="row">
	<div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">
		<?php if (isset($content->heading) && $content->heading) : ?>
			<h1>
				<?php echo $content->heading; ?>
			</h1>
		<?php endif; ?>
	</div>
</div>

<?php if (!empty($googleMap)): ?>
	<div class="row ">
		<div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">
			<!-- <div class="mapholder_wrap">
				<div id="mapholder">
					<div class="map_wrap" id="googleMapCanvas" > -->
						<?php // echo $googleMap->display();   ?>
              <dl id="imap">
                <dt><a id="title" href="#map" title="Contact">Contact</a></dt>
                <dd id="dotlondon"><a id="london" title="London" href="#uk">
                <span>PSE Head Office <br>London, United Kingdom</span></a>
                </dd>
                <dd id="dotnj"><a id="usa" title="USA" href="#us">
                <span>PSE Americas<br>Cedar Knolls, NJ, USA</span></a>
                </dd>
                <!--<dd id="dotcologne"><a id="germany" title="Germany" href="#">
                <span>PSE Central Europe <br />K&ouml;ln, Germany</span></a>
                </dd>-->
                <dd id="dotswitzerland"><a id="switzerland" title="Switzerland" href="#swiss">
                <span>Blue Watt Engineering <br>Switzerland</span></a>
                </dd>
                <!--
                <dd id="dotsaudi"><a id="saudi" title="Saudi Arabia" href="#sa">
                <span>Hyperion Systems* <br /> Al Khobar, Saudi Arabia</span></a>
                </dd>
                <dd id="dotuae"><a id="uae" title="United Arab Emirates" href="#uae">
                <span>Arabian Company*<br />Dubai, UAE</span></a>
                </dd>
                -->
                <dd id="dotmalaysia"><a id="malaysia" title="Malaysia" href="#malaysia">
                <span>MECIP Global Engineers*<br>Kerteh, Malaysia</span></a>
                </dd>
                <dd id="dotthailand"><a id="thailand" title="Thailand" href="#thailand">
                <span>Asia Pacific Green Energy Corporation* <br>
                Bangkok, Thailand</span></a>
                </dd>
                <dd id="dotchina"><a id="china" title="China" href="#china">
                <span>Beijing Hi-Key Technology Co., Ltd.* <br> Beijing, PR China</span></a>
                </dd>
                <dd id="dotjapan"><a id="japan" title="Japan" href="#japan">
                <span>PSE Japan
                <br>Yokohama, Japan</span></a>
                </dd>
                <dd id="dotkorea"><a id="korea" title="South Korea" href="#korea">
                <span>PSE Korea<br>
                Daejeon, South Korea</span></a>
                </dd>
                <dd id="dothouston"><a id="houston" title="Houston" href="#houston">
                <span>PSE Houston<br>
                Houston, Texas</span></a>
                </dd>
              </dl>
					<!-- </div>
				</div>
			</div> -->
		</div>
	</div>
<?php endif; ?>

<div class="row equal_children_height">

	<div class="col-xs-12 col-sm-12 col-md-8 col-lg-8">

		<div class="row">
			<div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">
				<?php
					/**
					 * contents can be found under the path 
					 * /sites/all/modules/fdc_pse/fdc_pse_locations.inc
					 */
				?>
				
				<?php include(drupal_get_path('module', 'fdc_pse') . '/fdc_pse_locations.inc'); ?>
			</div>
		</div>

		<div class="row">
			<div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">
				<?php if (isset($content->body) && $content->body) : ?>
					<?php echo $content->body; ?>
				<?php endif; ?>
			</div>
		</div>
	</div>

	<aside class="col-xs-12 col-sm-12 col-md-3 col-lg-3 pull-right" id="sidebarnobg">
		<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/right_menu.inc'; ?>

	</aside>
	
</div>