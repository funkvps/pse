
<?php
//echo "<pre>";
//print_r ($results);
//echo "</pre>";
$we_have_orders = false;
if (!empty($results->orders)) {
  foreach ($results->orders as $or) {
    if (!empty($or->orders)) {
      $we_have_orders = true;
      break;
    }
  }
}

?>

<?php if (!empty($results->user_type)): ?>
	<?php if ($results->user_type == "company_admin"): ?>
		<?php if (!empty($results->orders)): ?>
			<div>
				<h3 class="dashboard-header" title="This is where you will see any training subscribed to by others in your company">Company user orders</h3>
			</div>
      <?php if ($we_have_orders == true) { ?>
        <table class="table order_listing_table my-orders">
          <tr>
            <!--<th>Order Id</th>-->
            <th class="date">Date</th>
            <th class="title">Training</th>
            <th class="user">User</th>
            <th class="status">Order Status</th>
          </tr>

          <?php  //print_r($results->orders); ?>

          <?php foreach ($results->orders as $or) : ?>
            <?php foreach ($or->orders as $value) : ?>
              <tr>
                <!--<td><?php // echo $value->order_id; ?> </td>-->
                <td><?php 
                if (date("d-M-Y", $value->product->start_date) == date("d-M-Y", $value->product->end_date)) {
                  echo date("d-M-Y", $value->product->start_date);; 
                } else {
                  echo date("d-M-Y", $value->product->start_date) . ' to <br/> ' . date("d-M-Y", $value->product->end_date); 
                }
                ?></td>
                <td><?php echo $value->product->title; ?></td>
                <td><?php echo $value->user_info->first_name; ?> <?php echo $value->user_info->last_name; ?></td>
                <!--<td><?php // echo $value->status; ?></td>-->
                <!--<td><a  class="btn btn-primary" href="/user/<?php // echo $value->uid; ?>/orders"> View</a></td>-->
                <td><?php echo $value->status; ?></td>


              </tr>
            <?php endforeach; ?>
          <?php endforeach; ?>
          <?php if (!empty($results->order)): ?>		
            <?php foreach ($results->order as $value) : ?>
              <tr>
                <td><?php 
                if (date("d-M-Y", $value->product->start_date) == date("d-M-Y", $value->product->end_date)) {
                  echo date("d-M-Y", $value->product->start_date);; 
                } else {
                  echo date("d-M-Y", $value->product->start_date) . ' to <br/> ' . date("d-M-Y", $value->product->end_date); 
                }
                ?></td>
                <td><a href="/user/<?php echo $value->uid; ?>/orders/<?php echo $value->order_id; ?>"><?php echo $value->product->title; ?></a></td>
                <td><?php if (!empty($user->first_name)): ?><?php echo $user->first_name; ?><?php endif; ?><?php if (!empty($user->last_name)): ?> <?php echo $user->last_name; ?><?php endif; ?></td>
                <td><?php echo $value->status; ?></td>
                <!--<td><a  class="btn btn-primary" href="/user/<?php // echo $value->uid; ?>/orders"> View</a></td>-->
              </tr>
            <?php endforeach; ?>
          <?php endif; ?>

        </table>
      <?php } else { ?>
        <p>You don't have any orders just yet.</p>
      <?php } ?>
		<?php else: ?>
			<div>
				<h3 class="dashboard-header">My Orders</h3>
			</div>
      <?php if (!empty($results->order)) { ?>
        <table class="table order_listing_table my-orders">
          <tr>
            <th class="date">Date</th>
            <th class="title">Training </th>
            <th class="status">Status</th>
            <!--<th> Action</th>-->
          </tr>

          <?php foreach ($results->order as $value) : ?>
            <tr>
              <td><?php 
                if (date("d-M-Y", $value->product->start_date) == date("d-M-Y", $value->product->end_date)) {
                  echo date("d-M-Y", $value->product->start_date);; 
                } else {
                  echo date("d-M-Y", $value->product->start_date) . ' to <br/> ' . date("d-M-Y", $value->product->end_date); 
                }
                ?></td>
              <td><a href="/user/<?php echo $value->uid; ?>/orders/<?php echo $value->order_id; ?>"><?php echo $value->product->title; ?></a></td>
              <td><?php echo $value->status; ?></td>
              <!--<td><a  class="btn btn-primary" href="/user/<?php // echo $value->uid;           ?>/orders"> View</a></td>-->
            </tr>
          <?php endforeach; ?>
        </table>
      <?php } else { ?>
        <p>You don't have any orders just yet.</p>
      <?php }?>
		<?php endif; ?>
	<?php else: ?>
		<!-- added this IF here to not show My Orders if there aren't any orders made -->
		<?php if (!empty($results->order)): ?>
		<div>
			<h3 title="This is where you will see any training you are attending">My Orders</h3>
		</div>

		<table class="table order_listing_table my-orders">
			<tr>
				<th class="date">Date</th>
				<th class="title">Training </th>
				<th class="status">Status</th>
				<!--<th> Action</th>-->
			</tr>

			<?php foreach ($results->order as $value) : ?>
				<tr>
					<td><?php echo date("d-M-Y", $value->product->start_date); ?> to <br/>  <?php echo date("d-M-Y", $value->product->end_date); ?></td>
					<td><a href="/user/<?php echo $value->uid; ?>/orders/<?php echo $value->order_id; ?>"><?php echo $value->product->title; ?></a></td>
					<td><?php echo $value->status; ?></td>
					<!--<td><a  class="btn btn-primary" href="/user/<?php // echo $value->uid;           ?>/orders"> View</a></td>-->
				</tr>
			<?php endforeach; ?>
		</table>
		<?php endif; ?>
	<?php endif; ?>
<?php endif; ?>