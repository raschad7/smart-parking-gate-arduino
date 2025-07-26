# Smart Car Parking System for Disabled People

A smart parking system that improves accessibility for disabled individuals using Arduino, sensors, and real-time feedback.

## 🎯 Objective

Help disabled drivers easily find available parking using automated gate control, LCD status updates, and occupancy sensors.

## 🔧 Components Used

- Arduino Uno
- Ultrasonic Sensor (HC-SR04)
- IR Sensors
- Servo Motor
- 16x2 LCD (I2C)
- ATX Power Supply
- Breadboard & Jumper Wires

## 🧠 How It Works

- Ultrasonic sensor detects incoming cars.
- IR sensors detect if a spot is occupied.
- Servo motor controls the parking gate.
- LCD displays live updates (spots & count).

## 📹 Demo

🎥 [Watch the prototype video](https://drive.google.com/file/d/1BZ9NbHq0VGi8tyY4YZjTwrTcVlhivH_e/view?usp=sharing)

## 📄 Project Report

See [`/docs/report.pdf`](./docs/report.pdf) for system architecture, testing, and conclusions.

## 👨‍💻 Code

See [`/Arduino_Code/smart_parking.ino`](./Arduino_Code/smart_parking.ino)

---

### 🏁 To Upload

After organizing this folder:

```bash
cd car-parking-disabled
git init
git add .
git commit -m "Initial commit - Smart Car Parking System"
git remote add origin https://github.com/your-username/car-parking-disabled.git
git push -u origin main
```
