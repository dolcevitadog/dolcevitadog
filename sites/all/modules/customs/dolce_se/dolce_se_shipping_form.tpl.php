<div id="shipping-form">
    <div class="inside">
        <div class="delivery-date">
            <label>
                <i class="fas fa-shipping-fast"></i>
                <?php print t('Estimated delivery date'); ?>:
            </label>
            <span>
                <?php print $content['delivery_date']; ?>
            </span>
        </div>
      <div class="delivery-date">
        <label>
          <i class="fas fa-broadcast-tower"></i>
          <?php print t('Availability of VOD'); ?>:
        </label>
        <span>
                <?php print t('Immediate'); ?>
            </span>
      </div>
        <?php if (!empty($content['dolce-se-text'])): ?>
            <div class="dolce-se-text">
                <?php print $content['dolce-se-text']; ?>
            </div>
        <?php endif; ?>
    </div>
</div>
