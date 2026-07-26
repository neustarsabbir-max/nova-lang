# nova-lang
An intent-driven cyber-physical transpiler for Edge AI and IoT. Write logic in Pythonic syntax, instantly compile to FreeRTOS bare-metal C++.
# Nova Programming Language

[![Version](https://img.shields.io/badge/Version-2.0.0-blue.svg)]()
[![Architecture](https://img.shields.io/badge/Architecture-FreeRTOS%20%7C%20Multi--Core-brightgreen.svg)]()
[![VS Code](https://img.shields.io/badge/VS%20Code-Extension%20Available-blueviolet.svg)]()
[![License](https://img.shields.io/badge/License-MIT-purple.svg)]()

Nova is an intent-driven, domain-specific programming language and transpiler built for Edge AI, Cyber-Physical Systems (CPS), and IoT development. 

It provides an indentation-based, Pythonic syntax that compiles directly into bare-metal, FreeRTOS-optimized C++. Nova is designed to bridge the gap between high-level logic design and low-level hardware execution, maintaining deterministic real-time performance without the overhead of an interpreter.

⭐ **Support the Project:** If you find this architecture useful or see its potential in solving embedded development bottlenecks, please consider leaving a **Star** on this repository to support the ongoing research.

---

## 🎯 The Problem Nova Solves (Why Switch?)

### 1. The MicroPython Performance Bottleneck
While MicroPython provides an easy syntax for microcontrollers, its background garbage collector and runtime interpreter consume excessive RAM and CPU cycles, making it unsuitable for strict real-time, low-latency applications. 
* **The Nova Solution:** Nova is not an interpreter. It acts as an Ahead-of-Time (AOT) transpiler. You write in a Python-like syntax, but the hardware runs pure, optimized C++ at 100% bare-metal speed.

### 2. Eliminating Dual-Device Synchronization
In traditional IoT architectures, complex logic (Python) runs on a server/Raspberry Pi, while hardware control (C++) runs on an ESP32/Arduino. Engineers waste hours writing MQTT/Serial protocols just to sync them.
* **The Nova Solution:** Write high-level logic directly in `.nv` files. Nova compiles it into native MCU C++, allowing you to run complex algorithms and real-time hardware execution on a single microcontroller.

### 3. Seamless Arduino Ecosystem Integration
Unlike other custom DSLs, Nova does not lock you into a restricted environment. It natively supports the **Arduino Library Manager**. Standard C++ libraries (`WiFi.h`, `PubSubClient.h`, `Adafruit_GFX.h`) can be included and utilized directly without any wrappers.

---

## ⚙️ Core Architectural Features

- **Semantic Normalization:** An intuitive syntax that maps human intent directly to hardware states (e.g., handling `On/Off` as `HIGH/LOW`).
- **Automated FreeRTOS Task Scheduling:** Automatically parses concurrent loops (e.g., `Always:`) into FreeRTOS tasks pinned to multiple MCU cores (Core 0 & Core 1 on ESP32).
- **Non-Blocking Temporal Logic:** Replaces standard CPU-blocking `delay()` calls with RTOS-aware `vTaskDelay`, optimizing CPU idle time and battery life.
- **Robust Error Handling:** Features semantic type checking, modular file imports (`Import "module.nv"`), and native `Try/Catch` blocks.
- **Developer Ecosystem:** Ships with a native CLI package manager (`nova install`) and an official Visual Studio Code extension.

---

## 🛠️ Installation & Setup

### 1. The CLI Transpiler (Windows)
1. Navigate to the [Releases](../../releases) section of this repository.
2. Download the standalone `nova.exe` compiler binary.
3. Move `nova.exe` to a dedicated directory (e.g., `C:\Nova`).
4. Add `C:\Nova` to your system's `PATH` environment variable to access the `nova` command globally.

### 2. VS Code Extension
For syntax highlighting and auto-completion:
1. Clone or download the `nova-vscode` directory from this repository.
2. Copy the directory into your VS Code extensions path:
   - **Windows:** `%USERPROFILE%\.vscode\extensions`
   - **Mac/Linux:** `~/.vscode/extensions`
3. Restart Visual Studio Code.

---

## 🚀 Quick Start Guide

### 1. Writing Source Code
Create a file named `project.nv`:

```text
Setup:
    Target: ESP32
    Pin 2 as StatusLED

Logic:
    Try:
        Always:
            Repeat 3 times:
                StatusLED status = On
                Wait 500 ms
                StatusLED status = Off
                Wait 500 ms
            
            Print "Routine executed."
            Wait 2000 ms
    Catch:
        Print "Execution error encountered."
```

### 2. Compilation
Execute the transpiler via the terminal:

```bash
nova run project.nv
```

**Under the hood:** The compiler parses the syntax, resolves task scheduling, replaces delays, and generates an optimized `project.cpp` file in the same directory.

### 3. Hardware Deployment
1. Open the generated `project.cpp` file in the Arduino IDE or PlatformIO.
2. Select your target MCU (e.g., ESP32 or ESP8266).
3. Compile and flash the firmware to your board.

---

## 📂 Explore the Examples

To see the transpiler in action before installing, check out the **[`examples/`](examples/)** folder in this repository. It contains side-by-side comparisons of `.nv` source files and the highly optimized `.cpp` output generated by the Nova engine.

---

## 📦 Package Manager (NPM)

Nova includes a built-in package manager to fetch component configurations and libraries natively.

```bash
nova install mqtt
```
Once installed, simply declare `Use Component: mqtt` in your Nova script's `Setup:` block.

---

## 🤖 LLM Context Integration

For researchers or developers leveraging Large Language Models (LLMs) to generate Nova code, provide the models with these structural rules:

1. **Architecture:** Scripts are strictly divided into `Setup:` and `Logic:` blocks.
2. **Formatting:** Use Pythonic indentation. Do not output semicolons (`;`), `#include` directives, or curly braces (`{}`).
3. **Setup Directives:** Use `Target: [MCU]`, `Pin [Num] as [Name]`, `Import "[file.nv]"`, and `Include "[Header.h]"`.
4. **Logic Directives:** Use `Always:` for infinite loops, `Repeat [X] times:` for finite loops, `Wait [X] ms` for delays, and `Execute: [C++ Code]` for raw injections.
5. **Reference:** Point models to the `SYNTAX.md` and `LLM_GUIDE.md` documents for full grammar context.

---

## 👨‍💻 Author & Research Context

**Nova** is conceptualized and developed by **Sabbir Hossan** (B.Sc. in Electrical and Electronic Engineering). 

This project is part of an ongoing research initiative focused on embedded systems, Edge AI, and optimizing transpilation pipelines for Cyber-Physical Systems (CPS). 

**License:** MIT | **Contributions:** Pull requests and architectural suggestions are highly welcome!
