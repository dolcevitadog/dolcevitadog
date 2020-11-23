(function ($) {
    /**
     * Load remote content after the main page loaded.
     */

    Drupal.behaviors.dolce_checkout = {
        'attach': function(context) {
            $('#edit-checkout', context)
                .addClass('dolce-checkout-processed')
                .bind('click', function(event) {
                    $.get('/ajax/remote-dolce-checkout', function( data ) {
                        if (data.exist == false) {
                            modal = $('#dolce-checkout').modal({show:true});
                            $('#edit-checkout').unbind('click');
                        }
                        else {
                            $('#edit-checkout').unbind('click');
                        }
                    });
                    return false;
                });
            if ($('#dolce-checkout').length == false) {
                $('#edit-checkout').unbind('click');
            }
        }
    }
})(jQuery);