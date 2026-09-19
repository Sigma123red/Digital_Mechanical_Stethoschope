# Digital Mechanical Stethoscope
Purpose: This project is a prototype of a digital mechanical stethoscope. Engineers use mechanical stethoscopes to detect abnormal vibrations in devices such as motors or fans- abnormal vibrations can include grinding, sputtering, etc. 

How it works:
The microcontroller of this project is an arduino nano- it was powerful enough for this simple project. This project uses a piezoelectric sensor that is attached to 2 6 inch wires to allow for easy probing. When put on the surface, a baseline vibration is calculated in the code to help filter out noise. Then, the user can use the potentiometer which functions as a manual threshold to increase or decrease the sensitivty of the piezoelectric depending on how much noise it is producing. There are two LEDS- a green one to indicate that the project is receiving power and a red one which is part of the warning system. The warning system consists of the Red LED and a passive buzzer. When abnormal vibrations are detected, the buzzer plays a tone and the led turns on. A 16x2 LCD displays the inital baseline, the vibration level, and the manual threshold. Finally, it is powered by 4XAA batteries and housed in a black enclosure composed of PLA. Some electrical tape is used to help with securing the enclosure.

Tools used:
63/37 Solder (I used Maiyum)
Soldering Iron (I have an AlientekT80)
Hacksaw for perfboard cutting
Diagonal cutters
Fume extractor (optional)
Multimeter for debugging
Marker (optional)
22-AWG hookup wire
Digital Caliper for enclosure measurement
Solder sucker

Important note: Keep in mind that this is just a basic prototype that can experience bugs. This was my first project in this category of embedded systems, so I had some issues that I will share if anyone wants to improve on the project. I used a perfboard for all the wiring and there were many issues with rat's nests and short circuits due to wires crossing over (I fried 2 Arduino Nanos). A large amount of the code was iterated by AI after I set up all the pins to help me save time as this project was hardware focused. Keeping this information in mind, the code may have bugs that cause issues in the future. My final major issue with this project was signal processing. I did not know how challenging calibrating a piezoelectric for this project would be due to its extreme sensitivity and susceptibility to noise. The processing is not perfect, but enough for my prototype. All in all, this project was mainly done for learning and figuring out the process of building a hardware product. Feedback would be much appreciated as I spent a large amount of time on this project.

