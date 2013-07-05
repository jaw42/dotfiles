#!javascript
////<adblock_subscriptions___SCRIPT
//extensions.load("adblock_subscriptions", {
////<adblock_subscriptions___CONFIG
//// To take effect dwb needs to be restarted
//
//// Shortcut to subscribe to a filterlist
//scSubscribe : as,
//// Command to subscribe to a filterlist
//cmdSubscribe : "adblock_subscribe",
//
//// Shortcut to unsubscribe from a filterlist
//scUnsubscribe : null,
//
//// Command to unsubscribe from a filterlist
//cmdUnsubscribe : "adblock_unsubscribe",
//
//// Path to the filterlist directory, will be created if it doesn't exist.
//filterListDir : data.configDir + "/adblock_lists"
////>adblock_subscriptions___CONFIG
//
//});
//>adblock_subscriptions___SCRIPT
//<contenthandler___SCRIPT
extensions.load("contenthandler", {
//<contenthandler___CONFIG
	// The handler can either be a string or a function, if it is a string
	// %u will be replaced with the uri of the request, if the handler is a
	// function the first parameter of the function will be the uri and the
	// function must return the command to execute.

	// Handle requests based on filename extension
	extension : {
		// "torrent" : "xterm -e 'aria2 %u'",
		// "pdf" : "xterm -e 'wget %u --directory-prefix=~/mypdfs'"
	},

	// Handle requests based on URI scheme
	uriScheme : {
			//ftp : function(uri) {
			//		if (uri[uri.length-1] == "/")
			//				return "xterm -e 'ncftp " + uri + "'";
			//		else
			//				return "xterm -e 'ncftpget " + uri + "'";
			//}
			mailto : "open -t terminal -e mutt %u"
	},

	// Handle requests based on MIME type
	mimeType : {
		// "application/pdf" : "xterm -e 'wget %u --directory-prefix=~/mypdfs'"
	}
//>contenthandler___CONFIG
});
//>contenthandler___SCRIPT
