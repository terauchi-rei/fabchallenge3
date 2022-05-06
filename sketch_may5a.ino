/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-light-sensor
 */

// The below are constants, which cannot be changed
#define LIGHT_SENSOR_PIN  A3  // ESP32 pin GIOP36 (ADC0) connected to light sensor
#define LED_PIN           13  // ESP32 pin GIOP22 connected to LED
#define ANALOG_THRESHOLD  3800

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT); // set ESP32 pin to output mode
}

void loop() {
  int analogValue = analogRead(LIGHT_SENSOR_PIN); // read the value on analog pin

  Serial.println(analogValue);
  if (analogValue < ANALOG_THRESHOLD)
    digitalWrite(LED_PIN, LOW); // turn on LED
  else
    digitalWrite(LED_PIN, HIGH);  // turn off LED
    

}