/*
  les fonctions ici presentent serve à augmenter ou à reduire de façon synchroniser les tours par minutes des moteurs
*/




void rpmSynchroneDuo(Servo moteur1 , Servo moteur2, int speed , int indice)
{
  if(indice == 1)
  {
    moteur1.writeMicroseconds(speed++);
    moteur2.writeMicroseconds(speed++);
  }
  else if(indice == 0)
  {
    moteur1.writeMicroseconds(speed--);
    moteur2.writeMicroseconds(speed--);
  }
}

void rpmSynchroneTrio(Servo moteur1 , Servo moteur2, Servo moteur3, int speed , int indice)
{
  if(indice == 1)
  {
    moteur1.writeMicroseconds(speed++);
    moteur2.writeMicroseconds(speed++);
    moteur3.writeMicroseconds(speed++);
  }
  else if(indice == 0)
  {
    moteur1.writeMicroseconds(speed--);
    moteur2.writeMicroseconds(speed--);
    moteur3.writeMicroseconds(speed--);
  }
  
}

void rpmSynchroneAll(Servo moteur1 , Servo moteur2 , Servo moteur3 , Servo moteur4 , int speed , int indice)
{
  if(indice == 1)
  {
    moteur1.writeMicroseconds(speed++);
    moteur2.writeMicroseconds(speed++);
    moteur3.writeMicroseconds(speed++);
    moteur4.writeMicroseconds(speed++);
  }
  else if(indice == 0)
  {
    moteur1.writeMicroseconds(speed--);
    moteur2.writeMicroseconds(speed--);
    moteur3.writeMicroseconds(speed--);
    moteur4.writeMicroseconds(speed--);
  }
  
}
