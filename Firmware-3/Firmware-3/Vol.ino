
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
        PID();
        brushlessMotor1_1.writeMicroseconds(++pwmM1);
        brushlessMotor2_2.writeMicroseconds(++pwmM2);
        brushlessMotor3_3.writeMicroseconds(++pwmM3);
        brushlessMotor4_4.writeMicroseconds(++pwmM4);
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
        PID();
        brushlessMotor1_1.writeMicroseconds(--pwmM1);
        brushlessMotor2_2.writeMicroseconds(--pwmM2);
        brushlessMotor3_3.writeMicroseconds(--pwmM3);
        brushlessMotor4_4.writeMicroseconds(--pwmM4);
      }
    }
}

void Stationnaire()
{
  if(hcsr04.ping_cm() == 0)
  {
    Decollage();
    PID();
    brushlessMotor1_1.writeMicroseconds(pwmM1);
    brushlessMotor2_2.writeMicroseconds(pwmM2);
    brushlessMotor3_3.writeMicroseconds(pwmM3);
    brushlessMotor4_4.writeMicroseconds(pwmM4);
  }
  else
  {
    
    PID();
    brushlessMotor1_1.writeMicroseconds(pwmM1);
    brushlessMotor2_2.writeMicroseconds(pwmM2);
    brushlessMotor3_3.writeMicroseconds(pwmM3);
    brushlessMotor4_4.writeMicroseconds(pwmM4);
    
  }
}
