#ifndef ROBOTMAP_H
#define ROBOTMAP_H


/**
* The RobotMap is a mapping from the ports sensors and actuators are wired into
* to a variable name. This provides flexibility changing wiring, makes checking
* the wiring easier and significantly reduces the number of magic numbers
* floating around.
*/

//Buttons

// A button
#define BUTTON_1 1
// B Button
#define BUTTON_2 2
// X Button
#define BUTTON_3 3
// Y Button
#define BUTTON_4 4
// Left Bumper 
#define BUTTON_5 5
// Right Bumper
#define BUTTON_6 6
// Back Button
#define BUTTON_7 7 
// Start Button
#define BUTTON_8 8
// Clicking the Left Joystick Down
#define BUTTON_9 9
// Clicking the Right Joystick Down
#define BUTTON_10 10


// Joysticks
#define RIGHT_JOYSTICK 11
#define LEFT_JOYSTICK 12



// DPad control mapping or + pad.
#define DPAD_LEFT 13
#define DPAD_RIGHT 14
#define DPAD_UP 15
#define DPAD_DOWN 16
#define DPAD_UPLEFT 17
#define DPAD_UPRIGHT 18
#define DPAD_DOWNLEFT 19
#define DPAD_DOWNRIGHT 20


#endif
