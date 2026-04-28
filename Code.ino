const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin = 11;
const int motorPin = 12; // Define the pin for the vibration motor

long duration;
int distance;
int safetyDistance = 50; 
int motorDistance = 20;  // Threshold for the vibration motor

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(motorPin, OUTPUT); // Set the motor pin as an output
  Serial.begin(9600); 
}

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Calculate the distance
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  
  // Buzzer logic: Activates at 50 cm or less
  if (distance <= safetyDistance && distance > 0) {
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
  }

  // Vibration motor logic: Activates at 20 cm or less
  if (distance <= motorDistance && distance > 0) {
    digitalWrite(motorPin, HIGH);
  } else {
    digitalWrite(motorPin, LOW);
  }
  
  delay(50); // Small delay for stability
}