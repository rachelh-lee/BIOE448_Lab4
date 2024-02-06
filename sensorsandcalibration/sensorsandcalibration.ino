
// trig is to pin 11
// echo is to pin 12
// Vcc is to 5V
// GND is to GND

const int trigPin = 11;
const int echoPin = 12;
long duration;
int distanceCm, distanceInch;
const double R1 = 0.0343/2;
// speed of sound in cm/uS and divded by two because the sound travels there and back
const double R2 = 0.0135/2;
// speed of sound in In/uS and divded by two because the sound travels there and back
const int LEDPin = 2;
// setting pin6 to input to Red Led
const int LEDPin2 = 6;
// setting pin 2 to input to Green Led 
const int threshold = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  // calibrating the sensor
  distanceCm = duration * R1;
  distanceInch = duration * R2;
  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.print(" cm/");
  Serial.print(distanceInch);
  Serial.println(" in");
  delay(1000);
  // adding complexity, if distance is less than threshold, Green LED lights up, if not Red lED lights up
  if (distanceInch < threshold) {
    digitalWrite(LEDPin, HIGH);
    digitalWrite(LEDPin2, LOW);
  }
  else {
    digitalWrite(LEDPin, LOW);
    digitalWrite(LEDPin2, HIGH);
  }

}
