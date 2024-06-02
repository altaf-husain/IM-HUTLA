# IM-HUTLA
![Logo IM-HUTLA](https://github.com/arutafusain/IM-HUTLA/assets/98148350/8e2c833c-b20a-46b9-9c62-37ff46338bb3)
# Early Detection Forest and Peatland Fire Patrol Robot Based on Internet of Things

This project involves the development of an early detection patrol robot for forest and peatland fires, utilizing Internet of Things (IoT) technology. The robot is designed as a tank that can traverse peatland and operate autonomously using a mission planner with an APM 2.8 controller. It is capable of detecting air temperature and humidity, as well as soil moisture, and sending this data to a website via ESP32. If the robot detects low soil moisture and high ambient temperature, it sends an alert signal for a potential fire hazard and marks the location. Additionally, if the robot loses control, it can be manually operated using a remote control, equipped with an FPV camera to monitor the surroundings.
<p align="center">
  <img src="https://github.com/arutafusain/IM-HUTLA/assets/98148350/15350168-41e8-42f3-9d2b-cc7b90c6d842" widht="400"/>
</p>
<p align="center">
  <img src="https://github.com/arutafusain/IM-HUTLA/assets/98148350/af9de26f-8cbe-4656-9ed7-ba7993c72d9e" widht="400"/>
</p>
you can visit the data website in link bellow : 
https://im-hutla.000webhostapp.com/

## Project Objectives

The primary objective of this project is to create an efficient and reliable system for early detection of forest and peatland fires, which can help in preventing large-scale fires by providing real-time data and alerts.

## Key Features

- **Autonomous Operation**: The robot operates autonomously using a mission planner controlled by APM 2.8.
- **Environmental Monitoring**: Equipped with sensors to measure air temperature, humidity, and soil moisture.
- **IoT Integration**: Sends real-time data to a website via ESP32 for monitoring and analysis.
- **Alert System**: Automatically sends an alert if low soil moisture and high temperature conditions are detected, indicating a potential fire hazard.
- **Manual Control**: Can be manually controlled using a remote control if it loses autonomous functionality.
- **FPV Camera**: Equipped with a First-Person View (FPV) camera to monitor the surroundings and assist in manual control.

## Technologies Used

- **Microcontroller**: ESP32
- **Controller**: APM 2.8 for autonomous navigation
- **Sensors**: 
  - Temperature and humidity sensor
  - Soil moisture sensor
- **Communication**: IoT data transmission via ESP32
- **Video Monitoring**: FPV camera for real-time visual feedback
- **Control**: Remote control for manual operation
- **Motor Driver**: Cytron MDD10A for controlling DC scooter motors with a 24-volt input
- **GPS Module**: M8N for navigation and location tracking
- **Radio Telemetry**: 433MHz for long-range communication

## Working Principle

1. **Autonomous Navigation**: The robot uses the mission planner and APM 2.8 for autonomous navigation across the peatland.
2. **Environmental Data Collection**: The robot collects data on air temperature, humidity, and soil moisture using its sensors.
3. **Data Transmission**: The collected data is sent to a website in real-time via the ESP32 module.
4. **Fire Hazard Detection**: If the robot detects conditions indicative of a potential fire (low soil moisture and high temperature), it sends an alert signal and marks the location.
5. **Manual Override**: If autonomous operation fails, the robot can be manually controlled using a remote, with the FPV camera providing visual feedback.

## Components Used

- **ESP32**: For IoT communication and data transmission.
- **APM 2.8**: For autonomous control and navigation.
- **Temperature and Humidity Sensor**: To monitor environmental conditions.
- **Soil Moisture Sensor**: To detect soil moisture levels.
- **FPV Camera**: For real-time visual monitoring.
- **Remote Control**: For manual operation of the robot.
- **DC Scooter Motors**: Powered by a 24-volt input.
- **Motor Driver**: Cytron MDD10A for controlling DC motors.
- **GPS Module**: M8N for navigation and location tracking.
- **Radio Telemetry**: 433MHz for long-range communication.
