# SimuPumpControl – Hardware Specification (Corrected)

## Microcontroller
- ESP8266 NodeMCU

## Inputs
- **Pressure Sensor (Analog):**
  - Pin: `A0` (GPIO ADC0)
  - Voltage Range: 0–1V (⚠️ voltage divider required if sensor outputs 5V)

- **Mode Selector (Digital Inputs):**
  - Mode Bit 0: `D1` (GPIO5)
  - Mode Bit 1: `D2` (GPIO4)

## Outputs
- **Pump Motor Control (PWM/Digital Output):**
  - Pin: `D5` (GPIO14)

- **Emergency LED (Optional):**
  - Pin: `D6` (GPIO12)

## Notes
- Ensure **boot-related pins** (`D3`, `D4`, `D8`) are not pulled LOW at boot time.
- All ground lines must be connected to `GND`.

> Note: No hardware is implemented yet. This is a placeholder for future expansion.
