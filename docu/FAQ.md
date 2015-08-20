# Frequently Asked Questions

## Is the SilentStepStick 100% compatible with a StepStick or Pololu A4988?
The SilentStepStick is hardware/pin compatible with StepStick and Pololu A4988 drivers.
However the TMC2100 has different and more settings, which can be set via the ```CFG/MS``` pins.
The TMC2100 config pins also know three states: GND, VCC and open.


## Where can I find more information on the settings and operation modes?
More information can be found in the [SilentStepStick schematics](https://github.com/watterott/SilentStepStick/tree/master/pcb) and [TMC2100 datasheet](http://www.trinamic.com/products/integrated-circuits/stepper-power-driver/tmc2100).

**Installation Guides:**
* [Ultimaker UM1 (English)](http://umforum.ultimaker.com/index.php?/topic/10571-step-by-step-install-silentstepstick-drivers-on-um1/)
* [Prusa i3 (Danish)](http://qblog.dk/2015/silent-step-sticks-paa-prusa-i3-hephestos/)
* [RAMPS (English)](http://www.instructables.com/id/Install-and-configure-SilentStepStick-in-RAMPS-TMC/)
* [Motor Current Setting (English)](https://www.youtube.com/watch?v=R5JgRhSSKUM)


## How to control the stepper motor driver?
The SilentStepStick has a normal step+direction interface.
You set the direction with the ```DIR``` pin and on every pulse on the ```STEP``` pin the motor will move one step.
Here is an [Arduino example](https://github.com/watterott/SilentStepStick/blob/master/docu/Stepper.ino).


## How to set the stepper motor current?
The best way to set the motor current is by measuring the voltage on the ```Vref``` pin (0...2.5V) and
adjusting the voltage with the potentiometer.
The maximum motor current is 1.77A and is set via the 0.11Ohm sense resistors.

Example: A voltage of 1.0V on Vref sets the motor current to 0.71A.

```Irms = (Vref * 1.77A) / 2.5V```


## What to consider when turning the power supply on or off?
**Power on:**
The motor supply voltage ```VM``` should come up first and then ```VIO```, because the internal logic of the TMC2100 driver is powered from ```VM```.
Only after ```VIO``` is present and stable, the driver inputs (STEP, DIR, EN) can be driven with a high level.

**Power off:**
If the motor is running/moving, then it is not allowed to switch off the power supply. Always make sure that the motor stands still on shutting down.
An **emergency stop** can be realized, when the ```EN/CFG6``` pin is set to ```VIO```. This will switch off all power drivers and will put the motor into freewheeling.


## Is it possible to connect the CFG pins from different SilentStepSticks?
It is possible to connect the ```CFG``` pins from two or more driver boards. However then the pin state can only be GND (low) or VIO (high). The open state is not possible in this configuration.
