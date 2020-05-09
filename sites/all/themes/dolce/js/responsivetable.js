(function ($, Drupal, window, document, undefined) {

    Drupal.behaviors.my_custom_behavior = {
        attach: function(context, settings) {


            $('table').not('.commerce-price-formatted-components').cardtable();
        }
    };

})(jQuery, Drupal, this, this.document);