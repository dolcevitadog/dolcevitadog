(function ($, Drupal, window, document, undefined) {

    Drupal.behaviors.my_custom_behavior = {
        attach: function(context, settings) {
            if (jQuery().ngResponsiveTables) {
                $('.views-table').once("ngtable", function() {
                    $('.views-table').ngResponsiveTables({
                        smallPaddingCharNo: 13,
                        mediumPaddingCharNo: 18,
                        largePaddingCharNo: 30
                    });
                });
            }
        }
    };

})(jQuery, Drupal, this, this.document);