# 📖 Nova Language: Syntax & Grammar Reference

Nova uses a highly readable, indentation-based syntax (similar to Python). It removes the clutter of semicolons and brackets to let you focus on the hardware logic.

## 1. Program Structure
Every Nova program is strictly divided into two sections. You can also import modular files.

```text
Setup:
    Import "motor.nv"
    // Configurations, Pins, and Libraries go here
Logic:
    // Variables, Functions, Data Structures, and Loops go here
```

## 2. Setup Commands
| Action | Syntax | Example |
| :--- | :--- | :--- |
| **Set MCU Target** | `Target: [MCU]` | `Target: ESP32` |
| **Define Pins** | `Pin [Number] as [Name]` | `Pin 5 as Relay` |
| **Include Library** | `Include "[Header]"` | `Include "WiFi.h"` |
| **Smart Components**| `Use Component: [Name]` | `Use Component: mqtt` |

## 3. Variables & Data Structures
Variables are dynamically placed in the global C++ scope by the transpiler.

```text
Logic:
    Number Temperature = 25.5
    String Password = "admin"
    Array SensorData = [10, 20, 30, 40]
    Dictionary Config = { "ip": "192", "port": 80 }
```

## 4. Hardware I/O & Logic Control
| Action | Nova Syntax |
| :--- | :--- |
| **Digital Write** | `[PinName] status = On` (or `Off`, `High`, `Low`) |
| **Analog Write (PWM)**| `[PinName] pwm = 255` |
| **Digital Read** | `Read [PinName] into [Variable]` |
| **Analog Read** | `ReadAnalog [PinName] into [Variable]` |
| **Delay/Wait** | `Wait 1000 ms` (Translates to non-blocking `vTaskDelay`) |
| **Serial Print** | `Print "Hello World"` or `Print Temperature` |

## 5. Loops, Conditionals & Error Handling

```text
Logic:
    Number Count = 0

    // Infinite Multi-core Task
    Always:
        Try:
            If Count < 5:
                Print "System Running"
                Count = Count + 1
            Else:
                Print "System Halted"
                Wait 5000 ms
            
            // Finite Loop
            Repeat 3 times:
                Relay status = On
                Wait 1000 ms
                Relay status = Off
        Catch:
            Print "Error detected!"
```

## 6. Advanced: Raw C++ Execution
Need to use an external library function? Inject raw C++ natively.

```text
Setup:
    Include "WebServer.h"
Logic:
    Execute: WebServer server(80)

    Forever:
        Execute: server.handleClient()
```
