<div id="dolce-cart">
    <a href="/cart">
        <span class="dolce-cart-bg"></span>
        <?php if ($cart['quantity']): ?>
         <span class="dolce-cart-quantity"><?php print $cart['quantity'];?></span>
        <?php endif; ?>
        <?php if ($cart['price']): ?>
            <span class="dolce-cart-price hidden-xs"><?php print $cart['price']; ?></span>
        <?php endif; ?>
        <span class="dolce-cart-label nomobile hidden-xs"><?php print t('My cart'); ?></span>
    </a>
</div>