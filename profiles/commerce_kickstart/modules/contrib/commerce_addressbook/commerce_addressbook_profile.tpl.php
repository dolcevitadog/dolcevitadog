<div class="commerce-addressbook-links-wrapper">
    <div class="commerce-addressbook-billing-link-wrapper">
        <?php print $variables['billing-link']; ?>
    </div>
    <div class="commerce-addressbook-shipping-link-wrapper">
        <?php print $variables['shipping-link']; ?>
    </div>
</div>
<h2><?php print $variables['title']; ?></h2>
<div id="commerce-addressbook">
    <div class="commerce-addressbook-links-wrapper">
        <div class="commerce-addressbook-create-link">
            <?php print $variables['create-link']; ?>
    </div>
    <?php if (!empty($variables['empty'])): ?>
        <?php print $variables['empty']; ?>
    <?php else: ?>
        <h3><?php print $variables['title_default']; ?></h3>
        <div class="commerce-addressbook-default">
            <?php print $variables['default_address']; ?>
        </div>
        <?php if (!empty($variables['all_addresses'])): ?>
            <h3><?php print $variables['title_list']; ?></h3>
            <div class="commerce-addressbook-others">
                <?php print $variables['all_addresses']; ?>
            </div>
        <?php endif; ?>
    <?php endif; ?>
</div>