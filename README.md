# Seven Segment Display

## Displaying Numbers 0-9

The individual segments of the seven-segment display are labelled 'a' to 'g'. Using a seven segment display, we can display the decimal digits 0-9 like so:

<img height="200" alt="image0" src="https://github.com/user-attachments/assets/1f0a866b-85b8-4f42-8091-5361f09630cb"/>
<img height="200" alt="image1" src="https://github.com/user-attachments/assets/c3ccc150-4fce-4d7a-bfbd-c03f84a2f4a7" />


Now we can write a truth table that indicates each digit's truth values for segments 'a' to 'g':
<img width="500" alt="image2" src="https://github.com/user-attachments/assets/98852c33-7981-433a-924c-b1ebf9d7aa72" />

(DP = Decimal Point display; we don't need this for our purposes, so we'll keep it as 0.)

Let's make some digits!

On my I/O board, I've connected input switches (S0 to S6) to segments 'a' to 'g' respectively (as well as S7 to DP). We can configure the switches according to the truth table above to display any digit:

<img width="180" alt="0" src="https://github.com/user-attachments/assets/78065385-211c-47cf-b68f-778a7f9795f1"/>
<img width="180" alt="1" src="https://github.com/user-attachments/assets/343809f9-c43b-42f5-8770-4f5fb3bae021"/>
<img width="180" alt="2" src="https://github.com/user-attachments/assets/c970329c-9e63-422b-876b-8e60d9aa7b51"/>
<img width="180" alt="3" src="https://github.com/user-attachments/assets/823acfbe-e965-4d33-b842-6b6ccb148f95"/>
<img width="180" alt="4" src="https://github.com/user-attachments/assets/ec9a5012-d362-4a18-beaa-ff741f7435ca"/>

<img width="180" alt="5" src="https://github.com/user-attachments/assets/b72ad0e5-7b9a-4279-aa3a-ee8400548f3a"/>
<img width="180" alt="6" src="https://github.com/user-attachments/assets/475fac8d-d27a-4023-a3b2-0600fda64f8c"/>
<img width="180" alt="7" src="https://github.com/user-attachments/assets/b19e998d-d971-4640-b63c-4ed90cef8da9"/>
<img width="180" alt="8" src="https://github.com/user-attachments/assets/84645e3c-38b6-4006-8937-046d37dacaa4"/>
<img width="180" alt="9" src="https://github.com/user-attachments/assets/1877ff79-e8c4-4133-b8db-b29729bf88aa"/>

Huzzah; we can display the digits 0-9. Though, the correspondence between input and digit is quite unintuitive.

What if we change the required input to have some semantic meaning? 

### Using a 4-bit Binary Input

Each digit from 0 to 9 corresponds to a 4-bit binary number (0000 to 1001). We will modify our display to take a 4-bit binary input from switches S0 (LSB) to S3 (MSB). Given the segment truth values that we found earlier, we can get the display value for each digit:

<img height="300" alt="image4" src="https://github.com/user-attachments/assets/cd005e23-833f-4bd8-965c-9454e1ac107f" />

To map each input to its output, I'm using the ATmega324A microchip. The microchip was programmed using `single_digit.c`, which does the following:

1. Set port C pins to be inputs and connect them to switches S0 to S3.
2. Set port A pins to be outputs and connect them to the seven-segment display.
3. Create a perpetual loop so that the microcontroller is always listening / handling events.
4. Mask out the upper bits of port C to read pins C0-C3, and hence obtain our 4-bit input.
5. If the digit is between 0-9 inclusive, output its corresponding seven segment value to port A to display the digit. Otherwise, output 0 to display nothing.
6. Repeat from Step 4.

<img width="180" alt="0" src="https://github.com/user-attachments/assets/50b9f41f-2d79-4cf6-9f78-1de746a818c2"/>
<img width="180" alt="1" src="https://github.com/user-attachments/assets/0a07bbcd-36ce-485e-9a64-d24fff06580c"/>
<img width="180" alt="2" src="https://github.com/user-attachments/assets/471a856f-f5dd-4170-b7a1-ecba67e4a526"/>
<img width="180" alt="3" src="https://github.com/user-attachments/assets/21df8d74-61b9-442f-ac7d-e5244655fffc"/>
<img width="180" alt="4" src="https://github.com/user-attachments/assets/27d2ba2d-0a1a-4f88-8560-5b348248882b"/>
<img width="180" alt="5" src="https://github.com/user-attachments/assets/e8506522-b745-4667-9020-f254906c9352"/>
<img width="180" alt="6" src="https://github.com/user-attachments/assets/ef7e815c-b949-4600-a72e-efb713063729"/>
<img width="180" alt="7" src="https://github.com/user-attachments/assets/4ccd0d3d-7584-4eec-90a5-bc9ba7fd44f9"/>
<img width="180" alt="8" src="https://github.com/user-attachments/assets/842e5e36-5194-44c3-9f0c-fbf7e022bce8"/>
<img width="180" alt="9" src="https://github.com/user-attachments/assets/687e0489-1fcd-4631-9f8b-f772fc1234ef"/>

Yippee! We can display single digits using a 4-digit binary input.

## Displayng Numbers 0 - 99

My I/O board has two seven-segment displays, but only one display can be illuminated at a time. Given this limitation, is it possible to display a two-digit number?

Yes, but technically no. What we can do is flick really fast between the two digits so that they appear to be simultaneously illuminated. 

### Using a 7-bit Binary Input

Since we are now displaying 0 to 99 (0000000 to 1100011), we need a 7-bit binary input; we will use switches S0-S6.
