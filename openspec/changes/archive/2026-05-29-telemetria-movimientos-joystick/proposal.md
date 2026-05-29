## Why

Currently, when the crane is operated in joystick (manual) mode, the movement commands and state changes (trolley, hoist, and slew movements) are not logged or printed to the wireless debug serial port. This makes it impossible for developers/operators to monitor manual control events wirelessly on the ESP32 debug console.

## What Changes

- Implement state tracking for physical joystick movements (trolley, hoist, slew) in `grua_arduino.ino`.
- Send descriptive log messages to `debugSerial` (SoftwareSerial) whenever a joystick movement starts, stops, or changes direction.
- Prevent serial port flooding by using transition-based event logging rather than logging on every loop iteration.

## Capabilities

### New Capabilities

<!-- None -->

### Modified Capabilities

- `telemetry`: Update the telemetry requirements to specify that joystick control movements must also produce log events on the debug serial interface when states change.

## Impact

- `arduino/grua_arduino/grua_arduino.ino`: Modify `loop()` to track joystick state transitions and print them to `debugSerial`.
- `esp32/main.py`: No direct changes needed, but its log viewer will automatically display the new joystick movement logs.
