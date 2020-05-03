<?php

/**
 * @param $id : Shippment ID
 * @return object : Data returned by the WS
 * Appel au WS de LaPoste
 */
function api_laposte_call_ws($id) {
    //On recupere la cle OKAPI (prod ou sandbox)
    $key = api_laposte_get_key();
    $response = exec('curl https://api.laposte.fr/suivi/v2/idships/'.$id.' -H "Accept: application/json" -H "X-Okapi-Key: '.$key.'"');
    $data = json_decode($response);
    return $data;
}

/**
 * @return String : Get API Key depending of the state of the application (sandbox or production)
 */
function api_laposte_get_key() {
    $status = variable_get('api_laposte_status', 'sandbox');
    switch ($status) {
        case 'production':
            $key = variable_get('api_laposte_x_okapi_production_key');
            break;
        case 'sandbox':
            $key = variable_get('api_laposte_x_okapi_sandbox_key');
            break;
        default:
    }
    return $key;
}

/**
 * @param $id : Number tracking id
 * @return bool : Check if the delivery is complete
 */
function api_laposte_delivery_complete($id) {
    $response = api_laposte_call_ws($id);
    if (api_laposte_get_returnCode($response) == 200) {
        if ($response->shipment->isFinal == TRUE) {
            return TRUE;
        } else {
            return FALSE;
        }
    }
    return FALSE;
}

/**
 * @param $response
 * @return : country Code or NULL
 * Fonction tres moche, en attente mail laposte concernant l'API
 */
function api_laposte_get_country_arrival($response) {
    $returnCode = api_laposte_get_returnCode($response);
    if ($returnCode == '200') {
        $timeline = $response->shipment->timeline;
        foreach ($timeline as $event) {
            if (!empty($event->country)) {
                $country = $event->country;
            }
        }
        return $country;
    }
    return NULL;
}

/**
 * @param $response
 * @return mixed : Retourne le type de produit LaPoste utilisé (lettre, colis, ...)
 */
function api_laposte_get_product_type($response) {
    return $response->shipment->product;
}

/**
 * @param $response
 * @return mixed : Return Code from the WS
 */
function api_laposte_get_returnCode($response) {
    return $response->returnCode;
}

/**
 * @param $response
 * @return mixed : Return all the events about a package
 */
function api_laposte_get_events($response) {
    return $response->shipment->event;
}

/* Retrieve Laposte Status
 * Array Code and Status Type
 */
function api_laposte_get_status() {
    return array(
        'DR1' => 1,
        'PC1' => 2,
        'PC2' => 2,
        'ET1' => 3,
        'ET2' => 3,
        'ET3' => 3,
        'ET4' => 3,
        'EP1' => 3,
        'DO1' => 3,
        'DO2' => 3,
        'DO3' => 3,
        'PB1' => 3,
        'PB2' => 3,
        'MD2' => 4,
        'ND1' => 4,
        'AG1' => 4,
        'RE1' => 4,
        'DI1' => 5,
        'DI2' => 5,
    );
}