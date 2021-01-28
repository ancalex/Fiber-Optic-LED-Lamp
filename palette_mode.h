#ifndef PALETTE_MODE_H_
#define PALETTE_MODE_H_

CRGBPalette16 currentPalette;
TBlendType    currentBlending;
int paletteCounter = 0;


void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
  uint8_t brightness = 255;

  for( int i = 0; i < NUM_LEDS; i++) {
    leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
    colorIndex += 3;
  }
}

// Gradient palette "rainbow_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/ds9/tn/rainbow.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 24 bytes of program space.

DEFINE_GRADIENT_PALETTE( rainbow_gp ) {
    0, 255,  0,255,
   51,   0,  0,255,
  102,   0,255,255,
  153,   0,255,  0,
  204, 255,255,  0,
  255, 255,  0,  0};

// Gradient palette "es_landscape_24_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/landscape/tn/es_landscape_24.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 24 bytes of program space.

DEFINE_GRADIENT_PALETTE( es_landscape_24_gp ) {
  0,  27, 91,  0,
 38,  94,255,  0,
 63, 142,255, 21,
 68, 173,244,252,
127,  10,164,156,
255,   5, 68, 66};

// Gradient palette "Gummy_Bears_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/ds/icons/tn/Gummy-Bears.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE( Gummy_Bears_gp ) {
    0, 252, 91,  0,
   63, 222, 21,  1,
  127, 194,  1,  1,
  191,  35, 48,  2,
  255,   1,215, 10};

// Gradient palette "bhw3_01_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw3/tn/bhw3_01.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 52 bytes of program space.

DEFINE_GRADIENT_PALETTE( bhw3_01_gp ) {
    0, 255,146,228,
   25, 152, 43, 65,
   48,  36, 17, 22,
   72,   8, 34, 75,
   81,   1, 58,170,
  104,  42, 49,245,
  124,  15, 15, 95,
  150,   1,  8, 39,
  175,  98, 32, 35,
  204, 123,  9,  2,
  219, 220, 15,  2,
  237, 255, 93,  6,
  255, 244,244,  0};

// Gradient palette "BlacK_Magenta_Red_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/basic/tn/BlacK_Magenta_Red.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE( BlacK_Magenta_Red_gp ) {
    0,   0,  0,  0,
   63,  42,  0, 45,
  127, 255,  0,255,
  191, 255,  0, 45,
  255, 255,  0,  0};

// Gradient palette "BlacK_Blue_Magenta_White_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/basic/tn/BlacK_Blue_Magenta_White.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE( BlacK_Blue_Magenta_White_gp ) {
    0,   0,  0,  0,
   42,   0,  0, 45,
   84,   0,  0,255,
  127,  42,  0,255,
  170, 255,  0,255,
  212, 255, 55,255,
  255, 255,255,255};

// Gradient palette "Sunset_Real_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/atmospheric/tn/Sunset_Real.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE( Sunset_Real_gp ) {
    0, 120,  0,  0,
   22, 179, 22,  0,
   51, 255,104,  0,
   85, 167, 22, 18,
  135, 100,  0,103,
  198,  16,  0,130,
  255,   0,  0,160};

// Gradient palette "lava_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/neota/elem/tn/lava.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 52 bytes of program space.

DEFINE_GRADIENT_PALETTE( lava_gp ) {
    0,   0,  0,  0,
   46,  18,  0,  0,
   96, 113,  0,  0,
  108, 142,  3,  1,
  119, 175, 17,  1,
  146, 213, 44,  2,
  174, 255, 82,  4,
  188, 255,115,  4,
  202, 255,156,  4,
  218, 255,203,  4,
  234, 255,255,  4,
  244, 255,255, 71,
  255, 255,255,255};

// Gradient palette "GMT_drywet_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/gmt/tn/GMT_drywet.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE( GMT_drywet_gp ) {
    0,  47, 30,  2,
   42, 213,147, 24,
   84, 103,219, 52,
  127,   3,219,207,
  170,   1, 48,214,
  212,   1,  1,111,
  255,   1,  7, 33};

// Gradient palette "gr65_hult_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/hult/tn/gr65_hult.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 24 bytes of program space.

DEFINE_GRADIENT_PALETTE( gr65_hult_gp ) {
    0, 247,176,247,
   48, 255,136,255,
   89, 220, 29,226,
  160,   7, 82,178,
  216,   1,124,109,
  255,   1,124,109};

// Gradient palette "departure_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/mjf/tn/departure.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 88 bytes of program space.

DEFINE_GRADIENT_PALETTE( departure_gp ) {
    0,   8,  3,  0,
   42,  23,  7,  0,
   63,  75, 38,  6,
   84, 169, 99, 38,
  106, 213,169,119,
  116, 255,255,255,
  138, 135,255,138,
  148,  22,255, 24,
  170,   0,255,  0,
  191,   0,136,  0,
  212,   0, 55,  0,
  255,   0, 55,  0};

// Gradient palette "Analogous_1_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/red/tn/Analogous_1.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE( Analogous_1_gp ) {
    0,   3,  0,255,
   63,  23,  0,255,
  127,  67,  0,255,
  191, 142,  0, 45,
  255, 255,  0,  0};

// There are several different palettes of colors demonstrated below.

void ChangePalettePeriodically()
{
    if( paletteCounter == 0)  { currentPalette = rainbow_gp; currentBlending = LINEARBLEND;  }
    if( paletteCounter == 1)  { currentPalette = es_landscape_24_gp; currentBlending = LINEARBLEND;  }
    if( paletteCounter == 2)  { currentPalette = Gummy_Bears_gp; currentBlending = LINEARBLEND;  }
    if( paletteCounter == 3)  { currentPalette = bhw3_01_gp; currentBlending = LINEARBLEND;  }
    if( paletteCounter == 4)  { currentPalette = BlacK_Magenta_Red_gp; currentBlending = LINEARBLEND;  }
    if( paletteCounter == 5)  { currentPalette = BlacK_Blue_Magenta_White_gp; currentBlending = LINEARBLEND;  }
    if( paletteCounter == 6)  { currentPalette = Sunset_Real_gp; currentBlending = LINEARBLEND;  }
    if( paletteCounter == 7)  { currentPalette = lava_gp; currentBlending = LINEARBLEND; }
    if( paletteCounter == 8)  { currentPalette = GMT_drywet_gp; currentBlending = LINEARBLEND; }
    if( paletteCounter == 9)  { currentPalette = gr65_hult_gp; currentBlending = LINEARBLEND; }
    if( paletteCounter == 10)  { currentPalette = departure_gp; currentBlending = LINEARBLEND; }
    if( paletteCounter == 11)  { currentPalette = Analogous_1_gp; currentBlending = LINEARBLEND; }
}

#endif /* PALETTE_MODE_H_ */

