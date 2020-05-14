/*
  ces fonctions servent à égalisées si nécéssaire le nombre de rotations par minutes de moteurs passé en parametre 
*/

void egalizeDuo(Servo moteur1 , Servo moteur2 , int rpm_value)
{
  if(moteur1.read() == moteur2.read() && moteur1.read() == rpm_value)
  {}
  else if(moteur1.read() == moteur2.read() && moteur1.read() != rpm_value)
  {
    if(moteur1.read() < rpm_value){rpmSynchroneDuo(moteur1 , moteur2 , rpm_value , 1);}
    else{rpmSynchroneDuo(moteur1 , moteur2 , rpm_value , 0);}
  }
  else
  {
    while(moteur1.read() != rpm_value)
    {
      int speed1 = moteur1.read();
      if(moteur2.read() > rpm_value){moteur1.writeMicroseconds(speed1--);}
      else{moteur1.writeMicroseconds(speed1++);}
    }

    while(moteur2.read() != rpm_value)
    {
      int speed2 = moteur2.read();
      if(moteur2.read() > rpm_value){moteur2.writeMicroseconds(speed2--);}
      else{moteur1.writeMicroseconds(speed2++);}
    }
    
  }

  
}

void egalizeTrio(Servo moteur1 , Servo moteur2 , Servo moteur3 , int rpm_value)
{
  egalizeDuo(moteur1 , moteur2 , rpm_value);
  egalizeDuo(moteur2 , moteur3 , rpm_value);
}

void egalizeAll(Servo moteur1 , Servo moteur2 , Servo moteur3 , Servo moteur4 , int rpm_value)
{
  egalizeDuo(moteur1 , moteur2 , rpm_value);
  egalizeDuo(moteur3 , moteur4 , rpm_value);
}
