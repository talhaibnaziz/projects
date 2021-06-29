function parseUri(a){var b=parseUri.options,c=b.parser[b.strictMode?'strict':'loose'].exec(a),d={},e=14;while(e--)d[b.key[e]]=c[e]||'';d[b.q.name]={};d[b.key[12]].replace(b.q.parser,function(a,c,e){if(c)d[b.q.name][c]=e});return d}parseUri.options={strictMode:false,key:['source','protocol','authority','userInfo','user','password','host','port','relative','path','directory','file','query','anchor'],q:{name:'queryKey',parser:/(?:^|&)([^&=]*)=?([^&]*)/g},parser:{strict:/^(?:([^:\/?#]+):)?(?:\/\/((?:(([^:@]*)(?::([^:@]*))?)?@)?([^:\/?#]*)(?::(\d*))?))?((((?:[^?#\/]*\/)*)([^?#]*))(?:\?([^#]*))?(?:#(.*))?)/,loose:/^(?:(?![^:@]+:[^:@\/]*@)([^:\/?#.]+):)?(?:\/\/)?((?:(([^:@]*)(?::([^:@]*))?)?@)?([^:\/?#]*)(?::(\d*))?)(((\/(?:[^?#](?![^?#\/]*\.[^?#\/.]+(?:[?#]|$)))*\/?)?([^?#\/]*))(?:\?([^#]*))?(?:#(.*))?)/}};function contains(p, v){ if(p==undefined) return false; else { var regex = new RegExp(v,'i'); if(p.search(regex) < 0) return false; else return true;}}var url = parseUri(document.URL);var refurl = parseUri(document.referrer); var urlparam = url.queryKey; var refurlparam = refurl.queryKey;var newdiv = document.createElement('div');
newdiv.setAttribute('style','display:inline;');
try{
   pageurl = document.location.href;
   if(pageurl.match(/unverified/)!=undefined) ae_parms_kv.depth=2;
   else if(pageurl.match(/demo-form/)!=undefined) ae_parms_kv.depth=2;
   else if(pageurl.match(/facecode/)!=undefined) ae_parms_kv.depth=1, ae_parms_kv["category"] = "INTERVIEW";
   else if(pageurl.match(/assessment/)!=undefined)  ae_parms_kv.depth=1, ae_parms_kv["category"] = "ASSESSMENT";
   else if(pageurl.match(/source=assessment/)!=undefined)  ae_parms_kv.depth=1, ae_parms_kv["category"] = "HACKATHON";
   else if(pageurl.match(/source/)!=undefined) ae_parms_kv.depth=1, ae_parms_kv["category"] = "SOURCING";
   else if(pageurl.match(/sprint/)!=undefined) ae_parms_kv.depth=1, ae_parms_kv["category"] = "HACKATHON";
   else if(pageurl.match(/recruit/)!=undefined)  ae_parms_kv.depth=1;
   else if(pageurl.match(/www.hackerearth.com/)!=undefined)  ae_parms_kv.depth=0;
}catch(e){}

var kv_pairs='';
if(!(typeof ae_parms_kv === 'undefined')){
for (key in ae_parms_kv){
if(!(typeof key === 'undefined')){
if (ae_parms_kv[key] instanceof Array) {
kv_pairs = kv_pairs+'&' + key+'='+encodeURIComponent(ae_parms_kv[key].join(','));
} else{
kv_pairs = kv_pairs+'&' + key+'='+encodeURIComponent(ae_parms_kv[key]);
}
if(kv_pairs.length > 2000)break;
}}
}var host = ("https:" == document.location.protocol) ? "https://" : "http://";var rt_url = host + "sc.adelement.com/setRT_adelement_cookie.php?ae_rt=8593aae1e19c83b7e222e914b3840e65&_ae_ref="+escape(document.referrer)+kv_pairs;newdiv.innerHTML = '<img height = "1" width = "1" style = "border-style:none;" alt = "" src="'+rt_url+'"/>';
document.getElementsByTagName('head')[0].appendChild(newdiv);

function t(a){        var b=typeof a;        return null==a||"object"==b||"function"==b?null:String(a).replace(/,/g,"\,").replace(/;/g,"\;").replace(/=/g,"\=")}
function u(a){    var b;    if("object"==typeof a&&"function"!=typeof a.join){        var d=[];        for(b in a)if(Object.prototype.hasOwnProperty.call(a,b)){            var c=a[b];            if(c&&"function"==typeof c.join){                for(var e=[],g=0;g<c.length;++g){                    var x=t(c[g]);                    null!=x&&e.push(x)                    }                    c=0==e.length?null:e.join(",")                }else c=t(c);            (e=t(b))&&null!=c&&d.push(e+"="+c)            }            b=d.join(";")        }else b="";    return""==b?"":"&".concat("data=",encodeURIComponent(b))}
ae_google_parms_kv=new Object();for (key in ae_parms_kv){ae_google_parms_kv['a2613_'+key]=ae_parms_kv[key];};var ret = u(ae_google_parms_kv);

var newdiv = document.createElement('div');
newdiv.setAttribute('style','display:inline;');
newdiv.innerHTML='<img height="1" width="1" style="border-style:none;" alt="" src="//googleads.g.doubleclick.net/pagead/viewthroughconversion/995239786/?value=0&amp;guid=ON&amp;script=0'+ret+'"/>';
document.getElementsByTagName('head')[0].appendChild(newdiv);

var newdiv = document.createElement('div');
newdiv.setAttribute('style','display:inline;');
newdiv.innerHTML='<img src="//befoperator-d.openx.net/w/1.0/rs?as=537066448&cb=INSERT_RANDOM_NUMBER_HERE" width="0" height="0" alt=""/>';
document.getElementsByTagName('head')[0].appendChild(newdiv);
try{
     if(ae_parms_kv.hasOwnProperty('depth') && ae_parms_kv['depth'] == '2'){
     	var ae_r = Math.floor(Math.random()*99999999999);
		var ae_u = (location.protocol=='https:'?'https://ads.adelement.com/www/delivery_dev/ti.php':'http://ads.adelement.com/www/delivery_dev/ti.php');
		var kv_pairs='';
		if(!(typeof ae_conv_parms_kv === 'undefined')){ 
			for (key in ae_conv_parms_kv) 
				kv_pairs = kv_pairs+'&amp;' + key+'='+escape(ae_conv_parms_kv[key]);
		}
		var newdiv = document.createElement('div');
		newdiv.setAttribute('style','display:inline;');
		var rt_url = ae_u+"?trackerid=411&amp;cb="+ae_r+kv_pairs;
		newdiv.innerHTML = '<img height = "1" width = "1" style = "border-style:none;" alt = "" src="'+rt_url+'"/>';
		document.getElementsByTagName('head')[0].appendChild(newdiv);
     }
}catch(e){}