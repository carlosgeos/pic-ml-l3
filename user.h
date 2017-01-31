/******************************************************************************/
/* User Level #define Macros                                                  */
/******************************************************************************/

/* TODO Application specific user parameters used in user.c may go here */
#define _XTAL_FREQ 32000000

#define on_state 15
#define off_state 9

#define long_seq_length 2000
#define short_seq_length 500

#define led LATAbits.LATA4

/******************************************************************************/
/* User Function Prototypes                                                   */
/******************************************************************************/

/* TODO User level functions prototypes (i.e. InitApp) go here */

void InitApp(void);         /* I/O and Peripheral Initialization */

void send_long_seq(void);

void send_short_seq(void);

void send_command(void);

void send_shutter_release(void);