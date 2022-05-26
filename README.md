# SOS in Assembly

Purpose:	The Purpose of this project is use Assembly programs which will be embedded into the Arduino C environment but also to be introduced to doing an input and an output from the Arduino board.  The input will be a switch to start the program with a pull-up or pull-down resistor and the output will drive an LED blinking an SOS in Morse Code.  It looks like it will be complicated, but you are given clues every step of the way. And you can use the previous lab delay function and R16 for the different delay times.

# Background
In the time of the telegram and radio telegraphy, before and even after voice was encoded, the means of communication was with a ‘tapper’ or a fancy looking switch, using Morse Code, whereby the sender could tap out a message using long and short durations or ‘taps’.   On the receiving end would be a relay or a tone which would repeat the taps so one could hear it and translate it back into words.  In Morse code, the letter S is encoded with 3 short dots or durations and the O is encoded with three long dashes or durations.  The Morse code for mayday or help is SOS which looks like …---…  …---… and so on.  

This lab will send SOS in Morse code to an LED when a switch is on and it will stop after sending the complete SOS when the switch is off.

![Picture1](https://user-images.githubusercontent.com/102126445/166611452-61959e7d-7a2e-40f6-9344-d6f30e59cfe7.png)

Here is an example of what it should sound like:
https://www.youtube.com/watch?v=Zsb7stKelq4

Creating an input for a switch.
Such a seemingly simple operation requires some thought when doing it on a microprocessor.  
1.	You have to select the pin which relates to a PORTx, and a bitx, 
2.	set it up to be an input, 
3.	then read that pin in the program and process it as a value depending on what bit it is on 
4.	then decide what you want to do afterwards based on its value

Here are some general steps to make an input:
1.	Determine or select the input pin you will use.   Do not use I/O pins 0 or 1.
2.	Find the DDR register associated with it
3.	Using CBI to clear the DDR register bit for the associated PORT pin to an input.
4.	The PORT pin is now configured and ready to be used by your program.
5.	Read the input and make a decision.

Reference the AVR datasheet section 14 about I/O ports.  Note below the hardware for one I/O pin in the AVR.  
![Picture2](https://user-images.githubusercontent.com/102126445/166611756-21192677-3de8-44b6-bbd2-0382e94cf992.png)

Internal hardware for an I/O pin in the AVR

All this hardware is required to be able to configure the pin as an input or an output, plus some other features like internal pullup resistors, sleep modes and synchronization with the clock.  Clearly, I/O pins are not simple but we will only be concerned for this lab with a simple input or output. For this we need the DDR register and the Port for the input or output that we will be using.

Previously we saw how outputs were configured for the LED on PORTB bit 5 to blink.  
1.	The data direction register, DDR, in the program had to setup register 4, bit 5 to a 1 so bit 5 of PORTB could be an output.  
2.	Register 4 is the DDR for PORTB which means it defines each bit to be an input or an output.  
3.	Section 14.4 in the AVR datasheet is a list of all these registers.

You can select any port pin that is available for this on your Arduino but then you must determine its port and bit.  

# Input and Output (I/O)
Output:
PORTB, register 5, bit 5, is used internally for the LED and is also brought out to a connector (pin 13 on the UNO) but do not use it externally-it does not have enough current capability to drive two LEDs.  
•	Suggestion: Use PORTB, register 5 bit 4 (pin 12 on the UNO) for the output

Input:
There are many other choices you can use (except do not use I/O pins 0 or 1 as those are needed to communicate with the computer).
•	Suggestion: PORTB, register 5 bit 3 (pin 11 on the UNO) can be used as an input.

![Picture3](https://user-images.githubusercontent.com/102126445/166611875-3ced6d4c-71ec-4656-a313-7e534eb0b007.png)

Typical setup: You choose the pins for the input and output.

![Screenshot 2022-05-03 183318](https://user-images.githubusercontent.com/102126445/166612255-bc4fb495-f873-4c83-946d-2dd4d4bfa497.png)

Reading an input:
To read an input knowing the port, you would use the IN instruction shown below and the pins address for the port that you are using.  For instance, to read the PORTB, bit 4 (pin 18 of UNO) you would use this instruction to read the port.

Loop:

IN r17, 0x03;    //read PORTB pins into register 17		

Now you need to pick out bit 4 by ANDing it with 0x10 to mask out all the other bits.  After this it depends on your input configuration and whether you are using a pull-up or a pull-down.  Here we are using a pulldown resistor.

If you are using a Pull-up resistor, the switch closure will result in a 0 otherwise it is a 1, so you can do the AND instruction and then branch if it is zero.

ANDI    r17, 0x08;     //AND r17 with 08h

BRNE   start;     //if the switch is not closed (i.e. 1) then go back and loop

If using a pull-down resistor the switch closure will result in a 1 otherwise it is a 0:

ANDI    r17, 0x08;     //AND r16 with 08h

BREQ   start;     //if the switch is not closed (i.e. 0) then go back and loop

![111](https://user-images.githubusercontent.com/102126445/170409460-ddb7ceb9-c406-48a1-baf9-7a44fd436dfc.png)
![222](https://user-images.githubusercontent.com/102126445/170409462-38daa07d-05ba-40de-8558-eff2ba177da0.png)
![333](https://user-images.githubusercontent.com/102126445/170409464-c54bde33-1e0b-4e1e-a812-5b5ab819f61a.png)

# Creating an output.
Creating an output is very similar to creating an input.  You have to set the port pin to be an output.  Then you can use the CBI or SBI to make it a zero or a one.

Here are some general steps to make an output:
1.	Determine or select the output pin you will use.  Do not use I/O pins 0 or 1 which are reserved for TX and RX.
2.	Find the DDR register associated with it.
3.	Using SBI to set the DDR register bit for the associated PORT pin to an output.
4.	The PORT pin is now configured and ready to be used by your program.
5.	Use CBI or SBI to control the output port pin connected to your LED.

Designing the program
This lab is very similar to the previous lab for the blinking LED.  That sketch is attached as a base for you to start with.  You just have to change the structure to create the SOS per the rules above and use an input for the switch to run the SOS and an output to drive the LED.  Use the delay subroutine to setup different delays for the dots, dashes, etc. as shown below in the box.

# Materials:
- 1 - Arduino Uno, Nano or Robotics Board | /re/
- 1 – Push button switch |
- 1 - LED |
- 1 – 220 ohm Resistor for LED |
- 1 – 10k resistor pullup or pulldown for Switch
