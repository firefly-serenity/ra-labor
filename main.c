/*
 First PIC32MM program
 
 This simple example program lets LED1 blink
 */

#include <stdint.h>
#include <xc.h>

void SYSTEM_Initialize(void);

const int pinnumber = 4;

void setup() { 
	SYSTEM_Initialize();  // set 24 MHz clock for CPU and Peripheral Bus
                          // clock period = 41,667 ns = 0,0417 us
	TRISDCLR = 1<<pinnumber;     // set bit 3 of Port D for output
    TRISBSET = 1<<9; // set input RB9 or button s1
}

void loop() { 
	int i;
    int alt_s1_state = 0;
    int new_s1_state = 0;
	while(1) {
        new_s1_state = !(PORTB & 1<<9);
        if(new_s1_state && !alt_s1_state){
            LATDINV = 1<<pinnumber;       // set bit 3 of Port D
        }
        alt_s1_state = new_s1_state;
    }
}

int main(void) {
    setup();
    loop();
}