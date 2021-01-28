#include <avr/sleep.h>
#include <FastLED.h>
#include <PinButton.h>
#include <EEPROM.h>

// define the LEDs
#define LED_PIN 5  //pin the LEDs are connected to
#define NUM_LEDS 32
#define BRIGHTNESS 160 //maximum brightness
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
struct CRGB leds[NUM_LEDS];
#define UPDATES_PER_SECOND 100

#include "solid_color_mode.h"
#include "palette_mode.h"
#include "effect_mode.h"

const int wakeUpPin = 2;
PinButton FunctionButton(wakeUpPin);
int setMode = 0;


void wakeUp(){
  Serial.println("Interrrupt Fired");
  sleep_disable();//Disable sleep mode
  detachInterrupt(0); //Removes the interrupt from pin D2;
}

void Going_To_Sleep(){
    sleep_enable();//Enabling sleep mode
    attachInterrupt(0, wakeUp, LOW);//attaching a interrupt to pin D2
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);//Setting the sleep mode, in our case full sleep
    sleep_cpu();//activating sleep mode
    Serial.println("just woke up!");//next line of code executed after the interrupt
  }

void setup() {
	delay(1000); // power-up safety delay
	Serial.begin(115200);
	FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
	FastLED.setBrightness(BRIGHTNESS);
	FastLED.clear();
	Serial.print("fastled started");
//	EEPROM.update(0, setMode);        // at first run uncomment this for lines for initializing the eeprom data
//	EEPROM.update(1, colorCounter);
//	EEPROM.update(2, paletteCounter);
//	EEPROM.update(3, gCurrentPatternNumber);
	setMode = EEPROM.read(0);
	colorCounter = EEPROM.read(1);
	paletteCounter = EEPROM.read(2);
	gCurrentPatternNumber = EEPROM.read(3);
}

void loop() {
	FunctionButton.update();

	if (FunctionButton.isSingleClick()) {
		if (setMode == 0) {
			colorCounter++;
			if (colorCounter > 17) {
				colorCounter = 0;
			}
		}
		else if (setMode == 1) {
			paletteCounter++;
			if (paletteCounter > 11) { // adjust if you have more or less than 34 palettes
				paletteCounter = 0;
			}
		}
		else if (setMode == 2) {
			nextPattern();  // Change to the next pattern
		}
	}
	else if (FunctionButton.isDoubleClick()) {
		setMode++;
		if (setMode > 2) {
			setMode = 0;
		}
	}
	else if (FunctionButton.isLongClick()) {
		FastLED.clear();
		FastLED.show();
		EEPROM.update(0, setMode);
		EEPROM.update(1, colorCounter);
		EEPROM.update(2, paletteCounter);
		EEPROM.update(3, gCurrentPatternNumber);
		Serial.print("shooting down");
		delay(500);
		Going_To_Sleep();
		Serial.print("waking up");
	}

	if (setMode == 0) {
		if (colorCounter % 2 == 0) {
		float breath = (exp(sin(millis()/2000.0*PI)) - 0.36787944)*108.0;
		FastLED.setBrightness(breath);
		}
		else {
			FastLED.setBrightness(BRIGHTNESS);
		}
		ChangeColorPeriodically();
	}
	else if (setMode == 1) {
		FastLED.setBrightness(BRIGHTNESS);
		ChangePalettePeriodically();
		static uint8_t startIndex = 0;
		startIndex = startIndex + 1;
		FillLEDsFromPaletteColors(startIndex);
	}
	else if (setMode == 2) {
		gPatterns[gCurrentPatternNumber]();
	}

	FastLED.show();
	FastLED.delay(2000 / UPDATES_PER_SECOND);
	EVERY_N_MILLISECONDS( 20 ) { gHue++; } // slowly cycle the "base color" through the rainbow
}
