# 🌿 Automatic Irrigation 69420: Automated Bio-Hydration System
An intelligent, IoT-ready automated plant watering system using Arduino Uno, capacitive sensors, and a web-based command center.

> [!IMPORTANT]
> This repository was built as a small school assignment using an AI-native workflow. 
> The focus was on prototyping, rather than 
> long-form manual architecture.

## 🚀 Features
* **Automatic Irrigation**: Waters the plant based on real-time soil moisture data.
* **Hybrid Logging**: Sends human-readable logs for Serial Monitor and JSON for machine processing.
* **Web Dashboard**: A futuristic HTML/CSS dashboard using Web Serial API for monitoring and remote control.
* **Manual Overrides**: Force the pump ON or OFF directly from your browser.
* **Anti-Corrosion**: Uses a capacitive sensor for long-term durability.

## 🛠 Materials & Components
| Component | Quantity | Description |
| :--- | :--- | :--- |
| **Arduino Uno R3** | 1 | The brain of the project. |
| **Capacitive Soil Moisture** | 1 | Corrosion-resistant soil sensor. |
| **5V Relay Module** | 1 | Switches the pump power (Active Low). |
| **Mini Water Pump 5V** | 1 | Submersible pump for watering. |
| **LED (Optional)** | 1 | Visual status indicator. |
| **Power Source** | 1 | Power bank or 5V Adapter. |

## 🔌 Pin Mapping (Wiring)

### 1. Sensor & Relay to Arduino
| Component Pin | Arduino Pin | Function |
| :--- | :--- | :--- |
| **Sensor VCC** | 5V | Power Input |
| **Sensor GND** | GND | Ground |
| **Sensor Signal (AU)** | **A0** | Analog Data |
| **Relay VCC** | 5V | Power Input |
| **Relay GND** | GND | Ground |
| **Relay IN1** | **D8** | Digital Control |
| **LED Anode (+)** | **D13** | Status Light (Optional) |

### 2. Pump & Power Connection (The Switch)
* **Power Source (+)** ➔ Relay **COM** (Central Terminal)
* **Relay NO** (Normally Open) ➔ **Pump USB (+)** (Red Wire)
* **Power Source (-)** ➔ **Pump USB (-)** (Black Wire)

## 💻 Installation
1.  Open the project in **VS Code** with **PlatformIO**.
2.  Upload the `src/main.cpp` code to your Arduino Uno.
3.  Open `index.html` in **Google Chrome** or **Microsoft Edge**.
4.  Close the Serial Monitor in VS Code.
5.  Click **Connect to Arduino** on the Web Dashboard.

## 🕹 Commands
Type these in Serial Monitor or use the Dashboard buttons:
* `ON` : Force pump to start (Manual Mode).
* `OFF`: Force pump to stop (Manual Mode).
* `AUTO`: Return control to the soil sensor (Automatic Mode).

## 📄 License
This project is part of an educational assignment.
Basically, you can do whatever you want with this code as long as you don't sue me if your plant gets too much water. It's a school project, after all! 🌿