# 🔒 Passcode-Based Security System Using STM32F4xx

This project implements a **passcode-based security system** using the STM32F4xx microcontroller. The system allows users to enter a 4-digit passcode using a 4x4 matrix keypad, verify it against a stored passcode, and provides feedback on an LCD screen. The system also includes an LED indicator for access status.

---

## ✨ Features
- 🎛️ **4x4 Keypad Input:** Users can enter a 4-digit passcode using a keypad.
- 📟 **LCD Display:** Displays messages like "Enter Password," "Access Granted," "Access Denied," or "Blocked."
- 💡 **LED Indicator:** An LED turns on upon successful passcode verification.
- 🔄 **Retry Limit:** Blocks user access after three failed attempts.
- ⚙️ **Embedded Programming:** Direct register-level programming for STM32F4xx microcontroller.

---

## 🛠️ Hardware Components
1. 🖥️ **STM32F4xx Microcontroller Board**
2. 📟 **16x2 LCD Display**
3. 🎛️ **4x4 Keypad**
4. 💡 **LED** (for access indication)
5. 🔧 **Resistors** (for pull-up configuration)
6. 🔌 **Connecting Wires**
7. ⚡ **Power Supply**

---

## 🔗 Circuit Diagram
- **LCD:** Connected to GPIOA (D0-D7 for data) and GPIOB (RS, RW, EN for control).
- **Keypad:** Rows connected to GPIOC (PC3-PC6 as output), Columns connected to GPIOC (PC0-PC2 as input).
- **LED:** Connected to GPIOB pin PB3.

---

## 💻 Software Features
- 📟 **LCD Initialization and Communication:** Controlled via GPIOA and GPIOB.
- 🎛️ **Keypad Scanning:** 4x4 matrix is scanned row by row to detect keypresses.
- 🔑 **Password Verification:** Compares user input with a pre-stored passcode.


---

## 🚀 How It Works
1. **Power On:**  
   - ⚡ The system initializes the LCD and displays `Enter Password`.
2. **User Input:**  
   - 🎛️ The user enters a 4-digit passcode via the keypad.  
   - Each keypress is displayed as an asterisk (`*`) on the LCD.
3. **Verification:**  
   - 🔓 If the entered passcode matches the pre-stored passcode, the LCD displays `Access Granted`, and the LED turns on.  
   - ❌ If incorrect, the LCD displays `Access Denied`, and the user can try again.
4. **Retry Limit:**  
   - ⛔ After 3 incorrect attempts, the system displays `Blocked` for 5 seconds before allowing another attempt.

---

## 📝 Pin Configuration
| 🛠️ Component    | 🔌 Pin Configuration                          |
|------------------|----------------------------------------------|
| **LCD**          | PA0-PA7 (D0-D7), PB0 (RS), PB1 (RW), PB2 (EN) |
| **Keypad**       | PC0-PC3 (Columns), PC4-PC6 (Rows)            |
| **LED**          | PC15                                          |

---

## ⚙️ How to Run
1. 🔧 Connect the components as per the circuit diagram.
2. 💾 Flash the code onto the STM32F4xx microcontroller using an IDE  **Keil uVision**.
3. 🔌 Power on the system.
4. 🎛️ Interact with the system via the keypad and observe the results on the LCD and LED.

---

## 🧰 Requirements
### 🛠️ Hardware:
- 🖥️ STM32F4xx Development Board
- 📟 16x2 LCD Display
- 🎛️ 4x4 Keypad
- 💡 LED
- ⚡ Power Supply (5V)

### 🖥️ Software:
- **Keil uVision**
- STM32 HAL Library (optional, if not using register-level code)
- USB Programmer (e.g., ST-Link V2)

---

## 🌟 Future Enhancements
- 🔧 **Changeable Passcode:** Add functionality for users to change the stored passcode.
- 🔔 **Buzzer Alert:** Integrate a buzzer to signal failed attempts or block events.
- 📜 **Security Logs:** Add external memory to store logs of access attempts.
- 🌐 **IoT Integration:** Connect the system to a network to allow remote monitoring and unlocking.


