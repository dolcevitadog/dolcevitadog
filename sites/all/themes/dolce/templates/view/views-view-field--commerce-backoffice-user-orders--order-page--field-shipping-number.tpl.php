<?php
 $order_id = $row->order_id;
 $order_uid = $row->commerce_order_uid;
 $shipping_number = $row->field_field_shipping_number['0']['raw']['safe_value'];
?>
<?php if (!empty($shipping_number)): ?>
    <?php if (module_exists('api_laposte')): ?>
        <?php print api_laposte_get_tracking_url($shipping_number, $order_id, $order_uid); ?>
    <?php endif; ?>
<?php endif; ?>