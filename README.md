# SOS in Assembly

Purpose:	The Purpose of this project is use Assembly programs which will be embedded into the Arduino C environment but also to be introduced to doing an input and an output from the Arduino board.  The input will be a switch to start the program with a pull-up or pull-down resistor and the output will drive an LED blinking an SOS in Morse Code.  It looks like it will be complicated, but you are given clues every step of the way. And you can use the previous lab delay function and R16 for the different delay times.

Background: In the time of the telegram and radio telegraphy, before and even after voice was encoded, the means of communication was with a ‘tapper’ or a fancy looking switch, using Morse Code, whereby the sender could tap out a message using long and short durations or ‘taps’.   On the receiving end would be a relay or a tone which would repeat the taps so one could hear it and translate it back into words.  In Morse code, the letter S is encoded with 3 short dots or durations and the O is encoded with three long dashes or durations.  The Morse code for mayday or help is SOS which looks like …---…  …---… and so on.  

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
