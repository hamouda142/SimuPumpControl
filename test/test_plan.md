# SimuPumpControl – Test Plan

## Purpose
To validate the correct behavior of the SimuPumpControl system under defined input scenarios.

## Tools Used
- Simulink Signal Editor
- Simulink Scope
- Stateflow animation
- Display blocks

## Test Inputs

| Time (s) | Mode | Pressure |
|----------|------|----------|
| 0        | 0    | 0.5      |
| 1        | 1    | 0.5      |
| 2        | 2    | 0.5      |
| 3        | 0    | 0.5      |
| 4        | 1    | 0.5      |
| 5        | 2    | 0.5      |
| 6        | 3    | 1.0      |
| 7        | 0    | 0.5      |

## Expected Output

| Time (s) | State        | pump_state |
|----------|--------------|------------|
| 0        | Idle         | 0          |
| 1        | Suction      | 1          |
| 2        | Flush        | 2          |
| 3        | Idle         | 0          |
| 4        | Suction      | 1          |
| 5        | Flush        | 2          |
| 6        | Emergency    | -1         |
| 7        | Idle         | 0          |

## Pass/Fail Criteria
- Stateflow animation transitions correctly
- `pump_state` matches expected values
- No simulation errors or undefined states
