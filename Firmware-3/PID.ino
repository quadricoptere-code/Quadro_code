void PID()
{
  //etant donné que j'ai 4 moteurs j'ai fait les PID selon deux direction 
   //filtre de fluctuation
      fxa = xa*a+(fxa*(1.0 - a));
      fya = ya*a+(fya*(1.0 - a));
      fza = za*a+(fza*(1.0 - a));
      //roll pitch et yaw accelerometre;
      rollA = (atan2(fya,fza)*180.0)/M_PI;
      pitchA = (atan2(-fxa , sqrt(fya*fya + fza*fza))*180.0)/M_PI;
      yawA = 180.0*atan(fza/sqrt(fxa*fxa+fza*fza))/M_PI; 
      //croll pitch et yaw gyro;
      rollG = xg/131.0;
      pitchG = ya/131.0;

      
      previousTime = currentTime;
      currentTime = millis();
      deltaTime = (currentTime - previousTime)/1000;
      angleActuelX = (angleActuelX + rollG*deltaTime) + 0.2*rollA;
      angleActuelY = (angleActuelY + pitchG*deltaTime)+ 0.2*pitchA; 
      error1 = angleActuelY - angleEquilibre;
      error2 = angleActuelX - angleEquilibre;

      pid_p1 = kp*error1;
      pid_p2 = kp*error2;
      if(-3<error1<3)
      {
        pid_i1 = pid_i1 + (ki*error1);
      }
      if(-3<error2<3)
      {
        pid_i2 = pid_i2 + (ki*error2);
      }

      pid_d1 = kd*((error1 - previousError1)/deltaTime);
      pid_d2 = kd*((error2 - previousError2)/deltaTime);
      
      PID1 = pid_p1 + pid_i1 + pid_d1;
      PID2 = pid_p2 + pid_i2 + pid_d2;
      /*
       * --y-- *
      pwmM1 = PID1 + throttle;
      pwmM3 = PID1 - throttle;
      pwmM2 = PID1 + throttle;
      pwmM4 = PID1 - throttle;
        * --x-- *
      pwmM1 = PID2 - throttle;
      pwmM3 = PID2 + throttle;
      pwmM2 = PID2 - throttle;
      pwmM4 = PID2 + throttle;
      */
//j'établi la moyenne par rapport au deux PID pour obtenir des pwmM un peu plus proche de la réalité
      pwmM1 = ((PID1 + throttle)+(PID2 - throttle))/2;
      pwmM3 = ((PID1 - throttle)+(PID2 + throttle))/2;
      pwmM2 = ((PID1 + throttle)+(PID2 - throttle))/2;
      pwmM4 = ((PID1 - throttle)+(PID2 + throttle))/2;
      
  
      if(pwmM1<testLowSpeed)
      {
        pwmM1 = testLowSpeed;
      }
      if(pwmM1>testMaxSpeed)
      {
        pwmM1 = testMaxSpeed;
      }

       if(pwmM3<testLowSpeed)
      {
        pwmM3 = testLowSpeed;
      }
      if(pwmM3>testMaxSpeed)
      {
        pwmM3 = testMaxSpeed;
      }

       if(pwmM2<testLowSpeed)
      {
        pwmM2 = testLowSpeed;
      }
      if(pwmM2>testMaxSpeed)
      {
        pwmM2 = testMaxSpeed;
      }

       if(pwmM4<testLowSpeed)
      {
        pwmM4 = testLowSpeed;
      }
      if(pwmM4>testMaxSpeed)
      {
        pwmM4 = testMaxSpeed;
      }
    
     
}
