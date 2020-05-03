
(function ($) {

    $(document).ready(function() {
        $("#toggle-information" ).click(function() {
            $( "#informations-inside" ).fadeToggle( "medium", function() {
            });
        });

        $("#checkbox-toggle" ).click(function() {
            $( "#facetapi-filters" ).fadeToggle( "medium", function() {
            });
        });
    });
 })(jQuery);
