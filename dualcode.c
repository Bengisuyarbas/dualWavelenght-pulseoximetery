//bby22, ig540, group 32
//This code is to be used on a dual-wavelength pulse and spO2 level detector system to provide patients with an accurate heart rate and spO2 levels


#include <Wire.h>
#include "MAX30100_PulseOximeter.h"

// Constants for report period (in milliseconds)
#define REPORTING_PERIOD_MS 1000

// LED pin assignments
#define RED_LED A3  
#define GREEN_LED A2
#define BIPOLAR_LED_POS D3   // Bipolar LED positive pin
#define BIPOLAR_LED_NEG A7   // Bipolar LED negative pin

// Healthy heart rate range
#define HR_MIN 50    
#define HR_MAX 120   

/////////////////////////////////////////////////
// OLED DISPLAY SETUP
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED display dimensions
#define SCREEN_WIDTH 96 // OLED display width, in pixels
#define SCREEN_HEIGHT 16 // OLED display height, in pixels

// OLED reset pin and address
#define OLED_RESET     -1 
#define SCREEN_ADDRESS 0x3C 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

///////////////////////////////////////////////////

PulseOximeter pox;    // Create PulseOximeter object
uint32_t tsLastReport = 0;  // Timestamp for periodic reporting

// Function to handle heartbeat detection and trigger LED indication
void onBeatDetected() {
    Serial.println("Beat Detected!");  // Print to serial for debugging

    // Blink Bipolar LED briefly to indicate a heartbeat
    digitalWrite(BIPOLAR_LED_POS, HIGH);  // Turn on positive pin
    digitalWrite(BIPOLAR_LED_NEG, LOW);   // Turn off negative pin
    delay(100);                           // Hold for 100ms to indicate beat

    // Reset Bipolar LED after heartbeat
    digitalWrite(BIPOLAR_LED_POS, LOW);  // Turn off positive pin
    digitalWrite(BIPOLAR_LED_NEG, LOW);  // Turn off negative pin
}

// Setup function: Initializes sensors, LEDs, and display
void setup() {
    Serial.begin(115200);  // Initialize serial communication at 115200 baud

    // Set LED pins as output
    pinMode(RED_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(BIPOLAR_LED_POS, OUTPUT);  // Set Bipolar LED positive pin as output
    pinMode(BIPOLAR_LED_NEG, OUTPUT);  // Set Bipolar LED negative pin as output

    Serial.print("Initializing pulse oximeter...");

    // Initialize the PulseOximeter instance
    if (!pox.begin()) {
        Serial.println("FAILED");  // Print failure message if initialization fails
        for (;;);  // Halt if initialization fails
    } else {
        Serial.println("SUCCESS");  // Print success message if initialization succeeds
    }

    // Set the callback for heartbeat detection
    pox.setOnBeatDetectedCallback(onBeatDetected);

    // Initialize OLED display
    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println(F("SSD1306 allocation failed"));  // Handle OLED initialization failure
        for (;;);  // Halt if OLED fails to initialize
    }
}

// Main loop: Updates sensor readings and controls display and LEDs
void loop() {
    pox.update();  // Update the sensor readings

    // Periodically report heart rate and SpO2 values every REPORTING_PERIOD_MS milliseconds
    if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
      
        if (int(millis()) > 20000) { // Wait for 20 seconds before starting measurements

            // Get heart rate and SpO2 from the sensor
            float heartRate = pox.getHeartRate(); 
            float spO2 = pox.getSpO2();

            // Update OLED display with heart rate and SpO2 data
            textOLED(heartRate, spO2);

            if (heartRate > 0 && spO2 > 0) { // Check if readings are valid
                Serial.print("Heart Rate: ");
                Serial.print(heartRate);
                Serial.print(" bpm / SpO2: ");
                Serial.print(spO2);
                Serial.println(" %");

                // LED control: Green LED for normal heart rate range, Red for outside range
                if (heartRate >= HR_MIN && heartRate <= HR_MAX) {
                    digitalWrite(GREEN_LED, HIGH);  // Turn on green LED
                    digitalWrite(RED_LED, LOW);     // Turn off red LED    
                } else {
                    digitalWrite(GREEN_LED, LOW);   // Turn off green LED
                    digitalWrite(RED_LED, HIGH);    // Turn on red LED
                }
            } else { 
                Serial.println("No valid data from sensor.");
                digitalWrite(RED_LED, LOW);     // Turn off all LEDs if data is invalid
                digitalWrite(GREEN_LED, LOW);
            }

            // Update the timestamp for the last report
            tsLastReport = millis();
        } else { // Display a message while initializing
            display.print("Initialising. \nPlease hold still.");
            display.display();
        }
    }
}

// Function to update OLED display with heart rate and SpO2 values
void textOLED(float bpm, float O2Level) {
    display.clearDisplay();  // Clear the display
    display.setTextSize(1);  // Set text size to normal
    display.setTextColor(SSD1306_WHITE);  // Set text color to white
    display.setCursor(0, 0);  // Set cursor to top-left corner

    // Display heart rate and SpO2 values on the OLED screen
    display.print("HR: ");
    display.print(bpm);
    display.print(" bpm \nSpO2: ");
    display.print(O2Level);
    display.print(" %");

    display.display();  // Update the OLED display
}
