[![noswpatv3](http://zoobab.wdfiles.com/local--files/start/noupcv3.jpg)](https://ffii.org/donate-now-to-save-europe-from-software-patents-says-ffii/)
Simplified BLE Beacon for Fri3dCamp Badge
=========================================

Bluetooth BLE beacon and scanner based on the ESP32, badge for Fri3dcamp. It
counts the number of similar badges around. #esp32 #Bluetooth #fri3dcamp 

Taken from the Arduino example, and simplified.

Picture
=======

![Fri3dcamp ESP32 badge with BLE beacon counting neighboors](fri3dcamp-badge-esp32-ble-beacon.jpg)

Todo
====

* Find out how to decrease the TX power of the Beacon, right now it goes too far (around 100m measured) Try "esp_ble_tx_power_set(ESP_BLE_PWR_TYPE_ADV, ESP_PWR_LVL_N11);" as mentioned here https://github.com/nkolban/esp32-snippets/issues/197
* Docker container to flash with arduino-cli

Links
=====

* Link to original source code of Arduino BLE here
