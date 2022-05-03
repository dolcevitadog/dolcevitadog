/**
 * @file
 * Written by Henri MEDOT <henri.medot[AT]absyx[DOT]fr>
 * http://www.absyx.fr
 */

(function($) {
  'use strict';

  // Drupal behavior.
  Drupal.behaviors.commerceMondialrelay = {
    attach: function(context, settings) {
      $('#commerce-mondialrelay-widget', context).once('commerce-mondialrelay', function() {
        $(this).MR_ParcelShopPicker({
          Target: 'input[name="commerce_shipping[service_details][parcelshop_id]"]',
          Brand: settings.commerce_mondialrelay.brand,
          Country: settings.commerce_mondialrelay.country,
          PostCode: settings.commerce_mondialrelay.postal_code,
          OnParcelShopSelected: function(data) {
            $('input[name="commerce_shipping[service_details][parcelshop]"]').val(JSON.stringify(data));
          }
        });
      });
    }
  };

})(jQuery);
