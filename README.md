# SOS in Assembly

Purpose:	The Purpose of this project is use Assembly programs which will be embedded into the Arduino C environment but also to be introduced to doing an input and an output from the Arduino board.  The input will be a switch to start the program with a pull-up or pull-down resistor and the output will drive an LED blinking an SOS in Morse Code.  It looks like it will be complicated, but you are given clues every step of the way. And you can use the previous lab delay function and R16 for the different delay times.

Background: In the time of the telegram and radio telegraphy, before and even after voice was encoded, the means of communication was with a ‘tapper’ or a fancy looking switch, using Morse Code, whereby the sender could tap out a message using long and short durations or ‘taps’.   On the receiving end would be a relay or a tone which would repeat the taps so one could hear it and translate it back into words.  In Morse code, the letter S is encoded with 3 short dots or durations and the O is encoded with three long dashes or durations.  The Morse code for mayday or help is SOS which looks like …---…  …---… and so on.  

This lab will send SOS in Morse code to an LED when a switch is on and it will stop after sending the complete SOS when the switch is off.

![Picture1](https://user-images.githubusercontent.com/102126445/166611452-61959e7d-7a2e-40f6-9344-d6f30e59cfe7.png)

Here is an example of what it should sound like:
https://www.youtube.com/watch?v=Zsb7stKelq4
