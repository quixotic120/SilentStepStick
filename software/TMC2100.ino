/*
  TMC2100 Example
*/

// Note: You also have to connect also GND, 5V and VM.
//       A connection diagram can be found in the schematics.
#define EN_PIN   7
#define DIR_PIN  8
#define STEP_PIN 9

void setup()
{
  pinMode(EN_PIN, OUTPUT);
  digitalWrite(EN_PIN, HIGH); //deactivate driver (LOW active)
  pinMode(DIR_PIN, OUTPUT);
  digitalWrite(DIR_PIN, LOW); //LOW or HIGH
  pinMode(STEP_PIN, OUTPUT);
  digitalWrite(STEP_PIN, LOW);

  digitalWrite(EN_PIN, LOW); //activate driver
}

void loop()
{
  //make steps
  digitalWrite(STEP_PIN, HIGH);
  delay(2);
  digitalWrite(STEP_PIN, LOW);
  delay(2);
}
