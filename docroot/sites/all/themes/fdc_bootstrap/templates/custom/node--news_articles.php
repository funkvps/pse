<?php
//meta stuff /sites/all/modules/fdc/fdc_meta/fdc_meta.module

if (function_exists('fdc_meta_add')) {
//	fdc_meta_add($node->nid);
}



// News Article specific SQL
$article = db_query("
	SELECT
		node.nid,
		node.title,
		field_text_value AS full_view_title,
		field_data_field_news_date.field_news_date_value AS date,
		field_data_field_news_heading.field_news_heading_value AS heading,
		field_data_field_news_content.field_news_content_value AS content,
		field_data_field_news_content.field_news_content_summary AS summary,
		field_data_field_news_image.field_news_image_title AS image_title,
		field_data_field_news_image.field_news_image_alt AS image_alt,
		file_managed.uri AS image
	FROM
		node
    LEFT JOIN field_data_field_text AS field_text ON field_text.entity_id = node.nid AND field_text.bundle = 'news_articles'
	INNER JOIN field_data_field_collection_newsarticle ON field_data_field_collection_newsarticle.entity_id = node.nid
	LEFT JOIN field_data_field_news_heading ON field_data_field_news_heading.entity_id = field_data_field_collection_newsarticle.field_collection_newsarticle_value
	LEFT JOIN field_data_field_news_date ON field_data_field_news_date.entity_id = field_data_field_collection_newsarticle.field_collection_newsarticle_value
	LEFT JOIN field_data_field_news_content ON field_data_field_news_content.entity_id = field_data_field_collection_newsarticle.field_collection_newsarticle_value
	LEFT JOIN field_data_field_news_image ON field_data_field_news_image.entity_id = field_data_field_collection_newsarticle.field_collection_newsarticle_value
	LEFT JOIN file_managed ON file_managed.fid = field_data_field_news_image.field_news_image_fid
	WHERE
		node.nid = :nid	
	", array(
    ':nid' => $node->nid
        )
        )->fetchObject();
//		taxonomy_term_data.`name` AS `category`,
//		taxonomy_term_data.tid AS `category_tid`
//	INNER JOIN field_data_field_news_category ON field_data_field_news_category.entity_id = field_data_field_collection_newsarticle.field_collection_newsarticle_value
//	INNER JOIN taxonomy_term_data ON taxonomy_term_data.tid = field_data_field_news_category.field_news_category_tid

if (!empty($article->full_view_title)) {
  $article->title = $article->full_view_title;
} else if (!empty($article->heading)) {
  $article->title = $article->heading;
}
/**
 * drupal function found in /sites/all/themes/fdc_bootstrap/template.php
 */
$content_menu = child_sibling_menu($node->nid);
?>

<?php /* <div id="trail">
  <ul id="breadcrumbs">
  <li><a href="/">PSE</a></li>
  <li class="active"><a href="/news">&gt;&nbsp;news</a> </li>
  </ul>
  </div> */ ?>

