/*
   Based on Neil Kolban example for IDF: https://github.com/nkolban/esp32-snippets/blob/master/cpp_utils/tests/BLE%20Tests/SampleScan.cpp
   Ported to Arduino ESP32 by Evandro Copercini
*/

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>
#include <Fri3dMatrix.h>

int scanTime = 30; //In seconds

class MyAdvertisedDeviceCallbacks: public BLEAdvertisedDeviceCallbacks {
    void onResult(BLEAdvertisedDevice advertisedDevice) {
      Serial.printf("Advertised Device: %s \n", advertisedDevice.toString().c_str());
    }
};

Fri3dMatrix matrix = Fri3dMatrix();

void displayNumbers( int left , int right ) {
  matrix.clear();
  if( left < 10 )
    matrix.drawString( 4, String( left ) );
  else
    matrix.drawString( 0, String( left ) );
  if( right < 10 )
    matrix.drawString( 11, String( right ) );
  else
    matrix.drawString( 7, String( right ) );
}

void setup() {
  Serial.begin(115200);
  Serial.println("Scanning...");

  BLEDevice::init("");
  BLEScan* pBLEScan = BLEDevice::getScan(); //create new scan
  pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
  pBLEScan->setActiveScan(true); //active scan uses more power, but get results faster
  BLEScanResults foundDevices = pBLEScan->start(scanTime);
  Serial.println("Dumping: ");
  int counter=0;
  for (int i=0; i<foundDevices.getCount(); i++) {
     String blename = foundDevices.getDevice(i).getName().c_str();
     if ( blename.indexOf("fried") == 0 ){
         Serial.println(blename);
         counter++;
     }
  }
  Serial.println("Number of frieds: ");
  Serial.println(counter);
  displayNumbers(0, counter);
}

void loop() {
  setup();
  delay(20000);
}
