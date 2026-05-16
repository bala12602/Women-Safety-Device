//#include <Wire.h>
//#include <LiquidCrystal_I2C.h>
//#include <PulseSensorPlayground.h>
//#include <TinyGPS++.h>
//#include <SoftwareSerial.h>
//
//// Initialize the LCD
//LiquidCrystal_I2C lcd(0x27, 16, 2);
//
//// Pulse Sensor Variables
//const int PulseWire = 0; // PulseSensor PURPLE WIRE connected to ANALOG PIN 0
//const int Threshold = 550; // Threshold for counting a beat
//
//PulseSensorPlayground pulseSensor; // Create an instance of the PulseSensorPlayground object
//
//// GPS Variables
//TinyGPSPlus gps;
//SoftwareSerial ss(8, 9); // RX, TX for both SIM800L and GPS
//
//void setup() {
//    Serial.begin(9600); // For Serial Monitor
//    ss.begin(9600); // Initialize SoftwareSerial for SIM800L and GPS
//    lcd.init(); // Initialize the LCD
//    lcd.backlight(); // Turn on the backlight
//
//    // Configure the PulseSensor object
//    pulseSensor.analogInput(PulseWire);
//    pulseSensor.setThreshold(Threshold);
//
//    // Check if the pulseSensor object was created successfully
//    if (pulseSensor.begin()) {
//        Serial.println("PulseSensor object created!");
//    }
//}
//
//void loop() {
//    int myBPM = pulseSensor.getBeatsPerMinute(); // Get BPM value
//
//    if (pulseSensor.sawStartOfBeat()) { // Check if a beat occurred
//        // Print heartbeat message and BPM to Serial Monitor
//        Serial.println("♥  A HeartBeat Happened!");
//        Serial.print("BPM: ");
//        Serial.println(myBPM);
//        
//        // Print heartbeat message and BPM to the LCD
//        lcd.clear(); // Clear the LCD
//        lcd.setCursor(0, 0); // Set cursor to the first row
//        lcd.print("A HeartBeat Happened!");
//        lcd.setCursor(0, 1); // Set cursor to the second row
//        lcd.print("BPM: "); // Print BPM label
//        lcd.print(myBPM); // Print the BPM value
//
//        // Check if BPM is greater than 170
//        if (myBPM > 20) {
//            getGPSData(); // Collect GPS data
//            sendSMS(); // Send SMS with GPS data
//        }
//
//        // Delay to keep the display active for a while
//        delay(2000); // Display for 2 seconds
//
//        // Clear the LCD after the delay
//        lcd.clear();
//    }
//
//    delay(20); // Short delay for stability
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
//    sendATCommand("AT", 2000); // Handshake test
//    sendATCommand("AT+CMGF=1", 1000); // Set SMS to text mode
//    
//    // Prepare the message with the GPS coordinates
//    String latitude = String(gps.location.lat(), 6);
//    String longitude = String(gps.location.lng(), 6);
//    String message = "Emergency! I am in danger. Here is my location: " 
//                     "https://maps.google.com/?q=" + latitude + "," + longitude;
//    
//    // Send SMS to emergency number
//    sendATCommand("AT+CMGS=\"+919629968261\"", 1000); // Replace with your phone number
//    ss.print(message); // Send the message
//    delay(500);
//    ss.write(26); // Send CTRL+Z to send the message
//    delay(5000); // Wait for the SMS to send
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
