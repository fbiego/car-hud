# Car HUD

Car HUD is a DIY heads-up display that shows real-time vehicle data on an ESP32-based screen using a BLE OBD2 ELM327 Mini adapter.

The system communicates with the vehicle ECU over ISO 15765-4 (CAN) and renders telemetry using LVGL.

## Features

- BLE connection to OBD2 ELM327 Mini adapter  
- ISO 15765-4 CAN protocol  
- Real-time vehicle telemetry  
- ESP32-based display  

## Hardware

- [`OBD2 ELM327 Mini adapter (BLE)`](https://www.google.com/search?q=elm327+mini)

![ELM 327](images/elm_327_mini.png?raw=true "elm_327")

- [`Viewe SmartRing Display`](https://viewedisplay.com/product/esp32-1-8-inch-round-amoled-touch-display-arduino-lvgl-wifi-voice-assistant-ai-smart-displays/)

![Viewe SmartRing](images/viewe_smartring.png?raw=true "smartring")

## Parameters

- Engine RPM  
- Vehicle Speed  
- Coolant Temperature  
- Fuel Level  

Protocol: ISO 15765-4 CAN

## UI

Built with [`LVGL Pro`](https://pro.lvgl.io/).

| Boot | Dashboard | Settings |
| ------ | ------- | ------- |
| ![Boot](lib/hud_ui/screenshots/boot.png?raw=true "boot") | ![Dashboard](lib/hud_ui/screenshots/dashboard.png?raw=true "dashboard") | ![Settings](lib/hud_ui/screenshots/settings.png?raw=true "settings") |


