# nova-lang
An intent-driven cyber-physical transpiler for Edge AI and IoT. Write logic in Pythonic syntax, instantly compile to FreeRTOS bare-metal C++.
# 🚀 Nova: The Intent-Driven Cyber-Physical Transpiler

[![Version](https://img.shields.io/badge/Version-2.0.0%20Ecosystem-blue.svg)]()
[![Architecture](https://img.shields.io/badge/Architecture-FreeRTOS%20%7C%20Multi--Core-brightgreen.svg)]()
[![VS Code](https://img.shields.io/badge/VS%20Code-Extension%20Available-blueviolet.svg)]()
[![AI Friendly](https://img.shields.io/badge/LLM-Friendly-purple.svg)]()
[![License](https://img.shields.io/badge/License-MIT-purple.svg)]()

**Nova** is a revolutionary, high-performance programming language ecosystem designed to eliminate the **"Two-Language Problem"** and **"Multi-Device Synchronization Bottlenecks"** in Edge AI, Cyber-Physical Systems (CPS), and IoT development.

It allows developers, hardware hackers, and AI models to write high-level hardware logic in an intuitive, Pythonic syntax. Nova instantaneously transpiles this logic into **100% bare-metal, highly optimized, FreeRTOS-powered C++** in `< 1 millisecond`.

⭐️ **If you find this project innovative, please consider leaving a Star to support the research!** ⭐️

---

## 🎯 The Core Problem Nova Solves

### 1. Eliminates Dual-Device / Dual-Language Synchronization
In traditional IoT architectures, complex logic or data processing is written in **Python** (running on a PC or Raspberry Pi), while low-level hardware control is written in **C++** (running on an ESP32 or Arduino). Engineers are forced to write communication protocols (Serial, MQTT, WebSockets) to synchronize the two devices.
* **The Nova Solution:** Write your high-level Pythonic logic directly in `.nv` files. Nova compiles it straight into native MCU C++, running both your high-level logic and real-time hardware execution on a single microcontroller—**zero synchronization overhead!**

### 2. Full Compatibility with 100% of Arduino IDE Libraries
Unlike other custom languages or DSLs that lock you into a limited ecosystem, Nova gives you full access to the **Arduino Library Manager**. Any library available in the Arduino ecosystem (`WiFi.h`, `PubSubClient.h`, `Adafruit_GFX.h`, etc.) works natively out-of-the-box using simple `Include` and `Execute` statements.

### 3. High-Performance Optimized C++ Generation (No MicroPython Overhead)
MicroPython is easy to write, but its background garbage collector and interpreter consume massive RAM/CPU cycles, causing latency in real-time applications. Nova is **not an interpreter**. It generates ultra-clean, production-ready C++ with non-blocking FreeRTOS multi-threading, keeping your MCU running at **100% native bare-metal speed**.

---

## 🔥 Key Architectural Features

- 🧠 **AI & Human Friendly Syntax:** No semicolons (`;`), no curly braces (`{}`). Focus purely on logic.
- ⚡ **Zero-Interpreter Overhead:** Compiles directly to C++ source code before flashing.
- 🚀 **Automatic FreeRTOS Multi-Threading:** Automatically converts concurrent `Forever` loops into FreeRTOS tasks pinned to multiple MCU cores (Core 0 & Core 1 on ESP32).
- ⏳ **Non-Blocking Execution:** Replaces CPU-blocking `delay()` calls with RTOS-aware `vTaskDelay`, preserving battery and CPU cycles.
- 🛡️ **Robust Error Handling:** Features semantic type checking, modular imports (`Import "file.nv"`), and `Try/Catch` structures.
- 🎨 **Full Developer Ecosystem:** Comes with a native Package Manager (`nova install`) and an official VS Code Extension.

---

## 🛠️ Step-by-Step Guide: From Zero to Blinking LED

We have made the developer experience (DX) completely frictionless. Follow these simple steps:

### Step 1: Install Nova & VS Code Extension
1. Go to the [Releases](../../releases) tab on this GitHub repository.
2. Download the standalone **`nova.exe`** compiler binary.
3. Place `nova.exe` in a folder on your PC (e.g., `C:\Nova`).
4. **Make it global:** Add `C:\Nova` to your Windows `Environment Variables -> System PATH`.
5. **Install VS Code Extension:** Copy the `nova-vscode` folder from this repository into `%USERPROFILE%\.vscode\extensions` for full syntax highlighting and code coloring!

### Step 2: Write Your First Script (`project.nv`)
Create a project folder, open it in VS Code, create a file named **`project.nv`**, and write:

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
            
            Print "Cycle Complete!"
            Wait 2000 ms
    Catch:
        Print "An error occurred in execution."
```

### Step 3: Transpile to Optimized C++
Open your terminal in that directory and run:

```bash
nova run project.nv
```

*✨ Magic! Nova analyzes your code, injects FreeRTOS task handling, optimizes delays, and generates a clean `project.cpp` file.*

### Step 4: Flash to Hardware (Arduino IDE / PlatformIO)
1. Open the generated **`project.cpp`** file.
2. Paste the code into your **Arduino IDE** or **PlatformIO**.
3. Select your board (ESP32/Arduino) and click **Upload**.
4. Your native, multi-threaded C++ firmware is now running on the hardware!

---

## 📂 Explore the Examples

Want to see the magic before installing? Check out the **[`examples/`](examples/)** folder in this repository! 
Inside, you will find side-by-side comparisons of `.nv` logic files and the incredibly optimized `.cpp` files generated by the Nova engine.

---

## 📦 Using the Nova Package Manager (NPM)

Need to integrate cloud libraries or MQTT communication without writing C++ boilerplate?

```bash
nova install mqtt
```

Once fetched, simply declare `Use Component: mqtt` in your Nova script!

---

## 🤖 For AI Models & LLMs (Context Prompting)

If you are an AI language model (ChatGPT, Gemini, Claude, etc.) instructed to write code in the **Nova Language**, strictly follow these rules:

1. **Structure:** Nova scripts must contain two root blocks: `Setup:` and `Logic:`.
2. **Syntax Rules:** Use Pythonic indentation. **DO NOT** output semicolons (`;`), `#include`, or curly braces (`{}`).
3. **Setup Block:**
   - MCU Target: `Target: ESP32`
   - Pin Assignment: `Pin [Number] as [Name]`
   - Module Imports: `Import "filename.nv"`
   - Header Inclusions: `Include "Library.h"`
4. **Logic Block:**
   - Infinite Loops: `Always:` or `Forever:`
   - Finite Loops: `Repeat [X] times:`
   - State Control: `[PinName] status = On` (or High/Low/Off)
   - Non-blocking Delays: `Wait [X] ms` or `Delay [X] ms`
   - Native Injections: `Execute: [Raw C++ Code]`
   - Error Handling: Use `Try:` and `Catch:` blocks.

*For full language specifications, view `SYNTAX.md` and `LLM_GUIDE.md` in this repository.*

---

## 👨‍💻 Architecture & Research

**Nova** is conceptualized and developed by **Sabbir Hossan** (B.Sc. in Electrical and Electronic Engineering) — Embedded Systems, Edge AI, and Cyber Security Researcher.

This transpiler is part of an ongoing research initiative to eliminate real-time constraints and multi-language overhead in complex Cyber-Physical Systems (CPS).

<div align="center">
  <b>Built with ❤️ for the Open-Source Embedded & AI Community.</b><br>
  <i>Do not forget to Star ⭐️ this repository to support the project!</i>
</div>
