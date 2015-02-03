# Frequently Asked Questions

## Is the SilentStepStick 100% compatible with a StepStick or Pololu A4988?
The SilentStepStick is hardware/pin compatible with StepStick and Pololu A4988 drivers. However the TMC2100 has different and more settings, which can be set via the CFG/MS pins.
The TMC2100 config pins also know three states: GND, VCC and open.


## How to set the stepper motor current?
The best way to set the motor current is by measuring the voltage on the Vref pin (0...2.5V) and
adjusting the voltage with the potentiometer.
The maximum motor current is 1.77A and is set via the 0.11Ohm sense resistor.

Example: A voltage of 1.0V on Vref sets the motor current to 0.71A.

```Irms = (Vref * 1.77A) / 2.5V```
