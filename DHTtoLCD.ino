/* This program measures temperature and humidity from a DHT temperature and humidity sensor
 *  and prints the measured values to a 16x2 LCD display
 *  Revision: 8/24/2020 Peter Sanchez 
 */





#include "DHT.h" // Temperature and Humidity Sensor library
#include <LiquidCrystal.h> // 16x2 LCD display library
#define DHTPIN 7 // Pin Temperature and Humidity Sensor is connected to
#define DHTTYPE DHT11 // Type of DHT sensor being used 


DHT dht(DHTPIN, DHTTYPE); // A DHT sensor named "dht" of type: "DHTTYPE" is connected on pin: "DHTPIN"
LiquidCrystal lcd( 12, 11, 5, 4, 3, 2);
/* A LiquidCrystal display is named "lcd"
 *  LCD WIRING:
 *    LCD RS  = Arduino D12
 *    LCD E   = Arduino D11
 *    LCD DB4 = Arduino D5
 *    LCD DB5 = Arduino D4
 *    LCD DB6 = Arduino D3
 *    LCD DB7 = Arduino D2
 * 
 */

void setup() {
  // begin DHT and LCD
  dht.begin();
  lcd.begin(16, 2); // LCD is 16x2 characters

  lcd.print("Hello,World!"); // Print to LCD

  delay(500);
}

void loop() {
  delay(2000);

  // Read Temperature and Humidity from DHT sensor and store results as floats

   float Humidity = dht.readHumidity();         // Read humidity from DHT
   float tempCel  = dht.readTemperature();      // Read temperature from DHT in Celsius
   float tempFahr = dht.readTemperature(true);  // Read temperature from DHT in Fahrenheit



   // Print Temperature and Humidity to LCD

   lcd.setCursor(0,0); // Set the LCD to print on the upper row

   // Print Humidity
   lcd.print("Humid: ");
   lcd.print(Humidity);
   lcd.print("%");

   lcd.setCursor(0,1); // Set the LCD to print on the lower row

   // Print Temperature in Fahrenheit
   lcd.print("Temp: ");
   lcd.print(tempFahr);
   lcd.print("F");

  
   
   

}
