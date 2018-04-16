#include <ESP8266WiFi.h>

const char* ssid = "Boarding_House";
const char* password = "idunnoclue101";
WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  delay(10);
  pinMode(5, OUTPUT);
  digitalWrite(5, LOW);
 
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
 
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

 
  // Match the request
  if (request.indexOf("/light-on") > 0)  {
    digitalWrite(5, HIGH);
  }
  if (request.indexOf("/light-off") >0)  {
    digitalWrite(5, LOW);
  }


// Set ledPin according to the request
 
 // Return the response
 client.println("HTTP/1.1 200 OK");
 client.println("Content-Type: text/html");
 client.println(""); //  do not forget this one
 client.println("<!DOCTYPE HTML>");
 client.println("<html>");
 client.println("<head>");
 client.println("<meta name='esp8266-iot-capable' content='yes' />");
 client.println("<meta name='esp8266-iot-status-bar-style' content='black-translucent' />");
 client.println("</head>");
 client.println("<body bgcolor = \"#f7e6ec\">"); 
 client.println("<hr/><hr>");
 client.println("<h4><center> Internet-Of-Things: Controlling Your Lights using ESP8266 </center></h4>");
 client.println("<hr/><hr>");
 client.println("<br><br>");
 client.println("<br><br>");
 client.println("<center>");
 client.println("Device1: Your Light Bulb");
 client.println("<br><br>");
 client.println("<a href=\"/light-on\"\"><button>Light On </button></a>");
 client.println("<a href=\"/light-off\"\"><button>Light Off </button></a><br />");  
 client.println("</center>");   
 client.println("<br><br>");
 client.println("<center>");
 client.println("<table border=\"5\">");
 client.println("<tr>");
 
  if (digitalRead(5))
         { 
           client.print("<td>Light 1 is ON</td>");
         }
          else
          {
            client.print("<td>Light 1 is OFF</td>");
          }
          
 client.println("<br />");
 client.println("</tr>");
 client.println("</table>");
 client.println("</center>");
 client.println("</html>"); 
 delay(1);

  
 Serial.println("Client disonnected");
 Serial.println("");
}
