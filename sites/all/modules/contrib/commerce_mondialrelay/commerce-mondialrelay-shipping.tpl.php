<?php

/**
 * @file
 * Theme implementation to display shipping information.
 */
?>
<div class="field field-name-commerce-customer-shipping<?php print $field_label ? ' field-label-above' : ' field-label-hidden'; ?>">

  <?php if ($field_label): ?>
    <div class="field-label"><?php print $field_label; ?></div>
  <?php endif; ?>

  <div class="field-items"><div class="field-item even">
    <?php print t('Customer detail : '); ?>
    <div><?php print $profile; ?></div>
    <hr />
    <?php print t('Mondial Relay detail : '); ?>
    <div><?php print $parcelshop_name_and_id; ?></div>
    <div><?php print check_plain($parcelshop['Adresse1']); ?></div>
    <?php if (strlen($parcelshop['Adresse2'])): ?>
      <div><?php print check_plain($parcelshop['Adresse2']); ?></div>
    <?php endif; ?>
    <div><?php print check_plain($parcelshop['CP']); ?> <?php print check_plain($parcelshop['Ville']); ?></div>
    <div><?php print $parcelshop_country; ?></div>
  </div></div>

</div>
