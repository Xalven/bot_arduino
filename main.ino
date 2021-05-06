#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2); //initialisation des broches de l'écran lcd

const int ultrasound_sensor_trigger_pin = 8;
const int ultrasound_sensor_echo_pin = 7;
float distance;
bool state_ultrasoud_sensor = true;
bool obstacle = false;

float distance_mesurement(){
    float distance;
    digitalWrite(ultrasound_sensor_trigger_pin, HIGH);
    delayMicroseconds(2);
    digitalWrite(ultrasound_sensor_trigger_pin, LOW);
    delayMicroseconds(10);
    distance= pulseIn(ultrasound_sensor_echo_pin, HIGH) / 58.0;
    return distance;
}


void setup()
  {
    pinMode(ultrasound_sensor_trigger_pin, OUTPUT);
    pinMode(ultrasound_sensor_echo_pin, INPUT);
    Serial.begin(9600);
    lcd.begin(16,2);
  }
void loop()
  {
    distance = distance_mesurement();
  } 
