
#include <ESP8266WiFi.h>

const char* ssid     = "your_SSID";
const char* password = "your_passwd";
const char* host = "api.thingspeak.com";



void setup() {
  Serial.begin(115200);
  delay(10);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(" BTC FTW ");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("");
}

int value = 0;



void loop() {
  delay(500);
  ++value;

  //Serial.print("connecting to ");
 // Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    
    return;
  }
  // We now create a URI for the request  /ticker/USD  
  // /v1/bpi/currentprice/USD.json 
  String url = "/apps/thinghttp/send_request\?api_key={put_your_api_Key_here}";

  Serial.println("");
  Serial.println("");
  Serial.println("Requesting BTC Price  ");
  Serial.println(url);
  Serial.println("");
  Serial.println("");
  
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  delay(3000);
  
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
    String hdr = client.readStringUntil('\n');
    String srvr = client.readStringUntil('\n');
    const String date = client.readStringUntil('2015');
    const String time = client.readStringUntil('\n');
    String cont = client.readStringUntil('\n');
    String e = client.readStringUntil('\n');
    String f = client.readStringUntil('\n');
    String g = client.readStringUntil('\n');
    String sts = client.readStringUntil('\n');
    String xfr = client.readStringUntil('\n');
    String acc = client.readStringUntil('\n');
    String meths = client.readStringUntil('\n');
    String acah = client.readStringUntil('\n'); 
    String mxage = client.readStringUntil('\n');
    String etag = client.readStringUntil('\n');
    String cachecntr = client.readStringUntil('\n');
    String rqid = client.readStringUntil('\n');
    String blnk = client.readStringUntil('\n');
    String blnk1 = client.readStringUntil('\n'); 
    const String price = client.readStringUntil('\n');
      
    
    Serial.print(date);
    Serial.println('5');
    Serial.print("Time:");
    Serial.println(time);
    Serial.println("");
    Serial.print("1 BTC = $");
    Serial.println(price);
    Serial.println("");
    Serial.println("");
    Serial.println("");
    Serial.println("");
    Serial.println("");
    Serial.println();
    
   }
  
    // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  delay(2000);
  Serial.println();
  Serial.println("closing connection");
}



 
