# 🚦 Traffic Lights Control System

A simple, C++ based traffic light controller built and simulated using Arduino on Tinkercad. This project demonstrates basic hardware-software integration, utilizing GPIO pins to sequence standard traffic light operations.

## 🛠️ Components Used
* **Microcontroller:** Arduino Uno R3 (or compatible)
* **Actuators:** 3x LEDs (Red, Yellow, Green)
* **Passives:** 3x Resistors (220Ω or 330Ω)
* **Prototyping:** Breadboard & Jumper Wires

## ⚙️ How It Works
The C++ code controls the digital output pins of the Arduino to simulate a real-world traffic light sequence using precise timing delays:
1. **Red Light (Stop):** Holds for a set duration.
2. **Green Light (Go):** Activates after Red.
3. **Yellow Light (Yield):** Activates briefly after Green to signal the upcoming stop.
4. **Loop:** The cycle repeats continuously.

## 🔗 Live Simulation
You can view the circuit wiring and run the live code simulation directly in your browser:  
👉 **[View & Run on Tinkercad](https://www.tinkercad.com/things/6SpF4AH6d0Q-traffic-lights-control?sharecode=Al-fUTIWk6LwjJrG20F51QonmTxn817v12DaXfcZ6UM)**

## 🚀 How to Run Locally
1. Clone this repository.
2. Open the `.ino` / `.cpp` file in the **Arduino IDE**.
3. Wire the physical components according to the Tinkercad schematic.
4. Connect your Arduino via USB and hit **Upload**.

---
*Created by [Your Name/GitHub Handle]*
