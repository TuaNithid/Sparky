
/* Remote KEY */
#define INFRD_REM_KEY2 0x18                 //Key:2 
#define INFRD_REM_KEY8 0x52                 //Key:8 
#define INFRD_REM_KEY4 0x08                 //Key:4 
#define INFRD_REM_KEY6 0x5A                 //Key:6 
#define INFRD_REM_KEY1 0x0C                 //Key:1 
#define INFRD_REM_KEY3 0x5E                 //Key:3 
#define INFRD_REM_KEY5 0x1C                 //Key:5
#define INFRD_REM_SP_DOWN 0x07            	//Key:VOL-
#define INFRD_REM_SP_UP 0x15              	//Key:VOL+
#define INFRD_REM_SP_RE 0x09           		//Key:EQ
#define INFRD_REM_REPEAT 0xFF               //press and hold the key

/* PIN */
#define INFRD_REM_PIN 4

/* Function Prototype */
/*-------------------------------------------------------*/
/* Function name: infrd_remote_pin_config                */
/* Detail       : For set up infrd remote pin            */
/* Input        : -                                      */
/* Output       : -                                      */
/* Return       : -                                      */
/*-------------------------------------------------------*/
void infrd_remote_pin_config(void);

/*-------------------------------------------------------*/
/* Function name: infrd_remote_decode                    */
/* Detail       : Decode user command                    */
/* Input        : -                                      */
/* Output       : code -  User command                   */
/* Return       : User already command                   */
/*-------------------------------------------------------*/
char infrd_remote_decode(unsigned char * code);