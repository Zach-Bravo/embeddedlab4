#include <msp430.h>
int main(void)
{
    WDTCTL = WDT_ADLY_250; //Defines Period
    P6OUT &= ~BIT6;
    P6DIR |= BIT6; // Output P6.6
    PM5CTL0 &= ~LOCKLPM5; //Low Impedance Mode
    SFRIE1 |= WDTIE; //
    _enable_interrupts(); //Enables Interrupt Function Whenever 250ms Reached
    while (1);
    }
    #pragma vector=WDT_VECTOR
    __interrupt void wdtled(void)
    {
            P6OUT^=BIT6;
    }
