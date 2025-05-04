#include <avr/io.h>

// Seven segment display values for digits 0 to 9
uint8_t seven_seg[10] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 111};

int main(void) {
	// Set port C pins to be inputs
	DDRC = 0x00;    // Default value; can omit
	
	// Set port A pins to be outputs
	DDRA = 0xFF;

	uint8_t input;
	
	while(1) {
		input = PINC & 0x0F;    // Read pins C0-C3 via bitmasking
		
		if (digit < 10) {
			PORTA = seven_seg[digit];    // Display the digit
			} else {
			PORTA = 0;    // Display nothing
		}
	}
}
