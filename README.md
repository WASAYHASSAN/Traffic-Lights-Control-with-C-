# Traffic Light Intersection Controller
<img width="1366" height="544" alt="Final project" src="https://github.com/user-attachments/assets/d54b64db-c04b-4715-a9be-d19fe73bc2c9" />

## Project Overview
This project simulates a fully functional, two-way traffic intersection utilizing an Arduino microcontroller. Written in C++, the system employs Object-Oriented Programming (OOP) concepts to manage the state of the traffic lights and includes an active serial-polling mechanism for real-time emergency vehicle overrides. 

## Hardware Configuration
The circuit design requires standard prototyping components. For a complete visual layout of the wiring, please reference the included Final project.png file.

### Components Required
* 1x Arduino Uno (or compatible microcontroller)
* 1x Prototyping Breadboard
* 6x LEDs (2 Red, 2 Yellow, 2 Green)
* 6x Current-limiting Resistors
* Jumper wires

### Pin Mapping
* **North Intersection:** 
  * Red LED: Digital Pin 12
  * Yellow LED: Digital Pin 10
  * Green LED: Digital Pin 8
* **East Intersection:**
  * Red LED: Digital Pin 7
  * Yellow LED: Digital Pin 6
  * Green LED: Digital Pin 5

## Software Architecture
The codebase is structured around object-oriented principles to ensure modularity and ease of expansion:
* **`TrafficLight` Class:** Encapsulates the pin configuration and state management (Red, Yellow, Green) for a single traffic light unit.
* **`Intersection` Class:** Inherits from `TrafficLight` and acts as a controller that manages multiple `TrafficLight` objects (North and East), allowing for coordinated multi-directional control and emergency state handling.

## System Operation
The main control loop cycles through four distinct phases to ensure safe traffic flow:
1. **Phase 0:** North is Green, East is Red (3 seconds).
2. **Phase 1:** North is Yellow, East is Red (1 second).
3. **Phase 2:** North is Red, East is Green (3 seconds).
4. **Phase 3:** North is Red, East is Yellow (1 second).

## Emergency Override System
Instead of relying on standard blocking `delay()` functions, the project utilizes a custom `smartWait()` function. This function breaks down the standard wait times into 10-millisecond intervals, continuously polling the Arduino Serial Monitor (at a 9600 baud rate) for incoming commands.

* **Command `1`:** Immediately forces the North light to Green and the East light to Red for 5 seconds, accommodating Northbound emergency vehicles.
* **Command `2`:** Immediately forces the East light to Green and the North light to Red for 5 seconds, accommodating Eastbound emergency vehicles.

## Setup and Installation
1. Assemble the hardware components according to the wiring diagram in Final project.png.
2. Open the source file in the Arduino IDE.
3. Select the correct board and COM port from the Tools menu.
4. Upload the code to the Arduino.
5. Open the Serial Monitor (set to 9600 baud) to interact with the emergency override system.
