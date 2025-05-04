#include <avr/io.h>
#include <util/delay.h>

// Seven segment display values for digits 0 to 9
uint8_t seven_seg[10] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 111};

int main(void) {
	// Set port C pins to be inputs
	DDRC = 0x00;    // Default value; can omit

	// Set port A pins to be outputs
	DDRA = 0xFF;

	// Set pin D0 to be an output
	DDRD = 0x01;

	uint8_t input, units, tens;

	while (1) {
		input = PINC & 0x7F;  // Read pins C0-C6 via bitmasking

		if (input < 100) {
			
			units = input % 10;
			tens = input / 10;

			// Display units digit
			PORTA = seven_seg[units];
			PORTD = 0x00;    // Set pin D0 to low
			_delay_ms(5);
			
			// Display tens digit
			PORTA = seven_seg[tens];
			PORTD = 0x01;    // Set pin D0 to high
			_delay_ms(5);
			
			} else {
			PORTA = 0;    // Turn off display
			PORTD = 0x00;    // Turn off signal
		}
	}
}
