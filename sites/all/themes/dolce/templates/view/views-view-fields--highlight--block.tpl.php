<div class="highlight-wrapper col-lg-12 col-sm-12 col-xs-12 col-md-12">
    <?php foreach ($fields as $id => $field): ?>
        <?php if (!empty($field->separator)): ?>
            <?php print $field->separator; ?>
        <?php endif; ?>

        <?php print $field->wrapper_prefix; ?>
        <?php print $field->label_html; ?>
        <?php print $field->content; ?>
        <?php print $field->wrapper_suffix; ?>
    <?php endforeach; ?>
</div>