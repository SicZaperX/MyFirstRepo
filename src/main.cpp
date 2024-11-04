#include <Arduino.h>
#include "SparkFun_AS7265X.h"

AS7265X sensor;

#include <Wire.h>

void setup()
{
  Serial.begin(115200);
  Serial.println("AS7265x Spectral Triad Example");
  if (sensor.begin() == false)
  {
    Serial.println("Sensor does not appear to be connected. Please check wiring. Freezing...");
    while (1)
      ;
  }

  //Once the sensor is started we can increase the I2C speed
  Wire.setClock(400000);

  sensor.disableIndicator();

  Serial.println("A,B,C,D,E,F,G,H,R,I,S,J,T,U,V,W,K,L");
}

void loop()
{
  sensor.takeMeasurements(); //This is a hard wait while all 18 channels are measured

  Serial.print(sensor.getA()); //410nm
  Serial.print(",");
  Serial.print(sensor.getB()); //435nm
  Serial.print(",");
  Serial.print(sensor.getC()); //460nm
  Serial.print(",");
  Serial.print(sensor.getD()); //485nm
  Serial.print(",");
  Serial.print(sensor.getE()); //510nm
  Serial.print(",");
  Serial.print(sensor.getF()); //535nm
  Serial.print(",");

  Serial.print(sensor.getG()); //560nm
  Serial.print(",");
  Serial.print(sensor.getH()); //585nm
  Serial.print(",");
  Serial.print(sensor.getR()); //610nm
  Serial.print(",");
  Serial.print(sensor.getI()); //645nm
  Serial.print(",");
  Serial.print(sensor.getS()); //680nm
  Serial.print(",");
  Serial.print(sensor.getJ()); //705nm
  Serial.print(",");

  Serial.print(sensor.getT()); //730nm
  Serial.print(",");
  Serial.print(sensor.getU()); //760nm
  Serial.print(",");
  Serial.print(sensor.getV()); //810nm
  Serial.print(",");
  Serial.print(sensor.getW()); //860nm
  Serial.print(",");
  Serial.print(sensor.getK()); //900nm
  Serial.print(",");
  Serial.print(sensor.getL()); //940nm
  Serial.print(",");

  Serial.println();
}