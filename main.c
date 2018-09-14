/* 
 * File:   main.c
 * Author: shiso
 *
 * Created on 2018/09/07, 13:53
 */

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <pic10F222.h>

// PIC10F222 Configuration Bit Settings
#pragma config IOSCFS = 4MHZ    // Internal Oscillator Frequency Select bit (4 MHz)
#pragma config MCPU = OFF       // Master Clear Pull-up Enable bit (Pull-up disabled)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config CP = OFF         // Code protection bit (Code protection off)
#pragma config MCLRE = OFF      // GP3/MCLR Pin Function Select bit (GP3/MCLR pin function is digital I/O, MCLR internally tied to VDD)

#define _XTAL_FREQ 4000000

// File->Project Propaties->PIC kit3->Option catgories->Power->Power target~->chack
int main(void) {
    ADCON0bits.ANS0 = 0;    //GP0 digital I/O
    ADCON0bits.ANS1 = 0;    //GP1 digital I/O
    OSCCALbits.FOSC4 = 0;   //GP2/T0CKI applied to GP2
    OPTION = 0b00000000;    //wakeup pullup
    TRISGPIO = 0b00000000;  //All for Output
    
     while(1){
        GP0 = 1;
        __delay_us(1);
        GP0 = 0;
        __delay_us(1);
     }
}

