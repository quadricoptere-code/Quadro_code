
void Decollage()
{
  if(hcsr04.ping_cm() != 0)
  {
    Serial.println("déjas décolé");
  }
  else
  {
    while(hcsr04.ping_cm() != 100)
    {
        rpmSynchroneAll(brushlessMotor1_1,brushlessMotor2_2,brushlessMotor3_3,brushlessMotor4_4,0,1);
    }
  }
  
}

void Atterissage()
{
    if(hcsr04.ping_cm() == 0)
    {
      Serial.println("au sol");  
    }
    else
    {
      while(hcsr04.ping_cm() != 0)
      {
        egalizeAll(brushlessMotor1_1,brushlessMotor2_2,brushlessMotor3_3,brushlessMotor4_4,0);
      }
    }
}

void Stationnaire()
{
  if(hcsr04.ping_cm() == 0)
  {
    Decollage();
  }
  else
  {
    IMU.readGyroscope(x,y,z);
    IMU.readAcceleration(xa,ya,za);
    
  }
}
