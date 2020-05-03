(function ($) {

  // Increase/decrease quantity
  Drupal.dolce_quantity = function(selector, way, lineStock) {
    // Find out current quantity and figure out new one
    var quantity = parseInt($(selector).val());
    if (way == 1) {
      // Increase
      var new_quantity = quantity+1;
    }
    else if (way == -1) {
      // Decrease
      var new_quantity = quantity-1;
    }
    else {
      var new_quantity = quantity;
    }

    // Set new quantity
      if (lineStock) {
          var maxStock = lineStock;
      }
      else {
          var maxStock = Drupal.settings.dolce_quantity.maxStock;
      }

    if (new_quantity >= 1 && new_quantity <= maxStock) {
      $(selector).val(new_quantity);
    }

    // Set disabled class depending on new quantity
    if (new_quantity <= 1 ) {
      $(selector).prev('span.commerce-quantity-plusminus-link').addClass('commerce-quantity-plusminus-link-disabled');

    }
    else if (new_quantity >= maxStock) {
          $(selector).next('span.commerce-quantity-plusminus-link').addClass('commerce-quantity-plusminus-link-disabled');
        }
    else {
        $(selector).prev('span.commerce-quantity-plusminus-link').removeClass('commerce-quantity-plusminus-link-disabled');
        $(selector).next('span.commerce-quantity-plusminus-link').removeClass('commerce-quantity-plusminus-link-disabled');
    }
      if (new_quantity < 1 ) {
          $("#main-content").after('<div class="alert alert-warning alert-dismissible" role="alert">Impossible de mettre une quantité à 0<button type="button" class="close" data-dismiss="alert" aria-label="Close"> <span aria-hidden="true">&times;</span></button></div>');

    }
      else if (new_quantity > maxStock) {
          $("#main-content").after('<div class="alert alert-warning alert-dismissible" role="alert">Le stock maximal est atteint<button type="button" class="close" data-dismiss="alert" aria-label="Close"> <span aria-hidden="true">&times;</span></button></div>');
      }
  }

}(jQuery));
