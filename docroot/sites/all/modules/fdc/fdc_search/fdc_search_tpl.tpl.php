<?php if (!empty($results)): ?>
	<h2>About <?php echo count($results); ?> result(s) matching your query</h2>
	<!-- product list goes here  -->
	<?php $_base = $GLOBALS['base_url']; ?>
	<div class="search-results content_page_text">
		<?php if (!empty($results)): ?>
			<?php foreach ($results as $items): ?>
				<?php $page_url = $items->url; ?>							
				<div class="search-result">
					<a class="name text_link" href="<?php echo $page_url; ?>">
						<?php if (!empty($items->name)): ?>
							<?php echo $items->name; ?>	
						<?php endif; ?>
					</a>


					<div class="search_url">
						<?php if (!empty($items->url)): ?>
							<?php echo $_base . $items->url; ?>	
						<?php endif; ?>
					</div>


					

					<div class="search_multi">
						<?php if (!empty($items->more)): ?>
							<?php foreach ($items->more as $multi) : ?>
								<?php echo "...<b>" . $multi . "</b>"; ?>	
							<?php endforeach; ?>
						<?php endif; ?>
					</div>

					<div class="search_occurrence">
						<?php if (!empty($items->occurence)): ?>
							appears	<?php echo $items->occurence; ?> time(s)
						<?php endif; ?>
					</div>



				</div>
			<?php endforeach; ?>
		<?php endif; ?>
	</div>
<?php endif; ?>






