/***************************************************
Description : Easing Library.
Author : Patrick Chiu.

Reference:
1. https://github.com/luisllamasbinaburo/Arduino-Easing
2. https://github.com/nicolausYes/easing-functions

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
 ****************************************************/
 
#ifndef _EASINGLIB_h
#define _EASINGLIB_h

enum ease_mode {
	LINEAR,

	EASE_IN_SINE,
	EASE_OUT_SINE,
	EASE_IN_OUT_SINE,

	EASE_IN_QUAD,
	EASE_OUT_QUAD,
	EASE_IN_OUT_QUAD,

	EASE_IN_CUBIC,
	EASE_OUT_CUBIC,
	EASE_IN_OUT_CUBIC,

	EASE_IN_QUART,
	EASE_OUT_QUART,
	EASE_IN_OUT_QUART,

	EASE_IN_QUINT,
	EASE_OUT_QUINT,
	EASE_IN_OUT_QUINT,

	EASE_IN_EXPO,
	EASE_OUT_EXPO,
	EASE_IN_OUT_EXPO,

	EASE_IN_CIRC,
	EASE_OUT_CIRC,
	EASE_IN_OUT_CIRC,

	EASE_IN_BACK,
	EASE_OUT_BACK,
	EASE_IN_OUT_BACK,

	EASE_IN_ELASTIC,
	EASE_OUT_ELASTIC,
	EASE_IN_OUT_ELASTIC,

	EASE_IN_BOUNCE,
	EASE_OUT_BOUNCE,
	EASE_IN_OUT_BOUNCE


};

class Easing
{

public:
	typedef float (Easing::* EasingFunction)(float);

	Easing();
	Easing(ease_mode mode, unsigned long millisInterval);

	void Init(float value);

	float operator = (float value);
	operator float();
	float GetSetpoint(float value);
	float SetSetpoint(float value);
	float GetValue();

	void SetMillisInterval(unsigned long interval);
	void SetMicrosInterval(unsigned long interval);
	void SetMode(ease_mode mode);

private:
	ease_mode Mode;
	float _startPoint;
	float _setPoint;
	float _currentValue;
	unsigned long _startTime;
	unsigned long _easyDuration = 1000000;
	bool _active;

	EasingFunction easingFunction;
	float linear(float t);

	float easeInSine(float t);
	float easeOutSine(float t);
	float easeInOutSine(float t);

	float easeInQuad(float t);
	float easeOutQuad(float t);
	float easeInOutQuad(float t);

	float easeInCubic(float t);
	float easeOutCubic(float t);
	float easeInOutCubic(float t);

	float easeInQuart(float t);
	float easeOutQuart(float t);
	float easeInOutQuart(float t);

	float easeInQuint(float t);
	float easeOutQuint(float t);
	float easeInOutQuint(float t);

	float easeInExpo(float t);
	float easeOutExpo(float t);
	float easeInOutExpo(float t);

	float easeInCirc(float t);
	float easeOutCirc(float t);
	float easeInOutCirc(float t);

	float easeInBack(float t);
	float easeOutBack(float t);
	float easeInOutBack(float t);

	float easeInElastic(float t);
	float easeOutElastic(float t);
	float easeInOutElastic(float t);

	float easeInBounce(float t);
	float easeOutBounce(float t);
	float easeInOutBounce(float t);

};

#endif

