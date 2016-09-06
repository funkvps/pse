<?php
// Load content. 'body' and 'heading'
$content = pageContent($node->nid);
?>

<div class="frame">
	<div class="panel full">
	    <div class="pad">

			<div class="page_content">
			    <div class="main_content">
					<?php if (isset($content->heading) && $content->heading) : ?>
						<h1>
							<?php echo $content->heading; ?>
						</h1>
					<?php endif; ?>

					<?php if (isset($content->body) && $content->body) : ?>
						<?php echo $content->body; ?>
					<?php endif; ?>
				</div>
			</div>
			
		</div>
	</div>
</div>