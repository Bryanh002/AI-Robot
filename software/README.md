# Software

Software for ERGOS is the stack that will run **on the robot** and the tools used to **train models for it**. That work is still early. This folder currently holds ESP32 bus bring-up sketches only.

ROS 2 packages, Isaac assets, and training code will land here (or be linked from here) as Phase 2–3 start. Until then, treat this page as the intended architecture.

## Intended stack

| Layer | Where it runs | Tools |
| :--- | :--- | :--- |
| Policy training | Workstation / lab GPU | **NVIDIA Isaac Sim**, **Isaac Lab**, **PyTorch** |
| Onboard autonomy | Jetson Orin Nano | **ROS 2**, JetPack, Python / C++ |
| Real-time actuation | ESP32-S3 on the motherboard | C/C++ (Arduino today) |
| Perception | Jetson + OAK-D Lite | DepthAI / ROS 2 camera pipeline *(planned)* |

Flow, once it exists:

1. Train locomotion policies in Isaac Sim / Isaac Lab with PyTorch.
2. Run the policy on the Jetson inside ROS 2 (state in, joint commands out).
3. The Jetson streams commands to the ESP32 over USB/UART and powers the PCB logic rail on that same USB link.
4. The ESP32 is the Feetech STS bus master (two 1 Mbps half-duplex buses) and reads the BMI323 IMU and foot FSRs.

The root README's development plan is the schedule: hardware and MCU bring-up first, then ROS 2, then simulation/RL, then sim-to-real walking.

## ServoSim (separate project)

ERGOS is also the **hardware test platform** for [ServoSim](https://github.com/Bryanh002/ServoSim).

ServoSim is not a substitute for the ERGOS software stack. It is an Isaac Lab extension for learned actuator models and domain randomization on position-controlled serial-bus servos (the same Feetech STS class used here). The research is aimed at getting the best locomotion performance on ERGOS given its limited DOF and actuator class.

- ERGOS software (this repo): robot firmware, ROS 2, the ERGOS sim/control bring-up
- [ServoSim](https://github.com/Bryanh002/ServoSim): servo modeling / DR research that uses ERGOS as the real-world target

## What's in this folder today

```
software/src/Arduino/Examples/
  Full-to-Half_Duplex_Test/   direction-pin toggle on the UART transceiver
  STS_Servo_Ping/             ping / write-position smoke test
  STS_Servo_WritePos/         read position, command two setpoints
```

These sketches talk to a single STS servo on `Serial1` at **1 Mbps**, using **[ERGOS_FTServo_Arduino](https://github.com/Bryanh002/ERGOS_FTServo_Arduino)** — a project-specific Feetech STS library, not the stock `SCServo` package.

| Signal | GPIO (current examples) |
| :--- | :--- |
| UART TX / RX | 12 / 11 (`Serial1`) |
| Bus direction | 4 (HIGH = transmit, LOW = receive) |
| LED | 8 |
| Debug USB serial | 115200 baud |

They match the motherboard's half-duplex direction control. They are not a multi-bus controller, not ROS 2, and not safe to run as a standing robot.

## Planned in this repo (not written yet)

- Production ESP32 firmware: dual bus, ID map, feedback at control rate
- ROS 2 package(s) on the Jetson: MCU bridge, joint states, command interface
- URDF / Isaac description of ERGOS that tracks V1.4 CAD
- Launch files, calibration, and a first standing controller
- Training and deployment notes once the sim model is stable

## Related hardware docs

- [Electrical](../Electrical/README.md) — buses, IMU, FSRs, Jetson 18 V rail
- [Mechanical](../mechanical/README.md) — V1.4 CAD the sim model needs to match
- Servo datasheets: [`docs/Datasheets/`](../docs/Datasheets/)
