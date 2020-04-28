// Simple BLE for FriedCamp Badge ESP32
// Beacon is friedMACADDR , like "friedAABBCCDDEEFF"

#include "SimpleBLE.h"
#include "WiFi.h"

SimpleBLE ble;
  
void setup() {
    Serial.begin(115200);
    Serial.setDebugOutput(true);
    //  waiting for 5secs, sometimes if I do not wait the MAC is 00:00:00:00:00:00, WTF
    sleep(5);
    String mac = WiFi.macAddress();
    String macwdot = mac;
    macwdot.replace(":", "");
    String head = "covid";
    String beacon_name = head + macwdot;
    String beacon_name_2 = head + macwdot + 2;
    
    ble.begin(beacon_name);
    Serial.println(beacon_name);
    
    ble.begin(beacon_name_2);
    Serial.println(beacon_name_2);
}
  
void loop() {
    while(Serial.available()) Serial.write(Serial.read());
}
