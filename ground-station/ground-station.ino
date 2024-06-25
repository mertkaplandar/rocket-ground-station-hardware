#include "LoRa_E32.h"
#include <SoftwareSerial.h>
#include <ArduinoJson.h>
 
SoftwareSerial mySerial(2, 3); 
LoRa_E32 e32ttl(&mySerial);

#define LORA_ADDR 2 
#define LORA_CH 20  
 
struct DataPack {
  char name[8];
  int packageNumber;
  float latitude;
  float longitude;
  float speed;
  float pressure;
  float altitude;
  float temperature;
  float pitch;
  float roll;
  float yaw;
  bool pyroTrigger;
  bool flightStatus;
} data;
 
StaticJsonDocument<200> doc;
 
void setup() {
  Serial.begin(9600);

  Serial.println("SYS-NAME_GROUND-STATION");
  Serial.println("SYS-VERSION_1.0");
 
  e32ttl.begin();
  delay(500);
  Serial.println("MODULE-STARTED_LORA-E32");
  Serial.println("SYS-READY");
}
 
void loop() {
  while (e32ttl.available() > 1) {
 
    ResponseStructContainer rsc = e32ttl.receiveMessage(sizeof(DataPack));
    struct DataPack data = *(DataPack*)rsc.data;
    rsc.close();
    
    Serial.println(" ");

    doc["name"] = data.name;
    doc["packageNumber"] = data.packageNumber;
    doc["latitude"] = data.latitude;  
    doc["longitude"] = data.longitude;
    doc["speed"] = data.speed;
    doc["pressure"] = data.pressure;
    doc["altitude"] = data.altitude;
    doc["temperature"] = data.temperature;
    doc["pitch"] = data.pitch;
    doc["roll"] = data.roll;
    doc["yaw"] = data.yaw;
    doc["pyroTrigger"] = data.pyroTrigger;
    doc["flightStatus"] = data.flightStatus;

    serializeJson(doc, Serial);

  }
}