<div class="container-fluid background-white">

  <div class="row">

    <div class="col-xs-12 col-sm-9 col-md-8 col-lg-8 article" id="content">

      <div class="pad">


        <?php
        /**
         * @surf
         * methods can be found in  /sites/all/modules/fdc/fdc_news/fdc_news.module
         */
        ?>
        <?php /* $fdc_news_get_multiple_categories = fdc_news_get_multiple_categories($node->nid); ?>
          <?php if (!empty($fdc_news_get_multiple_categories)): ?>
          <p class="category">
          <?php $num_of_items = count($fdc_news_get_multiple_categories); ?>
          <?php $counter = 1; ?>
          <?php foreach ($fdc_news_get_multiple_categories as $cat) : ?>

          <a href="/news/<?php echo str_replace(array('--'), array('-'), str_replace('+', '-', urlencode(strtolower(preg_replace('/[^A-Za-z0-9-]/', '', iconv('UTF-8', 'ASCII//TRANSLIT//IGNORE', str_replace(' ', '-', str_replace('&', '', $cat->category)))))))); ?>">
          <?php echo $cat->category; ?><?php if ($num_of_items > $counter): ?>,<?php endif; ?>
          </a>
          <?php $counter ++; ?>
          <?php endforeach; ?>
          </p>
          <?php endif; */ ?>

        <!-- 				<div class="share_linkedin">
                  <script src="//platform.linkedin.com/in.js" type="text/javascript"></script>
                  <span class="IN-widget" style="line-height: 1; vertical-align: baseline; display: inline-block; text-align: center;"><span style="padding: 0px !important; margin: 0px !important; text-indent: 0px !important; display: inline-block !important; vertical-align: baseline !important; font-size: 1px !important;"><span id="li_ui_li_gen_1435939596271_0"><a id="li_ui_li_gen_1435939596271_0-link" href="javascript:void(0);"><span id="li_ui_li_gen_1435939596271_0-logo">in</span><span id="li_ui_li_gen_1435939596271_0-title"><span id="li_ui_li_gen_1435939596271_0-mark"></span><span id="li_ui_li_gen_1435939596271_0-title-text">Share</span></span></a></span></span></span>
                  <script type="IN/Share+init" data-url="http://www.psenterprise.com/news/press_releases/150210_gcoas/index.html"></script>
                </div> -->

        <!-- <div class="addthis_sharing_toolbox"></div> -->

        <p><?php echo date('j F Y', $article->date); ?></p>
        
        <?php if (!empty($node_content['field_press_release_pdf']['#items'][0]['uri'])) { ?>
          <div class="extras">
            <p class="news_pdf_link">
              <a href="<?php print file_create_url($node_content['field_press_release_pdf']['#items'][0]['uri']); ?>">
                <span class="glyphicon glyphicon-file" aria-hidden="true"></span>	Download this Press release 
              </a>
            </p>
          </div>
        <?php } ?>
        
        <h2 class="clearfix">
          <?php echo $article->title; ?>
        </h2>

        <div class="article_content">


          <?php if ($article->image) : ?>
            <div class="article_image">
              <img 
                class="img-responsive"
                src="<?php echo image_style_url('news_top_feature', $article->image); // old style news_thumb ?>"
                alt="<?php
                if (isset($article->image_alt) && $article->image_alt) {
                  echo strip_tags($article->image_alt);
                } else {
                  echo strip_tags($article->title);
                }
                ?>"
                title="<?php
              if (isset($article->image_title) && $article->image_title) {
                echo strip_tags($article->image_title);
              } else {
                echo strip_tags($article->title);
              }
                ?>"
                />
            </div>		
          <?php endif; ?>


          <div class="article_text">
            <?php if (isset($article->content) && $article->content) : ?>
              <?php echo $article->content; ?>
            <?php endif; ?>
          </div>
          


          <?php if (!empty($node_content['field_col_media']['#items'])): ?>
            <div>
              <h3>Media files</h3>
              <p>Click on a File to open it, then select "Save As" to download and save.</p>
            </div>
          <?php foreach ($node_content['field_col_media']['#items'] as $delta => $item) :
            $item_content = $node_content['field_col_media'][$delta];
            $collection_id = key($item_content['entity']['field_collection_item']);
            $collection = $item_content['entity']['field_collection_item'][$collection_id];
            ?>
              <div class="row news_media_items">
                <a href="<?php echo image_style_url('media_original_file', $collection['field_media_download']['#items'][0]['uri']); ?>" class="btn btn-link col-xs-12 col-sm-6 col-md-4 col-lg-4">
                  <img src="<?php echo image_style_url('media_file_thumb', $collection['field_media_download']['#items'][0]['uri']); ?>" class="img-responsive" 
                       <?php if (!empty($media->img_title)): ?>title = "<?php echo $media->img_title; ?>"<?php endif; ?>
                       <?php if (!empty($media->img_alt)): ?> alt= "<?php echo $media->img_alt; ?>"<?php endif; ?>
                       />
                </a>

                <?php if (!empty($collection['field_media_description'][0]['#markup'])): ?>
                  <div class="">
                    <?php echo $collection['field_media_description'][0]['#markup']; ?>
                  </div>
                <?php endif; ?>
              </div>
            <?php endforeach; ?>

          <?php endif; ?>
          <p><?php print l('See all our news articles >', 'news'); ?></p>



        </div>
      </div>

    </div>

    <aside class="col-xs-12 col-sm-3 col-md-3 col-lg-3 news_nav_col pull-right"  id="sidebarnobg">
      <div class="addthis_sharing_toolbox" ></div>

      <?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/right_menu.inc'; ?>

      <div class="news_nav">

        <div class="pad">
          <?php
          /**
           * @surf
           * can be found in  /sites/all/modules/fdc/fdc_news/fdc_news.module
           */
          print fdc_news_navigation();
          ?>
        </div>

      </div>
    </aside>
  </div>
</div>
