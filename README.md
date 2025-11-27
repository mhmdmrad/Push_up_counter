
# **Push-Up Counter – Connection & Setup Guide**

## **Required Components**
- **Arduino UNO**  
- **Ultrasonic Distance Sensor (HC-SR04)**  
- **4-Digit LED Display Tube (TM1637)**  
- **Passive Buzzer**  
- **Jumper Wires**  

## **Connection Instructions**
**Important:** Ensure the correct wiring order. Incorrect connections may cause all dots on the TM1637 display to light up or even damage the display.  

### **Wiring Guide**
| **Component**  | **Arduino UNO Pin** |
|---------------|------------------|
| **HC-SR04 Trig** | D9 |
| **HC-SR04 Echo** | D8 |
| **TM1637 CLK** | D4 |
| **TM1637 DIO** | D5 |
| **Buzzer (+)** | D3 |
| **Buzzer (-)** | GND |

## **Software Setup**
### 1️**Install Required Libraries**
1. Open **Arduino IDE**
2. Go to **Sketch** → **Include Library** → **Manage Libraries**
3. Search for **TM1637**
4. Install the TM1637 library

### 2️ **Download & Upload Code**
- Get the source code from GitHub: [Push-Up Counter Code](https://github.com/DKARDU/fitness-with-arduino)
- Open the code in **Arduino IDE**
- Select the correct **Board**: **Arduino/Genuino Uno**
- Select the correct **Port**
- Upload the code to your Arduino

Now your push-up counter should be ready to use! 
