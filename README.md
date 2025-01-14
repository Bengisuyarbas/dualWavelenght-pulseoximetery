# Dual-Wavelength Pulse Oximeter

**Version**: 1.0  
**Date**: 10/01/2025

## Overview
The **Dual-Wavelength Pulse Oximeter** is a wearable device that measures heart rate (BPM) and blood oxygen levels (SpO2) using dual infrared and red LEDs. The device outputs real-time feedback via an OLED display and status LEDs. It is powered by an Arduino NANO ESP32 and uses a MAX30100 sensor for accurate measurements.

## Table of Contents
- [Overview](#overview)
- [Electrical Specifications](#electrical-specifications)
- [Mechanical Specifications](#mechanical-specifications)
- [Environmental Specifications](#environmental-specifications)
- [Performance Characteristics](#performance-characteristics)
- [License](#license)


**Wiring Diagram**:  
![diagram](https://github.com/user-attachments/assets/90f80236-1adb-4299-a045-a74ff9570aa7)
*A clear diagram showing all the connections between the MAX30100, Arduino NANO ESP32, and other components used in your project.*

## Electrical Specifications
| **Parameter**                   | **Value** |
|----------------------------------|----------|
| Operating Voltage                | 3.3V     |
| VIN Range                        | 6-21V    |
| Current Draw (Deep Sleep Mode)   | 7 μA     |
| Current Draw (Light Sleep Mode)  | 240 μA   |

## Mechanical Specifications
- **Device Dimensions**: 76 x 45 x 19 mm
- **Device Weight**: TBD
- **Mounting Holes**: 4 holes, 2mm diameter
- **Housing**: Pending design

## Environmental Specifications
- **Temperature**: -40°C to +85°C
- **Humidity**: 20% to 90% (±5%)
- **Pressure**: Ambient, 101kPa Abs

## Performance Characteristics
- **OLED Display**: 96x16 pixels, monochrome
- **Sensor Accuracy**: 
  - Heart Rate: ±5 bpm
  - SpO2: ±2%


