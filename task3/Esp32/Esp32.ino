#include <WiFi.h>
#include <HTTPClient.h>

const char WIFI_SSID[] = "Ssid";
const char WIFI_PASSWORD[] = "Password";

String url = "http://192.168.8.107"
String link = "/insert_temp.php?temperature=";

void setup() {
  
  Serial.begin(9600); 
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() 
{
  float temp = random(10,50);
  HTTPClient http;
  http.begin(url + link + temp); //HTTP
  int httpCode = http.GET();

  // httpCode will be negative on error
  if(httpCode > 0) 
  {
    if(httpCode == HTTP_CODE_OK) {String payload = http.getString();Serial.println(payload);} 
    else {Serial.printf("[HTTP] GET... code: %d\n", httpCode);}
  } 
  else 
  {
    Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }
  http.end();
  delay(5000);
  Serial.println("Sleep 5S");
}
