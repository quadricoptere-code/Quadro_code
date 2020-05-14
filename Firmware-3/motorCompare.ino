/*
  les fonction ici presentent on pour unique but de verifier si des moteurs passé en parametre tourne à la meme vitesse elles retourne 1 si oui et 0 si non
  les decisions suivantes peuvent etre prisent apres leur appelle.
*/

//Compare la vitesse de rotation de tous les moteurs
int motorCompareAll(Servo moteur1 , Servo moteur2 , Servo moteur3 , Servo moteur4)
{
    float actualSpeed1 = moteur1.read();
    float actualSpeed2 = moteur2.read();
    float actualSpeed3 = moteur3.read();
    float actualSpeed4 = moteur4.read();
    if(actualSpeed1 == actualSpeed4 && actualSpeed2 == actualSpeed3 && actualSpeed1 == actualSpeed2 && actualSpeed3 == actualSpeed4)
    {  
      return 1;
    }
    else
    {
      return 0;
    }
}  



// Compare la vitesse de rotation de deux moteurs passés en parametre
int motorCompareDuo(Servo moteur1, Servo moteur2)
{
    float actualSpeed1 = moteur1.read();
    float actualSpeed2 = moteur2.read();
    if(actualSpeed1 == actualSpeed2)
    {
      return 1;
    }
    else
    {
      return 0;
    }
    
}  



// Compare la vitesse de rotation de trois moteurs passés en parametre
int motorCompareTrio(Servo moteur1, Servo moteur2 , Servo moteur3)
{
    float actualSpeed1 = moteur1.read();
    float actualSpeed2 = moteur2.read();
    float actualSpeed3 = moteur3.read();
    if(actualSpeed1 == actualSpeed3 && actualSpeed2 == actualSpeed3 && actualSpeed1 == actualSpeed2)
    {
      return 1;   
    }
    else
    {
      return 0;
    }
    
}  
 
