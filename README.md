```
███████╗██████╗  ██████╗  ██████╗ ███████╗
██╔════╝██╔══██╗██╔════╝ ██╔═══██╗██╔════╝
█████╗  ██████╔╝██║  ███╗██║   ██║███████╗
██╔══╝  ██╔══██╗██║   ██║██║   ██║╚════██║
███████╗██║  ██║╚██████╔╝╚██████╔╝███████║
╚══════╝╚═╝  ╚═╝ ╚═════╝  ╚═════╝ ╚══════╝
```
### Embodied Reinforcement Gait Optimization System
---

<p align="center">
  <img src="https://github.com/Bryanh002/ERGOS-Dynamic-Humanoid-Platform/blob/main/docs/images/ERGOS-Rendered-images/ERGOS-Rendered-image-dark-transparent.png" width="2000"/>
  <br>
</p>

---

## Project Overview

ERGOS is a low-cost, open-source 20-DOF humanoid platform for dynamic locomotion research. It is a self-contained robot: 3D-printed structure, belt-driven Feetech STS serial servos, a custom motherboard, and a Jetson Orin Nano as the onboard computer.

The long-term goal is stable, adaptive bipedal gait on this hardware. High-level perception, planning, and learned policies run on the Jetson inside a ROS 2 control stack. Low-level servo timing and bus I/O run on an ESP32-S3. Simulation and training use NVIDIA Isaac Sim / Isaac Lab and PyTorch; trained policies are meant to transfer onto the physical robot.

---

## 🗺️ Repository Map

- **Hardware**
  - [`mechanical/`](mechanical/) — SolidWorks CAD (current: ERGOS V1.4), STEP exports, renders, walking tether
  - [`Electrical/`](Electrical/) — Altium motherboard project, schematics, PCB
- **Software**
  - [`software/`](software/) — ESP32 firmware examples now; ROS 2 packages, tools, and simulation wiring as they land
- **Docs**
  - [`docs/`](docs/) — architecture diagram, renders, datasheets, BOM

---

## ERGOS Features

### Mechanical System *(designed — V1.4)*
- Custom 20-DOF humanoid: legs, arms, neck/head, and torso packaging for battery, motherboard, and Jetson
- Belt-driven joints using HTD-3M pulleys (18T driving, 30T driven) for torque amplification at selected axes
- 3D-printed structural housings for low cost and fast iteration
- Modular joint layout so actuators and transmissions can be swapped without redesigning the whole robot
- Safety tether (4040 extrusion frame) for early walking tests

### Electronics & Power *(designed — testing)*
- Custom motherboard with an ESP32-S3 for real-time servo communication
- On-board full-duplex to half-duplex TTL path for two Feetech STS buses at 1 Mbps
- BMI323 IMU on the motherboard; two force-sensing resistors on each foot
- Power from a 3S 8400 mAh LiPo: eFuse-protected distribution to the servo harness, boost to 18 V for the Jetson
- Jetson Orin Nano as the primary compute module; USB from the Jetson powers the PCB logic (ESP32) and carries control
- OAK-D Lite depth camera in the head for later perception work

