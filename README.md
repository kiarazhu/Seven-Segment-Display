# Seven-Segment-Display

## Displaying Numbers 0-9

The individual segments of the display are labelled 'a' to 'g' as follows:

<img width="200" alt="image0" src="https://github.com/user-attachments/assets/1f0a866b-85b8-4f42-8091-5361f09630cb"/>

Using a seven segment display, we can display the decimal digits 0-9 like so:
<img width="800" alt="image1" src="https://github.com/user-attachments/assets/c93af443-7bce-458d-be98-0189bbff12ac" />

Now we can write a truth table that indicates each digit's truth values for segments 'a' to 'g':
<img width="500" alt="image2" src="https://github.com/user-attachments/assets/98852c33-7981-433a-924c-b1ebf9d7aa72" />

(DP = Decimal Point display; we don't need this today, so we'll keep it as 0.)

Let's make some digits!

Here, I've connected input switches (S0 to S6) to segments 'a' to 'g' respectively (as well as S7 to DP). We can configure the switches according to the truth table above to display any digit:

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

Huzzah; we can display the digits 0-9. Though, the correspondence between input and digit is quite unintuitive, and I doubt the user has the time to create a truth table.

What if we change the required input to have some semantic meaning? 

### Using a 4-bit Binary Input


<img width="214" alt="image3" src="https://github.com/user-attachments/assets/f596812f-d8d6-4702-83be-33224323a68e"/>


## Displayng Numbers 0 - 99

My I/O board has two seven-segment displays, but only one display can be illuminated at a time. With this limitation, is it possible to display a two-digit number?

Yes, but technically no; we can flick really fast between the two digits so that both appear to be simultaneously illuminated. 

### Using a 7-bit Binary Input

Since 99 in binary is 0b1100011, we need a 7-bit binary input (we are using switches S0-S6 to determine the number to dispay, so 7 is the perfect number of bits!).
