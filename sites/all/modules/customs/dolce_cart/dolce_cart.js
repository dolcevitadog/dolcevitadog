
(function ($) {

    $(document).ready(function() {
        $('#edit-quantity').spinner();
        var readmore = Drupal.t('read more');
        var readless = Drupal.t('read less');
        $('.node-product-type .field-name-body .field-item').expander({
            slicePoint: 300,
            expandPrefix: '...<br />',
            expandText: readmore,
            userCollapseText: readless,
            expandEffect: 'fadeIn',
            expandSpeed: 250,
            collapseEffect: 'fadeOut',
            collapseSpeed: 200
        });
    });
 })(jQuery);
