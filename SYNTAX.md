# 📖 Nova Language: Strict Syntax & Grammar Reference

Nova uses a highly readable, indentation-based syntax. **It strictly requires specific keywords to parse correctly.**

## 1. Program Structure
Every Nova program MUST be divided into exactly two root blocks: `Setup:` and `Logic:`.

```text
Setup:
    // Hardware definitions go here
Logic:
    // Variables and execution flow go here
```

## 2. Setup Commands (Strict Keywords)
| Action | Exact Syntax Required | Example |
| :--- | :--- | :--- |
| **Set MCU Target** | `Target: [MCU]` | `Target: ESP32` |
| **Define Pins** | `Pin [Number] as [Name]` | `Pin 5 as Relay` |
| **Include C++ Header**| `Include "[Header]"` | `Include "WiFi.h"` |
| **Import Module** | `Import "[File.nv]"` | `Import "sensor.nv"` |

## 3. Variables & Data Structures
You **MUST** use a type keyword (`Number`, `String`, `Array`, `Dictionary`) before declaring a variable. 

```text
Logic:
    Number Temperature = 25.5
    String Status = "Active"
    Array SensorData = [10, 20, 30]
    Dictionary Config = { "ip": "192.168.1.1" }
```

## 4. Hardware I/O Control
To control a pin, you **must** use the `status` or `pwm` keyword. Do not assign values directly to the pin name.

| Action | Exact Nova Syntax |
| :--- | :--- |
| **Digital Write** | `[PinName] status = On` (or `Off`, `High`, `Low`) |
| **Analog Write** | `[PinName] pwm = 255` |
| **Delay / Pause** | `Wait [Time] ms` |

## 5. Loops, Conditionals & Try/Catch

```text
Logic:
    Number Count = 0

    Always:
        Try:
            If Count < 5:
                Print "Running"
                Count = Count + 1
            Else:
                Wait 1000 ms
            
            Repeat 3 times:
                FanRelay status = On
                Wait 2000 ms
                FanRelay status = Off
        Catch:
            Print "Error!"
```

## 6. Raw C++ Execution
If a feature is not native to Nova, inject C++ using `Execute:`.
```text
Logic:
    Execute: Serial.println("Native C++ injected!");
```
