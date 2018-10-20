#include "ultra_sen.h"
#include <Servo.h>
#include <math.h>
static Servo myservo;

/*-------------------------------------------------------*/
/* Function name: ultra_sen_pin_config                   */
/* Detail       : For set up infrd remote pin            */
/* Input        : -                                      */
/* Output       : -                                      */
/* Return       : -                                      */
/*-------------------------------------------------------*/
void ultra_sen_pin_config(void)
{
  pinMode(ULTRA_SEN_TRIG, INPUT);                      // Define the ultrasonic echo input pin
  pinMode(ULTRA_SEN_ECHO, OUTPUT);                     // Define the ultrasonic trigger input pin
  myservo.attach(ULTRA_SEN_SERVO);
}
/*--------------------------------------------------------*/
/* Function name: ultra_sen_dist_check                    */
/* Detail       : Check distance from input angle 0-180   */
/* Input        : serv_angle - Desire anagle to check dist*/
/* Output       : -                                       */
/* Return       : Distance in cm                          */
/*--------------------------------------------------------*/
float ultra_sen_dist_check(int serv_angle)
{
  float ret_dist = 0;
  static prev_angle = 0;
  
  prev_angle = serv_angle;
  myservo.write(serv_angle);
  delay( (abs(prev_angle - serv_angle)) * 50 )        // Wait serv reach that angle
  
  digitalWrite(ULTRA_SEN_TRIG, LOW);                   // set trig pin low 2?s
  delayMicroseconds(2);
  digitalWrite(ULTRA_SEN_TRIG, HIGH);                  // set trig pin 10?s , at last 10us 
  delayMicroseconds(10);
  digitalWrite(ULTRA_SEN_TRIG, LOW);                   // set trig pin low
  ret_dist = pulseIn(ULTRA_SEN_ECHO, HIGH);     // Read echo pin high level time(us)
  ret_dist= ret_dist / 58;        
  //Y m=(X s*344)/2
  //X s=( 2*Y m)/344 
  //X s=0.0058*Y m 
  //cm = us /58
  
  Serial.print("ultrasonic sensor distance:");               //output distance (Unit: cm)
  Serial.println(ret_dist);
  
  return ret_dist;
}