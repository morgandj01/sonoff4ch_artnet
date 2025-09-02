#pragma once
#include "esphome.h"
#include "ArtnetWifi.h"
class ArtnetRelay : public Component {
 public:
  bool* dmx_ch1;
  bool* dmx_ch2;
  bool* dmx_ch3;
  bool* dmx_ch4;
  ArtnetWifi artnet;

  ArtnetRelay(bool* ch1, bool* ch2, bool* ch3, bool* ch4)
      : dmx_ch1(ch1), dmx_ch2(ch2), dmx_ch3(ch3), dmx_ch4(ch4) {}

  void setup() override;
  void loop() override;
};