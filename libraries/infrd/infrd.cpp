#include "Arduino.h"
#include "infrd.h"

static int infrd_l_sensor = 0;
static int infrd_r_sensor = 0;

/* Function Prototype */
/*-------------------------------------------------------*/
/* Function name: infrd_pin_config                       */
/* Detail       : For set up infrd pin                   */
/* Input        : -                                      */
/* Output       : -                                      */
/* Return       : -                                      */
/*-------------------------------------------------------*/
void infrd_pin_config(void)
{
  pinMode(INFRD_R_PIN, INPUT);   //Define the input pin of Right Infrared Proximity Sensor
  pinMode(INFRD_L_PIN, INPUT);   //Define the input pin of Left Infrared Proximity Sensor
}
/*-------------------------------------------------------*/
/* Function name: infrd_check_obstacle                   */
/* Detail       : Checking for obstacle                  */
/* Input        : -                                      */
/* Output       : -                                      */
/* Return       : Position of obstacle                   */
/*-------------------------------------------------------*/
INFRD_STATUS infrd_check_obstacle(void)
{
  INFRD_STATUS infrd_ret;

  infrd_r_sensor = digitalRead(INFRD_R_PIN);            //LOW means signal, HIGH means no signal 
  infrd_l_sensor = digitalRead(INFRD_L_PIN);            //LOW means signal, HIGH means no signal 	

  if (infrd_r_sensor == LOW && infrd_l_sensor == LOW)       //Obstacle in right and left
    infrd_ret = INFRD_BOTH;                             
  else if (infrd_l_sensor == HIGH && infrd_r_sensor == LOW)   //Obstacle in right
    infrd_ret = INFRD_RIGHT;
  else if (infrd_r_sensor == HIGH && infrd_l_sensor == LOW)   //Obstacle in left	
    infrd_ret = INFRD_LEFT;
  else
    infrd_ret = INFRD_NONE;
  return infrd_ret;
}

