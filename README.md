### [ MAIN DOC IS WIP === WILL BE UPDATED BY 07/01/2026]

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

## Project Overview
ERGOS is meant to be a low-cost, open-source platform designed for dynamic humanoid robotics research. It serves as a ROS2-based control environment that integrates serial servo hardware with Reinforcement Learning (RL) techniques. The primary goal of ERGOS is to develop and optimize dynamic, stable gait patterns for bipedal systems, demonstrating advanced movement capabilities on an economical, self-contained hardware platform. Here is a photo of ERGOS's current design:

<p align="center">
  <img src="https://github.com/Bryanh002/ERGOS-Dynamic-Humanoid-Platform/blob/main/docs/images/ERGOS-Rendered-images/ERGOS-Rendered-image-dark-transparent.png" width="2000"/>
  <br>
</p>

---

## 🗺️ Repository Map

- **Hardware**
  - [`mechanical/`](mechanical/) — CAD, renders
  - [`electrical/`](electrical/) — schematics, PCB, BOM
- **Software**
  - [`software/`](software/) — firmware, ROS 2 packages, tools, simulations
- **Docs**
  - [`docs/`](docs/) — BOM, images, datasheets

---

## ERGOS Features
*(Planned and In Progress)*

### Mechanical System
- Custom humanoid mechanical design
- Belt-driven actuation using HTD-3M pulleys (18T–30T) for joint-specific torque amplification
- 3D-printed structural housings optimized for low cost and rapid iteration
- Modular joint architecture to support future actuator and transmission upgrades

### Electronics & Power
- Custom PCB featuring an ESP32-S3 for real-time servo communication
- Custom full-duplex to half-duplex TTL transceiver for serial servo bus control
- On-board power management from a 3S 8400 mAh LiPo battery
- Custom power and communication harness backbone for distributed serial servos
- Jetson Orin Nano as the primary compute module, interfacing with the MCU for control and perception workloads

### Dynamic Locomotion (Reinforcement Learning) *(Future)*
- Reinforcement learning-based locomotion control for stable, adaptive walking
- Simulation-first training pipeline with planned sim-to-real transfer onto physical hardware
- Architecture designed to support experimentation with different control formulations and reward structures

### Environmental Perception *(Future)*
- Vision system integration for obstacle detection and terrain awareness
- Planned fusion of perception outputs into locomotion and navigation policies

### Speech & Human Interaction *(Future)*
- On-board large language model (LLM) for voice-based command interpretation
- Natural-language interface for high-level behavior control and human–robot interactions

---

## System Architecture

<p align="center">
  <img src="https://github.com/Bryanh002/ERGOS-Dynamic-Humanoid-Platform/blob/main/docs/images/Architecture-Diagrams/ERGOS-System-Architecture.svg" width="3000"/>
  <br>
</p>

**Figure 1.** High-level system architecture of the ERGOS humanoid platform. The system is powered by a centralized 3S LiPo battery, which feeds a custom power distribution and regulation stage. This stage supplies both the actuator subsystem and the main compute unit. High-level perception, planning, and reinforcement learning policies are executed on the Jetson Orin Nano within a ROS 2-based control stack. Control commands are transmitted to an ESP32-S3 real-time controller, which handles low-level actuation and interfaces directly with modular servo daisy chains. Sensor inputs, including depth vision, inertial measurements, and foot force sensing, are processed on the Jetson and integrated into the control pipeline. Detailed mechanical, electrical, and software architectures are documented in subsystem-specific sections.

---

## Development Phases
=== WIP === 
1. **Phase 1 — Hardware Creation**  
   Finalize CAD design and PCB for servo control and power distribution.

3. **Phase 2 — Reinforcement Learning Simulation**  
   Develop a simulation environment for dynamic walking using RL.  
   *(Likely frameworks: PyTorch, custom physics simulation, or Isaac Gym)*

4. **Phase 3 — Real-World Testing**  
   Transfer trained model to the Jetson Orin Nano for live walking experiments.

5. **Phase 4 — Vision and Speech Integration**  
   Add camera input for object detection and LLM for high-level control.

---

## Technical Summary
- **Programming Language:** Python (planned)
- **Frameworks:** TBD (PyTorch or TensorFlow for RL; ROS2 possible integration)
- **Hardware:** Jetson Orin Nano, ESP32-S3, Feetech STS3235/STS3250 smart servos
- **Design Tools:** SolidWorks (mechanical), Altium Designer (PCB)

---

## Getting Started
*(To be updated as the project matures)*

**Planned sections:**
1. Hardware Assembly (It's not easy, this will be detailed in Mechanical Section)
2. Updated BOM
3. Installation requirements (JetPack SDK, Python environment, dependencies)
4. Simulation setup (RL environment)
5. Model training and deployment instructions
6. Hardware configuration and servo connection mapping

---

## Future Work
- WIP

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
Special thanks to the open-source robotics community for the tools, documentation, and inspiration that contributed to this project’s foundation.

**Project sponsors:**
- **[Thompson Innovation Fund](https://www.eng.uwo.ca/tc/innovation-fund.html)**
- **[WESEF](https://www.eng.uwo.ca/departments-units/finance-stores/undergrads/wesef.html)**
- **[Luxonis](https://www.luxonis.com/)**
- **[GoBilda](https://www.gobilda.com/)**
---


