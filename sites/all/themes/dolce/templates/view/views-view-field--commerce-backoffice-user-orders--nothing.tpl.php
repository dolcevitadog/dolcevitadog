<?php if (!empty($row->field_field_shipping_number['0']['raw']['safe_value'])): ?>
    <?php if (module_exists('api_laposte')): ?>
        <?php print api_laposte_get_info($row->field_field_shipping_number['0']['raw']['safe_value'], 'message'); ?>
    <?php endif; ?>
<?php endif; ?>