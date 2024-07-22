#include <SoftwareSerial.h>
#include <LoRa_E32.h>
#include <ArduinoJson.h>

// Define pins and parameters
const int RX_PIN = 5;
const int TX_PIN = 6;
const int LORA_ADDR = 2;
const int LORA_CH = 20;

// Define SoftwareSerial and LoRa instances
SoftwareSerial mySerial(RX_PIN, TX_PIN);
LoRa_E32 e32ttl(&mySerial);

// Define the data structure
struct DataPack {
  char name[8];
  int packageNumber;
  float latitude;
  float longitude;
  float speed;
  float pressure;
  float altitude;
  float pitch;
  float roll;
  float yaw;
  float status;
} data;

// Define JSON document size
const size_t JSON_DOC_SIZE = JSON_OBJECT_SIZE(11) + 200;
DynamicJsonDocument doc(JSON_DOC_SIZE);

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    // Wait for serial port to connect
  }

  Serial.println("SYS-NAME_GROUND-STATION");
  Serial.println("SYS-VERSION_1.0");

  mySerial.begin(9600);
  e32ttl.begin();
  delay(500);

  Serial.println("MODULE-STARTED_LORA-E32");
  Serial.println("SYS-READY");

  // Check free memory
  Serial.print("Free memory: ");
  Serial.println(freeMemory());
}

void loop() {
  if (e32ttl.available() >= sizeof(DataPack)) {
    ResponseStructContainer rsc = e32ttl.receiveMessage(sizeof(DataPack));
    if (rsc.status.code == 1) {
      if (rsc.data) {
        memcpy(&data, rsc.data, sizeof(DataPack));
        free(rsc.data);

        // if (isValidData(data)) {
          doc.clear();
          populateJson(doc, data);
          serializeJson(doc, Serial);
          Serial.println();
        // } else {
          // Serial.println("ERROR: Invalid data received");
        // }
      } else {
        Serial.println("ERROR: No data received");
      }
    } else {
      Serial.println("ERROR: Failed to receive data");
    }

    // Check free memory
    // Serial.print("Free memory: ");
    // Serial.println(freeMemory());
  }
}

bool isValidData(const DataPack &data) {
  if (data.latitude < -90.0 || data.latitude > 90.0) return false;
  if (data.longitude < -180.0 || data.longitude > 180.0) return false;
  if (strcmp(data.name, "Rocket") != 0 && strcmp(data.name, "Payload") != 0) return false;
  return true;
}

void populateJson(DynamicJsonDocument &doc, const DataPack &data) {
  doc["name"] = data.name;
  doc["packageNumber"] = data.packageNumber;
  doc["latitude"] = data.latitude;
  doc["longitude"] = data.longitude;
  doc["speed"] = data.speed;
  doc["pressure"] = data.pressure;
  doc["altitude"] = data.altitude;
  doc["pitch"] = data.pitch;
  doc["roll"] = data.roll;
  doc["yaw"] = data.yaw;
  doc["status"] = data.status;
}

int freeMemory() {
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}