### Control & Locomotion *(planned)*
- ROS 2 control stack on the Jetson: policy inference, state estimation, and command streaming to the ESP32
- Reinforcement learning for walking, trained in simulation and transferred onto hardware
- Simulation and training in **NVIDIA Isaac Sim / Isaac Lab** with **PyTorch**
- [ServoSim](https://github.com/Bryanh002/ServoSim) research is aimed at getting the best locomotion performance on ERGOS given its limited DOF and serial-bus actuator class

### Environmental Perception *(planned)*
- OAK-D Lite for depth and RGB
- Fusion of vision, IMU, and foot sensing into locomotion and navigation

---

## System Architecture

<p align="center">
  <img src="https://github.com/Bryanh002/ERGOS-Dynamic-Humanoid-Platform/blob/main/docs/images/Architecture-Diagrams/ERGOS-System-Architecture.svg" width="3000"/>
  <br>
</p>

**Figure 1.** High-level system architecture of the ERGOS humanoid platform. A 3S LiPo feeds the custom motherboard: servo-bus power at battery voltage, and a boost converter to 18 V for the Jetson Orin Nano (18 V leaves more buffer on the Jetson input). The Jetson runs perception, planning, and learned policies in ROS 2, and powers the ESP32 logic rail over USB while streaming commands. The MCU drives two half-duplex Feetech STS buses and reads the on-board IMU and foot FSRs (two per foot). Arms are 4 DOF each; legs 5 DOF; neck 2 DOF. The OAK-D Lite connects to the Jetson over USB 3.0. Diagram source: [`docs/ergos_mermaidchart.txt`](docs/ergos_mermaidchart.txt).

---

## Development Plan

| Phase | Focus | Status |
| :--- | :--- | :--- |
| **1. Hardware platform** | V1.4 CAD, motherboard (designed — testing), harness, assembly, tether | In progress |
| **2. Embedded control** | ESP32 servo firmware, Jetson bring-up, ROS 2 driver | Starting (bus examples exist) |
| **3. Simulation & RL** | Isaac Sim / Isaac Lab, PyTorch locomotion policies | Planned |
| **4. Sim-to-real walking** | Transfer onto ERGOS, tethered then free walking | Planned |
| **5. Perception** | OAK-D in the control loop | Planned |

**Phase 1 — Hardware platform.** Current work. Build the V1.4 mechanical design. The custom motherboard is designed and in testing (servo buses, power distribution, IMU, foot FSRs, Jetson 18 V rail). Assemble the robot and the walking tether.

**Phase 2 — Embedded control.** Firmware on the ESP32-S3 for dual-bus STS command/feedback, then a ROS 2 layer on the Orin Nano that talks to that MCU. Servo ID map, calibration, and a first standing / joint-tracking controller.

**Phase 3 — Simulation and RL.** Model ERGOS in Isaac Sim / Isaac Lab and train walking policies with PyTorch. This is also where ERGOS is used as the hardware test platform for [ServoSim](https://github.com/Bryanh002/ServoSim).

**Phase 4 — Sim-to-real walking.** Run trained policies on the Jetson, first on the tether, then untethered.

**Phase 5 — Perception.** Bring the OAK-D Lite into locomotion and navigation.

---

## Technical Summary

| Item | Choice |
| :--- | :--- |
| **On-robot compute** | NVIDIA Jetson Orin Nano (JetPack, ROS 2) |
| **Real-time MCU** | ESP32-S3 (C/C++, Arduino today) |
| **Actuators** | Feetech STS3250 (14×) and STS3235 (6×), TTL half-duplex @ 1 Mbps |
| **Sensors** | BMI323 IMU, OAK-D Lite, two FSRs per foot |
| **Power** | 3S 8400 mAh LiPo → motherboard eFuse / boost (18 V Jetson) / servo rails; Jetson USB powers PCB logic |
| **Simulation & training** | NVIDIA Isaac Sim / Isaac Lab, PyTorch |
| **Control stack** | ROS 2 on the Jetson, USB/UART to the ESP32 |
| **CAD / PCB** | SolidWorks, Altium Designer |

---

## Getting Started

The robot is still being built. There is not a one-command install yet. Use the folders that actually exist:

1. **Mechanical** — [mechanical/README.md](mechanical/README.md) · CAD in `mechanical/ERGOS_V1.4/`, STEP exports, interactive renders. Full assembly instructions will live there; they are not written yet.
2. **Electrical** — [Electrical/README.md](Electrical/README.md) · Altium project, schematic PDF, motherboard overview.
3. **BOM** — [docs/README.md](docs/README.md) · current parts list. This spreadsheet is out of date and will be rebuilt last.
4. **Software** — [software/README.md](software/README.md) · ESP32 bus examples now. ROS 2, Isaac, and training docs come with Phase 2–3.

**Later (when those phases land):** JetPack / Python environment, simulation setup, training and deployment, and a servo ID / wiring map.

---

## 📜 License

This project is open source and released under the **MIT License**.  
See the [LICENSE](LICENSE) file for more information.

---

## 👤 Project Developer

**Bryan Heddle**  
Mechatronics & AI Systems Engineering Student — *Western University*

---

## 💡 Acknowledgments

Thanks to the open-source robotics community for the tools, documentation, and work this project builds on.

**Project sponsors:**
- **[Thompson Innovation Fund](https://www.eng.uwo.ca/tc/innovation-fund.html)**
- **[WESEF](https://www.eng.uwo.ca/departments-units/finance-stores/undergrads/wesef.html)**
- **[Luxonis](https://www.luxonis.com/)**
- **[GoBilda](https://www.gobilda.com/)**
---
