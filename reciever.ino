#include <RH_ASK.h> // Include RadioHead Amplitude Shift Keying Library
#include <SPI.h> // Include dependant SPI Library
 
// Create Amplitude Shift Keying Object
RH_ASK rf_driver;
const char* csvData = "C:\Users\sayya\Desktop\SIH23\SHIPDATA - Sheet1.csv";

void setup()
{
// Initialize ASK Object
rf_driver.init();
// Setup Serial Monitor
Serial.begin(9600);
}
 
void processCSVData() {
  // Your CSV processing logic goes here
  Serial.println("Processing CSV data...");
  // Example: Split the CSV lines and print them
  char* token = strtok((char*)csvData, "\n");
  while (token != NULL) {
    Serial.println(token);
    token = strtok(NULL, "\n");
  }
}


void loop()
{
// Set buffer to size of expected message
uint8_t buf[11];
uint8_t buflen = sizeof(buf);
// Check if received packet is correct size
if (rf_driver.recv(buf, &buflen))
{
// Message received with valid che-cksum
Serial.print("Recieveing Encroachment");
Serial.println((char*)buf);

Serial.println("Identifying Enroachment");
delay(3000);
Serial.println("..................");
Serial.println("..................");
delay(3000);
Serial.println("Checking Database");
Serial.println("..................");
delay(4000);

if (strlen(csvData) > 0) {
    Serial.println("CSV data found!");

    // Process CSV data
    processCSVData();

  }


Serial.println("Ship ID: ABC1234");
delay(4000);
Serial.println("..................");
Serial.println("..................");
Serial.println("..................");
Serial.println("..................");
delay(4000);
Serial.println("Authorised Encroachment");
delay(5000);


}
}