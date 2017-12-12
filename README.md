# My personal sketch for MySensor
[![Build Status](https://travis-ci.org/alheureux88/MySensors.svg?branch=travis)](https://travis-ci.org/alheureux88/MySensors)
## What is it?
Personal repository of the different sensor and configuration I am currently using for my home automation. You can see how they are used in my `homeassistant` repository.

## How to use it
1.  Edit the `MyCommon.h` to include the valid AES encryption key.
2.  Run and upload `SecurityPersonalizer` before any other project.
3.  Choose which component to use and upload it :)
  
## Component
1. My current gateway is using a raspberry-pi over ethernet to the controller
2. `AlarmSystemSensor`: Simple project that reads 6 inputs and send them to the controller