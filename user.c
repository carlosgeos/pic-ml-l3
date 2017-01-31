/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#include "user.h"

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.> */

void InitApp(void)
{
    /* TODO Initialize User Ports/Peripherals/Project here */

    /* Setup analog functionality and port direction */
    /* Initialize peripherals */
    // Obligatorio, sin esto no funciona nada
    
    TRISA4 = 0; // modo del pin RA4
    TRISA2 = 1;
    ANSELA = 0;           // leer aquí abajo:
    //    The  ANSELA  bits  default  to  the  Analog
    //    mode  after  Reset.  To  use  any  pins  as
    //    digital   general   purpose   or   peripheral
    //    inputs,   the   corresponding   ANSEL   bits
    //    must be initialized to ?0? by user software.

    // Extra power consumption reduction:
    VREGPM = 1;
    
    /* Enable interrupts */
    GIE = 1;
    //PEIE = 1; // no es necesario pero puede servir...
    INTE = 1;
  
    INTEDG = 1; // rising edge
}

void send_long_seq(void) 
{
    for (int i = 0; i < long_seq_length / (on_state + off_state); ++i) {
        led = 1;
        __delay_us(on_state);
        led = 0;
        __delay_us(off_state);
    }
}

void send_short_seq(void) {
    for (int i = 0; i < short_seq_length / (on_state + off_state); ++i) {
        led = 1;
        __delay_us(on_state);
        led = 0;
        __delay_us(off_state);
    }
}

void send_command(void) {
    // Nikon specific timings
    send_long_seq();
    __delay_us(27800);
    send_short_seq();
    __delay_us(1500);
    send_short_seq();
    __delay_us(3500);
    send_short_seq();
}

void send_shutter_release(void) {
    // Two commands separated by 63 ms
    send_command();
    __delay_ms(63);
    send_command();
}
