var xhrRequest = function (url, type, callback) {
  var xhr = new XMLHttpRequest();
  xhr.onload = function () {
    callback(this.responseText);
  };
  xhr.open(type, url);
  xhr.send();
};

function dataBitstamp() {
  // Construct URL
  var url = "https://www.bitstamp.net/api/ticker/";

  // Send request to OpenWeatherMap
  xhrRequest(url, 'GET', 
    function(responseText) {
      // responseText contains a JSON object with weather info
      var json = JSON.parse(responseText);

      // Last BTC Price
      var last = Math.round(json.last);
      console.log("Last transaction is " + last);

      // Last 24 hours price high
      var high = Math.round(json.high);      
      console.log("Highest transaction is " + high);

      // Last 24 hours volume weighted average price
      var vwap = Math.round(json.vwap);      
      console.log("Vwap transaction is " + vwap);

      // Last 24 hours price low
      var low = Math.round(json.low);      
      console.log("Low transaction is " + low);

      // Volume transaction
      var volume = Math.round(json.volume);      
      console.log("Volume of transactions is " + volume);

      // Highest buy order
      var bid = Math.round(json.bid);      
      console.log("Highest buy order is " + bid);

      // Lowest sell order
      var ask = Math.round(json.ask);      
      console.log("Lowest sell order is " + ask);

      // Assemble dictionary using our keys
      var dictionary = {
        KEY_LAST: last,
        KEY_HIGH: high,
	KEY_VWAP: vwap,
	KEY_LOW: low,
	KEY_VOLUME: volume,
	KEY_BID: bid,
	KEY_ASK: ask
      };

      // Send to Pebble
      Pebble.sendAppMessage(dictionary,
        function(e) {
          console.log("Bitstamp info sent to Pebble successfully!");
        },
        function(e) {
          console.log("Error sending Bitstamp info to Pebble!");
        }
      );
    }      
  );
}

// Listen for when the watchface is opened
Pebble.addEventListener('ready', 
  function(e) {
    console.log("PebbleKit JS ready!");

    // Get the initial Bitstamp's data
    dataBitstamp();
  }
);

// Listen for when an AppMessage is received
Pebble.addEventListener('appmessage',
  function(e) {
    console.log("AppMessage received!");
    dataBitstamp();
  }                     
);
