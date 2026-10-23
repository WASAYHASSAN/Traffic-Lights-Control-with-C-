# Smart Traffic Light Intersection Controller

This project is an Arduino-based traffic light simulation for a two-way intersection (North and East). It is programmed in C++ using Object-Oriented Programming (OOP) principles to manage the states of the traffic lights and includes a serial-based emergency override system.

## Hardware Configuration
The physical wiring and component layout are documented in the Final project.png file[cite: 1]. The required components include:
* Arduino Uno microcontroller[cite: 1]
* 1 Breadboard[cite: 1]
* 6 LEDs (2 Red, 2 Yellow, 2 Green)[cite: 1]
* 6 Resistors[cite: 1]
* Jumper wires connecting the components to the Arduino digital pins[cite: 1]

### Pin Mapping
* **North Light:** Red (Pin 12), Yellow (Pin 10), Green (Pin 8)
* **East Light:** Red (Pin 7), Yellow (Pin 6), Green (Pin 5)

## Features
* **Object-Oriented Design:** Utilizes `TrafficLight` and `Intersection` classes to encapsulate pin management and light behaviors cleanly.
* **Standard Traffic Cycle:** Automatically alternates through Green, Yellow, and Red phases for both directions.
* **Emergency Override System:** Implements a custom `smartWait` function that continuously polls the Serial Monitor (9600 baud) during active delays.
  * Sending `1` overrides the sequence, forcing the North light to Green and East light to Red for 5 seconds.
  * Sending `2` overrides the sequence, forcing the North light to Red and East light to Green for 5 seconds.
