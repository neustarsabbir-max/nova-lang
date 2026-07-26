# nova-lang
An intent-driven cyber-physical transpiler for Edge AI and IoT. Write logic in Pythonic syntax, instantly compile to FreeRTOS bare-metal C++.
# Nova Programming Language

[![Version](https://img.shields.io/badge/Version-2.0.0-blue.svg)]()
[![Architecture](https://img.shields.io/badge/Architecture-FreeRTOS%20%7C%20Multi--Core-brightgreen.svg)]()
[![VS Code](https://img.shields.io/badge/VS%20Code-Extension%20Available-blueviolet.svg)]()
[![License](https://img.shields.io/badge/License-MIT-purple.svg)]()

Nova is an intent-driven, domain-specific programming language and transpiler built for Edge AI, Cyber-Physical Systems (CPS), and IoT development. 

It provides an indentation-based, Pythonic syntax that compiles directly into bare-metal, FreeRTOS-optimized C++. Nova is designed to bridge the gap between high-level logic design and low-level hardware execution, maintaining deterministic real-time performance without the overhead of an interpreter.

⭐ **Support the Project:** If you find this architecture useful, please consider leaving a **Star** on this repository to support the ongoing research.

---

## 🎯 The Problem Nova Solves (Why Switch?)

### 1. The MicroPython Performance Bottleneck
While MicroPython provides an easy syntax, its background garbage collector and runtime interpreter consume excessive RAM and CPU cycles. 
* **The Nova Solution:** Nova acts as an Ahead-of-Time (AOT) transpiler. You write in a Python-like syntax, but the hardware runs pure, optimized C++ at 100% bare-metal speed.

### 2. Formal Verification & Memory Safety Guarantee
C++ is notoriously prone to memory leaks and core panics (e.g., Division by Zero, Watchdog timeouts).
* **The Nova Solution:** The Nova transpiler enforces implicit memory safety. It utilizes `std::vector` to prevent buffer overflows and implements **Automated Watchdog Injection** (`vTaskDelay`) inside infinite loops to mathematically prevent real-time deadlocks and core crashes.

### 3. Eliminating Dual-Device Synchronization
Write high-level logic directly in `.nv` files. Nova compiles it into native MCU C++, allowing you to run complex algorithms and hardware execution on a single microcontroller without writing MQTT/Serial sync protocols.

### 4. Seamless Arduino Ecosystem Integration
Nova natively supports the **Arduino Library Manager**. Standard C++ libraries (`WiFi.h`, `PubSubClient.h`) can be included and utilized directly without any wrappers.

---

## ⚙️ Core Architectural Features

- **Semantic Normalization:** An intuitive syntax that maps human intent directly to hardware states (e.g., `On/Off` -> `HIGH/LOW`).
- **Automated FreeRTOS Task Scheduling:** Parses concurrent loops (e.g., `Always:`) into FreeRTOS tasks pinned to multiple MCU cores.
- **Robust Error Handling:** Features semantic type checking, modular imports (`Import "module.nv"`), and native `Try/Catch` blocks.

---

## 🤖 Generating Nova Code with AI (ChatGPT, DeepSeek, Claude)

You can use any LLM to generate complex Smart Home or Edge AI projects using Nova. 

**How to prompt an AI:**
Copy the URL of this repository and paste it into your AI prompt along with your components. 

**Example Prompt to paste in DeepSeek/ChatGPT:**
> *"Read the GitHub repo: [Insert your Repo URL here] and specifically analyze the SYNTAX.md and LLM_GUIDE.md files. I have an ESP32, a 5V Relay, and a 12V DC Fan. Write a complete Nova language script (.nv) to create a smart fan controller that turns on for 10 seconds and turns off for 5 seconds."*

The AI will automatically read the strict syntax rules and generate flawless, compilable Nova code!

---

## 🛠️ Installation & Setup

### 1. The CLI Transpiler (Windows)
1. Download the standalone `nova.exe` compiler binary from the [Releases](../../releases) tab.
2. Move `nova.exe` to a dedicated directory (e.g., `C:\Nova`).
3. Add `C:\Nova` to your system's `PATH` environment variable.

### 2. VS Code Extension
For syntax highlighting and auto-completion:
1. Copy the `nova-vscode` directory from this repository into `%USERPROFILE%\.vscode\extensions`.
2. Restart Visual Studio Code.

---

## 🚀 Quick Start Guide

### 1. Compilation
Create a `project.nv` file and execute the transpiler via the terminal:

```bash
nova run project.nv
```

**Under the hood:** The compiler parses the syntax, resolves task scheduling, injects Watchdog safeguards, and generates an optimized `project.cpp` file.

### 2. Hardware Deployment
1. Open the generated `project.cpp` file in the Arduino IDE or PlatformIO.
2. Select your target MCU and click upload.

---

## 👨‍💻 Author & Research Context
**Nova** is conceptualized and developed by **Sabbir Hossan** (B.Sc. in Electrical and Electronic Engineering).
