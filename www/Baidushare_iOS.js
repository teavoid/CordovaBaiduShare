

    var cordovaRef = window.PhoneGap || window.Cordova || window.cordova;

    function success () {
        console.log("Baidushare failure: success callback parameter must be a function");
    }

    function fail () {
        console.log("Baidushare failure: failure parameter not a function");
    }
    var Baidushare = {

        bdshare:function(success,fail,title,content,url,imageurl) {
            cordovaRef.exec(success, fail, "Baidushare", "bdshare", [title,content,url,imageurl]);
        }
    };
    if(!window.plugins) {
        window.plugins = {};
    }
    if (!window.plugins.Baidushare) {
        window.plugins.Baidushare = new Baidushare();
    }

