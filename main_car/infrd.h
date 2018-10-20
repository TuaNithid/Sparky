
/* PIN */
#define INFRD_L_PIN 7
#define INFRD_R_PIN 8

/* ENUM */
enum INFRD_STATUS
{
    INFRD_NONE,
    INFRD_LEFT,
    INFRD_RIGHT,
    INFRD_BOTH,
	LAST
};

/* Function Prototype */
/*-------------------------------------------------------*/
/* Function name: infrd_pin_config                       */
/* Detail       : For set up infrd pin                   */
/* Input        : -                                      */
/* Output       : -                                      */
/* Return       : -                                      */
/*-------------------------------------------------------*/
void infrd_pin_config(void);
/*-------------------------------------------------------*/
/* Function name: infrd_check_obstacle                   */
/* Detail       : Checking for obstacle                  */
/* Input        : -                                      */
/* Output       : -                                      */
/* Return       : Position of obstacle                   */
/*-------------------------------------------------------*/
INFRD_STATUS infrd_check_obstacle(void);


