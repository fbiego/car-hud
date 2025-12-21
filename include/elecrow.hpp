
#pragma once
#include <Arduino.h>
#include <Wire.h>


// ELECROW C3 I2C IO extender
#define PI4IO_I2C_ADDR 0x43

// Extended IO function
void init_IO_extender()
{
    Wire.beginTransmission(PI4IO_I2C_ADDR);
    Wire.write(0x01); // test register
    Wire.endTransmission();
    Wire.requestFrom(PI4IO_I2C_ADDR, 1);
    uint8_t rxdata = Wire.read();
    Serial.print("Device ID: ");
    Serial.println(rxdata, HEX);

    Wire.beginTransmission(PI4IO_I2C_ADDR);
    Wire.write(0x03);                                                 // IO direction register
    Wire.write((1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4)); // set pins 0, 1, 2 as outputs
    Wire.endTransmission();

    Wire.beginTransmission(PI4IO_I2C_ADDR);
    Wire.write(0x07);                                                    // Output Hi-Z register
    Wire.write(~((1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4))); // set pins 0, 1, 2 low
    Wire.endTransmission();
}

void set_pin_io(uint8_t pin_number, bool value)
{

    Wire.beginTransmission(PI4IO_I2C_ADDR);
    Wire.write(0x05); // test register
    Wire.endTransmission();
    Wire.requestFrom(PI4IO_I2C_ADDR, 1);
    uint8_t rxdata = Wire.read();
    Serial.print("Before the change: ");
    Serial.println(rxdata, HEX);

    Wire.beginTransmission(PI4IO_I2C_ADDR);
    Wire.write(0x05); // Output register

    if (!value)
        Wire.write((~(1 << pin_number)) & rxdata); // set pin low
    else
        Wire.write((1 << pin_number) | rxdata); // set pin high
    Wire.endTransmission();
}

void elecrow_c3_init()
{
    Wire.begin(4, 5);
    init_IO_extender();
    delay(100);
    set_pin_io(0, false);
    set_pin_io(2, true);
    set_pin_io(3, true);
    set_pin_io(4, true);
}
