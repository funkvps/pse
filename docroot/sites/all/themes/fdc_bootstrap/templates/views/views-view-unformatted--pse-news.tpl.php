<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
$row_started = false;
$do_news_homepage_formating = false;
if (!isset($_GET['page']) && empty($_GET['f'])) {
  $do_news_homepage_formating = true;
}

?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <?php if ($do_news_homepage_formating) { ?>
  <?php if ($id == 1) { ?>
  <div class="row">
  <?php }?>
  <?php if ($id == 7 || $id == 10) {
    $row_started = true;
  ?>
  </div><div class="row">
  <?php }
  if ($id > 0 && $id < 4) { $classes_array[$id] .= ' col-md-4'; }
  if ($id >= 4 && $id < 12) { $classes_array[$id] .= ' col-md-4'; }
  } ?>
    
    
  <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
    <?php print $row; ?>
  </div>
<?php endforeach; ?>
<?php if ($row_started) { ?>
</div>
<?php }?>