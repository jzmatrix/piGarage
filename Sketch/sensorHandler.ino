unsigned long curTime;
// ============================================================= //
// GPIO Pin Assignments
const int sensor1Trig = 48;
const int sensor1Echo = 49;
//
const int sensor2Trig = 50;
const int sensor2Echo = 51;
//
const int sensor3Trig = 52;
const int sensor3Echo = 53;
// ============================================================= //
String sensor1Distance;
String sensor2Distance;
String sensor3Distance;
// ============================================================= //
void setup()
{
//  pinMode(sensor1Trig , OUTPUT);
//  pinMode(sensor1Echo , INPUT);
  //
//  pinMode(sensor2Trig , OUTPUT);
//  pinMode(sensor2Echo , INPUT);
  //
//  pinMode(sensor3Trig , OUTPUT);
//  pinMode(sensor3Echo , INPUT);
  //
  //pinMode(sensor4Trig , OUTPUT);
  //pinMode(sensor4Echo , INPUT);
  //
  Serial.begin(9600);
}
// ---------------------------------------------------------------------------------- //
String readDistance(int trigPin,int echoPin)
{
  pinMode(trigPin , OUTPUT);
  pinMode(echoPin , INPUT);
  //
  String returnDistance;
  //
  int sensorDuration;
  int sensorDistance;
  //
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // ============== //
  digitalWrite(trigPin , HIGH);
  delayMicroseconds(10);
  digitalWrite(echoPin , LOW);
  //
  sensorDuration = pulseIn(echoPin, HIGH);
  //
  sensorDistance = ((sensorDuration/2) / 28.5) / 2.54;  // Find distance, in inches
  //
  if (sensorDistance < 10)
  {
    returnDistance = "0" + (String)sensorDistance;
  }
  else
  {
    returnDistance = (String)sensorDistance;
  }
  //
  return returnDistance;
}

// ---------------------------------------------------------------------------------- //
void loop()
{
  sensor1Distance = readDistance(sensor1Trig,sensor1Echo);
  sensor2Distance = readDistance(sensor2Trig,sensor2Echo);
  sensor3Distance = readDistance(sensor3Trig,sensor3Echo);
  //
  curTime = millis();
  Serial.println((String)sensor1Distance + "," + sensor2Distance + "," + sensor3Distance + "," + curTime);

  delay(250);
}