<?php

/**
 * @package Tawk.to module for Drupal
 * @copyright (C) 2014- Tawk.to
 * @license GNU/GPLv3 http://www.gnu.org/licenses/gpl-3.0.html
**/

return '<script type="text/javascript" src="'.$baseUrl.'/public/js/jquery-1.11.0.min.js"></script>

<iframe
    id="tawkIframe"
    src=""
    style="min-height: 300px; width : 100%; border: none">
</iframe>

<script type="text/javascript">
    var currentHost = window.location.protocol + "//" + window.location.host;
    var url = "'.$iframeUrl.'&parentDomain=" + currentHost;

    jQuery("#tawkIframe").attr("src", url);

    var iframe = jQuery("#tawk_widget_customization")[0];

    window.addEventListener("message", function(e) {
        if(e.origin === "'. $baseUrl .'") {

            if(e.data.action === "setWidget") {
                setWidget(e);
            }

            if(e.data.action === "removeWidget") {
                removeWidget(e);
            }
        }
    });

    function setWidget(e) {
        jQuery.post("/admin/config/tawk/setwidget", {
            pageId : e.data.pageId,
            widgetId : e.data.widgetId
        }, function(r) {
            e.source.postMessage({action: "setDone"}, "'.$baseUrl.'");
        });
    }

    function removeWidget(e) {
        jQuery.post("/admin/config/tawk/removewidget", function() {
            e.source.postMessage({action: "removeDone"}, "'.$baseUrl.'");
        });
    }
</script>';