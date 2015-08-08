
#define EN_PIN   2 //enable pin
#define STEP_PIN 3 //step pin
#define DIR_PIN  4 //direction pin

//Note: You also have to connect GND and 5V from the Arduino to the SilentStepStick.
//      A connection diagram can be found in the schematics.

void setup()
{
  pinMode(EN_PIN, OUTPUT);
  digitalWrite(EN_PIN, HIGH); //deactivate driver (LOW active)
  pinMode(DIR_PIN, OUTPUT);
  digitalWrite(DIR_PIN, LOW);
  pinMode(STEP_PIN, OUTPUT);
  digitalWrite(STEP_PIN, LOW);

  digitalWrite(EN_PIN, LOW); //activate driver
}

void loop()
{
  int i;

  digitalWrite(DIR_PIN, LOW); //set the direction: low

  for(i=0; i<3200; i++) //iterate for 3200 steps
  {
    digitalWrite(STEP_PIN, LOW);
    delay(2); //wait 2ms
    digitalWrite(STEP_PIN, HIGH);
    delay(2); //wait 2ms
  }

  delay(500); //wait 500ms

  digitalWrite(DIR_PIN, HIGH); //set the direction: high

  for(i=0; i<3200; i++) //iterate for 3200 steps
  {
    digitalWrite(STEP_PIN, LOW);
    delay(2); //wait 2ms
    digitalWrite(STEP_PIN, HIGH);
    delay(2); //wait 2ms
  }

  delay(500); //wait 500ms
}
