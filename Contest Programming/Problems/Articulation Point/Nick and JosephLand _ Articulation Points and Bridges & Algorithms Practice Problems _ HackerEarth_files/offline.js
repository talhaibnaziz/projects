/*! offline 0.4.1 */(function(){var a,b,c,d,e,f,g;d=function(a,b){var c,d,e,f;f=[];for(d in b.prototype)try{e=b.prototype[d],null==a[d]&&"function"!=typeof e?f.push(a[d]=e):f.push(void 0)}catch(g){c=g}return f},a={},null==a.options&&(a.options={}),c={checks:{xhr:{url:function(){return"/offline-test-request/"+Math.floor(1e9*Math.random())}},image:{url:function(){return"https://hackerearth.global.ssl.fastly.net/static/are-we-online.gif?_="+Math.floor(1e9*Math.random())}},active:"image"},checkOnLoad:!1,interceptRequests:!0},e=function(a,b){var c,d,e,f,g,h;for(c=a,h=b.split("."),d=f=0,g=h.length;g>f&&(e=h[d],c=c[e],"object"==typeof c);d=++f);return c},a.getOption=function(b){var d,f;return d=null!=(f=e(a.options,b))?f:e(c,b),"function"==typeof d?d():d},"function"==typeof window.addEventListener&&window.addEventListener("online",function(){return setTimeout(a.confirmUp,100)},!1),"function"==typeof window.addEventListener&&window.addEventListener("offline",function(){return a.confirmDown()},!1),a.state="up",a.markUp=function(){return a.trigger("confirmed-up"),"up"!==a.state?(a.state="up",a.trigger("up")):void 0},a.markDown=function(){return a.trigger("confirmed-down"),"down"!==a.state?(a.state="down",a.trigger("down")):void 0},f={},a.on=function(b,c,d){var e,g,h,i,j;if(g=b.split(" "),g.length>1){for(j=[],h=0,i=g.length;i>h;h++)e=g[h],j.push(a.on(e,c,d));return j}return null==f[b]&&(f[b]=[]),f[b].push([d,c])},a.off=function(a,b){var c,d,e,g,h;if(null!=f[a]){if(b){for(d=0,h=[];d<f[a].length;)g=f[a][d],c=g[0],e=g[1],e===b?h.push(f[a].splice(d--,1)):h.push(void 0);return h}return f[a]=[]}},a.trigger=function(a){var b,c,d,e,g,h,i;if(null!=f[a]){for(g=f[a],i=[],d=0,e=g.length;e>d;d++)h=g[d],b=h[0],c=h[1],i.push(c.call(b));return i}},b=function(a,b,c){var d,e;return d=function(){return a.status&&a.status<12e3?b():c()},null===a.onprogress?(a.addEventListener("error",c,!1),a.addEventListener("timeout",c,!1),a.addEventListener("load",d,!1)):(e=a.onreadystatechange,a.onreadystatechange=function(){return 4===a.readyState?d():0===a.readyState&&c(),"function"==typeof e?e.apply(null,arguments):void 0})},a.checks={},a.checks.xhr=function(){var c;return c=new XMLHttpRequest,c.open("GET",a.getOption("checks.xhr.url"),!0),b(c,a.markUp,a.markDown),c.send(),c},a.checks.image=function(){var b;return b=document.createElement("img"),b.onerror=a.markDown,b.onload=a.markUp,b.src=a.getOption("checks.image.url"),void 0},a.check=function(){return a.trigger("checking"),a.checks[a.getOption("checks.active")]()},a.confirmUp=a.confirmDown=a.check,a.onXHR=function(a){var b,c,e;return b=function(b,c){var d;return d=b.open,b.open=function(e,f,g,h,i){return a({type:e,url:f,async:g,flags:c,user:h,password:i,xhr:b}),d.apply(b,arguments)}},e=window.XMLHttpRequest,window.XMLHttpRequest=function(a){var c,d,f;return c=new e(a),b(c,a),f=c.setRequestHeader,c.headers={},c.setRequestHeader=function(a,b){return c.headers[a]=b,f.call(c,a,b)},d=c.overrideMimeType,c.overrideMimeType=function(a){return c.mimeType=a,d.call(c,a)},c},d(window.XMLHttpRequest,e),null!=window.XDomainRequest?(c=window.XDomainRequest,window.XDomainRequest=function(){var a;return a=new c,b(a),a},d(window.XDomainRequest,c)):void 0},g=function(){return a.getOption("interceptRequests")&&a.onXHR(function(c){var d;return d=c.xhr,b(d,a.confirmUp,a.confirmDown)}),a.getOption("checkOnLoad")?a.check():void 0},setTimeout(g,0),window.Offline=a}).call(this),function(){var a,b,c,d,e,f,g,h,i;if(!window.Offline)throw new Error("Offline Reconnect brought in without offline.js");d={},f=null,e=function(){var a;return null!=d.state&&Offline.trigger("reconnect:stopped"),d.state="inactive",d.remaining=d.delay=null!=(a=Offline.getOption("reconnect.initialDelay"))?a:3},b=function(){var a,b;return a=null!=(b=Offline.getOption("reconnect.delay"))?b:Math.min(Math.ceil(1.5*d.delay),3600),d.remaining=d.delay=a},g=function(){return"connecting"!==d.state?(d.remaining-=1,Offline.trigger("reconnect:tick"),0===d.remaining?h():void 0):void 0},h=function(){return"waiting"===d.state?(Offline.trigger("reconnect:connecting"),d.state="connecting",Offline.check()):void 0},a=function(){return d.state="waiting",Offline.trigger("reconnect:started"),f=setInterval(g,1e3)},i=function(){return clearInterval(f),e()},c=function(){return"connecting"===d.state?(Offline.trigger("reconnect:failure"),d.state="waiting",b()):void 0},d.tryNow=h,setTimeout(function(){return Offline.getOption("reconnect")!==!1?(e(),Offline.on("down",a),Offline.on("confirmed-down",c),Offline.on("up",i),Offline.reconnect=d):void 0},0)}.call(this),function(){var a,b,c,d,e,f;if(!window.Offline)throw new Error("Requests module brought in without offline.js");c=[],f=!1,d=function(a){return Offline.trigger("requests:capture"),"down"!==Offline.state&&(f=!0),c.push(a)},e=function(a){var b,c,d,e,f,g,h,i,j;i=a.xhr,f=a.url,e=a.type,g=a.user,d=a.password,b=a.body,i.abort(),i.open(e,f,!0,g,d),j=i.headers;for(c in j)h=j[c],i.setRequestHeader(c,h);return i.mimeType&&i.overrideMimeType(i.mimeType),i.send(b)},a=function(){return c=[]},b=function(){var b,d,f,g,h,i;for(Offline.trigger("requests:flush"),f={},h=0,i=c.length;i>h;h++)d=c[h],g=d.url.replace(/(\?|&)_=[0-9]+/,function(a,b){return"?"===b?b:""}),f[""+d.type.toUpperCase()+" - "+g]=d;for(b in f)d=f[b],e(d);return a()},setTimeout(function(){return Offline.getOption("requests")!==!1?(Offline.on("confirmed-up",function(){return f?(f=!1,a()):void 0}),Offline.on("up",b),Offline.on("down",function(){return f=!1}),Offline.onXHR(function(a){var b,c,e,f,g;return e=a.xhr,b=a.async,c=function(){return d(a)},g=e.send,e.send=function(b){return a.body=b,g.apply(e,arguments)},b?null===e.onprogress?(e.addEventListener("error",c,!1),e.addEventListener("timeout",c,!1)):(f=e.onreadystatechange,e.onreadystatechange=function(){return 0===e.readyState?c():4===e.readyState&&(0===e.status||e.status>=12e3)&&c(),"function"==typeof f?f.apply(null,arguments):void 0}):void 0}),Offline.requests={flush:b,clear:a}):void 0},0)}.call(this),function(){var a,b,c,d,e,f,g,h,i,j,k,l,m;if(!window.Offline)throw new Error("Offline UI brought in without offline.js");b='<div class="offline-ui"><div class="offline-ui-content"></div></div>',a='<a href class="offline-ui-retry"></a>',e=function(a){var b;return b=document.createElement("div"),b.innerHTML=a,b.children[0]},f=d=null,c=function(a){return k(a),f.className+=" "+a},k=function(a){return f.className=f.className.replace(new RegExp("(^| )"+a.split(" ").join("|")+"( |$)","gi")," ")},h={},g=function(a,b){return c(a),null!=h[a]&&clearTimeout(h[a]),h[a]=setTimeout(function(){return k(a),delete h[a]},1e3*b)},i=function(a,b){var c,d,e,f,g,h;if(null==b&&(b=!1),0===a)return"now";c={d:86400,h:3600,m:60,s:1},d={s:"second",m:"minute",h:"hour",d:"day"},f="";for(g in c)if(e=c[g],a>=e)return h=Math.floor(a/e),b&&(g=" "+d[g],1!==h&&(g+="s")),""+h+g},l=function(){var g,h;return f=e(b),document.body.appendChild(f),null!=Offline.reconnect&&(f.appendChild(e(a)),g=f.querySelector(".offline-ui-retry"),h=function(a){return a.preventDefault(),Offline.reconnect.tryNow()},null!=g.addEventListener?g.addEventListener("click",h,!1):g.attachEvent("click",h)),c("offline-ui-"+Offline.state),d=f.querySelector(".offline-ui-content")},j=function(){return l(),Offline.on("up",function(){return k("offline-ui-down"),c("offline-ui-up"),g("offline-ui-up-2s",2),g("offline-ui-up-5s",5)}),Offline.on("down",function(){return k("offline-ui-up"),c("offline-ui-down"),g("offline-ui-down-2s",2),g("offline-ui-down-5s",5)}),Offline.on("reconnect:connecting",function(){return c("offline-ui-connecting"),k("offline-ui-waiting")}),Offline.on("reconnect:tick",function(){return c("offline-ui-waiting"),k("offline-ui-connecting"),d.setAttribute("data-retry-in-seconds",Offline.reconnect.remaining),d.setAttribute("data-retry-in-abbr",i(Offline.reconnect.remaining)),d.setAttribute("data-retry-in",i(Offline.reconnect.remaining,!0))}),Offline.on("reconnect:stopped",function(){return k("offline-ui-connecting offline-ui-waiting"),d.setAttribute("data-retry-in-seconds",null),d.setAttribute("data-retry-in-abbr",null),d.setAttribute("data-retry-in",null)}),Offline.on("reconnect:failure",function(){return g("offline-ui-reconnect-failed-2s",2),g("offline-ui-reconnect-failed-5s",5)}),Offline.on("reconnect:success",function(){return g("offline-ui-reconnect-succeeded-2s",2),g("offline-ui-reconnect-succeeded-5s",5)})},null!=document.addEventListener?document.addEventListener("DOMContentLoaded",j,!1):(m=document.onreadystatechange,document.onreadystatechange=function(){return"complete"===document.readyState&&j(),"function"==typeof m?m.apply(null,arguments):void 0})}.call(this);