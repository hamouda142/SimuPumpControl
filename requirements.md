SimuPumpControl – System Requirements

Functional Requirements:

The system must support two pump modes: suction and flushing.

The user can switch between modes during operation.

The flow rate should be adjustable.

The system should detect overpressure or blockages.

Safety Requirements:

If a sensor fails or gives no signal for 3 seconds → trigger emergency stop.

If sensor signals conflict (e.g. pressure too high and flow zero) → trigger fault state.

Emergency mode overrides all other modes.

Hardware Interfaces:

Simulated pressure sensor input 

Simulated flow sensor input 

PWM output for controlling motor speed

