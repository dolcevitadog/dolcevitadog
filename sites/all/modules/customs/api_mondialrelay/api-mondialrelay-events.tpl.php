<div id="mondialrelay-following">
  <?php if (!empty($variables['emptyText'])): ?>
    <?php print $variables['emptyText']; ?>
  <?php else: ?>
    <div class="mondialrelay-header">
      <div class="mondialrelay-product-id">
        <?php print(t('Mondial Relay expedition number')); ?> : <?php print $variables['num_expedition']; ?>
      </div>
      <div class="mondialrelay-relais-wrapper">
        <?php print $variables['renderRelais'];  ?>
      </div>
    </div>
    <?php foreach($variables['events'] as $event): ?>
      <div class="mondialrelay-event">
        <span class="laposte-event-date"><?php print($event['date']); ?></span>
        <span class="laposte-event-text"><?php print($event['text']); ?></span>
      </div>
      <div class="mondialrelay-event-line <?php print $event['class']; ?>"></div>
    <?php endforeach; ?>
  <?php endif; ?>
</div>
