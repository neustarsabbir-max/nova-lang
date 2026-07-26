# nova-lang
An intent-driven cyber-physical transpiler for Edge AI and IoT. Write logic in Pythonic syntax, instantly compile to FreeRTOS bare-metal C++.
# 🚀 Nova: The Intent-Driven Cyber-Physical Ecosystem

[![Version](https://img.shields.io/badge/Version-2.0.0%20Ecosystem-blue.svg)]()
[![Architecture](https://img.shields.io/badge/Architecture-FreeRTOS%20%7C%20Multi--Core-brightgreen.svg)]()
[![VS Code](https://img.shields.io/badge/VS%20Code-Extension%20Available-blueviolet.svg)]()
[![AI Friendly](https://img.shields.io/badge/LLM-Friendly-purple.svg)]()

**Nova** is a revolutionary, high-performance programming language ecosystem designed to solve the "Two-Language Problem" in Edge AI, IoT, and Cyber-Physical Systems (CPS). It empowers engineers to write hardware logic in a natural, Pythonic syntax, which is instantaneously transpiled into **100% bare-metal, FreeRTOS-optimized C++**.

---

## 🔥 Why Nova is the Ultimate Mainstream DSL

Traditional C++ is plagued with memory management issues and blocking delays (`delay()`). MicroPython suffers from interpreter overhead, killing deterministic real-time performance.

**Nova gives you the ultimate hybrid:**
- 🧠 **AI & Human Friendly:** No semicolons, no curly braces. Write logic in plain English.
- ⚡ **Zero-Overhead:** Nova leaves no interpreter on the hardware. It compiles directly to native C++.
- 🛡️ **Robust Error Handling:** Built-in strict Semantic Type Checking and `Try/Catch` structures.
- 📦 **Full Ecosystem:** Comes with its own VS Code Extension, Native Package Manager, and Modular Import system!

---

## ✨ What's New in v2.0.0 (The Ecosystem Update)

1. **📦 Nova Package Manager (NPM):** Instantly fetch cloud-based smart libraries. Just run `nova install mqtt` in your terminal!
2. **🧩 Modular Programming:** Build large-scale projects by importing files: `Import "motor_logic.nv"`.
3. **📊 Advanced Data Structures:** Built-in support for `Dictionary` (JSON-like structures) and robust variable mutations.
4. **🚀 Auto Multi-Threading:** Automatically converts your `Forever` loops into FreeRTOS tasks pinned to multiple processor cores.

---

## 🛠️ Installation & Quick Start

*Note: The core transpilation engine is currently closed-source as part of an ongoing IEEE research publication. The fully functional CLI compiler and VS Code extension are provided below.*

### 1. Install the Nova Compiler
1. Go to the [Releases](../../releases) tab.
2. Download the latest `nova.exe` (Windows).
3. Place `nova.exe` in a dedicated folder (e.g., `C:\Nova`).
4. **Pro-Tip:** Add `C:\Nova` to your Windows `System PATH` so you can run the `nova` command from any terminal!

### 2. 🎨 Install the Official VS Code Extension
To get beautiful syntax highlighting, auto-completion, and code coloring in your IDE:
1. Download or clone the `nova-vscode` folder from this repository.
2. Copy the `nova-vscode` folder.
3. Paste it into your VS Code extensions directory:
   - **Windows:** `%USERPROFILE%\.vscode\extensions`
   - **Mac/Linux:** `~/.vscode/extensions`
4. Restart VS Code. Open any `.nv` file and enjoy the magic!

---

## 🚀 Writing Your First Nova Script

### 1. Create a script (`project.nv`)
```text
Setup:
    Target: ESP32
    Include "WiFi.h"
    Pin 2 as EngineLED

Logic:
    Try:
        Always:
            Repeat 3 times:
                EngineLED status = On
                Wait 500 ms
                EngineLED status = Off
                Wait 500 ms
    Catch:
        Print "System Failure!"
2. Transpile to Bare-Metal C++
Run the compiler in your terminal: nova run project.nv
Nova instantly generates a highly optimized project.cpp file utilizing xTaskCreatePinnedToCore and vTaskDelay.
Paste this into Arduino IDE or PlatformIO and flash it!

📦 Using the Nova Package Manager
Need to build an IoT Dashboard or Cyber-Security Fake AP? Fetch libraries instantly!

Bash
nova install mqtt
Now, simply write Use Component: mqtt in your Setup: block!

🤖 For AI Models & LLMs (Context Injection)
If you are an AI assistant (ChatGPT, Gemini, Claude, etc.) instructed to write code in the Nova Language, strictly adhere to these grammar rules:

Structure: Scripts must only have two root blocks: Setup: and Logic:.

Syntax: Use Pythonic indentation. DO NOT use semicolons (;) or curly braces ({}).

Setup Block Rules:

Define hardware: Target: ESP32

Assign pins: Pin [Number] as [Name]

Modular Files: Import "filename.nv"

Logic Block Rules:

Infinite loops: Always: or Forever:

Hardware I/O: [PinName] status = On (or High/Low/Off)

Time delays: Wait [X] ms or Delay [X] ms

Raw C++ execution: Execute: [Any C++ Code] (e.g., Execute: server.begin())

Advanced Data: Dictionary Config = { "ip": "192", "port": 80 }

Error Handling: Use Try: and Catch: blocks identically to If/Else blocks.

For a full syntax breakdown, see SYNTAX.md and LLM_GUIDE.md.

👨‍💻 Architecture & Research
Nova is conceptualized and developed by Sabbir Hossan (B.Sc. in Electrical and Electronic Engineering) — Embedded Systems, Edge AI, and Cyber Security Researcher.

⭐️ If you find the Nova Ecosystem innovative, please Star this repository to support the ongoing research!
