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

      // Last transaction
      var last = Math.round(json.last);
      console.log("Last transaction is " + last);

      // Highest transaction
      var high = Math.round(json.high);      
      console.log("Highest transaction is " + high);
      
      // Assemble dictionary using our keys
      var dictionary = {
        KEY_LAST: last,
        KEY_HIGH: high
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

    // Get the initial weather
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
