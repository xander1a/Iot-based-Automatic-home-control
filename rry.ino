#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>

#define WIFI_SSID "Rwanda-ltd"            // WIFI SSID here                                   
#define WIFI_PASSWORD "VRT0931VRT"

String  postData, postData2;

void setup() {
  Serial.begin(9600);
  pinMode(23,OUTPUT);
   pinMode(22,OUTPUT);
    pinMode(19,OUTPUT);
   pinMode(21, OUTPUT);
   ////////////////
     pinMode(25,OUTPUT);
     pinMode(26,OUTPUT);
    pinMode(33, OUTPUT);
     pinMode(32,OUTPUT);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());
  delay(30);
}

void loop() {
http1();
}

void http1() {
  String sendval = String("22");
  String sendval2 = String("11");
 
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Ndabona zanze");
    WiFiClientSecure client;
    client.setInsecure(); // Ignore SSL certificate validation
    HTTPClient https;
    https.begin(client, "https://animal.rwandahouseland.com/node.php");
    // Create a JSON object to hold the data
    DynamicJsonDocument jsonDoc(200);
    jsonDoc["sendval"] = sendval;
    jsonDoc["sendval2"] = sendval2;
    String jsonStr;
    serializeJson(jsonDoc, jsonStr);
    Serial.print(jsonStr);
    https.addHeader("Content-Type", "application/json");
    int httpCode = https.POST(jsonStr);

    if (httpCode > 0) {
      Serial.print("HTTP Response Code: ");
      Serial.println(httpCode);
      if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
        String payload = https.getString();
        Serial.println(payload);



// Stream& input;
// Stream& input;

StaticJsonDocument<192> doc;

DeserializationError error = deserializeJson(doc, payload);

if (error) {
  Serial.print("deserializeJson() failed: ");
  Serial.println(error.c_str());
  return;
}

int L1 = doc["L1"]; // 1
int L2 = doc["L2"]; // 1
int L3 = doc["L3"]; // 1
int L4 = doc["L4"]; // 1
int L5 = doc["L5"]; // 1
int L6 = doc["L6"]; // 1
int L7 = doc["L7"]; // 1
int L8 = doc["L8"]; // 1


//....................................................
if (L1 == 1) {
  digitalWrite(23, HIGH);
}
else{
   digitalWrite(23, LOW);
  }
//...........................................................
  if (L2 == 1) {
  digitalWrite(22, HIGH);
}
else{
   digitalWrite(22, LOW);
  }
//......................................................
  if (L3 == 1) {
  digitalWrite(21, HIGH);
}
else{
   digitalWrite(21, LOW);
  }

//....................................................

  if (L4 == 1) {
  digitalWrite(19, HIGH);
}
else{
   digitalWrite(19, LOW);
  }

//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    if (L5== 1) {
  digitalWrite(25, HIGH);
}
else{
   digitalWrite(25, LOW);
  }

//..........................................
    if (L6 == 1) {
  digitalWrite(26, HIGH);
}
else{
   digitalWrite(26, LOW);
  }

//...............................................................
    if (L7== 1) {
  digitalWrite(32, HIGH);
}
else{
   digitalWrite(32, LOW);
  }

//.......................................................

    if (L8== 1) {
  digitalWrite(33, HIGH);
}
else{
   digitalWrite(33, LOW);
  }








        
      }
    }
    else {
      Serial.print("HTTP POST request failed with error code: ");
      Serial.println(httpCode);
    }

    https.end();
    delay(1000);
  }
}
