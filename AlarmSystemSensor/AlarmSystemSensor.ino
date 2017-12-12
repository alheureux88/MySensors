/**
   The MySensors Arduino library handles the wireless radio link and protocol
   between your home built sensors/actuators and HA controller of choice.
   The sensors forms a self healing radio network with optional repeaters. Each
   repeater and gateway builds a routing tables in EEPROM which keeps track of the
   network topology allowing messages to be routed to nodes.

   Created by Henrik Ekblad <henrik.ekblad@mysensors.org>
   Copyright (C) 2013-2015 Sensnology AB
   Full contributor list: https://github.com/mysensors/Arduino/graphs/contributors

   Documentation: http://www.mysensors.org
   Support Forum: http://forum.mysensors.org

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License
   version 2 as published by the Free Software Foundation.
*/
#include <MyCommon.h>
#include <MySensors.h>

#define SKETCH_NAME "Alarm System"
#define SKETCH_MAJOR_VER "1"
#define SKETCH_MINOR_VER "0"

#define ZONE_START_CHILD_ID 3
#define ZONE_AMOUNT 6

#define SLEEP_AMOUNT_MS 1000
#define SEND_OVERRIDE 300 // this will push the data even if it didn't change every 1 sec * 300 (5 minutes)

MyMessage* msg[ZONE_AMOUNT];

uint8_t sentValue[ZONE_AMOUNT];
uint8_t counter = 0;

void setup()
{
  for (int i = 0; i < ZONE_AMOUNT; ++i)
  {
    pinMode(ZONE_START_CHILD_ID + i, INPUT);
    digitalWrite(ZONE_START_CHILD_ID + i, HIGH); //Activate the pullup
    sentValue[i] = 2;
    msg[i] = new MyMessage(ZONE_START_CHILD_ID + i, V_TRIPPED);
  }
}

void presentation()
{
  // Send the sketch version information to the gateway and Controller
  sendSketchInfo(SKETCH_NAME, SKETCH_MAJOR_VER "." SKETCH_MINOR_VER);
  for (int i = 0; i < ZONE_AMOUNT; ++i)
  {
    present(ZONE_START_CHILD_ID + i, S_DOOR);
  }
}

void loop()
{
  uint8_t value;
  sleep(SLEEP_AMOUNT_MS);

  for (int i = 0; i < ZONE_AMOUNT; ++i)
  {
    value = digitalRead(ZONE_START_CHILD_ID + i);
    if (counter == 0 || value != sentValue[i])
    {
      // Value has changed from last transmission, send the updated value
      send(msg[i]->set(value == HIGH));
      sentValue[i] = value;
    }
  }
  counter = (counter + 1) % SLEEP_AMOUNT_MS;
}
