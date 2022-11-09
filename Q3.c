
#include <msp430.h>
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;                 // Stop WDT
    P1DIR |= BIT6 | BIT7;                     // P1.6 and P1.7 output
    P1SEL1 |= BIT6 | BIT7;                    // P1.6 and P1.7 options select
    PM5CTL0 &= ~LOCKLPM5;
    TB0CCR0 = 250;                         // PWM Period
    TB0CCTL1 = OUTMOD_7;                      // CCR1 reset/set
    TB0CCR1 = 50;                            // CCR1 PWM duty cycle
    TB0CCTL2 = OUTMOD_7;                      // CCR2 reset/set
    TB0CCR2 = 800;                            // CCR2 PWM duty cycle
    TB0CTL = TBSSEL__SMCLK | MC__UP | TBCLR;  // SMCLK, up mode, clear TBR
    while(1)
    {
        P1OUT ^= BIT6;// For debugger
    }
}







/*#include <msp430.h>
void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;
    P1DIR |= BIT0;                            // P1.0  output
    P1DIR |= BIT6 | BIT7;                     // P1.6 and P1.7 output
    P1SEL1 |= BIT6 | BIT7;                    // P1.6 and P1.7 options select
    //PWM Generator
    TB0CCR0 = 250;
    TB0CCTL1 = OUTMOD_7;
    TB0CCR1 = 200;
    TB0CTL = TBSSEL_1 + MC_1 + TBCLR;
    TB0CCTL0 |= CCIE;
    TB0CCTL1 |= CCIE;
    TB0CCTL0 &=~CCIFG;
    TB0CCTL1 &=~CCIFG;
    _enable_interrupts();
}
#pragma vector = TIMER0_B0_VECTOR       //define the interrupt service vector
__interrupt void ISR_TB0_CCR0 (void)    // interrupt service routine
    {
    P1OUT |=BIT0;
    TB0CCTL0 &=~CCIFG;
    P1OUT ^= BIT6;
    }
#pragma vector = TIMER0_B1_VECTOR
__interrupt void ISR_TB0_CCR1  (void) {
    P1OUT &=~BIT0;
    TB0CCTL1 &=~CCIFG;
    P1OUT ^= BIT6;
    }
*/
