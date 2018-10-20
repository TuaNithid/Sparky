
/* PIN */
#define ULTRA_SEN_TRIG 11
#define ULTRA_SEN_ECHO 12
#define ULTRA_SEN_SERVO 9

/* Function Prototype */
/*-------------------------------------------------------*/
/* Function name: ultra_sen_pin_config                   */
/* Detail       : For set up infrd remote pin            */
/* Input        : -                                      */
/* Output       : -                                      */
/* Return       : -                                      */
/*-------------------------------------------------------*/
void ultra_sen_pin_config(void);

/*--------------------------------------------------------*/
/* Function name: ultra_sen_dist_check                    */
/* Detail       : Check distance from input angle 0-180   */
/* Input        : serv_angle - Desire anagle to check dist*/
/* Output       : -                                       */
/* Return       : Distance in cm                          */
/*--------------------------------------------------------*/
float ultra_sen_dist_check(int serv_angle);

