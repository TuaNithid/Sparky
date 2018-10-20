#include <Servo.h>
#include "infrd.h"
#include "infrd_remote.h"
#include "Arduino.h"
#include "ultra_sen.h"
#include <AlphaBot.h>

static AlphaBot alpha_car = AlphaBot();
static int push_delay = 0;
static INFRD_STATUS infrd_check = INFRD_NONE;
static unsigned char code = 0;
static int serv_angle = 0;
void main_control_car (unsigned char code)
{
  if(infrd_check != INFRD_NONE)
  {
//    if(code == INFRD_REM_KEY1 || code == INFRD_REM_KEY2 ||
//       code == INFRD_REM_KEY3 ||
//       code == INFRD_REM_KEY4 ||
//       code == INFRD_REM_KEY6
//       )
//    {
//      return;     
//    }
       
  }
  push_delay = millis();
  switch (code)
  {
    case INFRD_REM_KEY1:
      alpha_car.LeftCircle();
      Serial.println("KEY1");
      break;

    case INFRD_REM_KEY2:
      alpha_car.Forward();
      Serial.println("KEY2");
      break;

    case INFRD_REM_KEY3:
      alpha_car.RightCircle();
      Serial.println("KEY3");
      break;

    case INFRD_REM_KEY4:
      alpha_car.Left();
      Serial.println("KEY4");
      break;

    case INFRD_REM_KEY5:
      alpha_car.Brake();
      Serial.println("KEY5");
      break;

    case INFRD_REM_KEY6:
      alpha_car.Right();
      Serial.println("KEY6");
      break;

    case INFRD_REM_KEY8:
      alpha_car.Backward();
      Serial.println("KEY8");
      break;
      
    case INFRD_REM_SP_DOWN:
      if(serv_angle>0)
      {
        serv_angle = serv_angle - 10;
      }
      Serial.println("INFRD_REM_SP_DOWN");
      break;

    case INFRD_REM_SP_UP:
      if(serv_angle<180)
      {
        serv_angle = serv_angle+10;
      }
      Serial.println("INFRD_REM_SP_UP");
      break;
    case INFRD_REM_REPEAT:
      break;

    default:
      alpha_car.Brake();
  }// End Case
}
void main_infrd_remote_step(void)
{
  char infrd_remote_check = 0;
  infrd_remote_check = infrd_remote_decode(&code);
  
  if(infrd_remote_check)
  {
    main_control_car(code);
  }
  
  if(millis() - push_delay > 200)
  {
    alpha_car.Brake();
  }
}

void main_infrd_step(void)
{
  infrd_check = infrd_check_obstacle();
}
void main_ultra_sen(void)
{
  float ultra_dist = 0;
  ultra_dist = ultra_sen_dist_check(serv_angle);
  
}
void setup()
{
  Serial.begin(115200);
  infrd_pin_config();
  infrd_remote_pin_config();
  ultra_sen_pin_config();
  alpha_car.SetSpeed(150);
  Serial.println("DONE SETUP");
}
int i=0;
void loop()
{  
  
  main_infrd_remote_step();
  main_infrd_step();
  main_ultra_sen();
  
}




