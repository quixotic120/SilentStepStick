# Frequently Asked Questions

## Is the SilentStepStick 100% compatible with a StepStick or Pololu A4988?
The SilentStepStick is hardware/pin compatible with StepStick and Pololu A4988 drivers. However the TMC2100 has different and more settings, which can be set via the CFG/MS pins.
The TMC2100 config pins also know three states: GND, VCC and open.


## How to set the stepper motor current?
The best way to set the motor current is by measuring the voltage on the ```Vref``` pin (0...2.5V) and
adjusting the voltage with the potentiometer.
The maximum motor current is 1.77A and is set via the 0.11Ohm sense resistors.

Example: A voltage of 1.0V on Vref sets the motor current to 0.71A.

```Irms = (Vref * 1.77A) / 2.5V```


## What to consider when turning the power supply on or off?
Always insure that the driver board has fixed signals on the control inputs and that the I/O supply voltage ```VIO``` and the motor supply voltage ```VM``` is present.
If the motor is moving, then it is not allowed to switch off the power supply. Always make sure that the motor stands still on shutting down.
An emergency stop can be realized, when the ```EN/CFG6``` pin is set to ```VIO```. This will switch off all power drivers and will put the motor into freewheeling.


## Where can I find more information on the settings and operation modes?
More information can be found in the [SilentStepStick schematics](https://github.com/watterott/SilentStepStick/tree/master/pcb) and [TMC2100 datasheet](http://www.trinamic.com/products/integrated-circuits/stepper-power-driver/tmc2100).

An installation guide for the Ultimaker UM1 can be found [here](http://umforum.ultimaker.com/index.php?/topic/10571-step-by-step-install-silentstepstick-drivers-on-um1/).
