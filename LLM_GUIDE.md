# 🤖 System Prompt & Strict Rules for LLMs (DeepSeek, ChatGPT, Claude)

If you are an AI generating code for the **Nova Language**, you MUST adhere to the following strict parsing rules. The Nova transpiler uses a rigid AST (Abstract Syntax Tree), and hallucinating syntax will cause compilation errors.

## 🛑 STRICT ANTI-PATTERNS (DO NOT DO THIS)
1. **Never** write variables without types. (WRONG: `x = 5`. RIGHT: `Number x = 5`).
2. **Never** assign pin states directly. (WRONG: `Relay = On`. RIGHT: `Relay status = On`).
3. **Never** use brackets `{}`, parentheses `()` in `If` statements, or semicolons `;`. (WRONG: `If (x > 5) { }`. RIGHT: `If x > 5:`).
4. **Never** write generic `delay(1000)`. (WRONG: `delay(1000)`. RIGHT: `Wait 1000 ms`).
5. **Never** omit the `Setup:` and `Logic:` blocks.

## ✅ CORE DIRECTIVES
1. **Indentation matters:** Use 4 spaces for Pythonic indentation.
2. **Infinite Loops:** Must use `Always:` or `Forever:`.
3. **Finite Loops:** Must use `Repeat [X] times:`.
4. **C++ Injections:** Use `Execute: [Raw C++ code]` for complex library calls.

---

## 🎯 GROUND-TRUTH EXAMPLE (Smart Home Project)

**Scenario:** An ESP32 connected to a Relay on Pin 4 controlling a 12V DC Fan.

**Perfect AI Output:**

```text
Setup:
    Target: ESP32
    Pin 4 as FanRelay

Logic:
    Number CycleDelay = 5000

    Always:
        Try:
            Print "Turning on 12V Fan..."
            FanRelay status = On
            Wait 10000 ms
            
            Print "Turning off Fan for cooling..."
            FanRelay status = Off
            Wait CycleDelay ms
        Catch:
            Print "System Error in Relay Control"
```

**End of Directives.** Follow these rules strictly to ensure zero syntax errors in the Nova Transpiler.
