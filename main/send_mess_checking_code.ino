//#include <SoftwareSerial.h>
//
//SoftwareSerial mySerial(8, 9); // SIM800L Tx & Rx is connected to Arduino #3 & #2
//
//void setup()
//{
//  Serial.begin(9600);
//  mySerial.begin(9600);
//  
//  Serial.println("Initializing...");
//  delay(1000);
//
//  // Test the SIM800L connection
//  sendATCommand("AT", 2000);       // Handshake test
//  sendATCommand("AT+CMGF=1", 1000); // Set SMS to text mode
//
//  // Send SMS to emergency number
//  sendATCommand("AT+CMGS=\"+917550345738\"", 1000);  // Replace with your number
//  mySerial.print("Hello, I am not safe hello now"); // Message content
//  delay(500);
//  mySerial.write(26);  // Send CTRL+Z to send the message
//  delay(5000);  // Give time for the SMS to send
//}
//
//void loop()
//{
//}
//
//void sendATCommand(const char *command, int timeout)
//{
//  mySerial.println(command);
//  updateSerial(timeout);
//}
//
//void updateSerial(int timeout)
//{
//  long int time = millis();
//  while ((time + timeout) > millis())
//  {
//    while (mySerial.available())
//    {
//      Serial.write(mySerial.read());
//    }
//    while (Serial.available())
//    {
//      mySerial.write(Serial.read());
//    }
//  }
//}
