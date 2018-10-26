
(function ($) {

    $( document ).ready(function() {

        $.getScript('//connect.facebook.net/fr_FR/sdk.js', function(){
            FB.init({
                appId: '837855276384036', //replace with your app ID
                version: 'v3.3'
            });
        });

        var facebookShare = function( callback ) {

                var options = {
                    method : 'share',
                    href   : 'https://www.dolcevitadog.com/fr/jeu-concours-halloween3'
                },
            status = '';

        FB.ui(options, function( response ){

            if (response && !response.error_code) {
                status = 'success';
                $.event.trigger('fb-share.success');

            } else {
                status = 'error';
                $.event.trigger('fb-share.error');
            }

            if(callback && typeof callback === "function") {
                callback.call(this, status);
            } else {
                return response;
            }
        });
        }
        console.log("test");
        $('.fb-share').on('click', function( e ) {
            console.log("test");
                e.preventDefault();

                facebookShare(function( response ) {
                    // simple function callback
                    console.log(response);
                });
        });
    });

    $(document)
        .on('fb-share.success', function( e ) {
            console.log('success events');
        })
        .on('fb-share.error', function( e ) {
            console.log('error events');
        });

})(jQuery);