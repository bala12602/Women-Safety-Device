//#include <TinyGPS++.h>
//#include <SoftwareSerial.h>
//
//// Create a TinyGPS++ object
//TinyGPSPlus gps;
//
//// Define SoftwareSerial for SIM800L and GPS (sharing pins)
//SoftwareSerial ss(8, 9); // RX, TX for both SIM800L and GPS
//
//void setup() {
//    Serial.begin(9600);
//    ss.begin(9600);
//    Serial.println("Initializing...");
//    delay(1000);
//}
//
//void loop() {
//    // Step 1: Collect GPS data
//    getGPSData();
//
//    // Step 2: Send the GPS data via SMS
//    sendSMS();
//    
//    // Wait for a while before repeating the process
////    delay(10000); // Wait 10 seconds before the next loop
//}
//
//void getGPSData() {
//    Serial.println("Getting GPS Data...");
//    long startTime = millis();
//    
//    while (millis() - startTime < 10000) { // Try to get GPS data for 10 seconds
//        while (ss.available()) {
//            gps.encode(ss.read());
//            if (gps.location.isUpdated()) {
//                Serial.print("Latitude: ");
//                Serial.print(gps.location.lat(), 6);
//                Serial.print(" Longitude: ");
//                Serial.println(gps.location.lng(), 6);
//                return; // GPS data acquired
//            }
//        }
//    }
//
//    Serial.println("Failed to get GPS data.");
//}
//
//void sendSMS() {
//    // Temporarily stop GPS communication
//    ss.end();
//    delay(500);
//    
//    // Step 3: Start SIM800L Communication
//    ss.begin(9600);
//    
//    Serial.println("Sending SMS...");
//    sendATCommand("AT", 2000);         // Handshake test
//    sendATCommand("AT+CMGF=1", 1000);  // Set SMS to text mode
//    
//    // Prepare the message with the GPS coordinates
//    String latitude = String(gps.location.lat(), 6);
//    String longitude = String(gps.location.lng(), 6);
//   String message = "Emergency! I am in danger. Here is my location: " 
//                 "https://maps.google.com/?q=" + latitude + "," + longitude;
//    
//    // Send SMS to emergency number
//    sendATCommand("AT+CMGS=\"+917550345738\"", 1000);  // Replace with your phone number
//    ss.print(message); // Send the message
//    delay(500);
//    ss.write(26); // Send CTRL+Z to send the message
//    delay(5000);  // Wait for the SMS to send
//    
//    Serial.println("SMS Sent!");
//    
//    // Step 4: Re-enable GPS communication
//    ss.end();
//    delay(500);
//    ss.begin(9600);
//}
//
//void sendATCommand(const char *command, int timeout) {
//    ss.println(command);
//    updateSerial(timeout);
//}
//
//void updateSerial(int timeout) {
//    long int time = millis();
//    while ((time + timeout) > millis()) {
//        while (ss.available()) {
//            Serial.write(ss.read());
//        }
//        while (Serial.available()) {
//            ss.write(Serial.read());
//        }
//    }
//}
