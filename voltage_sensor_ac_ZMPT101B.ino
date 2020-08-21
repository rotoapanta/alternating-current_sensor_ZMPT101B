/******************************************************************************************************
  voltaje_sensor_ac_ZMPT101B.ino
  Measure ac power with the ZMPT101B sensor.
  Version: 1.0
  Fecha: 20/08/2020
  Autor: Roberto Toapanta, @rotoapanta
  © 2017-2020 ToGuBrain Solutions
*******************************************************************************************************
/*
El Sketch usa 3502 bytes (10%) del espacio de almacenamiento de programa. El máximo es 32256 bytes.
Las variables Globales usan 200 bytes (9%) de la memoria dinámica, dejando 1848 bytes para las variables locales. El máximo es 2048 bytes.

Wiring diagram

Arduino Pin                       ZMPT101B Sensor
5V  -----------------------------   (+)
GND -----------------------------   (-)
AN0 -----------------------------   OUT
*/

#include <ZMPT101B.h>

#define FIRMWARE_VERSION "1.0"
const float A_CALIBRATION = 2.35;
const float B_CALIBRATION = -1.90;

ZMPT101B voltageSensor(A0,60);                          // ZMPT101B sensor connected to A0 pin of arduino

void setup(){
//  #if DEBUG == true
  Serial.begin(9600);
//  #endif 
  Serial.println("Booting");
  Serial.print("--Firmware Version:");
  Serial.println(FIRMWARE_VERSION);
  
//  Serial.begin(9600);
  // calibrate() method calibrates zero point of sensor,
  // It is not necessary, but may positively affect the accuracy
  // Ensure that no current flows through the sensor at this moment
/*  Serial.println("Calibrating... Ensure that no current flows through the sensor at this moment");
  delay(100);
  voltageSensor.calibrate(120);
  Serial.println("Done!");*/
  voltageSensor.set_a_b(A_CALIBRATION, B_CALIBRATION);
}

void loop() {
  // To measure voltage/current we need to know the frequency of voltage/current
  // By default 60Hz is used, but you can specify desired frequency
  // as first argument to getVoltageAC method, if necessary
  float V = voltageSensor.get_ac();
  Serial.println(String("V = ") + V + " V");
  delay(1000);
}
