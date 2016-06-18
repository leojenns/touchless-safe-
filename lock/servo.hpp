///@file

/*
* File:   servo.hpp
* Author: Tim IJntema
*
* Created on 30 may 2016, 10:04
*/

#ifndef SERVO_HPP
#define SERVO_HPP

#include "PWM_signal.hpp"
#include "hwlib.hpp"

#define MAX_DEGREES 360
#define MIN_DEGREES 0


class servo : public PWM_signal{
public:
	

	servo(hwlib::target::pin_out & pwmPin);

	void turnDegrees(int degrees);
};

#endif 
