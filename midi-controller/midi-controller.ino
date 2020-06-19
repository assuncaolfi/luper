#include <Encoder.h> // Include the Encoder library.
// This must be done before the Control Surface library.
#include <Control_Surface.h> // Include the Control Surface library
// Include the display interface you'd like to use
#include <Display/DisplayInterfaces/DisplayInterfaceSSD1306.hpp>

Adafruit_SSD1306 ssd1306Display = {128, 32, &Wire, 4};

// --------------------------- Display interface ---------------------------- //
// ========================================================================== //

// Implement the display interface, specifically, the begin and drawBackground
// methods.
class MySSD1306_DisplayInterface : public SSD1306_DisplayInterface {
 public:
  MySSD1306_DisplayInterface(Adafruit_SSD1306 &display)
    : SSD1306_DisplayInterface(display) {}

  void begin() override {
    // Initialize the Adafruit_SSD1306 display
 if (!disp.begin())
 FATAL_ERROR(F("SSD1306 allocation failed."), 0x1306);

    // If you override the begin method, remember to call the super class method
    SSD1306_DisplayInterface::begin();
  }

 void drawBackground() override {  }

} display = ssd1306Display;

// ---------------------------- MIDI Out ---------------------------- //
// ========================================================================== //

// Instantiate a MIDI over USB interface.
USBMIDI_Interface midi;
//using namespace MIDI_Notes;

// Instantiate an array of CCPotentiometer objects
CCPotentiometer potentiometers[2] = {
{A0, 0x14}, // Controller number of the first potentiometer
{A1, 0x15},
};

// Instantiate an array of CCButton objects
CCButton buttons[4] = {
  {10, 0x10},
  {16, 0x11},
  {14, 0x12},
  {15, 0x13},
};

//MCU::VPotRing vpots[1] = {
  //{1, CHANNEL_1},
//  0x15,
//};


// ---------------------------- Display Elements ---------------------------- //
// ========================================================================== //

/*
   Define all display elements that display the state of the input elements.
*/

// VPot rings
//MCU::VPotDisplay vpotDisp[] = {
  // position (0, 10), outer radius (16) px, inner radius (13) px
 //{display, vpots[0], {64, 15}, 13, 10, WHITE},
//j/};

void setup() {
  Control_Surface.begin(); // Initialize Control Surface
}

void loop() {
  Control_Surface.loop(); // Update the Control Surface
}
