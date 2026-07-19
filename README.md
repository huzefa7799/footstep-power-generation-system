# Footstep Power Generation System

The system converts mechanical energy from human footsteps into usable electrical energy using piezoelectric transducers, and displays the harvested voltage in real time on an LCD via an Arduino Uno.

---

## Overview

Public spaces such as railway stations, bus stands, shopping malls, and school corridors see constant foot traffic — an abundant, untapped source of mechanical energy. This project harvests that energy using piezoelectric discs, converts it to a stable DC voltage, and displays it live, demonstrating a low-cost, scalable approach to decentralized, eco-friendly power generation.

**Key objectives:**
- Convert footstep-induced mechanical stress into electrical energy using piezoelectric discs
- Rectify and filter the AC output into a stable, measurable DC voltage
- Read and display the voltage in real time on a 16x2 I2C LCD using an Arduino Uno (no memory storage or step-counting — pure live monitoring)

---

## How It Works

```
Piezoelectric Transducers → AC-to-DC Conversion Circuit → Charging/Discharging Mechanism → Arduino Uno → LCD Display
```

1. **Piezoelectric Discs (35mm)** — Generate AC voltage when mechanical stress (a footstep) is applied.
2. **Full-Wave Bridge Rectifier (4× 1N4007 diodes)** — Converts the AC signal into pulsating DC.
3. **Filtering Capacitor (10µF, 450V electrolytic)** — Smooths the rectified voltage, reducing ripple.
4. **Voltage Divider (50kΩ + 10kΩ resistors)** — Scales the voltage down to a safe 0–5V range for the Arduino's analog input.
5. **Arduino Uno** — Reads the scaled analog voltage via its ADC and computes the actual voltage.
6. **16x2 I2C LCD** — Displays the real-time voltage output.
7. **BC547 NPN Transistor** — Included for optional switching (e.g., driving an indicator LED).

---

## Components Used

| Component | Purpose |
|---|---|
| Piezoelectric Discs (35mm) | Primary energy-harvesting element |
| 1N4007 Diodes (×4) | Full-wave bridge rectifier (AC → DC) |
| 10µF, 450V Electrolytic Capacitor | Output smoothing/filtering |
| 50kΩ & 10kΩ Resistors | Voltage divider for safe Arduino input |
| BC547 NPN Transistor | Switching/amplification |
| Arduino Uno | Voltage monitoring & processing |
| 16x2 I2C LCD Display | Real-time voltage display |
| Breadboard & Jumper Wires | Prototyping |

---

## Simulation

Circuit behavior was validated in **Proteus Design Suite** prior to hardware assembly. Since Proteus lacks a native piezoelectric disc model, an AC voltage source was substituted to emulate footstep-induced stress. The simulation confirmed correct operation of the rectification, filtering, voltage-division, and Arduino/LCD display stages under varying simulated pressure.

---

## Advantages

- Environmentally friendly, renewable energy source
- Low maintenance (few moving parts)
- Simple, low-cost, and educational to build
- Ideal for high-footfall public areas
- Silent operation
- Modular — units can be scaled up in series/parallel

## Limitations

- Low energy output per footstep *(mitigated via sensor arrays + supercapacitor/battery storage)*
- Output varies with force applied *(mitigated via spring-loaded distribution plates)*
- Not suited for high-power loads *(best for LEDs, sensors, and low-power charging; can be hybridized with solar/wind)*

---

## Future Scope

- Add energy storage (supercapacitors/batteries) for offline use
- Wireless data logging and smart-grid integration
- Scale up using piezo arrays for higher output
- Step-counting and analytics features

---

## License

This project was developed for academic purposes as part of the Second Year Engineering Project Based Learning curriculum. This project is licensed under the MIT License — see the LICENSE file for details.

---

## Author
**Huzefa Shaikh**

Email: huzefashaikh385@gmail.com

LinkedIn: https://www.linkedin.com/in/huzefa-shaikh-34881a290

GitHub: https://github.com/huzefa7799
