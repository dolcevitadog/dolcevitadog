<div id="laposte-following">
    <?php if (!empty($variables['emptyText'])): ?>
        <?php print $variables['emptyText']; ?>
    <?php else: ?>
        <div class="laposte-header">
            <div class="laposte-product-type">
                <?php print(t('Type of package')); ?> : <?php print $variables['product_type']; ?>
            </div>
            <div class="laposte-product-id">
                <?php print(t('Following number')); ?> : <?php print $variables['tracking_id']; ?>
            </div>
        </div>
        <?php foreach($variables['events'] as $event): ?>
            <div class="laposte-event">
                <span class="laposte-event-date"><?php print($event['date']); ?></span>
                <span class="laposte-event-text"><?php print($event['text']); ?></span>
                <img class="img-responsive" src="/<?php print($event['imageUrl']); ?>" />
            </div>
            <div class="laposte-event-line <?php print $event['class']; ?>"></div>
        <?php endforeach; ?>
    <?php endif; ?>
</div>