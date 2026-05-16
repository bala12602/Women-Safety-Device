//#include <Wire.h>
//#include <LiquidCrystal_I2C.h>
//#include <PulseSensorPlayground.h> // Include the PulseSensorPlayground Library
//
//// Initialize the LCD with I2C address 0x27, 16 columns and 2 rows
//LiquidCrystal_I2C lcd(0x27, 16, 2);
//
//// Variables
//const int PulseWire = A0;       // PulseSensor PURPLE WIRE connected to ANALOG PIN 0
//const int Threshold = 550;     // Threshold for counting a beat
//
//PulseSensorPlayground pulseSensor; // Create an instance of the PulseSensorPlayground object
//
//void setup() {
//  Serial.begin(9600);          // For Serial Monitor
//  lcd.init();                  // Initialize the LCD
//  lcd.backlight();             // Turn on the backlight
//
//  // Configure the PulseSensor object
//  pulseSensor.analogInput(PulseWire);
//  pulseSensor.setThreshold(Threshold);
//
//  // Check if the pulseSensor object was created successfully
//  if (pulseSensor.begin()) {
//    Serial.println("PulseSensor object created!");
//  }
//}
//
//void loop() {
//  int myBPM = pulseSensor.getBeatsPerMinute(); // Get BPM value
//
//  if (pulseSensor.sawStartOfBeat()) {           // Check if a beat occurred
//    // Print heartbeat message and BPM to Serial Monitor
//    
//    // Print heartbeat message and BPM to the LCD
//    lcd.clear();                                // Clear the LCD
//    lcd.setCursor(0, 0);                        // Set cursor to the first row
//    lcd.print("A HeartBeat Happened!");     // Print heartbeat message
//    lcd.setCursor(0, 1);                        // Set cursor to the second row
//    lcd.print("BPM: ");                         // Print BPM label
//    lcd.print(myBPM);                           // Print the BPM value
//  
//    // Delay to keep the display active for a while
//    delay(2000);                                // Display for 2 seconds
//
//    // Clear the LCD after the delay
//    lcd.clear();
//  }
//
//  delay(20);                                    // Short delay for stability
//}
