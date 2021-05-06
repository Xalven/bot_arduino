const int ultrasound_sensor_trigger_pin = 2;
const int ultrasound_sensor_echo_pin = 4;
long lecture_echo; // long[2^31-1;2^31-1]
long obstacle_distance;
bool is_obstacle = false // true if there is an obstacle

long distance_mesurement(){
  digitalWrite(ultrasound_sensor_trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultrasound_sensor_trigger_pin, LOW);
  lecture_echo = pulseIn(ultrasound_sensor_echo_pin,HIGH);
  obstacle_distance = lecture_echo /58;
  return distance;
}

void setup(){
  pinMode(ultrasound_sensor_trigger_pin, OUTPUT);
  digitalWrite(ultrasound_sensor_trigger_pin, LOW);
  pinMode(ultrasound_sensor_echo_pin, INPUT);
  Serial.begin(9600);
}

void loop(){
  obstacle_distance = distance_mesurement();
  Serial.print("Distance en cm :");
  Serial.println(distance);
  delay(1500);
}
