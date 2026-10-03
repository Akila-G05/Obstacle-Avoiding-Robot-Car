# Obstacle-Avoiding Robot Car

An Arduino-based robotic car that detects and avoids obstacles. An HC-SR04 ultrasonic
sensor is mounted on a servo that sweeps left and right, and the car steers away from
anything detected within 20 cm. Movement is driven by commands received over a serial
connection (Bluetooth module or USB).

## Features

- **Obstacle detection** using an HC-SR04 ultrasonic sensor with a 20 cm threshold
- **Scanning servo** — the sensor sweeps from centre (90°) to 45° and 135° to scan both
  sides before turning
- **Five movement commands** over serial at 9600 baud:
  | Command | Action |
  |---|---|
  | `1` | Forward (continues only while the path ahead is clear) |
  | `2` | Backward |
  | `3` | Stop |
  | `4` | Turn right (only if an obstacle is detected) |
  | `5` | Turn left (only if an obstacle is detected) |
- **Motor speed control** via PWM on the L298N driver enable pins
- **Serial debugging** output at 9600 baud

## Project Structure

```
sketch_jul11a/
└── sketch_jul11a.ino   # Complete sketch — setup(), loop(), motor and sensor logic
```

## Hardware

| Component | Arduino pins | Notes |
|---|---|---|
| HC-SR04 ultrasonic sensor | 12 (Trig), 13 (Echo) | Uses the `Ultrasonic` library |
| Servo motor | 3 | Sensor mount, sweeps 45°–135° |
| L298N motor driver — ENA | 11 | Left motor enable (PWM) |
| L298N — IN1 / IN2 | 10 / 9 | Left motor direction |
| L298N — ENB | 5 | Right motor enable (PWM) |
| L298N — IN3 / IN4 | 7 / 6 | Right motor direction |
| DC motors | Via L298N outputs | Chassis drive |
| Bluetooth / USB | Serial (RX) | Sends movement commands |

Motor speed is set with `analogWrite(ENA, 250)` and `analogWrite(ENB, 250)` in `setup()`.

## Technologies

| Technology | Purpose |
|---|---|
| Arduino (C/C++) | Platform |
| `Servo` library | Servo control for the sensor mount |
| `Ultrasonic` library | HC-SR04 distance measurement |
| L298N | Dual H-bridge DC motor driver |
| HC-SR04 | Ultrasonic distance sensor |
| Serial / Bluetooth | Remote command input |

## Getting Started

### Prerequisites

- Arduino IDE
- Arduino Uno (or compatible board)
- L298N motor driver, HC-SR04 sensor, a servo, DC motors, and a Bluetooth module

### Wiring

1. Wire the components to the pins listed in the Hardware table above.
2. Connect the L298N module's 12V input to the motor supply and its 5V output to the
   Arduino 5V pin.
3. Install the `Servo` library (bundled with the IDE) and the `Ultrasonic` library
   (Library Manager → search "Ultrasonic" by Inventar).

### Upload & Run

1. Open `sketch_jul11a.ino` in the Arduino IDE.
2. Select your board and port.
3. Upload the sketch.
4. Open the Serial Monitor at **9600 baud** and send `1`–`5` to drive the car.

> **Note:** pin 8 is used for motor control in the sketch but is not declared as a named
> constant like the other pins. Verify your wiring matches the actual pin numbers used
> in `loop()` before running.
## License

MIT � see [LICENSE](LICENSE).
