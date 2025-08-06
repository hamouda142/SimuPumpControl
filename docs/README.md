# SimuPumpControl

A control system simulation for a medical suction/flushing pump using Simulink and Stateflow.

---

##  Features

-  **State Machine Logic**: Built with Stateflow to handle four key operational states:
  - `Idle` (0)
  - `Suction` (1)
  - `Flush` (2)
  - `Emergency` (-1)

- **Signal-based Transitions**:
  - Controlled by two input signals: `mode` and `pressure`
  - Includes safety logic for pressure anomalies

-  **Dynamic Test Scenarios**:
  - Custom signal scenarios via Signal Editor
  - Supports full operational loop simulation

- **Modular Design**:
  - `SensorSim`, `ControlLogic`, and `MotorControl` subsystems
  - Clear signal naming (`pressure`, `mode`, `pumpState`)
  - Display block for real-time pump state monitoring

---

## How to Run

1. Open `SimuPumpControl.slx` in Simulink
2. Launch Signal Editor and load a scenario (pressure + mode)
3. Click **Run** to simulate the control logic
4. Watch the state output via the display connected to `pumpState`

---

## Future Improvements

- Add live displays for `mode` and `pressure`
- Extend motor control logic to react to pump state
- Hardware-in-the-loop simulation (e.g., ESP8266 + sensors)

---

## 📂 Folder Structure

SimuPumpControl/
├── models/      → Simulink model (.slx)
├── code/        → Auto-generated C code
├── docs/        → Diagrams, requirements, README
├── hardware/    → ESP8266 pinouts, sensor datasheets
├── test/        → Test plans and simulation results
