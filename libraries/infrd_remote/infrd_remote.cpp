#include "Arduino.h"
#include "infrd_remote.h"

/*-------------------------------------------------------*/
/* Function name: infrd_remote_pin_config                */
/* Detail       : For set up infrd remote pin            */
/* Input        : -                                      */
/* Output       : -                                      */
/* Return       : -                                      */
/*-------------------------------------------------------*/
void infrd_remote_pin_config(void)
{
  pinMode(INFRD_REM_PIN, INPUT);
}


/*-------------------------------------------------------*/
/* Function name: infrd_remote_decode                    */
/* Detail       : Decode user command                    */
/* Input        : -                                      */
/* Output       : code -  User command                   */
/* Return       : User already command                   */
/*-------------------------------------------------------*/
char infrd_remote_decode(unsigned char * code)
{
  char flag = 0;
  unsigned int count = 0;
  unsigned char i, index, cnt = 0, data[4] = {0, 0, 0, 0};
  unsigned char t[30];
  
  if (digitalRead(INFRD_REM_PIN) == LOW)
  {
    count = 0;
    while (digitalRead(INFRD_REM_PIN) == LOW && count++ < 200)  //9ms
      delayMicroseconds(60);
    t[0] = count;
    count = 0;
    while (digitalRead(INFRD_REM_PIN) == HIGH && count++ < 80)   //4.5ms
      delayMicroseconds(60);
    t[1] = count;
    for (i = 0; i < 32; i++)
    {
      count = 0;
      while (digitalRead(INFRD_REM_PIN) == LOW && count++ < 15) //0.56ms
        delayMicroseconds(60);
      count = 0;
      while (digitalRead(INFRD_REM_PIN) == HIGH && count++ < 40) //0: 0.56ms; 1: 1.69ms
        delayMicroseconds(60);
      if (count > 20)data[index] |= (1 << cnt);
      if (cnt == 7)
      {
        cnt = 0;
        index++;
      }
      else cnt++;
    }
    if (data[0] + data[1] == 0xFF && data[2] + data[3] == 0xFF) //check
    {
      code[0] = data[2];
      Serial.println(code[0], HEX);
      flag = 1;
    }
    if (data[0] == 0xFF && data[1] == 0xFF && data[2] == 0xFF && data[3] == 0xFF)
    {
      code[0] = 0xFF;
      Serial.println("Repeat");
      flag = 1;
    }
  }
  return flag;

}
