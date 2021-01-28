#ifndef SOLID_COLOR_MODE_H_
#define SOLID_COLOR_MODE_H_

int colorCounter = 0;

void ChangeColorPeriodically()
{
if( colorCounter == 0 || colorCounter == 1) { fill_solid( leds, NUM_LEDS, CHSV(0, 255, 192));}
if( colorCounter == 2 || colorCounter == 3) { fill_solid( leds, NUM_LEDS, CHSV(32, 255, 255));}
if( colorCounter == 4 || colorCounter == 5) { fill_solid( leds, NUM_LEDS, CHSV(64, 255, 255));}
if( colorCounter == 6 || colorCounter == 7) { fill_solid( leds, NUM_LEDS, CHSV(96, 255, 255));}
if( colorCounter == 8 || colorCounter == 9) { fill_solid( leds, NUM_LEDS, CHSV(138, 255, 255));}
if( colorCounter == 10 || colorCounter == 11) { fill_solid( leds, NUM_LEDS, CHSV(160, 255, 255));}
if( colorCounter == 12 || colorCounter == 13) { fill_solid( leds, NUM_LEDS, CHSV(180, 255, 255));}
if( colorCounter == 14 || colorCounter == 15) { fill_solid( leds, NUM_LEDS, CHSV(214, 255, 255));}
if( colorCounter == 16 || colorCounter == 17) { fill_solid( leds, NUM_LEDS, CHSV(0, 0, 192));}
}

#endif /* SOLID_COLOR_MODE_H_ */
