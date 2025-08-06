# SimuPumpControl – System Requirements

## 1. Functional Requirements

- The system shall support two pump modes: **Suction** and **Flushing**.
- The user shall be able to switch between pump modes during runtime.
- The **flow rate** shall be adjustable in real time.
- The system shall **detect overpressure or blockages** and respond appropriately.

## 2. Safety Requirements

- If **no sensor input** (e.g., pressure or flow) is received within **3 seconds**, the system shall trigger an **Emergency Stop**.
- If **conflicting sensor signals** are detected (e.g., high pressure with zero flow), the system shall enter a **Fault State**.
- **Emergency mode** shall have the highest priority and override all other states or transitions.

## 3. Hardware Interfaces

- **Pressure Sensor Input** (simulated or real)
- **Flow Sensor Input** (simulated or real)
- **PWM Output** for controlling motor speed

## 4. Simulation Environment

- Simulated signals shall be generated using **Signal Editor** or equivalent.
- Sensor data shall include **noise or anomalies** for robustness testing.
- Transition conditions and state outputs shall be observable via **Display** and **Scope** blocks.

## 5. Extendability

- The system architecture shall allow easy extension with:
  - Additional sensors (e.g., temperature, blockage detection)
  - Real-time embedded deployment on **ESP8266**
  - GUI control via **Simulink Dashboard** or **App Designer**
