<?php

/**
 * @file
 * Template for invoiced orders.
 */
?>
<style type="text/css">
    p {
        color: #26b72b;
    }
</style>
<div class="invoice-invoiced">
    <div class="header">
        <img src="<?php print $content['invoice_logo']['#value']; ?>"/>
        <div class="invoice-header">
            <p><?php print render($content['invoice_header']); ?></p>
        </div>
    </div>
    <div class="customer"><?php print render($content['commerce_customer_billing']); ?></div>
    <div class="invoice-informations-bill">
        <div class="order-date"><span class="header-label"><?php print t('Order date:'); ?></span><span class="header-field"><?php print render($content['created_date']); ?></span></div>
        <?php if ($content['in_delivery_date']): ?>
        <div class="delivery-date"><span class="header-label"><?php print t('In delivery date:'); ?></span><span class="header-field"><?php print render($content['in_delivery_date']); ?></span></div>
        <?php endif; ?>
        <div class="invoice-date"><span class="header-label"><?php print t('Billing date:'); ?></span><span class="header-field"><?php print render($content['invoice_header_date']); ?></span></div>
        <div class="invoice-number-two"><span class="header-label"><?php print t('Invoice No.:'); ?></span><span class="header-field"><?php print render($content['order_number']); ?></span></div>
        <div class="order-id-number"><span class="header-label"><?php print t('Order No.:'); ?></span><span class="header-field"><?php print render($content['order_id']); ?></span></div>
    </div>
    <h2><?php print t('Bill'); ?></h2>
    <div class="line-items">
        <div class="line-items-view"><?php print render($content['commerce_line_items']); ?></div>
    </div>
    <div class="order-total"><?php print render($content['commerce_order_total']); ?></div>
    <div class="invoice-text"><?php print render($content['invoice_text']); ?></div>
    <div class="invoice-footer"><?php print render($content['invoice_footer']); ?></div>
</div>
