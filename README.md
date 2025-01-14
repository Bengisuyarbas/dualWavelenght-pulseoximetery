# dualWavelenght-pulseoximetery
Dual-Wavelength Pulse Oximeter
Version: 1.0
Date: 10/01/2025

Overview
The Dual-Wavelength Pulse Oximeter is an innovative wearable device designed to monitor heart rate (BPM) and oxygen saturation (SpO2) in real time. By using dual LEDs (infrared and red), this device measures the absorbance of light through the skin to compute vital signs, providing users with accurate and immediate feedback.

Utilizing the MAX30100 Pulse Oximeter sensor, the system collects raw data, processes it, and outputs the results on an OLED display. The system also uses a bipolar LED to visually indicate the heartbeat in real-time. In addition, status LEDs show whether the heart rate falls within a healthy range (green for normal, red for abnormal).

Table of Contents
Electrical Specifications
Mechanical Specifications
Environmental Specifications
Performance Characteristics
Internal Operation
Safety Precautions
Compliance Certification
Code
License
Electrical Specifications
Parameter	Value	Unit
Operating Voltage	3.3	V
VIN Range	6-21	V
VBUS supply via USB-C® connector	5.0	V
Current draw in deep sleep mode	7	μA
Current draw in light sleep mode	240	μA
Note: The device can be configured to operate on battery power using the integrated connector on the board; however, it is currently not configured for battery use.

Mechanical Specifications
Device dimensions: 76 x 45 x 19 mm
Device weight: TBD
Mounting holes: 4 mounting holes with a 2mm diameter, located on the outer corners of the main board.
Casing/Housing: Yet to be designed and implemented.
Environmental Specifications
Ideal Operating Condition	Value
Temperature	-40°C to +85°C
Humidity	20% to 90% (±5%)
Pressure	Ambient, 101kPa Abs
Note:

Unsuitable for use in wet or damp conditions.
Unsuitable for prolonged outdoor use.
Performance Characteristics
OLED Screen Performance:
Parameter	Value	Unit
Dimensions	96 x 16	Pixels
Pixel size	0.198 x 0.198	mm
Response time	10	µs
Display Colour	Monochrome	-
OLED lifetime	20,000	Hours
Note: OLED lifetime is defined by the time taken for luminance to decay to <50% of the initial value.

Sensor Performance:
Sample rate: 50-1000 samples per second
Internal communication rate: 115200 baud
Accuracy and Precision:
Property	Accuracy (±)	Precision	Unit
Heart Rate	5	0.01	bpm
SpO2	2	0.01	%
Note: Accuracy may decrease if the device is not used under ideal conditions.

Internal Operation
Data from the MAX30100 sensor is transferred to the control unit (Arduino NANO ESP32) via mikroBUS. The data is processed, and the heart rate and SpO2 values are displayed on an OLED screen. The system also provides feedback using LEDs (green and red) to indicate whether the heart rate is within the healthy range, and a bipolar LED blinks in real-time with the heartbeat.

Functional Block Diagram:


Safety Precautions
Operating conditions: Always use the device within the specified temperature and humidity range to avoid potential damage and inaccurate readings.
Power supply: Ensure that the device is powered within the provided voltage range (3.3V to 5V).
Mechanical safety: Avoid physical impacts on the OLED display, as it is made of glass. In case of breakage, avoid contact with any internal organic substances that may leak.
Environment: Do not use the device in wet or humid conditions.
Compliance Certification
RoHS Compliance: All components used are RoHS compliant (except for the soldering paste).
CE Certification: The components used are CE certified for safety.
Battery Connectors: The device can be powered by a USB-C® connector or via the onboard battery connector.
Code
The code for the Pulse Oximeter system is available in this repository. It uses the MAX30100 Pulse Oximeter library to interact with the sensor and display the results on an OLED screen. The system also provides feedback using LEDs and serial communication for debugging.

cpp
Kodu kopyala
// Your full code goes here...
License
This project is licensed under the MIT License - see the LICENSE file for details.
