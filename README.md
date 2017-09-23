# PlayWithArduino
This was part of my submission for MRSD Project Course.

Materials required:
Arduino Uno
USB A-B Cable
Breadboard
Button (2)
RGB LED
10kΩ Rotary Potentiometer
150Ω Resistor
100Ω Resistor (2)
10kΩ Resistor (2)
Wire

Set up circuit as shown:

Switching:
Switching between states happen every time Button 0 is pressed. The states shall transition in order (0, 1, 2, 0, 1, 2, …) and holding and releasing will have no further effect.

State 0:
Pressing Button 1 will make LED toggle between on and off, with no further effect on holding and releasing.

State 1:
When potentiometer is turned clockwise, the LED shall become brighter, and when turned anti-clockwide, the LED shall become dimmer.

State 2:
The color/brightness of the LED is controlled by serial commands structured as ‘r’, ‘g’, or ‘b’, followed by a number.  The number, an integer in range [0, 255], will set brightness of that channel, with 0 for none and 255 for full brightness.


