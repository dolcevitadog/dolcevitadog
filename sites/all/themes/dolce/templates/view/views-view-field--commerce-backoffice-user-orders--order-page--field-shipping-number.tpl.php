<?php
 $order_id = $row->order_id;
 $order_uid = $row->commerce_order_uid;
 $order = commerce_order_load($order_id);
 $type = api_shipment_get_shipment_type($row);
 $shipping_number = $row->field_field_shipping_number['0']['raw']['safe_value'];
?>
<?php if (!empty($shipping_number)): ?>
    <?php if (module_exists('api_laposte')): ?>
        <?php print api_shipment_get_tracking_url($type, $order_id, $order_uid, $shipping_number); ?>
    <?php endif; ?>
<?php endif; ?>
