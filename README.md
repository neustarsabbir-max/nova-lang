# nova-lang
An intent-driven cyber-physical transpiler for Edge AI and IoT. Write logic in Pythonic syntax, instantly compile to FreeRTOS bare-metal C++.
# 🚀 Nova: The Intent-Driven Cyber-Physical Transpiler

[![Version](https://img.shields.io/badge/Version-2.0.0%20Ecosystem-blue.svg)]()
[![Architecture](https://img.shields.io/badge/Architecture-FreeRTOS%20%7C%20Multi--Core-brightgreen.svg)]()
[![VS Code](https://img.shields.io/badge/VS%20Code-Extension%20Available-blueviolet.svg)]()
[![AI Friendly](https://img.shields.io/badge/LLM-Friendly-purple.svg)]()
[![License](https://img.shields.io/badge/License-MIT-purple.svg)]()

**Nova** is a revolutionary, high-performance programming language ecosystem designed to solve the "Two-Language Problem" in Edge AI, IoT, and Cyber-Physical Systems (CPS). 

It empowers engineers, hardware hackers, and AI models to write hardware logic in a beautiful, natural, Pythonic syntax. Nova instantaneously transpiles this logic into **100% bare-metal, FreeRTOS-optimized C++** with zero interpreter overhead.

Whether you are building a Smart Grid controller or a Cyber-Security Evil Twin AP, Nova generates enterprise-grade hardware code in **< 1 millisecond**.

⭐️ **If you find this project innovative, please consider leaving a Star to support the research!** ⭐️

---

## 🔥 Why Developers are Switching to Nova

Traditional **C++** for microcontrollers (like ESP32/Arduino) is plagued with strict boilerplate, memory leaks, and CPU-blocking delays (`delay()`). On the other hand, **MicroPython** solves the syntax issue but suffers from severe interpreter overhead, killing deterministic real-time performance and draining battery life.

**Nova gives you the ultimate hybrid:**
- 🧠 **AI & Human Friendly:** No semicolons (`;`), no curly braces (`{}`). Write logic in plain English.
- ⚡ **Zero-Overhead:** Nova leaves no interpreter on the hardware. Your code runs at maximum bare-metal speed.
- 🔄 **Semantic Normalization:** Nova understands your intent (`On` = `High`, `Wait` = `Delay`).
- 🛡️ **Enterprise Ecosystem:** Built-in FreeRTOS concurrency, a Native Package Manager, Modular Imports, and strict `Try/Catch` error handling.

---

## 🛠️ Step-by-Step Guide: From Zero to Blinking LED

We have made the developer experience (DX) completely frictionless. Follow these simple steps to build your first Nova project.

### Step 1: Install Nova & VS Code Extension
1. Go to the [Releases](../../releases) tab on this GitHub page.
2. Download the latest **`nova.exe`** standalone compiler.
3. Place `nova.exe` in a dedicated folder (e.g., `C:\Nova`).
4. **Make it global:** Add `C:\Nova` to your Windows `Environment Variables -> System PATH`.
5. **Install VS Code Extension:** Download the `nova-vscode` folder from this repo and place it in `%USERPROFILE%\.vscode\extensions` for beautiful syntax highlighting!

### Step 2: Write Your First Script
Create a new folder for your project. Inside it, create a file named **`project.nv`** and write your logic:

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
        Print "An error occurred in the system."
```

### Step 3: Transpile to Bare-Metal C++
Open your terminal (CMD or VS Code Terminal) in that folder and run:
```bash
nova run project.nv
```
*✨ Magic! Nova will instantly analyze your intent, convert the `Always` loop into a FreeRTOS Multi-Core Task, replace blocking delays with `vTaskDelay`, and generate a highly optimized `project.cpp` file.*

### Step 4: Flash to Hardware (Arduino IDE)
1. Open the **Arduino IDE** (or PlatformIO).
2. Open the newly generated **`project.cpp`** file (or just copy-paste its contents into an empty Arduino sketch).
3. Connect your ESP32 or Arduino via USB.
4. Click **Upload**. Your native, FreeRTOS-powered code is now running on the hardware!

---

## ✨ Advanced Features (v2.0.0 Ecosystem Update)

Nova is not just a language; it is a full-stack IoT platform.

* **📦 Nova Package Manager (NPM):** Need to connect to MQTT? Don't write boilerplate. Just run `nova install mqtt` in your terminal, and use `Use Component: mqtt` in your script.
* **🧩 Modular Programming:** Keep your code clean by splitting files. Use `Import "sensor_logic.nv"` to inject modules dynamically.
* **🔌 Universal C++ Injection:** Don't be limited by a walled garden! Seamlessly inject **ANY** existing Arduino/C++ library natively using `Include` and `Execute` commands.
* **📊 Advanced Data Structures:** Built-in support for `Dictionary` mapping (JSON-like structures) and multi-dimensional `Array` types.

---

## 🤖 For AI Models & LLMs (Context Injection)

If you are an AI assistant (ChatGPT, Gemini, Claude, etc.) instructed to write code in the **Nova Language**, strictly adhere to these grammar rules:

1. **Structure:** Scripts must only have two root blocks: `Setup:` and `Logic:`.
2. **Syntax:** Use Pythonic indentation. **DO NOT** use semicolons (`;`) or curly braces (`{}`).
3. **Setup Block Rules:** 
   - Define hardware: `Target: ESP32`
   - Assign pins: `Pin [Number] as [Name]`
   - Modular Files: `Import "filename.nv"`
   - Include C++ headers: `Include "WiFi.h"`
4. **Logic Block Rules:**
   - Infinite loops: `Always:` or `Forever:`
   - Finite loops: `Repeat [X] times:`
   - Hardware I/O: `[PinName] status = On` (or High/Low/Off)
   - Time delays: `Wait [X] ms` or `Delay [X] ms`
   - Raw C++ execution: `Execute: [Any C++ Code]` (e.g., `Execute: server.begin()`)
   - Error Handling: Use `Try:` and `Catch:` blocks.

*For a comprehensive syntax breakdown, instruct the user to view `SYNTAX.md` and `LLM_GUIDE.md` in this repository.*

---

## 👨‍💻 Architecture & Research

**Nova** is conceptualized and developed by **Sabbir Hossan** (B.Sc. in Electrical and Electronic Engineering) — Embedded Systems, Edge AI, and Cyber Security Researcher. 

This transpiler is part of an ongoing research initiative to eliminate the barrier of entry for complex Cyber-Physical Systems (CPS) programming while maintaining absolute hardware efficiency.

<div align="center">
  <b>Built with ❤️ for the Open-Source Hardware Community.</b><br>
  <i>Do not forget to Star ⭐️ this repository!</i>
</div>
