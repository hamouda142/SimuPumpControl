# SimuPumpControl

**Project Goal:**  
This project simulates the control of a medical suction and flushing system to demonstrate model-based design (MBD) with a focus on safety-critical functionality in accordance with IEC 62304 – the international standard for medical device software.
This project is inspired by the IEC 62304 standard — focusing on modularity, traceability, testability, and safety logic within a simulated environment.
---

**Technologies Used:**
- MATLAB R202x
- Simulink
- Stateflow (graphical state machine)
- Embedded C (via Embedded Coder)
- ESP8266 (optional – for hardware simulation)

---

**Core Features:**
- State-machine logic for pump modes (suction, flush, idle, emergency)
- Pressure and flow sensor simulation using Signal Builder
- Safety mechanism: overpressure detection, inconsistent signal handling
- Optional embedded C code generation for ESP8266
- Structured folder system for documentation, testing, and hardware interfacing

---

**Structure:**

```plaintext
SimuPumpControl/
├── models/      → Simulink models (.slx)
├── code/        → Auto-generated C code
├── docs/        → Diagrams, requirements, README
├── hardware/    → ESP8266 pinouts, sensor datasheets
├── test/        → Test plans and simulation results
└── README.md    → This project overview
