//#include <TinyGPS++.h>
//#include <SoftwareSerial.h>
//
//// Create a TinyGPS++ object
//TinyGPSPlus gps;
//
//// Use the same pins you already have for RX and TX
//SoftwareSerial ss(8, 9); // RX, TX
//
//void setup() {
//    Serial.begin(9600);
//    ss.begin(9600);
//}
//
//void loop() {
//    while (ss.available()) {
//        gps.encode(ss.read());
//        if (gps.location.isUpdated()) {
//            Serial.print("Latitude= ");
//            Serial.print(gps.location.lat(), 6); // 6 decimal places
//            Serial.print(" Longitude= ");
//            Serial.println(gps.location.lng(), 6);
//        }
//    }
//}
