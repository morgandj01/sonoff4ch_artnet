#include "sonoff4ch_artnet.h"

void ArtnetRelay::setup() {
  artnet.begin();
  artnet.setArtDmxCallback([this](uint16_t universe, uint16_t length, uint8_t sequence, uint8_t* data){
    if (universe == 0 && length >= 4) {
      *dmx_ch1 = (data[0] > 127);
      *dmx_ch2 = (data[1] > 127);
      *dmx_ch3 = (data[2] > 127);
      *dmx_ch4 = (data[3] > 127);
    }
  });
}

void ArtnetRelay::loop() {
  artnet.read();
}