<style>
.users_list ul { height:60px; float: left; margin: 20px 35px 20px 15px; }
.users_list ul li { list-style: none; }
</style>

<?php if (!empty($results->members)): ?>
	<div>
		<h3 class="dashboard-header" title="This is where you will see other My PSE subscribers in your company">Company users</h3>
	</div>
	<div class="users_list row">
		<ul class="users_list_ul">
			<?php foreach ($results->members as $key => $member) : ?>
				<?php $profile = fdc_membership_utils_user_profile($member->user_id); ?>
				<?php if (!empty($profile)): ?>
					<li><?php echo $profile->first_name . " " . $profile->last_name; ?></li>
				<?php endif; ?>
			<?php endforeach; ?>
		</ul>
	</div>
<?php endif; ?>


<script>
/* set max height of containers */
var maxHt=50;/* may need to adjust based on css*/

var $list=$('.users_list_ul')
var $container=$list.parent();

var $li=$list.find('li');

var totHt=0;    
var totItems=$li.length;
$li.each(function( idx){

    var ht=$(this).height();
    if( totHt + ht >= maxHt || idx==totItems-1){
        $('<ul>').append( $(this).prevAll().andSelf() ).appendTo( $container );
        totHt=0;
    }else{
        totHt += ht;
    }  

});

$list.remove()

</script>

