<!DOCTYPE html>
<html style="--font-family-text: OpenSans, Arial, Helvetica, sans-serif; --font-family-input: SourceCodePro, monaco, Courier, monospace;" lang="en-us"><head>
<meta http-equiv="content-type" content="text/html; charset=UTF-8">
  <meta charset="utf-8">
  
  
        
        
        
        
      
  <script src="h2_files/mixpanel-2-latest.js" async="" type="text/javascript"></script><script src="h2_files/ga.js" async="" type="text/javascript"></script><script>/*!
 * JavaScript Cookie v2.1.3
 * https://github.com/js-cookie/js-cookie
 *
 * Copyright 2006, 2015 Klaus Hartl & Fagner Brack
 * Released under the MIT license
 */
;(function (factory) {
	var registeredInModuleLoader = false;
	if (typeof define === 'function' && define.amd) {
		define(factory);
		registeredInModuleLoader = true;
	}
	if (typeof exports === 'object') {
		module.exports = factory();
		registeredInModuleLoader = true;
	}
	if (!registeredInModuleLoader) {
		var OldCookies = window.Cookies;
		var api = window.Cookies = factory();
		api.noConflict = function () {
			window.Cookies = OldCookies;
			return api;
		};
	}
}(function () {
	function extend () {
		var i = 0;
		var result = {};
		for (; i < arguments.length; i++) {
			var attributes = arguments[ i ];
			for (var key in attributes) {
				result[key] = attributes[key];
			}
		}
		return result;
	}

	function init (converter) {
		function api (key, value, attributes) {
			var result;
			if (typeof document === 'undefined') {
				return;
			}

			// Write

			if (arguments.length > 1) {
				attributes = extend({
					path: '/'
				}, api.defaults, attributes);

				if (typeof attributes.expires === 'number') {
					var expires = new Date();
					expires.setMilliseconds(expires.getMilliseconds() + attributes.expires * 864e+5);
					attributes.expires = expires;
				}

				try {
					result = JSON.stringify(value);
					if (/^[\{\[]/.test(result)) {
						value = result;
					}
				} catch (e) {}

				if (!converter.write) {
					value = encodeURIComponent(String(value))
						.replace(/%(23|24|26|2B|3A|3C|3E|3D|2F|3F|40|5B|5D|5E|60|7B|7D|7C)/g, decodeURIComponent);
				} else {
					value = converter.write(value, key);
				}

				key = encodeURIComponent(String(key));
				key = key.replace(/%(23|24|26|2B|5E|60|7C)/g, decodeURIComponent);
				key = key.replace(/[\(\)]/g, escape);

				return (document.cookie = [
					key, '=', value,
					attributes.expires ? '; expires=' + attributes.expires.toUTCString() : '', // use expires attribute, max-age is not supported by IE
					attributes.path ? '; path=' + attributes.path : '',
					attributes.domain ? '; domain=' + attributes.domain : '',
					attributes.secure ? '; secure' : ''
				].join(''));
			}

			// Read

			if (!key) {
				result = {};
			}

			// To prevent the for loop in the first place assign an empty array
			// in case there are no cookies at all. Also prevents odd result when
			// calling "get()"
			var cookies = document.cookie ? document.cookie.split('; ') : [];
			var rdecode = /(%[0-9A-Z]{2})+/g;
			var i = 0;

			for (; i < cookies.length; i++) {
				var parts = cookies[i].split('=');
				var cookie = parts.slice(1).join('=');

				if (cookie.charAt(0) === '"') {
					cookie = cookie.slice(1, -1);
				}

				try {
					var name = parts[0].replace(rdecode, decodeURIComponent);
					cookie = converter.read ?
						converter.read(cookie, name) : converter(cookie, name) ||
						cookie.replace(rdecode, decodeURIComponent);

					if (this.json) {
						try {
							cookie = JSON.parse(cookie);
						} catch (e) {}
					}

					if (key === name) {
						result = cookie;
						break;
					}

					if (!key) {
						result[name] = cookie;
					}
				} catch (e) {}
			}

			return result;
		}

		api.set = api;
		api.get = function (key) {
			return api.call(api, key);
		};
		api.getJSON = function () {
			return api.apply({
				json: true
			}, [].slice.call(arguments));
		};
		api.defaults = {};

		api.remove = function (key, attributes) {
			api(key, '', extend(attributes, {
				expires: -1
			}));
		};

		api.withConverter = init;

		return api;
	}

	return init(function () {});
}));
</script>
  <style>
  .cdn-error-view {
    position: fixed;
    width: 100%;
    height: 100%;
    top: 0;
    left: 0;
    background: white;
    z-index: 9999;
    font-family: "Whitney SSm A", "Whitney SSm B", "Avenir", "Segoe UI", "Ubuntu", "Helvetica Neue", Helvetica, Arial, sans-serif;
  }

  .cdn-error-view .error-box-wrap {
    position: absolute;
    top: 50%;
    left: 50%;
    padding: 20px;
    transform: translate(-50%, -50%);
    -ms-transform: translate(-50%, -50%);
    -webkit-transform: translate(-50%, -50%);
    text-align: center;
  }
  .cdn-error-view .error-icon {
    text-align: center;
  }
  .cdn-error-view .error-title {
    font-size: 48px;
    margin-top: 30px;
    margin-bottom: 0;
    font-weight: bold;
  }
  .cdn-error-view .error-message {
    margin-top: 20px;
    margin-bottom: 0;
  }
  .cdn-error-view .btn-wrap {
    margin-top: 20px;
  }
  .cdn-error-view .btn-reload {
    width: 300px;
    padding: 10px;
    border-radius: 3px;
    border-color: #088837;
    border-bottom-color: #007827;
    border-width: 1px;
    border-style: solid;
    color : #FFF;
    background-color: #2ec866;
    background-image: -webkit-gradient(linear, top left, bottom left, color-stop(0, #2ec866), color-stop(1, #29b35b));
    background-image: -webkit-linear-gradient(top, #2ec866, #29b35b);
    background-image: linear-gradient(top, #2ec866, #29b35b);
    box-shadow: 0 1px 3px rgba(0, 0, 0, 0.2), inset 0 1px 1px rgba(255, 255, 255, 0.1), inset 0 -1px 4px rgba(32, 138, 70, 0.3);
    outline: none;
  }
</style>


<script>
  var cdnLoaded = false;

  var checkForWorkingCDN = (function() {
    //this two value should come from configuration
    var cdns = ["hrcdn.net","d3keuzeb2crhkn.cloudfront.net"];
    var cdnUrl = Cookies.get('cdn_url') || cdns[0];
    var filePath = "https://hrcdn.net/hackerrank/assets/cdnping-e4dfec54a83d6e6bc9baf3ce741ae25e.js";

    //extract pathname from url
    var urlRegex = /^[^#]*?:\/\/.*?(\/.*)$/ ;
    var match = filePath.match(urlRegex);
    if(match) filePath = match[1];

    //add current cdn on first of array
    cdns.splice(cdns.indexOf(cdnUrl), 1);
    cdns.unshift(cdnUrl);

    var cdnIndx = 0;

    function tryCurrentCDN() {
      if (cdnUrl) document.write('<script src="https://' + cdnUrl + filePath + '?' + Date.now() + '"><\/script>');
      document.write('<script>checkForWorkingCDN();<\/script>');
    }

    //try the current cdn
    tryCurrentCDN();

    return function() {
      if (cdnUrl && cdnLoaded) {
        Cookies.set('cdn_url', cdnUrl, {expires: 3});
        Cookies.set('cdn_set', 'true', {expires: 3});
        if (cdnIndx !== 0) {
          document.location.reload();
        }

        //if cdnUrl not loaded check the next cdn;
      } else if (cdnUrl) {
        //track all the failed cdn
        var failedCdns = Cookies.get('failed_cdn_hosts');
        if (failedCdns) {
          failedCdns = JSON.parse(failedCdns);
        } else {
          failedCdns = [];
        }

        failedCdns.push(cdnUrl);
        var fifteenMinuteFromNow = new Date();
        fifteenMinuteFromNow.setMinutes(15);
        Cookies.set('failed_cdn_hosts', JSON.stringify(failedCdns), {expires: fifteenMinuteFromNow});
        Cookies.set("cdn_url_switched", "true", {expires: fifteenMinuteFromNow});

        //try next cdn
        cdnIndx += 1;
        cdnUrl = cdns[cdnIndx];
        tryCurrentCDN();

        //if no cdn left to check and none of loaded return err
      } else {
        Cookies.remove('cdn_url');
        return 'cdnerror';
      }
    }
  }());
</script><script src="h2_files/cdnping-e4dfec54a83d6e6bc9baf3ce741ae25e.js"></script><script>checkForWorkingCDN();</script>

<script>
  //track cdn related matrices
  (function() {
    var allCdns = ["hrcdn.net","d3keuzeb2crhkn.cloudfront.net"];

    var metrics = [];
    var defaultCdn = Cookies.get('default_cdn_url');

    //method to track the events
    function appTrack(key, attrs) {
      attrs = attrs || {};
      attrs.uid = Cookies.get('hackerrank_mixpanel_token')
      metrics.push({
        'key': key,
        'meta_data': attrs
      });
    }

    function sendMetrices() {
      if (!XMLHttpRequest) return;
      var xhr = new XMLHttpRequest();
      var metrics_endpoint = 'https://metrics.hackerrank.com/app_metrics'; // Todo : this need to move on configuration

      if (!xhr) return;

      xhr.open("POST", metrics_endpoint, true);

      //set xhr headers and options
      xhr.setRequestHeader('Content-Type', 'application/json');
      xhr.withCredentials = true;

      xhr.send(JSON.stringify({
        data: metrics,
        default_cdn_url: defaultCdn,
        document_referrer: document.referrer
      }));
    }

    var cdnUrl = Cookies.get('cdn_url');
    var failedCdns = Cookies.get('failed_cdn_hosts');

    var cdnMetrices = {};

    //track used cdn host
    if (cdnUrl) {
      cdnMetrices['used-cdn'] = cdnUrl;
      cdnMetrices['cdn-index'] = allCdns.indexOf(cdnUrl) + 1;
      cdnMetrices['all-failed'] = false;
    //track if all cdn failed (If cdnUrl is not set it means all cdn url failed)
    } else {
      cdnMetrices['used-cdn'] = '';
      cdnMetrices['cdn-index'] = 999;
      cdnMetrices['all-failed'] = true;
    }

    appTrack('cdn-metrices', cdnMetrices);

    //track failed cdn
    if (failedCdns) {
      failedCdns = JSON.parse(failedCdns);
      Cookies.remove('failed_cdn_hosts');
      failedCdns.forEach(function(cdn) {
        appTrack('failed-cdn-host', {
          cdn: cdn
        });
      });
    }

    //send metrics
    sendMetrices();

  }());
</script>


  

  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="icon" type="image/png" href="https://hrcdn.net/hackerrank/assets/favicon-95dc36c7e91ed5f1841649303c027edb.png">

  <!-- Prefetch dns on production -->
  
    <link rel="dns-prefetch" href="https://hrcdn.net/">
    <link rel="dns-prefetch" href="https://d3keuzeb2crhkn.cloudfront.net/">
    <link rel="dns-prefetch" href="https://notifications.hackerrank.com/">
    <link rel="dns-prefetch" href="https://api.mixpanel.com/">
    <link rel="dns-prefetch" href="https://metrics.hackerrank.com/">
    <link rel="preconnect" href="https://sentry.io/">
    <link rel="dns-prefetch" href="https://sentry.io/">
  

  
    <link href="h2_files/hackerrank_libraries-21fce5f00a5704ab97ea6e29f618ca7f.css" media="all" rel="stylesheet"><link href="h2_files/hackerrank_libraries-21fce5f00a5704ab97ea6e29f618ca7f.css" rel="stylesheet">

    <link href="h2_files/hackerrank-core-f0b52f49b01ade8d9b872d1734792f3f.css" media="all" rel="stylesheet">

    
      <link href="h2_files/dashboard-e26d916d8859b521a068330828d9578e.css" media="all" rel="stylesheet">
    
  


  

  <link rel="stylesheet" type="text/css" href="h2_files/hackerrank_r_app-088f0c165949d9236d27.css">
  
    <link rel="stylesheet" type="text/css" href="h2_files/vendorshackerrank_r_communityhackerrank_r_work-9aab4d2fe33fc.css">
  
    <link rel="stylesheet" type="text/css" href="h2_files/vendorshackerrank_r_community-91f95c40be0457f91736.css">
  
    <link rel="stylesheet" type="text/css" href="h2_files/hackerrank_r_community-79917fcc15243bffeb0f.css">
  
    <link rel="stylesheet" type="text/css" href="h2_files/vendorshackerrank_r_challengehackerrank_r_leaderboardv2-8c51.css">
  
    <link rel="stylesheet" type="text/css" href="h2_files/vendorshackerrank_r_challenge-fa2f3f4121bc97487f0d.css">
  
    <link rel="stylesheet" type="text/css" href="h2_files/hackerrank_r_challengehackerrank_r_code_snippetshackerrank_r.css">
  
    <link rel="stylesheet" type="text/css" href="h2_files/hackerrank_r_challenge-53a881b6e1a89a0e9af4.css">
  
    <link rel="stylesheet" type="text/css" href="h2_files/hackerrank_r_code_snippetshackerrank_r_forum-3edc913aa15d51d.css">
  
    <link rel="stylesheet" type="text/css" href="h2_files/hackerrank_r_forum-09cb81cea09b82387941.css">
  

  <!-- Prefetch / preload assets on production -->
  

    <!-- Prefetch old assets -->
    
      <link rel="prefetch" href="https://hrcdn.net/hackerrank/assets/hackerrank-29975682f302f0fbbdae252d97e4788d.js">
    
      <link rel="prefetch" href="https://hrcdn.net/hackerrank/assets/base-4e953f9582ddc0e62ee5b02dbe2520ca.js">
    
      <link rel="prefetch" href="https://hrcdn.net/hackerrank/assets/hackerrank_libraries-ee40391d20d8d00f36e1a0af1ee56beb.js">
    
    <!-- Prefetch old assets end-->

    <!-- preload scripts required on the same page -->
    <link rel="preload" as="script" href="h2_files/hackerrank_r_vendor-5bc167c024.js">
    <link rel="preload" as="script" href="h2_files/hackerrank_r_app-088f0c165949d9236d27.js">
    <link rel="preload" as="script" href="h2_files/runtime-bc150ed6206fab6e52b2.js">

    
      <link rel="preload" as="script" href="h2_files/vendorshackerrank_r_communityhackerrank_r_work-9aab4d2fe33fc3.js">
    
      <link rel="preload" as="script" href="h2_files/vendorshackerrank_r_community-91f95c40be0457f91736.js">
    
      <link rel="preload" as="script" href="h2_files/hackerrank_r_community-79917fcc15243bffeb0f.js">
    
      <link rel="preload" as="script" href="h2_files/hackerrank_r_challengehackerrank_r_code_snippetshackerrank_r_.js">
    
      <link rel="preload" as="script" href="h2_files/vendorshackerrank_r_challengehackerrank_r_leaderboardv2-8c51f.js">
    
      <link rel="preload" as="script" href="h2_files/vendorshackerrank_r_challengehackerrank_r_onboarding-e1d4d842.js">
    
      <link rel="preload" as="script" href="h2_files/vendorshackerrank_r_challenge-fa2f3f4121bc97487f0d.js">
    
      <link rel="preload" as="script" href="h2_files/hackerrank_r_challenge-53a881b6e1a89a0e9af4.js">
    
      <link rel="preload" as="script" href="h2_files/vendorshackerrank_r_code_snippetshackerrank_r_forumlsp_client.js">
    
      <link rel="preload" as="script" href="h2_files/hackerrank_r_code_snippetshackerrank_r_forum-3edc913aa15d51db.js">
    
      <link rel="preload" as="script" href="h2_files/vendorshackerrank_r_code_snippetshackerrank_r_forum-6f7c92c59.js">
    
      <link rel="preload" as="script" href="h2_files/hackerrank_r_forum-09cb81cea09b82387941.js">
    
    <!-- preload scripts end -->

    <!-- Prefetch old css files -->
    <link rel="prefetch" href="h2_files/hackerrank-core-f0b52f49b01ade8d9b872d1734792f3f.css">
    <link rel="prefetch" href="h2_files/hackerrank_libraries-21fce5f00a5704ab97ea6e29f618ca7f.css">

    
      <link rel="prefetch" href="h2_files/dashboard-e26d916d8859b521a068330828d9578e.css">
    
    <!-- Prefetch old css files end -->
  
  

  <!-- Load promise polyfill for the non-believers -->
  <script>
    window.Promise || document.write('<script src="https://hrcdn.net/hackerrank/assets/promise-polyfill/promise.min-9b7934fab083223fac8be5ee5ae0b68d.js" type="text\/javascript"><\/script>');
  </script>

<script src="h2_files/vendorshackerrank_r_communityhackerrank_r_work-9aab4d2fe33fc3.js" charset="utf-8"></script><script src="h2_files/vendorshackerrank_r_community-91f95c40be0457f91736.js" charset="utf-8"></script><script src="h2_files/hackerrank_r_community-79917fcc15243bffeb0f.js" charset="utf-8"></script><link rel="prefetch" href="https://hrcdn.net/hackerrank/assets/hackerrank_r_challenge_list_v2-bcd262a13f4cb9aad94e.js"><link rel="prefetch" href="https://hrcdn.net/hackerrank/assets/hackerrank_r_challenge_list-d10db3038004d275b491.js"><link rel="prefetch" href="https://hrcdn.net/hackerrank/assets/hackerrank_r_leaderboardv2-f1c0cb0eb000428f82df.js"><link rel="prefetch" href="https://hrcdn.net/hackerrank/assets/hackerrank_r_challengev2-df9a71d3de9b750a93a9.js"><link rel="prefetch" href="https://hrcdn.net/hackerrank/assets/hackerrank_r_contest-3291f63f1eb3ddf8e643.js"><link rel="prefetch" href="https://hrcdn.net/hackerrank/assets/hackerrank_r_dashboardv2-f4870e92b5527c9f9f81.js"><link rel="prefetch" href="https://hrcdn.net/hackerrank/assets/hackerrank_r_rank-4b66b0e972f3325be84b.js"><link rel="prefetch" href="https://hrcdn.net/hackerrank/assets/hackerrank_r_leaderboard-1c6209365c78c05bcfd5.js">
        <style>
          html.scroll-hidden,html.scroll-hidden body{
              overflow: hidden;
              height:100vh;
          }
          html.scroll-hidden.pad-adjustment body{
              padding-right : 17px;
          }
          html.scroll-hidden.pad-adjustment .fixed-elm{
              padding-right : 17px;
          }
        </style>
    <link rel="prefetch" href="https://hrcdn.net/hackerrank/assets/hackerrank_r_company_header-636b102e73487d1540e0.js"><link rel="prefetch" href="https://hrcdn.net/hackerrank/assets/hackerrank_r_jobs-36bf3c8efa4179d4b463.js"><link rel="prefetch" href="https://hrcdn.net/hackerrank/assets/hackerrank_r_profile-77f7254877a5e9418c00.js"><link rel="prefetch" href="https://hrcdn.net/hackerrank/assets/hackerrank_r_calendar-39e0123fafa71c174852.js"><link rel="prefetch" href="https://hrcdn.net/hackerrank/assets/hackerrank_r_code_snippets-6cbf97a378c7c18bfe6f.js"><link rel="prefetch" href="https://hrcdn.net/hackerrank/assets/hackerrank_r_onboarding-efcba62fbbd14c48fc8d.js"><link rel="prefetch" href="https://hrcdn.net/hackerrank/assets/hackerrank_r_scoring-6271c45ea69fe147bc7a.js"><link rel="prefetch" href="https://hrcdn.net/hackerrank/assets/hackerrank_r_interview-53b3666e7dcad615f75b.js"><script src="h2_files/vendorshackerrank_r_challengehackerrank_r_onboarding-e1d4d842.js" charset="utf-8"></script><script src="h2_files/vendorshackerrank_r_challengehackerrank_r_leaderboardv2-8c51f.js" charset="utf-8"></script><script src="h2_files/vendorshackerrank_r_challenge-fa2f3f4121bc97487f0d.js" charset="utf-8"></script><script src="h2_files/hackerrank_r_challengehackerrank_r_code_snippetshackerrank_r_.js" charset="utf-8"></script><script src="h2_files/hackerrank_r_challenge-53a881b6e1a89a0e9af4.js" charset="utf-8"></script><link rel="prefetch" href="h2_files/hackerrank_r_codeshell_lib-d4842419f71f863c0455.js"><link rel="prefetch" href="h2_files/codeshell_editor_theme_m-4d369be9eed481523d5e.js"><link rel="prefetch" href="h2_files/codeshell_editor_theme_m-4d369be9eed481523d5e.css"><link rel="prefetch" href="h2_files/hackerrank_r_krackjack-cf5f7a0a567cedb6a3a6.js"><script src="h2_files/vendorshackerrank_r_code_snippetshackerrank_r_forumlsp_client.js" charset="utf-8"></script><script src="h2_files/vendorshackerrank_r_code_snippetshackerrank_r_forum-6f7c92c59.js" charset="utf-8"></script><script src="h2_files/hackerrank_r_code_snippetshackerrank_r_forum-3edc913aa15d51db.js" charset="utf-8"></script><script src="h2_files/hackerrank_r_forum-09cb81cea09b82387941.js" charset="utf-8"></script><link href="h2_files/font-awesome.css" rel="stylesheet"><meta content="input character, string and a sentence" id="meta-description" name="description"><meta content="https://hrcdn.net/og/default.jpg" id="meta-og-image" property="og:image"><meta content="HackerRank" id="meta-og-site" property="og:site_name"><meta content="website" id="meta-og-type" property="og:type"><meta content="https://www.facebook.com/hackerrank" property="article:author"><meta content="summary" id="meta-twitter-card" name="twitter:card"><meta content="@hackerrank" id="meta-twitter-site" name="twitter:site"><meta content="Playing With Characters | HackerRank" id="meta-twitter-title" name="twitter:title"><meta content="347499128655783" id="meta-fb-id" property="fb:app_id"><meta id="csrf-param" name="csrf-param" content="authenticity_token"><meta id="csrf-token" name="csrf-token" content="8FjvXSUUUeUy8dpwjyLfbPMC54eQz0yDUjGRPapWk7/O2oGGRrSg2bYiZM37+r7kyeeaTHhVwi/VuNE4AXiBew=="><link href="h2_files/vendorshackerrank_r_krackjack-3461f827ca7fde557909.css" type="text/css" rel="stylesheet"><script src="h2_files/vendorshackerrank_r_krackjack-3461f827ca7fde557909.js" charset="utf-8"></script><script src="h2_files/hackerrank_r_krackjack-cf5f7a0a567cedb6a3a6.js" charset="utf-8"></script><style id="react-tooltip">.__react_component_tooltip{border-radius:3px;display:inline-block;font-size:13px;left:-999em;opacity:0;padding:8px 21px;position:fixed;pointer-events:none;transition:opacity 0.3s ease-out;top:-999em;visibility:hidden;z-index:999}.__react_component_tooltip:before,.__react_component_tooltip:after{content:"";width:0;height:0;position:absolute}.__react_component_tooltip.show{opacity:0.9;margin-top:0px;margin-left:0px;visibility:visible}.__react_component_tooltip.type-dark{color:#fff;background-color:#222}.__react_component_tooltip.type-dark.place-top:after{border-top-color:#222;border-top-style:solid;border-top-width:6px}.__react_component_tooltip.type-dark.place-bottom:after{border-bottom-color:#222;border-bottom-style:solid;border-bottom-width:6px}.__react_component_tooltip.type-dark.place-left:after{border-left-color:#222;border-left-style:solid;border-left-width:6px}.__react_component_tooltip.type-dark.place-right:after{border-right-color:#222;border-right-style:solid;border-right-width:6px}.__react_component_tooltip.type-dark.border{border:1px solid #fff}.__react_component_tooltip.type-dark.border.place-top:before{border-top:8px solid #fff}.__react_component_tooltip.type-dark.border.place-bottom:before{border-bottom:8px solid #fff}.__react_component_tooltip.type-dark.border.place-left:before{border-left:8px solid #fff}.__react_component_tooltip.type-dark.border.place-right:before{border-right:8px solid #fff}.__react_component_tooltip.type-success{color:#fff;background-color:#8DC572}.__react_component_tooltip.type-success.place-top:after{border-top-color:#8DC572;border-top-style:solid;border-top-width:6px}.__react_component_tooltip.type-success.place-bottom:after{border-bottom-color:#8DC572;border-bottom-style:solid;border-bottom-width:6px}.__react_component_tooltip.type-success.place-left:after{border-left-color:#8DC572;border-left-style:solid;border-left-width:6px}.__react_component_tooltip.type-success.place-right:after{border-right-color:#8DC572;border-right-style:solid;border-right-width:6px}.__react_component_tooltip.type-success.border{border:1px solid #fff}.__react_component_tooltip.type-success.border.place-top:before{border-top:8px solid #fff}.__react_component_tooltip.type-success.border.place-bottom:before{border-bottom:8px solid #fff}.__react_component_tooltip.type-success.border.place-left:before{border-left:8px solid #fff}.__react_component_tooltip.type-success.border.place-right:before{border-right:8px solid #fff}.__react_component_tooltip.type-warning{color:#fff;background-color:#F0AD4E}.__react_component_tooltip.type-warning.place-top:after{border-top-color:#F0AD4E;border-top-style:solid;border-top-width:6px}.__react_component_tooltip.type-warning.place-bottom:after{border-bottom-color:#F0AD4E;border-bottom-style:solid;border-bottom-width:6px}.__react_component_tooltip.type-warning.place-left:after{border-left-color:#F0AD4E;border-left-style:solid;border-left-width:6px}.__react_component_tooltip.type-warning.place-right:after{border-right-color:#F0AD4E;border-right-style:solid;border-right-width:6px}.__react_component_tooltip.type-warning.border{border:1px solid #fff}.__react_component_tooltip.type-warning.border.place-top:before{border-top:8px solid #fff}.__react_component_tooltip.type-warning.border.place-bottom:before{border-bottom:8px solid #fff}.__react_component_tooltip.type-warning.border.place-left:before{border-left:8px solid #fff}.__react_component_tooltip.type-warning.border.place-right:before{border-right:8px solid #fff}.__react_component_tooltip.type-error{color:#fff;background-color:#BE6464}.__react_component_tooltip.type-error.place-top:after{border-top-color:#BE6464;border-top-style:solid;border-top-width:6px}.__react_component_tooltip.type-error.place-bottom:after{border-bottom-color:#BE6464;border-bottom-style:solid;border-bottom-width:6px}.__react_component_tooltip.type-error.place-left:after{border-left-color:#BE6464;border-left-style:solid;border-left-width:6px}.__react_component_tooltip.type-error.place-right:after{border-right-color:#BE6464;border-right-style:solid;border-right-width:6px}.__react_component_tooltip.type-error.border{border:1px solid #fff}.__react_component_tooltip.type-error.border.place-top:before{border-top:8px solid #fff}.__react_component_tooltip.type-error.border.place-bottom:before{border-bottom:8px solid #fff}.__react_component_tooltip.type-error.border.place-left:before{border-left:8px solid #fff}.__react_component_tooltip.type-error.border.place-right:before{border-right:8px solid #fff}.__react_component_tooltip.type-info{color:#fff;background-color:#337AB7}.__react_component_tooltip.type-info.place-top:after{border-top-color:#337AB7;border-top-style:solid;border-top-width:6px}.__react_component_tooltip.type-info.place-bottom:after{border-bottom-color:#337AB7;border-bottom-style:solid;border-bottom-width:6px}.__react_component_tooltip.type-info.place-left:after{border-left-color:#337AB7;border-left-style:solid;border-left-width:6px}.__react_component_tooltip.type-info.place-right:after{border-right-color:#337AB7;border-right-style:solid;border-right-width:6px}.__react_component_tooltip.type-info.border{border:1px solid #fff}.__react_component_tooltip.type-info.border.place-top:before{border-top:8px solid #fff}.__react_component_tooltip.type-info.border.place-bottom:before{border-bottom:8px solid #fff}.__react_component_tooltip.type-info.border.place-left:before{border-left:8px solid #fff}.__react_component_tooltip.type-info.border.place-right:before{border-right:8px solid #fff}.__react_component_tooltip.type-light{color:#222;background-color:#fff}.__react_component_tooltip.type-light.place-top:after{border-top-color:#fff;border-top-style:solid;border-top-width:6px}.__react_component_tooltip.type-light.place-bottom:after{border-bottom-color:#fff;border-bottom-style:solid;border-bottom-width:6px}.__react_component_tooltip.type-light.place-left:after{border-left-color:#fff;border-left-style:solid;border-left-width:6px}.__react_component_tooltip.type-light.place-right:after{border-right-color:#fff;border-right-style:solid;border-right-width:6px}.__react_component_tooltip.type-light.border{border:1px solid #222}.__react_component_tooltip.type-light.border.place-top:before{border-top:8px solid #222}.__react_component_tooltip.type-light.border.place-bottom:before{border-bottom:8px solid #222}.__react_component_tooltip.type-light.border.place-left:before{border-left:8px solid #222}.__react_component_tooltip.type-light.border.place-right:before{border-right:8px solid #222}.__react_component_tooltip.place-top{margin-top:-10px}.__react_component_tooltip.place-top:before{border-left:10px solid transparent;border-right:10px solid transparent;bottom:-8px;left:50%;margin-left:-10px}.__react_component_tooltip.place-top:after{border-left:8px solid transparent;border-right:8px solid transparent;bottom:-6px;left:50%;margin-left:-8px}.__react_component_tooltip.place-bottom{margin-top:10px}.__react_component_tooltip.place-bottom:before{border-left:10px solid transparent;border-right:10px solid transparent;top:-8px;left:50%;margin-left:-10px}.__react_component_tooltip.place-bottom:after{border-left:8px solid transparent;border-right:8px solid transparent;top:-6px;left:50%;margin-left:-8px}.__react_component_tooltip.place-left{margin-left:-10px}.__react_component_tooltip.place-left:before{border-top:6px solid transparent;border-bottom:6px solid transparent;right:-8px;top:50%;margin-top:-5px}.__react_component_tooltip.place-left:after{border-top:5px solid transparent;border-bottom:5px solid transparent;right:-6px;top:50%;margin-top:-4px}.__react_component_tooltip.place-right{margin-left:10px}.__react_component_tooltip.place-right:before{border-top:6px solid transparent;border-bottom:6px solid transparent;left:-8px;top:50%;margin-top:-5px}.__react_component_tooltip.place-right:after{border-top:5px solid transparent;border-bottom:5px solid transparent;left:-6px;top:50%;margin-top:-4px}.__react_component_tooltip .multi-line{display:block;padding:2px 0px;text-align:center}</style><link href="h2_files/codeshell_editor_theme_m-4d369be9eed481523d5e.css" type="text/css" rel="stylesheet"><script src="h2_files/codeshell_editor_theme_m-4d369be9eed481523d5e.js" charset="utf-8"></script><script src="h2_files/vendorshackerrank_r_codeshell_libhackerrank_r_teams-989af7c6a.js" charset="utf-8"></script><script src="h2_files/vendorshackerrank_r_codeshell_lib-575d563e37ae32aea08c.js" charset="utf-8"></script><script src="h2_files/hackerrank_r_codeshell_lib-d4842419f71f863c0455.js" charset="utf-8"></script><style class="monaco-colors" media="screen" type="text/css">.monaco-editor .accessibilityHelpWidget { background-color: #efeff2; }
.monaco-editor .accessibilityHelpWidget { box-shadow: 0 2px 8px #a8a8a8; }
.monaco-editor, .monaco-editor-background, .monaco-editor .inputarea.ime-input { background-color: #fffffe; }
.monaco-editor, .monaco-editor .inputarea.ime-input { color: #000000; }
.monaco-editor .margin { background-color: #fffffe; }
.monaco-editor .rangeHighlight { background-color: rgba(253, 255, 0, 0.2); }
.vs-whitespace { color: rgba(51, 51, 51, 0.2) !important; }
.monaco-editor .bracket-match { background-color: rgba(0, 100, 0, 0.1); }
.monaco-editor .bracket-match { border: 1px solid #b9b9b9; }
.monaco-editor .monaco-editor-overlaymessage .anchor { border-top-color: #007acc; }
.monaco-editor .monaco-editor-overlaymessage .message { border: 1px solid #007acc; }
.monaco-editor .monaco-editor-overlaymessage .message { background-color: #d6ecf2; }
.monaco-editor .codelens-decoration { color: #999999; }
.monaco-editor .codelens-decoration > a:hover { color: #0000ff !important; }
.monaco-editor .findMatch { background-color: rgba(234, 92, 0, 0.33); }
.monaco-editor .currentFindMatch { background-color: #a8ac94; }
.monaco-editor .findScope { background-color: rgba(180, 180, 180, 0.3); }
.monaco-editor .find-widget { background-color: #efeff2; }
.monaco-editor .find-widget { box-shadow: 0 2px 8px #a8a8a8; }
.monaco-editor .find-widget.no-results .matchesCount { color: #a1260d; }
.monaco-editor .find-widget .monaco-sash { background-color: #c8c8c8; width: 3px !important; margin-left: -4px;}
.monaco-editor .findOptionsWidget { background-color: #efeff2; }
.monaco-editor .findOptionsWidget { box-shadow: 0 2px 8px #a8a8a8; }
.monaco-editor .line-numbers { color: #237893; }
.monaco-editor .current-line ~ .line-numbers { color: #0b216f; }
.monaco-editor .view-overlays .current-line { border: 2px solid #eeeeee; }
.monaco-editor .margin-view-overlays .current-line-margin { border: 2px solid #eeeeee; }
.monaco-editor .lines-content .cigr { box-shadow: 1px 0 0 0 #d3d3d3 inset; }
.monaco-editor .lines-content .cigra { box-shadow: 1px 0 0 0 #939393 inset; }
.monaco-editor .view-ruler { box-shadow: 1px 0 0 0 #d3d3d3 inset; }
.monaco-editor .scroll-decoration { box-shadow: #dddddd 0 6px 6px -6px inset; }
.monaco-editor .focused .selected-text { background-color: #add6ff; }
.monaco-editor .selected-text { background-color: #e5ebf1; }
.monaco-editor .cursor { background-color: #000000; border-color: #000000; color: #ffffff; }
.monaco-editor .minimap-slider, .monaco-editor .minimap-slider .minimap-slider-horizontal { background: rgba(100, 100, 100, 0.2); }
.monaco-editor .minimap-slider:hover, .monaco-editor .minimap-slider:hover .minimap-slider-horizontal { background: rgba(100, 100, 100, 0.35); }
.monaco-editor .minimap-slider.active, .monaco-editor .minimap-slider.active .minimap-slider-horizontal { background: rgba(0, 0, 0, 0.3); }
.monaco-editor .minimap-shadow-visible { box-shadow: #dddddd -6px 0 6px -6px inset; }
.monaco-editor .squiggly-error { background: url("data:image/svg+xml,%3Csvg%20xmlns%3D'http%3A%2F%2Fwww.w3.org%2F2000%2Fsvg'%20viewBox%3D'0%200%206%203'%20enable-background%3D'new%200%200%206%203'%20height%3D'3'%20width%3D'6'%3E%3Cg%20fill%3D'%23d60a0a'%3E%3Cpolygon%20points%3D'5.5%2C0%202.5%2C3%201.1%2C3%204.1%2C0'%2F%3E%3Cpolygon%20points%3D'4%2C0%206%2C2%206%2C0.6%205.4%2C0'%2F%3E%3Cpolygon%20points%3D'0%2C2%201%2C3%202.4%2C3%200%2C0.6'%2F%3E%3C%2Fg%3E%3C%2Fsvg%3E") repeat-x bottom left; }
.monaco-editor .squiggly-warning { background: url("data:image/svg+xml,%3Csvg%20xmlns%3D'http%3A%2F%2Fwww.w3.org%2F2000%2Fsvg'%20viewBox%3D'0%200%206%203'%20enable-background%3D'new%200%200%206%203'%20height%3D'3'%20width%3D'6'%3E%3Cg%20fill%3D'%23117711'%3E%3Cpolygon%20points%3D'5.5%2C0%202.5%2C3%201.1%2C3%204.1%2C0'%2F%3E%3Cpolygon%20points%3D'4%2C0%206%2C2%206%2C0.6%205.4%2C0'%2F%3E%3Cpolygon%20points%3D'0%2C2%201%2C3%202.4%2C3%200%2C0.6'%2F%3E%3C%2Fg%3E%3C%2Fsvg%3E") repeat-x bottom left; }
.monaco-editor .squiggly-info { background: url("data:image/svg+xml,%3Csvg%20xmlns%3D'http%3A%2F%2Fwww.w3.org%2F2000%2Fsvg'%20viewBox%3D'0%200%206%203'%20enable-background%3D'new%200%200%206%203'%20height%3D'3'%20width%3D'6'%3E%3Cg%20fill%3D'%23008000'%3E%3Cpolygon%20points%3D'5.5%2C0%202.5%2C3%201.1%2C3%204.1%2C0'%2F%3E%3Cpolygon%20points%3D'4%2C0%206%2C2%206%2C0.6%205.4%2C0'%2F%3E%3Cpolygon%20points%3D'0%2C2%201%2C3%202.4%2C3%200%2C0.6'%2F%3E%3C%2Fg%3E%3C%2Fsvg%3E") repeat-x bottom left; }
.monaco-editor .squiggly-hint { background: url("data:image/svg+xml,%3Csvg%20xmlns%3D%22http%3A%2F%2Fwww.w3.org%2F2000%2Fsvg%22%20height%3D%223%22%20width%3D%2212%22%3E%3Cg%20fill%3D%22%236c6c6c%22%3E%3Ccircle%20cx%3D%221%22%20cy%3D%221%22%20r%3D%221%22%2F%3E%3Ccircle%20cx%3D%225%22%20cy%3D%221%22%20r%3D%221%22%2F%3E%3Ccircle%20cx%3D%229%22%20cy%3D%221%22%20r%3D%221%22%2F%3E%3C%2Fg%3E%3C%2Fsvg%3E") no-repeat bottom left; }
.showUnused .monaco-editor .squiggly-inline-unnecessary { opacity: 0.467; will-change: opacity; }
.monaco-editor .reference-zone-widget .ref-tree .referenceMatch { background-color: rgba(234, 92, 0, 0.3); }
.monaco-editor .reference-zone-widget .preview .reference-decoration { background-color: rgba(245, 216, 2, 0.87); }
.monaco-editor .reference-zone-widget .ref-tree { background-color: #f3f3f3; }
.monaco-editor .reference-zone-widget .ref-tree { color: #646465; }
.monaco-editor .reference-zone-widget .ref-tree .reference-file { color: #1e1e1e; }
.monaco-editor .reference-zone-widget .ref-tree .monaco-tree.focused .monaco-tree-rows > .monaco-tree-row.selected:not(.highlighted) { background-color: rgba(51, 153, 255, 0.2); }
.monaco-editor .reference-zone-widget .ref-tree .monaco-tree.focused .monaco-tree-rows > .monaco-tree-row.selected:not(.highlighted) { color: #6c6c6c !important; }
.monaco-editor .reference-zone-widget .preview .monaco-editor .monaco-editor-background,.monaco-editor .reference-zone-widget .preview .monaco-editor .inputarea.ime-input {	background-color: #f2f8fc;}
.monaco-editor .reference-zone-widget .preview .monaco-editor .margin {	background-color: #f2f8fc;}
.monaco-editor .goto-definition-link { color: #0000ff !important; }
.monaco-editor .hoverHighlight { background-color: rgba(173, 214, 255, 0.15); }
.monaco-editor .monaco-editor-hover { background-color: #efeff2; }
.monaco-editor .monaco-editor-hover { border: 1px solid #c8c8c8; }
.monaco-editor .monaco-editor-hover .hover-row:not(:first-child):not(:empty) { border-top: 1px solid rgba(200, 200, 200, 0.5); }
.monaco-editor .monaco-editor-hover a { color: #006ab1; }
.monaco-editor .monaco-editor-hover code { background-color: rgba(220, 220, 220, 0.4); }
.monaco-editor.vs .valueSetReplacement { outline: solid 2px #b9b9b9; }
.monaco-editor .tokens-inspect-widget { border: 1px solid #c8c8c8; }
.monaco-editor .tokens-inspect-widget .tokens-inspect-separator { background-color: #c8c8c8; }
.monaco-editor .tokens-inspect-widget { background-color: #efeff2; }
.monaco-editor .detected-link-active { color: #0000ff !important; }
.monaco-editor .parameter-hints-widget { border: 1px solid #c8c8c8; }
.monaco-editor .parameter-hints-widget.multiple .body { border-left: 1px solid rgba(200, 200, 200, 0.5); }
.monaco-editor .parameter-hints-widget .signature.has-docs { border-bottom: 1px solid rgba(200, 200, 200, 0.5); }
.monaco-editor .parameter-hints-widget { background-color: #efeff2; }
.monaco-editor .parameter-hints-widget a { color: #006ab1; }
.monaco-editor .parameter-hints-widget code { background-color: rgba(220, 220, 220, 0.4); }
.monaco-editor .suggest-widget .monaco-list .monaco-list-row .monaco-highlighted-label .highlight { color: #007acc; }
.monaco-editor .suggest-widget { color: #000000; }
.monaco-editor .suggest-widget a { color: #006ab1; }
.monaco-editor .suggest-widget code { background-color: rgba(220, 220, 220, 0.4); }
.monaco-editor .focused .selectionHighlight { background-color: rgba(173, 214, 255, 0.3); }
.monaco-editor .selectionHighlight { background-color: rgba(173, 214, 255, 0.15); }
.monaco-editor .wordHighlight { background-color: rgba(87, 87, 87, 0.25); }
.monaco-editor .wordHighlightStrong { background-color: rgba(14, 99, 156, 0.25); }
.monaco-diff-editor .diff-review-line-number { color: #237893; }
.monaco-diff-editor .diff-review-shadow { box-shadow: #dddddd 0 -6px 6px -6px inset; }
.monaco-editor .line-insert, .monaco-editor .char-insert { background-color: rgba(155, 185, 85, 0.2); }
.monaco-diff-editor .line-insert, .monaco-diff-editor .char-insert { background-color: rgba(155, 185, 85, 0.2); }
.monaco-editor .inline-added-margin-view-zone { background-color: rgba(155, 185, 85, 0.2); }
.monaco-editor .line-delete, .monaco-editor .char-delete { background-color: rgba(255, 0, 0, 0.2); }
.monaco-diff-editor .line-delete, .monaco-diff-editor .char-delete { background-color: rgba(255, 0, 0, 0.2); }
.monaco-editor .inline-deleted-margin-view-zone { background-color: rgba(255, 0, 0, 0.2); }
.monaco-diff-editor.side-by-side .editor.modified { box-shadow: -6px 0 5px -5px #dddddd; }

.mtk1 { color: #000000; }
.mtk2 { color: #fffffe; }
.mtk3 { color: #808080; }
.mtk4 { color: #ff0000; }
.mtk5 { color: #0451a5; }
.mtk6 { color: #0000ff; }
.mtk7 { color: #09885a; }
.mtk8 { color: #008000; }
.mtk9 { color: #dd0000; }
.mtk10 { color: #383838; }
.mtk11 { color: #cd3131; }
.mtk12 { color: #863b00; }
.mtk13 { color: #af00db; }
.mtk14 { color: #800000; }
.mtk15 { color: #e00000; }
.mtk16 { color: #3030c0; }
.mtk17 { color: #666666; }
.mtk18 { color: #778899; }
.mtk19 { color: #ff00ff; }
.mtk20 { color: #a31515; }
.mtk21 { color: #4f76ac; }
.mtk22 { color: #008080; }
.mtk23 { color: #001188; }
.mtk24 { color: #4864aa; }
.mtki { font-style: italic; }
.mtkb { font-weight: bold; }
.mtku { text-decoration: underline; text-underline-position: under; }</style><script async="" src="h2_files/codemirror_basic-ea8e34ebc0b1a33b938bc18d9364a64c.js"></script><script async="" src="h2_files/clike-730a8140c63a08831b4b7153287a6f04.js"></script><title> Playing With Characters | HackerRank </title><meta content="Playing With Characters | HackerRank" id="meta-og-title" property="og:title"><meta content="input character, string and a sentence" id="meta-og-description" property="og:description"><meta content="https://www.hackerrank.com/challenges/playing-with-characters/problem" id="meta-og-url" property="og:url"><meta content="https://www.hackerrank.com/challenges/playing-with-characters/problem" id="meta-twitter-url" name="twitter:url"></head>
<body id="hr_v2">
  <div class="cdn-error-view" style="display:none;">
  <div class="error-box-wrap">
    <div class="error-icon">
      <svg x="0px" y="0px" width="80px" height="80px" viewBox="0 0 367.011 367.01" style="enable-background:new 0 0 367.011 367.01;" xml:space="preserve">
        <g>
         <g>
          <path d="M365.221,329.641L190.943,27.788c-1.542-2.674-4.395-4.318-7.479-4.318c-3.084,0-5.938,1.645-7.48,4.318L1.157,330.584    c-1.543,2.674-1.543,5.965,0,8.639c1.542,2.674,4.395,4.318,7.48,4.318h349.65c0.028,0,0.057,0,0.086,0    c4.77,0,8.638-3.863,8.638-8.639C367.011,332.92,366.342,331.1,365.221,329.641z M23.599,326.266L183.464,49.381l159.864,276.885    H23.599z"></path>
          <path d="M174.826,136.801v123.893c0,4.773,3.867,8.638,8.638,8.638c4.77,0,8.637-3.863,8.637-8.638V136.801    c0-4.766-3.867-8.637-8.637-8.637C178.693,128.165,174.826,132.036,174.826,136.801z"></path>
          <path d="M183.464,279.393c-5.922,0-10.725,4.8-10.725,10.722s4.803,10.729,10.725,10.729c5.921,0,10.725-4.809,10.725-10.729    C194.189,284.193,189.386,279.393,183.464,279.393z"></path>
         </g>
        </g>
      </svg>
    </div>
    <h2 class="error-title">Something went wrong!</h2>
    <p class="error-message">Some error occured while loading page for you. Please try again.</p>
    <div class="btn-wrap">
      <a href="#" onclick="window.location.reload(true);"><button class="btn-reload">Reload</button></a>
    </div>
  </div>
</div>
<script>
  if(typeof cdnLoaded !== 'undefined' && cdnLoaded === false){
    document.querySelector('.cdn-error-view').style.display = 'block';
  }
</script>

  <div id="fb-root"></div>
  

  <!-- Just a placeholder div to start loading open sans and source code loader -->
  <div class="font-open-sans-loader"></div>
  <div class="font-source-code-loader"></div>
  <!-- Just a placeholder div to start loading open sans and source code loader end -->

  <div id="content" onclick="void(0);"><div class="body-wrap  community-page challenges-page problem-page show-cookie-banner"><div class="toast-message loading"><span class="toast-container containment"><i class="ui-icon-loading"></i><span class="toast-text">Loading...</span></span></div><div class="theme-m new-design logged-user"><div class="page-header-wrapper theme-m-section"><nav class="community-header"><div class="container"><div class="header-nav-links theme-m-section"><ul class="nav-links"><li class="nav-link-item logo-wrap"><a href="https://www.hackerrank.com/dashboard" data-attr1="/dashboard" data-analytics="NavBarLogo" class="nav_link backbone logo_mark js_logo_mark logo-link"><img alt="" src="h2_files/h_mark_sm-9c05999c62674028552f4e813728e591.svg" class="logo-img-small" id="feed-intro"></a></li><li class="nav-link-item"><a href="https://www.hackerrank.com/dashboard" data-analytics="NavBarDomains" class="nav-link dashboard active"><span>Practice</span></a></li><li class="nav-link-item"><a href="https://www.hackerrank.com/contests" data-analytics="NavBarContests" class="nav-link contests"><span>Compete</span></a></li><li class="nav-link-item"><a href="https://www.hackerrank.com/jobs" data-analytics="NavBarJobs" class="nav-link"><span>Jobs</span><i class="icon-circle js-jobs-notification navigation-highlight-icon hidden"></i></a></li><li class="nav-link-item"><a href="https://www.hackerrank.com/leaderboard" id="leaderboard-nav-link" data-analytics="NavBarLeaderboard" class="nav-link"><span>Leaderboard</span></a></li></ul></div><div class="nav-buttons theme-m-section"><ul class="pull-left psR"><li id="search-span" class="hide-in-private-contest search-input-container input-icon main-hr-search"><div class="search-form new-search"><div><div class="search-query asyn-autocomplete autocomplete"><div class="ac-input-wrap cf"><input placeholder="Search" class="ac-input " autocomplete="off"></div></div><i class="ui-icon-search"></i></div></div></li></ul><ul class="pull-left nav-wrap mmL"><li class="hide-in-private-contest button-item"><div class="dropdown dropdown message-dropdown notify-dropdown theme-m-content"><a data-analytics="NavBarMessageIcon" class="cursor dropdown-handle nav_link hr_nav_messages_link js-dropdown-toggle js-link"><i class="dropdown-icon ui-icon-message"></i></a><div class="dropdown-menu large"><header class="psT psB text-center menu-header"><strong class="header-title">Messages</strong></header><div class="dropdown-body" id="notify_messages"><div class="hr_nav_messages_list"><div class="no-propagation text-center txt-navy empty-msg">You have no unread messages.</div></div></div><footer class="final text-center show-all"><a data-analytics="NavBarMessageShowAll" href="https://www.hackerrank.com/inbox" class="btn show-all-link">Show All</a></footer></div></div></li><li class="button-item"><div class="dropdown dropdown notification-dropdown notify-dropdown theme-m-content"><a data-analytics="NavBarNotificationsIcon" data-toggle="dropdown" class="cursor dropdown-handle nav_link hr_nav_notifications_link js-dropdown-toggle js-link"><i class="dropdown-icon ui-icon-notification"></i></a><div id="notify_broadcasts" class="dropdown-menu large"><header class="psA menu-header"><strong class="header-title">Notifications</strong><a data-analytics="NavBarNotificationsArchiveAll" class="hr_archive_all archive pull-right js-link"><i class="icon-folder-open"></i>Archive All</a></header><div class="clearfix dropdown-body"><div class="hr_nav_notifications_list"><ul><li data-url="/domains/tutorials/30-days-of-code" data-category="contest-announcements" data-id="64040332" class="notify_item dropdown-item cursor"><div class="notification-icon"><img src="h2_files/notifymarker-72a631c740640b69e5d277569c59b97e.png"></div><div class="notification-subject pmT"><div class="psA"><div>Improve your coding skills. Join our 30 Days of Code challenge!</div><small class="meta"><time title="2018-06-12 06:35" datetime="2018-06-12T06:35:57.000Z" class="time-text">3 months ago</time></small></div></div></li></ul></div></div><footer class="final show-all"><a data-analytics="NavBarNotificationsShowAll" href="https://www.hackerrank.com/notifications" class="btn show-all-link">Show All</a></footer></div></div></li><li class="button-item"><div class="dropdown dropdown dropdown-auth profile-menu cursor theme-m-content"><a data-analytics="NavBarProfileDropDown" class="backbone nav_link js-dropdown-toggle js-link toggle-wrap"><i class="ui-icon-user default-user-icon"></i><span class="mmR username text-ellipsis">bantinarvariya16</span><i class="ui-icon-chevron-down down-icon"></i></a><div class="dropdown-menu drop-list pull-right"><ul><li class="hide-in-private-contest profile-nav-item"><a href="https://www.hackerrank.com/bantinarvariya16/hackos" data-analytics="NavBarProfileDropDownHackos" class="navigation_hackos hackos-count">Hackos: <span class="navigation_hackos-count">120</span></a></li><li class="hide-in-private-contest profile-nav-item"><a href="https://www.hackerrank.com/bantinarvariya16" data-analytics="NavBarProfileDropDownProfile" data-placement="left" rel="tooltip">Profile<div class="ui-progress-bar progress-bar theme-default"><div style="width: 30%;" class="progress-filler"></div></div></a></li><li class="hide-in-private-contest profile-nav-item"><a data-analytics="NavBarProfileDropDownSettings" href="https://www.hackerrank.com/settings/profile">Settings</a></li><li class="hide-in-private-contest profile-nav-item"><a data-analytics="NavBarDropDownBookmarks" href="https://www.hackerrank.com/challenges/bookmarks">Bookmarks</a></li><li class="hide-in-private-contest profile-nav-item"><a data-analytics="NavBarProfileDropDownNetwork" href="https://www.hackerrank.com/network">Network</a></li><li class="hide-in-private-contest profile-nav-item"><a data-analytics="NavBarProfileDropDownSubmissions" href="https://www.hackerrank.com/submissions">Submissions</a></li><li class="hide-in-private-contest profile-nav-item"><a data-analytics="NavBarProfileDropDownAdministration" href="https://www.hackerrank.com/administration">Administration</a></li><li class="profile-nav-item"><a data-analytics="NavBarProfileDropDownLogout" class="logout-button js-link">Logout</a></li></ul></div></div></li></ul></div></div></nav></div><header class="community-header-breadcrumb"><div class="container"><div class="d-flex justify-content-between align-items-center content-header-wrapper"><div class="community-header-breadcrumb-items"><ol class="community-breadcrumb text-content" itemtype="http://schema.org/BreadcrumbList"><li class="breadcrumb-item" itemtype="http://schema.org/ListItem" itemprop="itemListElement"><a href="https://www.hackerrank.com/dashboard" data-attr7="1" data-attr2="global" data-attr1="Practice" data-analytics="Breadcrumb" class="breadcrumb-link" itemprop="item"><span class="breadcrumb-item-text" itemprop="name">Practice</span></a><meta content="1" itemprop="position"></li><li class="breadcrumb-item" itemtype="http://schema.org/ListItem" itemprop="itemListElement"><span class="ui-icon-chevron-right mmL mmR chevron-icon"></span><a href="https://www.hackerrank.com/domains/c" data-attr7="1" data-attr2="global" data-attr1="C" data-analytics="Breadcrumb" class="breadcrumb-link" itemprop="item"><span class="breadcrumb-item-text" itemprop="name">C</span></a><meta content="1" itemprop="position"></li><li class="breadcrumb-item" itemtype="http://schema.org/ListItem" itemprop="itemListElement"><span class="ui-icon-chevron-right mmL mmR chevron-icon"></span><a href="https://www.hackerrank.com/domains/c/c-introduction" data-attr7="1" data-attr2="global" data-attr1="Introduction" data-analytics="Breadcrumb" class="breadcrumb-link" itemprop="item"><span class="breadcrumb-item-text" itemprop="name">Introduction</span></a><meta content="1" itemprop="position"></li><li class="breadcrumb-item" itemtype="http://schema.org/ListItem" itemprop="itemListElement"><span class="ui-icon-chevron-right mmL mmR chevron-icon"></span><span class="breadcrumb-item-text" itemprop="name">Playing With Characters</span><meta content="1" itemprop="position"></li></ol><div class="page-label-wrapper text-headline"><h1 class="page-label"><div class="challenge-page-label-wrapper align-items-center"><h1 class="ui-icon-label page-label">Playing With Characters<i class="icon-bookmark ui-icon-star txt-grey"></i></h1></div></h1></div></div><div class="community-header-aside"><div class="challange-header-aside"><div class="domain-scores d-flex align-items-center"><div class="brcumb-points"><span class="zeta bold">Points: </span><span class="bold domain-score msR">6.67</span><span class="domain-rank-span"><span class="zeta bold">Rank: </span><span class="bold msR domain-rank ">28533</span></span></div></div></div></div></div></div></header><div class="container"></div><div class="community-content"><div class="challenge-view theme-m"><div class="challenge-page-header container"><div class="ui-card theme-m-content submission-status-banner ui-layer-2"><div class="card-content"><div class="submission-model-wrapper"><div class="points-message">Your Playing With Characters submission got 5.00 points.</div><div class="share-btns-wrap"><iframe allowtransparency="true" class="share-btn" scrolling="no" src="h2_files/share_button.htm" frameborder="0"></iframe>&nbsp;&nbsp;<iframe allowtransparency="true" class="share-btn" scrolling="no" src="h2_files/tweet_button.htm" frameborder="0"></iframe></div><div class="next-challenge-link"><span class="challenge-next-link"><a href="https://www.hackerrank.com/challenges/sum-numbers-c" class="challenge-link close-success">Try the next challenge</a></span><span class="seperator">&nbsp;|&nbsp;</span><span class="challenge-random-link"><a href="https://www.hackerrank.com/challenges/sum-numbers-c" class="challenge-link hr_tour-leaderboard close-success">Try a Random Challenge</a></span></div></div><span class="ui-icon-cross cross-icon"></span></div></div><div class="ui-tabs-wrap"><div class="render-list clearfix"><ul class="tab-header"><li class="tab-item active" id="Problem"><a href="https://www.hackerrank.com/challenges/playing-with-characters/problem" data-attr2="Problem" data-attr1="/challenges/playing-with-characters/problem" data-analytics="ChallengeViewTab" class="tab-item-color"><span class="ui-icon-label">Problem</span></a></li><li class="tab-item" id="Submissions"><a href="https://www.hackerrank.com/challenges/playing-with-characters/submissions" data-attr2="Submissions" data-attr1="/challenges/playing-with-characters/submissions" data-analytics="ChallengeViewTab" class="tab-item-color"><span class="ui-icon-label">Submissions</span></a></li><li class="tab-item" id="Leaderboard"><a href="https://www.hackerrank.com/challenges/playing-with-characters/leaderboard" data-attr2="Leaderboard" data-attr1="/challenges/playing-with-characters/leaderboard" data-analytics="ChallengeViewTab" class="tab-item-color"><span class="ui-icon-label">Leaderboard</span></a></li><li class="tab-item" id="Discussions"><a href="https://www.hackerrank.com/challenges/playing-with-characters/forum" data-attr2="Discussions" data-attr1="/challenges/playing-with-characters/forum" data-analytics="ChallengeViewTab" class="tab-item-color"><span class="ui-icon-label">Discussions</span></a></li><li class="tab-item" id="Editorial"><a href="https://www.hackerrank.com/challenges/playing-with-characters/editorial" data-attr2="Editorial" data-attr1="/challenges/playing-with-characters/editorial" data-analytics="ChallengeViewTab" class="tab-item-color"><span class="ui-icon-label">Editorial</span><i class="ui-icon-lock"></i></a></li></ul></div></div></div><section class="challenge-interface challenge-problem"><div class="challenge-body"><div class="challenge-body-elements-problem challenge-container-element"><div class="container challenge-page-wrap panes-container theme-m-content"><div class="full-screen-split split-wrap left-pane"><section class="problem-statement split"><div class="tab-list-content"><div class="theme-m hr_tour-problem-statement problem-statement have-external-links"><div class="content-text challenge-text mlB hackdown-container theme-m"><div class="challenge-body-html"><div class="challenge_problem_statement"><div class="msB challenge_problem_statement_body"><div class="hackdown-content"><style id="MathJax_SVG_styles">.MathJax_SVG_Display {text-align: center; margin: 1em 0em; position: relative; display: block!important; text-indent: 0; max-width: none; max-height: none; min-width: 0; min-height: 0; width: 100%}
.MathJax_SVG .MJX-monospace {font-family: monospace}
.MathJax_SVG .MJX-sans-serif {font-family: sans-serif}
.MathJax_SVG {display: inline; font-style: normal; font-weight: normal; line-height: normal; font-size: 100%; font-size-adjust: none; text-indent: 0; text-align: left; text-transform: none; letter-spacing: normal; word-spacing: normal; word-wrap: normal; white-space: nowrap; float: none; direction: ltr; max-width: none; max-height: none; min-width: 0; min-height: 0; border: 0; padding: 0; margin: 0}
.MathJax_SVG * {transition: none; -webkit-transition: none; -moz-transition: none; -ms-transition: none; -o-transition: none}
.mjx-svg-href {fill: blue; stroke: blue}
.MathJax_SVG_LineBox {display: table!important}
.MathJax_SVG_LineBox span {display: table-cell!important; width: 10000em!important; min-width: 0; max-width: none; padding: 0; border: 0; margin: 0}
</style><svg style="display: none;"><defs id="MathJax_SVG_glyphs"></defs></svg><p><strong>Objective</strong></p>

<p>This challenge will help you to learn how to take a character, a string and a sentence as input in C. </p>

<p>To take a single character <span style="font-size: 100%; display: inline-block;" class="MathJax_SVG" id="MathJax-Element-1-Frame"><svg xlink="http://www.w3.org/1999/xlink" width="2.346ex" height="2.176ex" style="vertical-align: -0.338ex;" viewBox="0 -791.3 1010 936.9" role="img" focusable="false"><g stroke="currentColor" fill="currentColor" stroke-width="0" transform="matrix(1 0 0 -1 0 0)"><path stroke-width="1" d="M34 159Q34 268 120 355T306 442Q362 442 394 418T427 355Q427 326 408 306T360 285Q341 285 330 295T319 325T330 359T352 380T366 386H367Q367 388 361 392T340 400T306 404Q276 404 249 390Q228 381 206 359Q162 315 142 235T121 119Q121 73 147 50Q169 26 205 26H209Q321 26 394 111Q403 121 406 121Q410 121 419 112T429 98T420 83T391 55T346 25T282 0T202 -11Q127 -11 81 37T34 159Z"></path><g transform="translate(433,0)"><path stroke-width="1" d="M137 683Q138 683 209 688T282 694Q294 694 294 685Q294 674 258 534Q220 386 220 383Q220 381 227 388Q288 442 357 442Q411 442 444 415T478 336Q478 285 440 178T402 50Q403 36 407 31T422 26Q450 26 474 56T513 138Q516 149 519 151T535 153Q555 153 555 145Q555 144 551 130Q535 71 500 33Q466 -10 419 -10H414Q367 -10 346 17T325 74Q325 90 361 192T398 345Q398 404 354 404H349Q266 404 205 306L198 293L164 158Q132 28 127 16Q114 -11 83 -11Q69 -11 59 -2T48 16Q48 30 121 320L195 616Q195 629 188 632T149 637H128Q122 643 122 645T124 664Q129 683 137 683Z"></path></g></g></svg></span> as input, you can use <code>scanf("%c", &amp;ch );</code> and <code>printf("%c", ch)</code> writes a character specified by the argument char to stdout</p>

<div class="highlight"><pre><span></span><span class="kt">char</span> <span class="n">ch</span><span class="p">;</span>
<span class="n">scanf</span><span class="p">(</span><span class="s">"%c"</span><span class="p">,</span> <span class="o">&amp;</span><span class="n">ch</span><span class="p">);</span>
<span class="n">printf</span><span class="p">(</span><span class="s">"%c"</span><span class="p">,</span> <span class="n">ch</span><span class="p">);</span>
</pre></div>


<p>This piece of code prints the character <span style="font-size: 100%; display: inline-block;" class="MathJax_SVG" id="MathJax-Element-2-Frame"><svg xlink="http://www.w3.org/1999/xlink" width="2.346ex" height="2.176ex" style="vertical-align: -0.338ex;" viewBox="0 -791.3 1010 936.9" role="img" focusable="false"><g stroke="currentColor" fill="currentColor" stroke-width="0" transform="matrix(1 0 0 -1 0 0)"><path stroke-width="1" d="M34 159Q34 268 120 355T306 442Q362 442 394 418T427 355Q427 326 408 306T360 285Q341 285 330 295T319 325T330 359T352 380T366 386H367Q367 388 361 392T340 400T306 404Q276 404 249 390Q228 381 206 359Q162 315 142 235T121 119Q121 73 147 50Q169 26 205 26H209Q321 26 394 111Q403 121 406 121Q410 121 419 112T429 98T420 83T391 55T346 25T282 0T202 -11Q127 -11 81 37T34 159Z"></path><g transform="translate(433,0)"><path stroke-width="1" d="M137 683Q138 683 209 688T282 694Q294 694 294 685Q294 674 258 534Q220 386 220 383Q220 381 227 388Q288 442 357 442Q411 442 444 415T478 336Q478 285 440 178T402 50Q403 36 407 31T422 26Q450 26 474 56T513 138Q516 149 519 151T535 153Q555 153 555 145Q555 144 551 130Q535 71 500 33Q466 -10 419 -10H414Q367 -10 346 17T325 74Q325 90 361 192T398 345Q398 404 354 404H349Q266 404 205 306L198 293L164 158Q132 28 127 16Q114 -11 83 -11Q69 -11 59 -2T48 16Q48 30 121 320L195 616Q195 629 188 632T149 637H128Q122 643 122 645T124 664Q129 683 137 683Z"></path></g></g></svg></span>.</p>

<p>You can take a string as input in C using <code>scanf(“%s”, s)</code>. But, it accepts string only until it finds the first space. </p>

<p>In order to take a line as input, you can use <code>scanf("%[^\n]%*c", s);</code> where  <span style="font-size: 100%; display: inline-block;" class="MathJax_SVG" id="MathJax-Element-3-Frame"><svg xlink="http://www.w3.org/1999/xlink" width="1.09ex" height="1.676ex" style="vertical-align: -0.338ex;" viewBox="0 -576.1 469.5 721.6" role="img" focusable="false"><g stroke="currentColor" fill="currentColor" stroke-width="0" transform="matrix(1 0 0 -1 0 0)"><path stroke-width="1" d="M131 289Q131 321 147 354T203 415T300 442Q362 442 390 415T419 355Q419 323 402 308T364 292Q351 292 340 300T328 326Q328 342 337 354T354 372T367 378Q368 378 368 379Q368 382 361 388T336 399T297 405Q249 405 227 379T204 326Q204 301 223 291T278 274T330 259Q396 230 396 163Q396 135 385 107T352 51T289 7T195 -10Q118 -10 86 19T53 87Q53 126 74 143T118 160Q133 160 146 151T160 120Q160 94 142 76T111 58Q109 57 108 57T107 55Q108 52 115 47T146 34T201 27Q237 27 263 38T301 66T318 97T323 122Q323 150 302 164T254 181T195 196T148 231Q131 256 131 289Z"></path></g></svg></span> is defined as <code>char s[MAX_LEN]</code> where <span style="font-size: 100%; display: inline-block;" class="MathJax_SVG" id="MathJax-Element-4-Frame"><svg xlink="http://www.w3.org/1999/xlink" width="12.75ex" height="2.176ex" style="vertical-align: -0.338ex;" viewBox="0 -791.3 5489.5 936.9" role="img" focusable="false"><g stroke="currentColor" fill="currentColor" stroke-width="0" transform="matrix(1 0 0 -1 0 0)"><path stroke-width="1" d="M289 629Q289 635 232 637Q208 637 201 638T194 648Q194 649 196 659Q197 662 198 666T199 671T201 676T203 679T207 681T212 683T220 683T232 684Q238 684 262 684T307 683Q386 683 398 683T414 678Q415 674 451 396L487 117L510 154Q534 190 574 254T662 394Q837 673 839 675Q840 676 842 678T846 681L852 683H948Q965 683 988 683T1017 684Q1051 684 1051 673Q1051 668 1048 656T1045 643Q1041 637 1008 637Q968 636 957 634T939 623Q936 618 867 340T797 59Q797 55 798 54T805 50T822 48T855 46H886Q892 37 892 35Q892 19 885 5Q880 0 869 0Q864 0 828 1T736 2Q675 2 644 2T609 1Q592 1 592 11Q592 13 594 25Q598 41 602 43T625 46Q652 46 685 49Q699 52 704 61Q706 65 742 207T813 490T848 631L654 322Q458 10 453 5Q451 4 449 3Q444 0 433 0Q418 0 415 7Q413 11 374 317L335 624L267 354Q200 88 200 79Q206 46 272 46H282Q288 41 289 37T286 19Q282 3 278 1Q274 0 267 0Q265 0 255 0T221 1T157 2Q127 2 95 1T58 0Q43 0 39 2T35 11Q35 13 38 25T43 40Q45 46 65 46Q135 46 154 86Q158 92 223 354T289 629Z"></path><g transform="translate(1051,0)"><path stroke-width="1" d="M208 74Q208 50 254 46Q272 46 272 35Q272 34 270 22Q267 8 264 4T251 0Q249 0 239 0T205 1T141 2Q70 2 50 0H42Q35 7 35 11Q37 38 48 46H62Q132 49 164 96Q170 102 345 401T523 704Q530 716 547 716H555H572Q578 707 578 706L606 383Q634 60 636 57Q641 46 701 46Q726 46 726 36Q726 34 723 22Q720 7 718 4T704 0Q701 0 690 0T651 1T578 2Q484 2 455 0H443Q437 6 437 9T439 27Q443 40 445 43L449 46H469Q523 49 533 63L521 213H283L249 155Q208 86 208 74ZM516 260Q516 271 504 416T490 562L463 519Q447 492 400 412L310 260L413 259Q516 259 516 260Z"></path></g><g transform="translate(1802,0)"><path stroke-width="1" d="M42 0H40Q26 0 26 11Q26 15 29 27Q33 41 36 43T55 46Q141 49 190 98Q200 108 306 224T411 342Q302 620 297 625Q288 636 234 637H206Q200 643 200 645T202 664Q206 677 212 683H226Q260 681 347 681Q380 681 408 681T453 682T473 682Q490 682 490 671Q490 670 488 658Q484 643 481 640T465 637Q434 634 411 620L488 426L541 485Q646 598 646 610Q646 628 622 635Q617 635 609 637Q594 637 594 648Q594 650 596 664Q600 677 606 683H618Q619 683 643 683T697 681T738 680Q828 680 837 683H845Q852 676 852 672Q850 647 840 637H824Q790 636 763 628T722 611T698 593L687 584Q687 585 592 480L505 384Q505 383 536 304T601 142T638 56Q648 47 699 46Q734 46 734 37Q734 35 732 23Q728 7 725 4T711 1Q708 1 678 1T589 2Q528 2 496 2T461 1Q444 1 444 10Q444 11 446 25Q448 35 450 39T455 44T464 46T480 47T506 54Q523 62 523 64Q522 64 476 181L429 299Q241 95 236 84Q232 76 232 72Q232 53 261 47Q262 47 267 47T273 46Q276 46 277 46T280 45T283 42T284 35Q284 26 282 19Q279 6 276 4T261 1Q258 1 243 1T201 2T142 2Q64 2 42 0Z"></path></g><g transform="translate(2654,0)"><path stroke-width="1" d="M0 -62V-25H499V-62H0Z"></path></g><g transform="translate(3155,0)"><path stroke-width="1" d="M228 637Q194 637 192 641Q191 643 191 649Q191 673 202 682Q204 683 217 683Q271 680 344 680Q485 680 506 683H518Q524 677 524 674T522 656Q517 641 513 637H475Q406 636 394 628Q387 624 380 600T313 336Q297 271 279 198T252 88L243 52Q243 48 252 48T311 46H328Q360 46 379 47T428 54T478 72T522 106T564 161Q580 191 594 228T611 270Q616 273 628 273H641Q647 264 647 262T627 203T583 83T557 9Q555 4 553 3T537 0T494 -1Q483 -1 418 -1T294 0H116Q32 0 32 10Q32 17 34 24Q39 43 44 45Q48 46 59 46H65Q92 46 125 49Q139 52 144 61Q147 65 216 339T285 628Q285 635 228 637Z"></path></g><g transform="translate(3836,0)"><path stroke-width="1" d="M492 213Q472 213 472 226Q472 230 477 250T482 285Q482 316 461 323T364 330H312Q311 328 277 192T243 52Q243 48 254 48T334 46Q428 46 458 48T518 61Q567 77 599 117T670 248Q680 270 683 272Q690 274 698 274Q718 274 718 261Q613 7 608 2Q605 0 322 0H133Q31 0 31 11Q31 13 34 25Q38 41 42 43T65 46Q92 46 125 49Q139 52 144 61Q146 66 215 342T285 622Q285 629 281 629Q273 632 228 634H197Q191 640 191 642T193 659Q197 676 203 680H757Q764 676 764 669Q764 664 751 557T737 447Q735 440 717 440H705Q698 445 698 453L701 476Q704 500 704 528Q704 558 697 578T678 609T643 625T596 632T532 634H485Q397 633 392 631Q388 629 386 622Q385 619 355 499T324 377Q347 376 372 376H398Q464 376 489 391T534 472Q538 488 540 490T557 493Q562 493 565 493T570 492T572 491T574 487T577 483L544 351Q511 218 508 216Q505 213 492 213Z"></path></g><g transform="translate(4601,0)"><path stroke-width="1" d="M234 637Q231 637 226 637Q201 637 196 638T191 649Q191 676 202 682Q204 683 299 683Q376 683 387 683T401 677Q612 181 616 168L670 381Q723 592 723 606Q723 633 659 637Q635 637 635 648Q635 650 637 660Q641 676 643 679T653 683Q656 683 684 682T767 680Q817 680 843 681T873 682Q888 682 888 672Q888 650 880 642Q878 637 858 637Q787 633 769 597L620 7Q618 0 599 0Q585 0 582 2Q579 5 453 305L326 604L261 344Q196 88 196 79Q201 46 268 46H278Q284 41 284 38T282 19Q278 6 272 0H259Q228 2 151 2Q123 2 100 2T63 2T46 1Q31 1 31 10Q31 14 34 26T39 40Q41 46 62 46Q130 49 150 85Q154 91 221 362L289 634Q287 635 234 637Z"></path></g></g></svg></span> is the maximum size of <span style="font-size: 100%; display: inline-block;" class="MathJax_SVG" id="MathJax-Element-5-Frame"><svg xlink="http://www.w3.org/1999/xlink" width="1.09ex" height="1.676ex" style="vertical-align: -0.338ex;" viewBox="0 -576.1 469.5 721.6" role="img" focusable="false"><g stroke="currentColor" fill="currentColor" stroke-width="0" transform="matrix(1 0 0 -1 0 0)"><path stroke-width="1" d="M131 289Q131 321 147 354T203 415T300 442Q362 442 390 415T419 355Q419 323 402 308T364 292Q351 292 340 300T328 326Q328 342 337 354T354 372T367 378Q368 378 368 379Q368 382 361 388T336 399T297 405Q249 405 227 379T204 326Q204 301 223 291T278 274T330 259Q396 230 396 163Q396 135 385 107T352 51T289 7T195 -10Q118 -10 86 19T53 87Q53 126 74 143T118 160Q133 160 146 151T160 120Q160 94 142 76T111 58Q109 57 108 57T107 55Q108 52 115 47T146 34T201 27Q237 27 263 38T301 66T318 97T323 122Q323 150 302 164T254 181T195 196T148 231Q131 256 131 289Z"></path></g></svg></span>. Here, <code>[]</code> is the scanset character. <code>^\n</code> stands for taking input until a newline isn't encountered. Then, with this <code>%*c</code>, it reads the newline character and here, the used <code>*</code> indicates that this newline character is discarded.</p>

<p><strong>Note:</strong> After inputting the character and the string, 
inputting the sentence by the above mentioned statement won't work. This
 is because, at the end of each line, a new line character (<code>\n</code>) is present. So, the statement: <code>scanf("%[^\n]%*c", s);</code>
 will not work because the last statement will read a newline character 
from the previous line. This can be handled in a variety of ways and one
 of them being: <code>scanf("\n");</code> before the last statement.  </p>

<p><strong>Task</strong></p>

<p>You have to print the character, <span style="font-size: 100%; display: inline-block;" class="MathJax_SVG" id="MathJax-Element-6-Frame"><svg xlink="http://www.w3.org/1999/xlink" width="2.346ex" height="2.176ex" style="vertical-align: -0.338ex;" viewBox="0 -791.3 1010 936.9" role="img" focusable="false"><g stroke="currentColor" fill="currentColor" stroke-width="0" transform="matrix(1 0 0 -1 0 0)"><path stroke-width="1" d="M34 159Q34 268 120 355T306 442Q362 442 394 418T427 355Q427 326 408 306T360 285Q341 285 330 295T319 325T330 359T352 380T366 386H367Q367 388 361 392T340 400T306 404Q276 404 249 390Q228 381 206 359Q162 315 142 235T121 119Q121 73 147 50Q169 26 205 26H209Q321 26 394 111Q403 121 406 121Q410 121 419 112T429 98T420 83T391 55T346 25T282 0T202 -11Q127 -11 81 37T34 159Z"></path><g transform="translate(433,0)"><path stroke-width="1" d="M137 683Q138 683 209 688T282 694Q294 694 294 685Q294 674 258 534Q220 386 220 383Q220 381 227 388Q288 442 357 442Q411 442 444 415T478 336Q478 285 440 178T402 50Q403 36 407 31T422 26Q450 26 474 56T513 138Q516 149 519 151T535 153Q555 153 555 145Q555 144 551 130Q535 71 500 33Q466 -10 419 -10H414Q367 -10 346 17T325 74Q325 90 361 192T398 345Q398 404 354 404H349Q266 404 205 306L198 293L164 158Q132 28 127 16Q114 -11 83 -11Q69 -11 59 -2T48 16Q48 30 121 320L195 616Q195 629 188 632T149 637H128Q122 643 122 645T124 664Q129 683 137 683Z"></path></g></g></svg></span>, in the first line. Then print <span style="font-size: 100%; display: inline-block;" class="MathJax_SVG" id="MathJax-Element-7-Frame"><svg xlink="http://www.w3.org/1999/xlink" width="1.09ex" height="1.676ex" style="vertical-align: -0.338ex;" viewBox="0 -576.1 469.5 721.6" role="img" focusable="false"><g stroke="currentColor" fill="currentColor" stroke-width="0" transform="matrix(1 0 0 -1 0 0)"><path stroke-width="1" d="M131 289Q131 321 147 354T203 415T300 442Q362 442 390 415T419 355Q419 323 402 308T364 292Q351 292 340 300T328 326Q328 342 337 354T354 372T367 378Q368 378 368 379Q368 382 361 388T336 399T297 405Q249 405 227 379T204 326Q204 301 223 291T278 274T330 259Q396 230 396 163Q396 135 385 107T352 51T289 7T195 -10Q118 -10 86 19T53 87Q53 126 74 143T118 160Q133 160 146 151T160 120Q160 94 142 76T111 58Q109 57 108 57T107 55Q108 52 115 47T146 34T201 27Q237 27 263 38T301 66T318 97T323 122Q323 150 302 164T254 181T195 196T148 231Q131 256 131 289Z"></path></g></svg></span> in  next line. In the last line print the sentence, <span style="font-size: 100%; display: inline-block;" class="MathJax_SVG" id="MathJax-Element-8-Frame"><svg xlink="http://www.w3.org/1999/xlink" width="3.569ex" height="1.676ex" style="vertical-align: -0.338ex;" viewBox="0 -576.1 1536.5 721.6" role="img" focusable="false"><g stroke="currentColor" fill="currentColor" stroke-width="0" transform="matrix(1 0 0 -1 0 0)"><path stroke-width="1" d="M131 289Q131 321 147 354T203 415T300 442Q362 442 390 415T419 355Q419 323 402 308T364 292Q351 292 340 300T328 326Q328 342 337 354T354 372T367 378Q368 378 368 379Q368 382 361 388T336 399T297 405Q249 405 227 379T204 326Q204 301 223 291T278 274T330 259Q396 230 396 163Q396 135 385 107T352 51T289 7T195 -10Q118 -10 86 19T53 87Q53 126 74 143T118 160Q133 160 146 151T160 120Q160 94 142 76T111 58Q109 57 108 57T107 55Q108 52 115 47T146 34T201 27Q237 27 263 38T301 66T318 97T323 122Q323 150 302 164T254 181T195 196T148 231Q131 256 131 289Z"></path><g transform="translate(469,0)"><path stroke-width="1" d="M39 168Q39 225 58 272T107 350T174 402T244 433T307 442H310Q355 442 388 420T421 355Q421 265 310 237Q261 224 176 223Q139 223 138 221Q138 219 132 186T125 128Q125 81 146 54T209 26T302 45T394 111Q403 121 406 121Q410 121 419 112T429 98T420 82T390 55T344 24T281 -1T205 -11Q126 -11 83 42T39 168ZM373 353Q367 405 305 405Q272 405 244 391T199 357T170 316T154 280T149 261Q149 260 169 260Q282 260 327 284T373 353Z"></path></g><g transform="translate(936,0)"><path stroke-width="1" d="M21 287Q22 293 24 303T36 341T56 388T89 425T135 442Q171 442 195 424T225 390T231 369Q231 367 232 367L243 378Q304 442 382 442Q436 442 469 415T503 336T465 179T427 52Q427 26 444 26Q450 26 453 27Q482 32 505 65T540 145Q542 153 560 153Q580 153 580 145Q580 144 576 130Q568 101 554 73T508 17T439 -10Q392 -10 371 17T350 73Q350 92 386 193T423 345Q423 404 379 404H374Q288 404 229 303L222 291L189 157Q156 26 151 16Q138 -11 108 -11Q95 -11 87 -5T76 7T74 17Q74 30 112 180T152 343Q153 348 153 366Q153 405 129 405Q91 405 66 305Q60 285 60 284Q58 278 41 278H27Q21 284 21 287Z"></path></g></g></svg></span>.</p></div></div></div><div class="challenge_input_format"><div class="msB challenge_input_format_title"><p><strong>Input Format</strong></p></div><div class="msB challenge_input_format_body"><div class="hackdown-content"><style id="MathJax_SVG_styles">.MathJax_SVG_Display {text-align: center; margin: 1em 0em; position: relative; display: block!important; text-indent: 0; max-width: none; max-height: none; min-width: 0; min-height: 0; width: 100%}
.MathJax_SVG .MJX-monospace {font-family: monospace}
.MathJax_SVG .MJX-sans-serif {font-family: sans-serif}
.MathJax_SVG {display: inline; font-style: normal; font-weight: normal; line-height: normal; font-size: 100%; font-size-adjust: none; text-indent: 0; text-align: left; text-transform: none; letter-spacing: normal; word-spacing: normal; word-wrap: normal; white-space: nowrap; float: none; direction: ltr; max-width: none; max-height: none; min-width: 0; min-height: 0; border: 0; padding: 0; margin: 0}
.MathJax_SVG * {transition: none; -webkit-transition: none; -moz-transition: none; -ms-transition: none; -o-transition: none}
.mjx-svg-href {fill: blue; stroke: blue}
.MathJax_SVG_LineBox {display: table!important}
.MathJax_SVG_LineBox span {display: table-cell!important; width: 10000em!important; min-width: 0; max-width: none; padding: 0; border: 0; margin: 0}
</style><svg style="display: none;"><defs id="MathJax_SVG_glyphs"></defs></svg><p>First, take a character, <span style="font-size: 100%; display: inline-block;" class="MathJax_SVG" id="MathJax-Element-1-Frame"><svg xlink="http://www.w3.org/1999/xlink" width="2.346ex" height="2.176ex" style="vertical-align: -0.338ex;" viewBox="0 -791.3 1010 936.9" role="img" focusable="false"><g stroke="currentColor" fill="currentColor" stroke-width="0" transform="matrix(1 0 0 -1 0 0)"><path stroke-width="1" d="M34 159Q34 268 120 355T306 442Q362 442 394 418T427 355Q427 326 408 306T360 285Q341 285 330 295T319 325T330 359T352 380T366 386H367Q367 388 361 392T340 400T306 404Q276 404 249 390Q228 381 206 359Q162 315 142 235T121 119Q121 73 147 50Q169 26 205 26H209Q321 26 394 111Q403 121 406 121Q410 121 419 112T429 98T420 83T391 55T346 25T282 0T202 -11Q127 -11 81 37T34 159Z"></path><g transform="translate(433,0)"><path stroke-width="1" d="M137 683Q138 683 209 688T282 694Q294 694 294 685Q294 674 258 534Q220 386 220 383Q220 381 227 388Q288 442 357 442Q411 442 444 415T478 336Q478 285 440 178T402 50Q403 36 407 31T422 26Q450 26 474 56T513 138Q516 149 519 151T535 153Q555 153 555 145Q555 144 551 130Q535 71 500 33Q466 -10 419 -10H414Q367 -10 346 17T325 74Q325 90 361 192T398 345Q398 404 354 404H349Q266 404 205 306L198 293L164 158Q132 28 127 16Q114 -11 83 -11Q69 -11 59 -2T48 16Q48 30 121 320L195 616Q195 629 188 632T149 637H128Q122 643 122 645T124 664Q129 683 137 683Z"></path></g></g></svg></span> as input. <br>
Then take the string, <span style="font-size: 100%; display: inline-block;" class="MathJax_SVG" id="MathJax-Element-2-Frame"><svg xlink="http://www.w3.org/1999/xlink" width="1.09ex" height="1.676ex" style="vertical-align: -0.338ex;" viewBox="0 -576.1 469.5 721.6" role="img" focusable="false"><g stroke="currentColor" fill="currentColor" stroke-width="0" transform="matrix(1 0 0 -1 0 0)"><path stroke-width="1" d="M131 289Q131 321 147 354T203 415T300 442Q362 442 390 415T419 355Q419 323 402 308T364 292Q351 292 340 300T328 326Q328 342 337 354T354 372T367 378Q368 378 368 379Q368 382 361 388T336 399T297 405Q249 405 227 379T204 326Q204 301 223 291T278 274T330 259Q396 230 396 163Q396 135 385 107T352 51T289 7T195 -10Q118 -10 86 19T53 87Q53 126 74 143T118 160Q133 160 146 151T160 120Q160 94 142 76T111 58Q109 57 108 57T107 55Q108 52 115 47T146 34T201 27Q237 27 263 38T301 66T318 97T323 122Q323 150 302 164T254 181T195 196T148 231Q131 256 131 289Z"></path></g></svg></span> as input. <br>
Lastly, take the sentence <span style="font-size: 100%; display: inline-block;" class="MathJax_SVG" id="MathJax-Element-3-Frame"><svg xlink="http://www.w3.org/1999/xlink" width="3.569ex" height="1.676ex" style="vertical-align: -0.338ex;" viewBox="0 -576.1 1536.5 721.6" role="img" focusable="false"><g stroke="currentColor" fill="currentColor" stroke-width="0" transform="matrix(1 0 0 -1 0 0)"><path stroke-width="1" d="M131 289Q131 321 147 354T203 415T300 442Q362 442 390 415T419 355Q419 323 402 308T364 292Q351 292 340 300T328 326Q328 342 337 354T354 372T367 378Q368 378 368 379Q368 382 361 388T336 399T297 405Q249 405 227 379T204 326Q204 301 223 291T278 274T330 259Q396 230 396 163Q396 135 385 107T352 51T289 7T195 -10Q118 -10 86 19T53 87Q53 126 74 143T118 160Q133 160 146 151T160 120Q160 94 142 76T111 58Q109 57 108 57T107 55Q108 52 115 47T146 34T201 27Q237 27 263 38T301 66T318 97T323 122Q323 150 302 164T254 181T195 196T148 231Q131 256 131 289Z"></path><g transform="translate(469,0)"><path stroke-width="1" d="M39 168Q39 225 58 272T107 350T174 402T244 433T307 442H310Q355 442 388 420T421 355Q421 265 310 237Q261 224 176 223Q139 223 138 221Q138 219 132 186T125 128Q125 81 146 54T209 26T302 45T394 111Q403 121 406 121Q410 121 419 112T429 98T420 82T390 55T344 24T281 -1T205 -11Q126 -11 83 42T39 168ZM373 353Q367 405 305 405Q272 405 244 391T199 357T170 316T154 280T149 261Q149 260 169 260Q282 260 327 284T373 353Z"></path></g><g transform="translate(936,0)"><path stroke-width="1" d="M21 287Q22 293 24 303T36 341T56 388T89 425T135 442Q171 442 195 424T225 390T231 369Q231 367 232 367L243 378Q304 442 382 442Q436 442 469 415T503 336T465 179T427 52Q427 26 444 26Q450 26 453 27Q482 32 505 65T540 145Q542 153 560 153Q580 153 580 145Q580 144 576 130Q568 101 554 73T508 17T439 -10Q392 -10 371 17T350 73Q350 92 386 193T423 345Q423 404 379 404H374Q288 404 229 303L222 291L189 157Q156 26 151 16Q138 -11 108 -11Q95 -11 87 -5T76 7T74 17Q74 30 112 180T152 343Q153 348 153 366Q153 405 129 405Q91 405 66 305Q60 285 60 284Q58 278 41 278H27Q21 284 21 287Z"></path></g></g></svg></span> as input.</p></div></div></div><div class="challenge_output_format"><div class="msB challenge_output_format_title"><p><strong>Output Format</strong></p></div><div class="msB challenge_output_format_body"><div class="hackdown-content"><style id="MathJax_SVG_styles">.MathJax_SVG_Display {text-align: center; margin: 1em 0em; position: relative; display: block!important; text-indent: 0; max-width: none; max-height: none; min-width: 0; min-height: 0; width: 100%}
.MathJax_SVG .MJX-monospace {font-family: monospace}
.MathJax_SVG .MJX-sans-serif {font-family: sans-serif}
.MathJax_SVG {display: inline; font-style: normal; font-weight: normal; line-height: normal; font-size: 100%; font-size-adjust: none; text-indent: 0; text-align: left; text-transform: none; letter-spacing: normal; word-spacing: normal; word-wrap: normal; white-space: nowrap; float: none; direction: ltr; max-width: none; max-height: none; min-width: 0; min-height: 0; border: 0; padding: 0; margin: 0}
.MathJax_SVG * {transition: none; -webkit-transition: none; -moz-transition: none; -ms-transition: none; -o-transition: none}
.mjx-svg-href {fill: blue; stroke: blue}
.MathJax_SVG_LineBox {display: table!important}
.MathJax_SVG_LineBox span {display: table-cell!important; width: 10000em!important; min-width: 0; max-width: none; padding: 0; border: 0; margin: 0}
</style><svg style="display: none;"><defs id="MathJax_SVG_glyphs"></defs></svg><p>Print three lines of output. The first line prints the character, <span style="font-size: 100%; display: inline-block;" class="MathJax_SVG" id="MathJax-Element-1-Frame"><svg xlink="http://www.w3.org/1999/xlink" width="2.346ex" height="2.176ex" style="vertical-align: -0.338ex;" viewBox="0 -791.3 1010 936.9" role="img" focusable="false"><g stroke="currentColor" fill="currentColor" stroke-width="0" transform="matrix(1 0 0 -1 0 0)"><path stroke-width="1" d="M34 159Q34 268 120 355T306 442Q362 442 394 418T427 355Q427 326 408 306T360 285Q341 285 330 295T319 325T330 359T352 380T366 386H367Q367 388 361 392T340 400T306 404Q276 404 249 390Q228 381 206 359Q162 315 142 235T121 119Q121 73 147 50Q169 26 205 26H209Q321 26 394 111Q403 121 406 121Q410 121 419 112T429 98T420 83T391 55T346 25T282 0T202 -11Q127 -11 81 37T34 159Z"></path><g transform="translate(433,0)"><path stroke-width="1" d="M137 683Q138 683 209 688T282 694Q294 694 294 685Q294 674 258 534Q220 386 220 383Q220 381 227 388Q288 442 357 442Q411 442 444 415T478 336Q478 285 440 178T402 50Q403 36 407 31T422 26Q450 26 474 56T513 138Q516 149 519 151T535 153Q555 153 555 145Q555 144 551 130Q535 71 500 33Q466 -10 419 -10H414Q367 -10 346 17T325 74Q325 90 361 192T398 345Q398 404 354 404H349Q266 404 205 306L198 293L164 158Q132 28 127 16Q114 -11 83 -11Q69 -11 59 -2T48 16Q48 30 121 320L195 616Q195 629 188 632T149 637H128Q122 643 122 645T124 664Q129 683 137 683Z"></path></g></g></svg></span>. <br>
The second line prints the string, <span style="font-size: 100%; display: inline-block;" class="MathJax_SVG" id="MathJax-Element-2-Frame"><svg xlink="http://www.w3.org/1999/xlink" width="1.09ex" height="1.676ex" style="vertical-align: -0.338ex;" viewBox="0 -576.1 469.5 721.6" role="img" focusable="false"><g stroke="currentColor" fill="currentColor" stroke-width="0" transform="matrix(1 0 0 -1 0 0)"><path stroke-width="1" d="M131 289Q131 321 147 354T203 415T300 442Q362 442 390 415T419 355Q419 323 402 308T364 292Q351 292 340 300T328 326Q328 342 337 354T354 372T367 378Q368 378 368 379Q368 382 361 388T336 399T297 405Q249 405 227 379T204 326Q204 301 223 291T278 274T330 259Q396 230 396 163Q396 135 385 107T352 51T289 7T195 -10Q118 -10 86 19T53 87Q53 126 74 143T118 160Q133 160 146 151T160 120Q160 94 142 76T111 58Q109 57 108 57T107 55Q108 52 115 47T146 34T201 27Q237 27 263 38T301 66T318 97T323 122Q323 150 302 164T254 181T195 196T148 231Q131 256 131 289Z"></path></g></svg></span>. <br>
The third line prints the sentence, <span style="font-size: 100%; display: inline-block;" class="MathJax_SVG" id="MathJax-Element-3-Frame"><svg xlink="http://www.w3.org/1999/xlink" width="3.569ex" height="1.676ex" style="vertical-align: -0.338ex;" viewBox="0 -576.1 1536.5 721.6" role="img" focusable="false"><g stroke="currentColor" fill="currentColor" stroke-width="0" transform="matrix(1 0 0 -1 0 0)"><path stroke-width="1" d="M131 289Q131 321 147 354T203 415T300 442Q362 442 390 415T419 355Q419 323 402 308T364 292Q351 292 340 300T328 326Q328 342 337 354T354 372T367 378Q368 378 368 379Q368 382 361 388T336 399T297 405Q249 405 227 379T204 326Q204 301 223 291T278 274T330 259Q396 230 396 163Q396 135 385 107T352 51T289 7T195 -10Q118 -10 86 19T53 87Q53 126 74 143T118 160Q133 160 146 151T160 120Q160 94 142 76T111 58Q109 57 108 57T107 55Q108 52 115 47T146 34T201 27Q237 27 263 38T301 66T318 97T323 122Q323 150 302 164T254 181T195 196T148 231Q131 256 131 289Z"></path><g transform="translate(469,0)"><path stroke-width="1" d="M39 168Q39 225 58 272T107 350T174 402T244 433T307 442H310Q355 442 388 420T421 355Q421 265 310 237Q261 224 176 223Q139 223 138 221Q138 219 132 186T125 128Q125 81 146 54T209 26T302 45T394 111Q403 121 406 121Q410 121 419 112T429 98T420 82T390 55T344 24T281 -1T205 -11Q126 -11 83 42T39 168ZM373 353Q367 405 305 405Q272 405 244 391T199 357T170 316T154 280T149 261Q149 260 169 260Q282 260 327 284T373 353Z"></path></g><g transform="translate(936,0)"><path stroke-width="1" d="M21 287Q22 293 24 303T36 341T56 388T89 425T135 442Q171 442 195 424T225 390T231 369Q231 367 232 367L243 378Q304 442 382 442Q436 442 469 415T503 336T465 179T427 52Q427 26 444 26Q450 26 453 27Q482 32 505 65T540 145Q542 153 560 153Q580 153 580 145Q580 144 576 130Q568 101 554 73T508 17T439 -10Q392 -10 371 17T350 73Q350 92 386 193T423 345Q423 404 379 404H374Q288 404 229 303L222 291L189 157Q156 26 151 16Q138 -11 108 -11Q95 -11 87 -5T76 7T74 17Q74 30 112 180T152 343Q153 348 153 366Q153 405 129 405Q91 405 66 305Q60 285 60 284Q58 278 41 278H27Q21 284 21 287Z"></path></g></g></svg></span>.</p></div></div></div><div class="challenge_sample_input"><div class="msB challenge_sample_input_title"><p><strong>Sample Input 0</strong></p></div><div class="msB challenge_sample_input_body"><div class="hackdown-content"><style id="MathJax_SVG_styles">.MathJax_SVG_Display {text-align: center; margin: 1em 0em; position: relative; display: block!important; text-indent: 0; max-width: none; max-height: none; min-width: 0; min-height: 0; width: 100%}
.MathJax_SVG .MJX-monospace {font-family: monospace}
.MathJax_SVG .MJX-sans-serif {font-family: sans-serif}
.MathJax_SVG {display: inline; font-style: normal; font-weight: normal; line-height: normal; font-size: 100%; font-size-adjust: none; text-indent: 0; text-align: left; text-transform: none; letter-spacing: normal; word-spacing: normal; word-wrap: normal; white-space: nowrap; float: none; direction: ltr; max-width: none; max-height: none; min-width: 0; min-height: 0; border: 0; padding: 0; margin: 0}
.MathJax_SVG * {transition: none; -webkit-transition: none; -moz-transition: none; -ms-transition: none; -o-transition: none}
.mjx-svg-href {fill: blue; stroke: blue}
.MathJax_SVG_LineBox {display: table!important}
.MathJax_SVG_LineBox span {display: table-cell!important; width: 10000em!important; min-width: 0; max-width: none; padding: 0; border: 0; margin: 0}
</style><svg style="display: none;"><defs id="MathJax_SVG_glyphs"></defs></svg><div class="highlight"><pre><span></span><span class="err">C</span>
<span class="err">Language</span>
<span class="err">Welcome To C!!</span>
</pre></div>
</div></div></div><div class="challenge_sample_output"><div class="msB challenge_sample_output_title"><p><strong>Sample Output 0</strong></p></div><div class="msB challenge_sample_output_body"><div class="hackdown-content"><style id="MathJax_SVG_styles">.MathJax_SVG_Display {text-align: center; margin: 1em 0em; position: relative; display: block!important; text-indent: 0; max-width: none; max-height: none; min-width: 0; min-height: 0; width: 100%}
.MathJax_SVG .MJX-monospace {font-family: monospace}
.MathJax_SVG .MJX-sans-serif {font-family: sans-serif}
.MathJax_SVG {display: inline; font-style: normal; font-weight: normal; line-height: normal; font-size: 100%; font-size-adjust: none; text-indent: 0; text-align: left; text-transform: none; letter-spacing: normal; word-spacing: normal; word-wrap: normal; white-space: nowrap; float: none; direction: ltr; max-width: none; max-height: none; min-width: 0; min-height: 0; border: 0; padding: 0; margin: 0}
.MathJax_SVG * {transition: none; -webkit-transition: none; -moz-transition: none; -ms-transition: none; -o-transition: none}
.mjx-svg-href {fill: blue; stroke: blue}
.MathJax_SVG_LineBox {display: table!important}
.MathJax_SVG_LineBox span {display: table-cell!important; width: 10000em!important; min-width: 0; max-width: none; padding: 0; border: 0; margin: 0}
</style><svg style="display: none;"><defs id="MathJax_SVG_glyphs"></defs></svg><div class="highlight"><pre><span></span><span class="err">C</span>
<span class="err">Language</span>
<span class="err">Welcome To C!!</span>
</pre></div>
</div></div></div></div></div></div></div></section><section class="code-editor-section split"><div><div></div><div class="codeeditor-view theme-m-section"><div id="codeshell-wrapper">
<div class="clearfix grey-header fixed-hand0 cap plL plR psT psB" style="position: relative;">
  <div class="msT pull-left"><em id="status-text"></em></div>
  
  <div class="fork-dialog cs-dialog hide">
    <div class="header">Fork <span class="version-seq"></span>
        <i data-analytics="CodeShellForkCode" data-attr1="Cancel" class="icon--single icon-cancel-small close-fork-dialog cursor-pointer pull-right psR"></i>
    </div>
    <div class="body">
      <p class="grey-msg">past buffers are marked read only, you wont be able to edit your current buffer without forking it</p>
      <div class="m msT">
        <button data-analytics="CodeShellForkCode" data-attr1="ForkCurrentBuffer" class="btn btn-primary fork-version" data-action="fork">Fork <span class="version-seq"></span></button>&nbsp;&nbsp;
        <button data-analytics="CodeShellForkCode" data-attr1="CreateNewBuffer" class="btn btn-primary fork-version" data-action="orphan">Create New Buffer</button>
      </div>
    </div>
  </div>
  <div class="fork-limit-reached-dialog cs-dialog hide">
    <div class="header">Fork Limit Reached</div>
    <div class="body">
      <p class="grey-msg">You can’t create more than 20 buffers, please delete one of your old bufferes to create a new buffer.</p>
      <div class="m msT">
        <button class="btn close-fork-limit-reached-dialog">OK</button>&nbsp;&nbsp;
      </div>
    </div>
  </div>
  <div class="delete-version-dialog cs-dialog hide">
    <div class="header">Delete <span class="version-seq"></span></div>
    <div class="body">
      <p class="grey-msg">Are you sure you want to delete <strong><span class="version-seq"></span></strong>? This action can’t be undone.</p>
      <div class="m msT">
        <button class="btn delete-version-button">Yes</button>&nbsp;&nbsp;
      </div>
    </div>
  </div>
  <div class="pull-left no-select">
    <p style="padding-top: 8px;">
      <strong class="version-name">Current Buffer</strong>
      <span class="gray-text version-meta">(saved locally, editable)</span>
      &nbsp;&nbsp;
      <a data-analytics="CodeShellShowForkOptions" class="fork-this-version"><i class="icon--grey cursor icon-flow-branch"></i></a>
      <a data-analytics="CodeShellShowVersionTimeline" class="show-version-timeline"><i class="icon--grey cursor icon-back-in-time"></i></a>
      <a class="delete-active-version hide"><i class="icon--grey cursor icon-trash"></i></a>
    </p>
  </div>
  
  
  <div class="pull-right">
    
    <div class="inline large lines inverse pull-right msT msL">
      
      
      <a class="restorefullscreen force-hide active-link no-select">
          <i class="icon-resize-small-alt icon--grey no-select"></i></a>
      <a class="fullscreen active-link no-select" data-analytics="Switch to fullscreen"><i class="icon-resize-full-alt icon--grey no-select"></i></a>
      
      
      
      <a class="hide" style="display:none;"></a>
      <div class="settings-editor" style="position:relative; margin-left: 0px;">
        <a class="cursor no-select" data-analytics="CodeShellShowPreferences" id="show-preferences"><i class="icon-cog icon--grey no-select"></i></a>
        <div id="pref-pane" style="position: absolute;right: -0.5em;top: 2em;z-index: 9;background: #fff;border: 1px solid #ddd;border-radius: 5px;padding: 10px;  width: 25em; display: none;">
          <div style="position: absolute;width: 0;right: 0.8em;height: 0;border-left: 7px solid transparent;border-right: 7px solid transparent;border-bottom: 7px solid #ddd;top: -0.4em;"></div>
          
            <div class="formgroup horizontal">
              <label class="span5">Editor Mode</label>
              <div class="inline">
                <div class="btn-group no-select">
                  <a data-analytics="CodeShellEditorMode" data-attr1="Emacs" class="cursor emacs btn btn-small btn-white editor-mode-button no-select" data-editor="emacs">Emacs</a>
                  <a data-analytics="CodeShellEditorMode" data-attr1="Normal" class="cursor default btn btn-small btn-white editor-mode-button no-select btn-primary" data-editor="sublime">Normal</a>
                  <a data-analytics="CodeShellEditorMode" data-attr1="Vim" class="cursor vim btn btn-small btn-white editor-mode-button no-select" data-editor="vim">Vim</a>
                </div>
              </div>
            </div>
          
          
            <div class="formgroup horizontal">
              <label class="span5">Editor Theme</label>
              <div class="inline">
                <div class="btn-group no-select">
                  <a data-analytics="CodeShellEditorTheme" data-attr1="Light" class="cursor light btn btn-small btn-white editor-theme-button no-select btn-primary" data-editor="light">Light</a>
                  <a data-analytics="CodeShellEditorTheme" data-attr1="Dark" class="cursor dark btn btn-small btn-white editor-theme-button no-select" data-editor="dark">Dark</a>
                </div>
              </div>
            </div>
          
          <div class="formgroup horizontal">
            <label class="span5">Tab Spaces</label>
            <div class="inline">
              <div class="btn-group no-select">
                <a data-analytics="CodeShellEditorSpace" data-attr1="2" class="cursor 2space btn btn-small btn-white editor-tabspace-button no-select" data-editor="2">2 spaces</a>
                <a data-analytics="CodeShellEditorSpace" data-attr1="4" class="cursor 4space  btn btn-small btn-white editor-tabspace-button no-select btn-primary" data-editor="4">4 spaces</a>
                <a data-analytics="CodeShellEditorSpace" data-attr1="8" class="cursor 8space btn btn-small btn-white editor-tabspace-button no-select" data-editor="8">8 spaces</a>
              </div>
            </div>
          </div>
          
            <div class="formgroup horizontal">
              <label class="span5">Intellisense
              
              <span data-balloon="Available only for C, C++, Java, Python, JavaScript, Ruby, PHP, C# and Go" data-balloon-pos="down">
              
              <i class="icon-info-circled fnt-sz-small txt-navy"></i>
              </span></label>
              <div class="inline">
                <div class="btn-group no-select">
                  <a data-analytics="CodeShellAutoComplete" data-attr1="Enable" class="cursor emacs btn btn-small btn-white editor-autocomplete-button no-select btn-primary" data-editor="true">Enable</a>
                  <a data-analytics="CodeShellAutoComplete" data-attr1="Disable" class="cursor default btn btn-small btn-white editor-autocomplete-button no-select" data-editor="false">Disable</a>
                </div>
              </div>
            </div>
          
          
        </div>
      </div>
      
    </div>
    
    <div class="pull-right lang-placeholder">
      <div class="dummy-lang-container hide"></div>
      <div id="s2id_select-lang" class="select2-container"><a href="javascript:void(0)" onclick="return false;" class="select2-choice" tabindex="-1">   <span>C</span><abbr class="select2-search-choice-close"></abbr>   <div><b></b></div></a><input id="s2id_autogen2" class="select2-focusser select2-offscreen" type="text"><div class="select2-drop select2-display-none">   <div class="select2-search select2-search-hidden select2-offscreen">       <input autocomplete="off" autocorrect="off" autocapitilize="off" spellcheck="false" class="select2-input" type="text">   </div>   <ul class="select2-results">   </ul></div></div><input value="c" class="select2-offscreen" tabindex="-1" id="select-lang" type="hidden">
    </div>
    
    <div class="clearfix"></div>
  </div>
</div>


<div class="version-timeline">
  <div class="version-timeline-inner">
    <div class="cross-line"></div>
    <div class="start-slab pull-left"></div>
    
    <div class="current-version-ball green-bkg pull-left cursor"></div>
  </div>
</div>
<div class="hr_tour-code-solution movable-hand flex-row" style="display: flex;">
  
  <div class="code-checker">
    <div id="notification-message" class="clearfix grey-header cap  hidden "> </div>
    <div style="max-height: 538px;" class="code-editors">
      
       <div class="loading-mode" style="display: none;">Loading Editor... </div> 
      <div style="display: block;" class="code-body">
        
       <textarea id="codeview" style="width: 100%; display: none;"></textarea><div class="CodeMirror cm-s-default CodeMirror-wrap CodeMirror-focused"><div style="overflow: hidden; position: relative; width: 3px; height: 0px; top: 319px; left: 355px;"><textarea tabindex="0" spellcheck="false" autocapitalize="off" autocorrect="off" style="position: absolute; bottom: -1em; padding: 0px; width: 1px; height: 1em; outline: medium none;" wrap="off"></textarea></div><div cm-not-content="true" tabindex="-1" class="CodeMirror-vscrollbar"><div style="min-width: 1px; height: 0px;"></div></div><div cm-not-content="true" tabindex="-1" class="CodeMirror-hscrollbar"><div style="height: 100%; min-height: 1px; width: 0px;"></div></div><div cm-not-content="true" class="CodeMirror-scrollbar-filler"></div><div cm-not-content="true" class="CodeMirror-gutter-filler"></div><div draggable="true" tabindex="-1" class="CodeMirror-scroll"><div style="margin-left: 57px; margin-bottom: -17px; border-right-width: 13px; min-height: 428px; padding-right: 0px; padding-bottom: 0px;" class="CodeMirror-sizer"><div style="position: relative; top: 0px;"><div role="presentation" class="CodeMirror-lines"><div role="presentation" style="position: relative; outline: medium none;"><div class="CodeMirror-measure"><pre>x</pre></div><div class="CodeMirror-measure"></div><div style="position: relative; z-index: 1;"></div><div style="" class="CodeMirror-cursors"><div style="left: 298px; top: 315px; height: 21px;" class="CodeMirror-cursor">&nbsp;</div></div><div style="" role="presentation" class="CodeMirror-code"><div class="" style="position: relative;"><div style="left: -57px;" class="CodeMirror-gutter-wrapper"><div style="left: 16px; width: 21px;" class="CodeMirror-linenumber CodeMirror-gutter-elt">1</div><div style="left: 45px; width: 11px;" class="CodeMirror-gutter-elt"><div class="CodeMirror-foldgutter-open CodeMirror-guttermarker-subtle"></div></div></div><pre role="presentation" class=" CodeMirror-line "><span role="presentation"><span class="cm-meta">#include &lt;stdio.h&gt;</span></span></pre></div><div style="position: relative;"><div style="left: -57px;" class="CodeMirror-gutter-wrapper"><div style="left: 16px; width: 21px;" class="CodeMirror-linenumber CodeMirror-gutter-elt">2</div></div><pre role="presentation" class=" CodeMirror-line "><span role="presentation"><span class="cm-meta">#include &lt;string.h&gt;</span></span></pre></div><div style="position: relative;"><div style="left: -57px;" class="CodeMirror-gutter-wrapper"><div style="left: 16px; width: 21px;" class="CodeMirror-linenumber CodeMirror-gutter-elt">3</div></div><pre role="presentation" class=" CodeMirror-line "><span role="presentation"><span class="cm-meta">#include &lt;math.h&gt;</span></span></pre></div><div style="position: relative;"><div style="left: -57px;" class="CodeMirror-gutter-wrapper"><div style="left: 16px; width: 21px;" class="CodeMirror-linenumber CodeMirror-gutter-elt">4</div></div><pre role="presentation" class=" CodeMirror-line "><span role="presentation"><span class="cm-meta">#include &lt;stdlib.h&gt;</span></span></pre></div><div style="position: relative;"><div style="left: -57px;" class="CodeMirror-gutter-wrapper"><div style="left: 16px; width: 21px;" class="CodeMirror-linenumber CodeMirror-gutter-elt">5</div></div><pre role="presentation" class=" CodeMirror-line "><span role="presentation"><span cm-text="">​</span></span></pre></div><div style="position: relative;"><div style="left: -57px;" class="CodeMirror-gutter-wrapper"><div style="left: 16px; width: 21px;" class="CodeMirror-linenumber CodeMirror-gutter-elt">6</div></div><pre role="presentation" class=" CodeMirror-line "><span role="presentation"><span class="cm-type">int</span> <span class="cm-def">main</span>() </span></pre></div><div style="position: relative;"><div style="left: -57px;" class="CodeMirror-gutter-wrapper"><div style="left: 16px; width: 21px;" class="CodeMirror-linenumber CodeMirror-gutter-elt">7</div><div style="left: 45px; width: 11px;" class="CodeMirror-gutter-elt"><div class="CodeMirror-foldgutter-open CodeMirror-guttermarker-subtle"></div></div></div><pre role="presentation" class=" CodeMirror-line "><span role="presentation">{</span></pre></div><div style="position: relative;"><div style="left: -57px;" class="CodeMirror-gutter-wrapper"><div style="left: 16px; width: 21px;" class="CodeMirror-linenumber CodeMirror-gutter-elt">8</div></div><pre role="presentation" class=" CodeMirror-line "><span role="presentation"><span cm-text="">​</span></span></pre></div><div style="position: relative;"><div style="left: -57px;" class="CodeMirror-gutter-wrapper"><div style="left: 16px; width: 21px;" class="CodeMirror-linenumber CodeMirror-gutter-elt">9</div></div><pre role="presentation" class=" CodeMirror-line "><span role="presentation">    <span class="cm-type">char</span> <span class="cm-variable">ch</span>;</span></pre></div><div style="position: relative;"><div style="left: -57px;" class="CodeMirror-gutter-wrapper"><div style="left: 16px; width: 21px;" class="CodeMirror-linenumber CodeMirror-gutter-elt">10</div><div style="left: 45px; width: 11px;" class="CodeMirror-gutter-elt"><div class="CodeMirror-foldgutter-open CodeMirror-guttermarker-subtle"></div></div></div><pre role="presentation" class=" CodeMirror-line "><span role="presentation">    <span class="cm-type">char</span> <span class="cm-variable">s</span>[<span class="cm-number">50</span>];</span></pre></div><div style="position: relative;"><div style="left: -57px;" class="CodeMirror-gutter-wrapper"><div style="left: 16px; width: 21px;" class="CodeMirror-linenumber CodeMirror-gutter-elt">11</div><div style="left: 45px; width: 11px;" class="CodeMirror-gutter-elt"><div class="CodeMirror-foldgutter-open CodeMirror-guttermarker-subtle"></div></div></div><pre role="presentation" class=" CodeMirror-line "><span role="presentation">    <span class="cm-type">char</span> <span class="cm-variable">sen</span>[<span class="cm-number">100</span>];</span></pre></div><div style="position: relative;"><div style="left: -57px;" class="CodeMirror-gutter-wrapper"><div style="left: 16px; width: 21px;" class="CodeMirror-linenumber CodeMirror-gutter-elt">12</div></div><pre role="presentation" class=" CodeMirror-line "><span role="presentation">    <span class="cm-variable">scanf</span>(<span class="cm-string">"%c"</span>,<span class="cm-operator">&amp;</span><span class="cm-variable">ch</span>);</span></pre></div><div style="position: relative;"><div style="left: -57px;" class="CodeMirror-gutter-wrapper"><div style="left: 16px; width: 21px;" class="CodeMirror-linenumber CodeMirror-gutter-elt">13</div></div><pre role="presentation" class=" CodeMirror-line "><span role="presentation">    <span class="cm-variable">scanf</span>(<span class="cm-string">"%s"</span>,<span class="cm-variable">s</span>);    </span></pre></div><div style="position: relative;"><div style="left: -57px;" class="CodeMirror-gutter-wrapper"><div style="left: 16px; width: 21px;" class="CodeMirror-linenumber CodeMirror-gutter-elt">14</div></div><pre role="presentation" class=" CodeMirror-line "><span role="presentation">    <span class="cm-variable">scanf</span>(<span class="cm-string">"\n"</span>);</span></pre></div><div style="position: relative;"><div style="left: -57px;" class="CodeMirror-gutter-wrapper"><div style="left: 16px; width: 21px;" class="CodeMirror-linenumber CodeMirror-gutter-elt">15</div></div><pre role="presentation" class=" CodeMirror-line "><span role="presentation">    <span class="cm-variable">scanf</span>(<span class="cm-string">"%[^\n]%*c"</span>, <span class="cm-variable">sen</span>);</span></pre></div><div class="CodeMirror-activeline" style="position: relative;"><div class="CodeMirror-activeline-background CodeMirror-linebackground"></div><div style="left: -57px; width: 57px;" class="CodeMirror-gutter-background CodeMirror-activeline-gutter"></div><div style="left: -57px;" class="CodeMirror-gutter-wrapper CodeMirror-activeline-gutter"><div style="left: 16px; width: 21px;" class="CodeMirror-linenumber CodeMirror-gutter-elt">16</div></div><pre role="presentation" class=" CodeMirror-line "><span role="presentation">    <span class="cm-variable">printf</span>(<span class="cm-string">"%c\n%s\n%s"</span>,<span class="cm-variable">ch</span>,<span class="cm-variable">s</span>,<span class="cm-variable">sen</span>); </span></pre></div><div style="position: relative;"><div style="left: -57px;" class="CodeMirror-gutter-wrapper"><div style="left: 16px; width: 21px;" class="CodeMirror-linenumber CodeMirror-gutter-elt">17</div></div><pre role="presentation" class=" CodeMirror-line "><span role="presentation">    </span></pre></div><div style="position: relative;"><div style="left: -57px;" class="CodeMirror-gutter-wrapper"><div style="left: 16px; width: 21px;" class="CodeMirror-linenumber CodeMirror-gutter-elt">18</div><div style="left: 45px; width: 11px;" class="CodeMirror-gutter-elt"><div class="CodeMirror-foldgutter-open CodeMirror-guttermarker-subtle"></div></div></div><pre role="presentation" class=" CodeMirror-line "><span role="presentation">    <span class="cm-comment">/* Enter your code here. Read input from STDIN. Print output to STDOUT */</span>    </span></pre></div><div style="position: relative;"><div style="left: -57px;" class="CodeMirror-gutter-wrapper"><div style="left: 16px; width: 21px;" class="CodeMirror-linenumber CodeMirror-gutter-elt">19</div></div><pre role="presentation" class=" CodeMirror-line "><span role="presentation">    <span class="cm-keyword">return</span> <span class="cm-number">0</span>;</span></pre></div><div class="" style="position: relative;"><div style="left: -57px;" class="CodeMirror-gutter-wrapper"><div style="left: 16px; width: 21px;" class="CodeMirror-linenumber CodeMirror-gutter-elt">20</div></div><pre role="presentation" class=" CodeMirror-line "><span role="presentation">}</span></pre></div></div></div></div></div></div><div style="position: absolute; height: 13px; width: 1px; border-bottom: 0px solid transparent; top: 428px;"></div><div style="height: 441px; left: 0px;" class="CodeMirror-gutters"><div class="CodeMirror-gutter CodeMirror-lint-markers"></div><div style="width: 29px;" class="CodeMirror-gutter CodeMirror-linenumbers"></div><div class="CodeMirror-gutter CodeMirror-foldgutter"></div></div></div></div>
       </div>
      
      <div class="clearfix"></div>
    </div>
    <div id="codeeditor-statusbar" class="clearfix psA codeeditor_statusbar">
      <span id="statusbar-mode"></span>
      <div class="pull-right">
        <span id="statusbar-line">Line: 16</span>
        <span id="statusbar-col">Col: 36</span>
        <span id="statusbar-count"></span>
      </div>
    </div>
  </div>
</div><div class="clearfix pmR pmL pmB plT fixed-hand1 codeshell-footer">
  <div class="pull-right">
    
    
    <button class="btn bb-compile msR " data-analytics="Compile and Test">Run Code</button>
    
    
    <button class="btn btn-primary bb-submit ans-submit" data-analytics="Submit Code">Submit Code</button>
    
    
  </div>
  <div class="pull-left inline">
      
      <button class="btn btn-text upload_file mlR" data-analytics="Upload File" type="button"><i class="icon-upload"></i>Upload Code as File</button>
      
      
      
      <div class="mmT">
          <label for="customtestcase"><div class="custom-checkbox-v3"><input id="customtestcase" type="checkbox"><span></span></div><span class="lmT msL">Test against custom input</span></label>
          
          <textarea rows="5" id="custominput" style="display:none"></textarea>
          
      </div>
      
  </div>
  
</div></div><div id="submission-message"></div><div data-id="tooltip" class="__react_component_tooltip place-top type-dark "></div></div></div><div class="challenge-response fs-container"><div class="output-area-wrap"><div id="output-area" class="output-area mlT psT"><div class="submission-status theme-m-content"><div class="challenge-submission-wrapper"><div class="congrats-wrapper"><div class="ui-card submission-congratulations ui-layer-2"><div class="card-content"><div class="submission-wrapper"><div class="submission-message"><div class="congrats-heading">Congratulations</div><div class="congrats-subtext">You solved this challenge. Would you like to challenge your friends?<div class="social-links-wrapper social-links"><a class="cursor"><i class="social-share-icon ui-icon-facebook"></i></a><a class="cursor"><i class="social-share-icon ui-icon-twitter"></i></a><a class="cursor"><i class="social-share-icon ui-icon-linkedin"></i></a></div></div></div><a href="https://www.hackerrank.com/challenges/sum-numbers-c?h_r=next-challenge&amp;h_v=zen"><button tabindex="0" class="ui-btn ui-btn-secondary"><div class="ui-content align-icon-left"><span class="ui-text">Next Challenge</span></div></button></a></div></div></div></div><div class="testcase-header"><div class="testcase-results"><div class="compile-tests-view"><div><div class="ui-tabs-wrap"><div class="render-list clearfix"><ul class="tab-header"><li class="tab-item active"><a class="tab-item-color-success" data-attr5="0" data-attr3="playing-with-characters" data-attr2="master" data-attr1="SubmitCode" data-analytics="TestCaseResultsTab"><i class="ui-icon-check-circle"></i><span class="ui-icon-label tab-item-label"> Testcase 0</span></a></li><li class="tab-item"><a class="tab-item-color-success" data-attr5="0" data-attr3="playing-with-characters" data-attr2="master" data-attr1="SubmitCode" data-analytics="TestCaseResultsTab"><i class="ui-icon-check-circle"></i><span class="ui-icon-label tab-item-label"> Testcase 1</span></a></li><li class="tab-item"><a class="tab-item-color-success" data-attr5="0" data-attr3="playing-with-characters" data-attr2="master" data-attr1="SubmitCode" data-analytics="TestCaseResultsTab"><i class="ui-icon-check-circle"></i><span class="ui-icon-label tab-item-label"> Testcase 2</span></a></li></ul></div></div></div><div class="tab-list-content tab-content tab-pane-success"><div class="tab-pane-content"><div class="flex-block compilation-time-response full-width"><div class="stdin run-time-message flex-display"><div class="compile-field-label">Input (stdin)<a class="text-link tc-download-link">Download </a></div><pre class="compile-output-message"><code class="bold">C
Language
Welcome To C!!</code></pre></div><div class="expected-output run-time-message flex-display"><div class="compile-field-label">Expected Output<a class="text-link tc-download-link">Download </a></div><pre class="compile-output-message"><code class="bold">C
Language
Welcome To C!!</code></pre></div><div class="compiler-message run-time-message flex-display"><div class="compile-field-label">Compiler Message</div><pre class="compile-output-message"><code class="bold">Success</code></pre></div></div></div></div></div></div></div></div></div></div></div></div></section></div><div class="right-pane"><aside class="theme-m-content fullscreen-hide challenge-sidebar"><div class="challenge-sidebar-container"><div class="sidebar-problem-difficulty challenge-sidebar-help"><div class="difficulty-block"><p class="difficulty-label">Author</p><a href="https://www.hackerrank.com/profile/mahak_bagha1" data-attr2="mahak_bagha1" data-attr1="playing-with-characters" data-analytics="ChallengeViewHeaderAuthor" class="pull-right text-link">mahak_bagha1</a></div><div class="difficulty-block"><p class="difficulty-label">Difficulty</p><p class="pull-right difficulty-easy">Easy</p></div><div class="difficulty-block"><p class="difficulty-label">Max Score</p><p class="sidebar-detail pull-right">5</p></div><div class="difficulty-block"><p class="difficulty-label">Submitted By</p><a href="https://www.hackerrank.com/challenges/playing-with-characters/leaderboard" data-attr1="playing-with-characters" data-analytics="ChallengeViewHackerCount" class="pull-right text-link">24909</a></div></div><div class="challenge-sidebar-help"><h2 class="text-sec-headline-s">Need Help?</h2><hr class="hr-line-light"><div class="mlB"><div class="link-wrapper"><a href="https://www.hackerrank.com/challenges/playing-with-characters/forum" data-attr3="master" data-attr2="playing-with-characters" data-attr1="discussions" data-analytics="ChallengeSidebarUI"><i class="ui-icon-discussion ui-icon-grey sidebar-icon"></i><span class="ui-icon-label">View discussions</span></a></div><div class="link-wrapper"><a href="https://www.hackerrank.com/challenges/playing-with-characters/editorial" data-attr3="master" data-attr2="playing-with-characters" data-attr1="editorial" data-analytics="ChallengeSidebarUI"><i class="ui-icon-editorial ui-icon-grey sidebar-icon"></i><span class="ui-icon-label">View editorial</span></a></div><div class="link-wrapper"><a href="https://www.hackerrank.com/challenges/playing-with-characters/leaderboard" data-attr3="master" data-attr2="playing-with-characters" data-attr1="topscorers" data-analytics="ChallengeSidebarUI"><i class="ui-icon-trophy ui-icon-grey sidebar-icon"></i><span class="ui-icon-label">View top submissions</span></a></div></div></div><div class="challenge-rating rating"><p class="zeta rating-label">rate this challenge</p><div class="rating"><i data-attr7="1" data-analytics="RatedChallenge" class="rating-icon cursor ui-icon-star"></i><i data-attr7="2" data-analytics="RatedChallenge" class="rating-icon cursor ui-icon-star"></i><i data-attr7="3" data-analytics="RatedChallenge" class="rating-icon cursor ui-icon-star"></i><i data-attr7="4" data-analytics="RatedChallenge" class="rating-icon cursor ui-icon-star"></i><i data-attr7="5" data-analytics="RatedChallenge" class="rating-icon cursor ui-icon-star"></i></div></div><div class="challenge-sidebar-help need-help-wrapper"><div class="text-sec-headline-s">MORE DETAILS</div><hr class="hr-line-light"><div class="link-wrapper"><a href="https://www.hackerrank.com/rest/contests/master/challenges/playing-with-characters/download_pdf?language=English" data-attr1="playing-with-characters" data-analytics="ChallengeViewSidebarPDF" id="pdf-link" target="_blank"><i class="ui-icon-grey sidebar-icon ui-icon-download"></i><span class="ui-icon-label">Download problem statement</span></a></div><div class="link-wrapper"><a href="https://www.hackerrank.com/rest/contests/master/challenges/playing-with-characters/download_testcases" data-attr1="playing-with-characters" data-analytics="ChallengeViewSidebarTestCases" id="test-cases-link" target="_blank"><i class="ui-icon-grey sidebar-icon ui-icon-download"></i><span class="ui-icon-label">Download sample test cases</span></a></div><div class="link-wrapper fullscreen-hide"><a data-attr1="playing-with-characters" data-analytics="ChallengeViewSuggestEdit" class="cursor"><i class="ui-icon-grey sidebar-icon ui-icon-edit"></i><span class="ui-icon-label">Suggest Edits</span></a></div></div><div class="social-share-wrap-2"><div class="clearfix"><div class="social-links-wrapper pull-left"><a class="cursor"><i class="social-share-icon ui-icon-facebook"></i></a><a class="cursor"><i class="social-share-icon ui-icon-twitter"></i></a><a class="cursor"><i class="social-share-icon ui-icon-linkedin"></i></a></div></div></div></div></aside></div></div></div></div></section></div></div><footer class="community-footer"><ul class="footer-links"><li class="link-item"><a href="https://www.hackerrank.com/calendar" data-analytics="FooterLinkCalendar" class="footer-link calendar" target="_blank">Contest Calendar</a></li><li class="link-item"><a href="https://blog.hackerrank.com/" data-analytics="FooterLinkBlog" class="footer-link blog" target="_blank">Blog</a></li><li class="link-item"><a href="https://www.hackerrank.com/scoring" data-analytics="FooterLinkScoring" class="footer-link scoring" target="_blank">Scoring</a></li><li class="link-item"><a href="https://www.hackerrank.com/environment" data-analytics="FooterLinkEnvironment" class="footer-link environment" target="_blank">Environment</a></li><li class="link-item"><a href="https://www.hackerrank.com/faq" data-analytics="FooterLinkFAQ" class="footer-link faq" target="_blank">FAQ</a></li><li class="link-item"><a href="https://www.hackerrank.com/aboutus" data-analytics="FooterLinkAboutUs" class="footer-link" target="_blank">About Us</a></li><li class="link-item"><a href="https://help.hackerrank.com/hc/en-us" data-analytics="FooterLinkSupport" class="footer-link" target="_blank">Support</a></li><li class="link-item"><a href="https://www.hackerrank.com/careers" data-analytics="FooterLinkCareers" class="footer-link" target="_blank">Careers</a></li><li class="link-item"><a href="https://www.hackerrank.com/terms-of-service" data-analytics="FooterLinkTermsOfService" class="footer-link" target="_blank">Terms Of Service</a></li><li class="link-item"><a href="https://www.hackerrank.com/privacy" data-analytics="FooterLinkPrivacyPolicy" class="footer-link" target="_blank">Privacy Policy</a></li><li class="link-item"><a href="https://www.hackerrank.com/support/feature" data-analytics="FooterLinkFeatureRequest" class="footer-link featureRequestButton" target="_blank">Request a Feature</a></li></ul></footer></div></div></div><!--Required to handle event bubbling of click in ios safari -->

  <script>
    //HR namespace
    var HR = {};
    HR.development = false;
    HR.assetPath = 'https://hrcdn.net/hackerrank/assets/';
    HR.pageLoadTime = Date.now();
    HR.productNamespace = 'hackerrank';
    HR.production = true;
    HR.devServer = false;
    HR.isIsomorphic = true;
    HR.loadedWithOldCss = true;
    HR.pusher = '{"key":"a280047e3b323ccb1b65","cluster":"mt1"}';
  </script>

  <!-- Vendor scripts -->
  
    <script src="h2_files/hackerrank_r_vendor-5bc167c024.js"></script>
  

  
  <script src="h2_files/runtime-bc150ed6206fab6e52b2.js"></script>
  <script src="h2_files/hackerrank_r_app-088f0c165949d9236d27.js"></script>
  
<script>
  var getUser = (function() {
    var userData;
    $(window).on('initializeNewUser', function(e, user) {
      userData = user;
    });
    try{
      if (typeof userData === 'undefined') {
        userData = JSON.parse(decodeURI($('#initialUserData').html()));
        $('#initialUserData').remove();
      }
    } catch(e){
      userData = {};
      console.log('No initial User data found');
    }
    return function() {
      return userData;
    }
  })();
</script>

<!-- setting up sentry -->

  <script src="h2_files/raven.js" async="" crossorigin="anonymous" id="raven"></script>
  <script>
    (function(window, queue, loaded, script, user) {

        var setupRaven = function(user) {
          var userContext = {};
          if (user && !!user.id) {
            userContext.handle = user.id;
          }
          var extraContext = {
            cdnUrl: Cookies.get("cdn_url")
          }
          if (Cookies) {
            if (HR.productNamespace === 'hackerrank') {
              extraContext.mixpanel_token = Cookies.get('hackerrank_mixpanel_token')
            } else if (HR.productNamespace === 'hackerrankx') {
              extraContext.mixpanel_token = Cookies.get('hackerrankx_mixpanel_token')
            }
          }
          if(typeof Raven !== 'undefined') {
            Raven.setUserContext(userContext);
            Raven.setExtraContext(extraContext);
          }
        }
        $(window).on('initializeNewUser', function(e, user) {
          setupRaven(user);
        });

        window.onerror = function e(message, file, lineNo, columnNo, error) {
            if (loaded) return;
            queue.push([message, file, lineNo, columnNo, error]);
        };

        window.onunhandledrejection = function e(error) {
            if (loaded) return;
            queue.push([
                error.reason,
            ]);
        };

        script.onreadystatechange = script.onload = function() {
            if (loaded) return;
            loaded = true;

            Raven.config('https://6b2d52b23d5a4dd4bc44330335327c04@sentry.io/234162', {
                release: "9cbff4ebd184b3359e1e50a64d14a5e3d28d9cfe",
                ignoreUrls: [/cdn\.userty\.com/]
            }).install();

            setupRaven(user);

            window.onunhandledrejection = function e(error) {
                Raven.captureException(error.reason, {
                    extra: {
                        type: error.type,
                    },
                });
            };

            queue.forEach(function(error) {
                Raven.captureException(error[4] || error[0], {
                    extra: {
                        file: error[1],
                        line: error[2],
                        col: error[3],
                    },
                });
            });
        };
    }(window, [], false, document.getElementById('raven'), getUser()));
 </script>




<!-- google analytics tracking -->
<script>
  var _gaq = _gaq || [];
  
  _gaq.push(['candidate_company._setAccount', 'UA-45092266-1']);
  _gaq.push(['candidate_company._trackPageview']);
  _gaq.push(['candidate_company._gat._anonymizeIp']);
  _gaq.push(['_setCampSourceKey', 'utm_source']);
  _gaq.push(['_setCampMediumKey', 'utm_medium']);
  _gaq.push(['_setCampContentKey', 'utm_keyword']);
  _gaq.push(['_setCampTermKey', 'utm_keyword']);
  _gaq.push(['_setCampNameKey', 'utm_campaign']);

  (function() {
    var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
    ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
    var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
  })();
  
</script>
<!-- Pending candidate site custom GA code -->
<!-- google analytics tracking end-->

<!-- mixpanel tracking -->
<script type="text/javascript">
  
    (function(e,a){if(!a.__SV){var b=window;try{var c,l,i,j=b.location,g=j.hash;c=function(a,b){return(l=a.match(RegExp(b+"=([^&]*)")))?l[1]:null};g&&c(g,"state")&&(i=JSON.parse(decodeURIComponent(c(g,"state"))),"mpeditor"===i.action&&(b.sessionStorage.setItem("_mpcehash",g),history.replaceState(i.desiredHash||"",e.title,j.pathname+j.search)))}catch(m){}var k,h;window.mixpanel=a;a._i=[];a.init=function(b,c,f){function e(b,a){var c=a.split(".");2==c.length&&(b=b[c[0]],a=c[1]);b[a]=function(){b.push([a].concat(Array.prototype.slice.call(arguments,
0)))}}var d=a;"undefined"!==typeof f?d=a[f]=[]:f="mixpanel";d.people=d.people||[];d.toString=function(b){var a="mixpanel";"mixpanel"!==f&&(a+="."+f);b||(a+=" (stub)");return a};d.people.toString=function(){return d.toString(1)+".people (stub)"};k="disable time_event track track_pageview track_links track_forms register register_once alias unregister identify name_tag set_config reset people.set people.set_once people.increment people.append people.union people.track_charge people.clear_charges people.delete_user".split(" ");
for(h=0;h<k.length;h++)e(d,k[h]);a._i.push([b,c,f])};a.__SV=1.2;b=e.createElement("script");b.type="text/javascript";b.async=!0;b.src="undefined"!==typeof MIXPANEL_CUSTOM_LIB_URL?MIXPANEL_CUSTOM_LIB_URL:"file:"===e.location.protocol&&"//cdn.mxpnl.com/libs/mixpanel-2-latest.min.js".match(/^\/\//)?"https://cdn.mxpnl.com/libs/mixpanel-2-latest.min.js":"//cdn.mxpnl.com/libs/mixpanel-2-latest.min.js";c=e.getElementsByTagName("script")[0];c.parentNode.insertBefore(b,c)}})(document,window.mixpanel||[]);
    mixpanel.init("bcb75af88bccc92724ac5fd79271e1ff");

    
      
        mixpanel.init("86cf4681911d3ff600208fdc823c5ff5", {}, "jobs_test");
      
      mixpanel.identify(Cookies.get("hackerrank_mixpanel_token"));
    
  
</script>
<!-- mixpanel tracking end-->

<!-- auryc tracking start -->
<script type="text/javascript">
  
</script>
<!-- auryc tracking end -->

<!-- Marketo to be added later -->



<!-- Bizible -->

<!-- HR metrics init -->
<script type="text/javascript">

  (function() {
    hr_metrics.init({
      product: 'hackerrank',
      use_cookie: true,
      uid_cookie_key: 'hackerrank_mixpanel_token',
      uid_token_cookie_key: 'metrics_user_identifier',
      session_cookie_key: 'session_id',
      metrics_endpoint:  'https://metrics.hackerrank.com/metrics' 
    });
  })();

  (function(h) {
    window.hr_metrics = h;
    if (!h.loaded) {
      var a = ['track', 'batch_track', 'app_track', 'externalService', 'init', 'batch_track_record', 'track_dwell_time', 'set_navigation_data'];
      for (var i = 0; i < a.length; i++) {
        if (!h[a[i]]) {h[a[i]] = function() {};}
      }
    }
  })(window.hr_metrics || {});



</script>

<!-- hrutm_params -->

<!-- HR metrics extension pack -->
<script type="text/javascript">

  
    if (('performance' in window) && ('timing' in window.performance)) {
      $(window).on("load", function() {
        setTimeout(function(){
          var timing = window.performance.timing;
          var obj = {
            referring_url: window.location.pathname,
            fullLoadTime: timing.loadEventEnd - timing.navigationStart,
            // Total time from req start to load
            loadTime: timing.loadEventEnd - timing.fetchStart,
            // Time spent constructing the DOM tree
            domReadyTime: timing.domComplete - timing.domInteractive,
            // Time consumed preparing the new page
            readyStart: timing.fetchStart - timing.navigationStart,
            // Time spent during redirection
            redirectTime: timing.redirectEnd - timing.redirectStart,
            // AppCache
            appcacheTime: timing.domainLookupStart - timing.fetchStart,
            // Time spent unloading documents
            unloadEventTime: timing.unloadEventEnd - timing.unloadEventStart,
            // DNS query time
            lookupDomainTime: timing.domainLookupEnd - timing.domainLookupStart,
            // TCP connection time
            connectTime: timing.connectEnd - timing.connectStart,
            // Time spent during the request
            requestTime: timing.responseEnd - timing.requestStart,
            // Request to completion of the DOM loading
            initDomTreeTime: timing.domInteractive - timing.responseEnd,
            // Load event time
            loadEventTime: timing.loadEventEnd - timing.loadEventStart,
            // Origin of the request
            react: true,
            //isIsomorphic flag
            isIsomorphic: window.HR.isIsomorphic,
            //old css loaded flag
            loadedWithOldCss: window.HR.loadedWithOldCss,
          }

          if (('navigation' in window.performance) && ('getEntries' in window.performance)) {
            obj.navigationType = window.performance.navigation.type;
            obj.navigationRedirectCount = window.performance.navigation.redirectCount;
            if (obj.fullLoadTime > 8000) {
              try {
                var entries = window.performance.getEntries();
                if(entries[0].toJSON){
                  obj.networkRequests = entries.map(function(e) {return e.toJSON();});
                }
              } catch (e) {
                //do nothing
              }
            }
          }

          hr_metrics.app_track('page-load-metrics', obj);
        }, 1000);
      });
    }
  

  $(window).on("load", function() {
      var _pathname = document.location.pathname;
      var cdn_url_switched = Cookies.get("cdn_url_switched");
      if (cdn_url_switched !== '') {
        Cookies.remove('cdn_url_switched');
      }
      hr_metrics.batch_track('PageLoad', _pathname + document.location.search, {
          attribute1: _pathname,
          attribute6: cdn_url_switched,
          cdn_url: Cookies.get("cdn_url")
      });

      if (hr_metrics.track_dwell_time) {
          hr_metrics.track_dwell_time(_pathname);
          hr_metrics.set_navigation_data();
      }

      $(window).on('beforeunload', function(){

          var _pathname = document.location.pathname;
          hr_metrics.batch_track('PageClose', _pathname + document.location.search, {
              attribute2: _pathname
          });

          hr_metrics.track_dwell_time(_pathname, true);

          hr_metrics.batch_track_record(true);
      });

  });

</script>

<!-- Facebook SDK -->
<!-- Twitter SDK -->

<!-- track button clicks -->
<script>
    $(document).on('click', 'a, button, input, select, i, div, span, h5', null, function(e) {
        var src = e.currentTarget, $src = $(e.currentTarget);
        if ($src.attr('data-analytics')) {
            action = 'Click'; data = $src.attr('data-analytics');
        } else {
            return;
        }

        
          hr_metrics.batch_track(action, data, (function() {
              var params={};
              for (var _i=1; _i<=12; ++_i){
                  var _attr = 'data-attr'+_i;
                  if ($src.attr(_attr)){
                    params['attribute'+_i] = $src.attr(_attr);
                  }
              }
              var attributes = src.attributes, attr_length = src.attributes.length;
              for (var i = 0; i < attr_length; i++){
                var attribute = attributes[i];
                if (attribute.name.indexOf('data-attr-') === 0){
                  param_name = attribute.name.substr('data-attr-'.length);
                  if (param_name.length > 0) {
                    params[param_name] = attribute.value;
                  }
                }
              }
              return params;
          })());
        

        
          // google analytics
          _gaq.push(['_trackEvent', 'Events' , action, data])
        
    });

    $(document).on('AnalyticsEvent', function(e) {
        action = e.event_type || false;
        data = e.event_name || false;

        if (!action || !data) {
          return;
        }

        params = {}
        params['attribute1'] = e.event_value || ""
        params['attribute7'] = e.integer_event_value

        if (window.HR && window.HR.current_page) {
          params['attribute2'] = window.HR.current_page;
        }

        if (window.HR && window.HR.current_contest) {
          params['attribute3'] = window.HR.current_contest.get('name');
        }

        
            hr_metrics.batch_track(action, data, params);
        

        
          // google analytics
          _gaq.push(['_trackEvent', 'Events' , action, data]);
        
    });

  </script>
<!-- track button clicks end-->

<!-- Linkedin Insights -->




</body></html>