#include <WiFi.h>
#include <WebServer.h>

int sensorPin = A3;


/*Put your SSID & Password*/
char* ssid = "Iaac-Wifi";  // Enter SSID here
char* password = "EnterIaac22@";  //Enter Password here

WebServer server(80);

int sensorValue;

int SoilHumidity;
//float Humidity;
 
void setup() {
  Serial.begin(115200);
  UpdateSensors();
  
  pinMode(sensorPin, INPUT);

              

  Serial.println("Connecting to ");
  Serial.println(ssid);

  //connect to your local wi-fi network
  WiFi.begin(ssid, password);

  //check wi-fi is connected to wi-fi network
  while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected..!");
  Serial.print("Got IP: ");  Serial.println(WiFi.localIP());

  server.on("/", handle_OnConnect);
  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("HTTP server started");

}
void loop() {
 
  server.handleClient();
  
  UpdateSensors();
  server.send(200, "text/html", SendHTML(SoilHumidity)); 
  delay(1000);  
}

void handle_OnConnect() {


  
  server.send(200, "text/html", SendHTML(SoilHumidity)); 
 
}

void UpdateSensors(){
  
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  
  int PSensorValue = map(sensorValue, 4096,0,0,100);
  Serial.println(PSensorValue);
  
  SoilHumidity = PSensorValue; // Gets the values of the temperature
  
}

  

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

String SendHTML(float SoilHumidity){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<img src=\"https://emiliosmith.github.io/mdef_emilio2/images/encabezado_1.jpg\" alt=\"compost system\" style=\"width:800x;height:300px;\">\n";

  
  ptr +="<title>ESP 32 Compost Sensor</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;}\n";
  ptr +="p {font-size: 40px;color: #87ff00;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="<meta http-equiv=\"refresh\" content=\"2\" >\n"; 
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<div id=\"webpage\">\n";
  ptr +="<h1>ESP32 Compost Commune Sensor</h1>\n";
  ptr +="<p>Your compost humidity is:";
  ptr +=SoilHumidity;
  ptr +="%</p>";
  ptr +="</p>";
  ptr +="<h3>Rember: if the % is below 40% you could add<br>more orgaic waste or just water.<br>Keep it between 40% and 60%.</h3>\n";
  //ptr +="p {font-size: 20px;color: #87ff00;margin-bottom: 10px;}\n";
  //ptr +="<h3>style=\"\background-color:#ff6347;\">Rember: if the % is below 40% <br> you could add more orgaic waste or just water</h3>\n";
   
  ptr +="<br>\n";

  return ptr;
}
