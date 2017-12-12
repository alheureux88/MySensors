# My personal sketch for MySensor
## What is it?
Personal repository of the different sensor and configuration I am currently using for my home automation. You can see how they are used in my `homeassistant` repository.

## How to use it
1.  Copy the content of the `libraries` folder to your own libraries folder.
2.  Edit the `MyCommon.h` to include the valid AES encryption key.
3.  Run and upload `SecurityPersonalizer` before any other project.
4.  Choose which component to use and upload it :)
  
## Component
1. My current gateway is using a raspberry-pi over ethernet to the controller
2. `AlarmSystemSensor`: Simple project that reads 6 inputs and send them to the controller