#include "stdafx.h"
#include "time_class.h"
#include <iostream>
#include <iomanip>

int Time::hour_in_day = 0;
int Time::minute_in_hour = 0;

// Time constructor, initialize time_hours
// and time_minutes
// Parameters: none
Time::Time()
{
	time = 0.0;
}

// Time constructor, initialize time_hours
// and time_minutes
// Parameters: int minutes
Time::Time(int minutes)
{
	time = static_cast<double>(minutes) / minute_in_hour;
}

// Time constructor, initialize time_hours
// and time_minutes
// Parameters: double hours
Time::Time(double hours)
{
	time = hours - (floor(hours / hour_in_day) * hour_in_day);
}

// Time constructor, initialize time_hours
// and time_minutes
// Parameters: int hours and int minutes
Time::Time(double hours, double minutes)
{
	time = (fmod(hours, hour_in_day)) + (minutes / minute_in_hour);
}

// Deconstructor
Time::~Time()
= default;

// Return time_minutes
// Parameters: none
int Time::minutes()
{
	return static_cast<int>(time * 60);
}

// Set minutes in hours to double i
// Parameters: double i
void Time::set_minutes(int i)
{
	double hours;
	double frac = modf(time, &hours);
	time = time - frac;

	if (frac >= 0.9999999)
	{
		hours += 1;
		frac = 0;
	}

	time = hours + round((i % minute_in_hour)) / minute_in_hour;
}

// Set minutes in hours to double i
// Parameters: double i
void Time::set_minutes(double i)
{
	double hours;
	double frac = modf(time, &hours);
	time = time + (fmod(i, minute_in_hour) / minute_in_hour) - frac;
}

// Set hours in time to int i
// Parameters: int i
void Time::set_hours(int i)
{
	double hours;
	double frac = modf(time, &hours);
	time += static_cast<double>(i % hour_in_day) - hours;
}

// Set hours in time to int i
// Parameters: double i
void Time::set_hours(double i)
{
	double hours;
	double frac = modf(time, &hours);
	time = time - hours + floor(i);
}

// Set the number of hours in a day
// Parameters: int i
void Time::set_hr_in_day(int i)
{
	hour_in_day = i;
}

// Set the number of minutes in a hour
// Parameters: int i
void Time::set_min_in_hr(int i)
{
	minute_in_hour = i;
}

// Operator<< overloading
// Parameters: ostream object and Time object by reference
std::ostream& operator<<(std::ostream& out, const Time& time)
{
	double hours;
	double frac = modf(time.time, &hours);

	if (frac >= 0.9999999)
	{
		hours += 1;
		frac = 0;
	}

	double min = round(frac * time.minute_in_hour);
	out << hours << ":" << std::setfill('0') << std::setw(2) << min;
	return out;
}

// Operator+ overloading
// Parameters: int add_time and rhs Time object by reference
Time operator+(int add_time, const Time& rhs)
{
	double result = rhs.time + (static_cast<double>(add_time) / rhs.minute_in_hour
	);
	return Time(result);
}

// Operator+ overloading
// Parameters: double add_time and rhs Time object by reference
Time operator+(double add_time, const Time& rhs)
{
	double result = rhs.time + add_time;
	return Time(result);
}

// Operator+ overloading
// Parameters: lhs Time object and rhs Time object by reference
Time operator+(const Time& lhs, const Time& rhs)
{
	return Time(rhs.time + lhs.time);
}

// Operator+= overloading
// Parameters: const int by reference
Time& Time::operator+=(const int& i)
{
	this->time += (static_cast<double>(i) / minute_in_hour);
	return *this;
}

// Operator+= overloading
// Parameters: const double by reference
Time& Time::operator+=(const double& i)
{
	this->time = this->time + i;
	return *this;
}

// Operator< overloading
// Parameters: Time object lhs and Time object rhs
// passed by reference
// Return true if lhs.time_hours < rhs.time_hours
bool operator<(const Time& lhs, const Time& rhs)
{
	return lhs.time < rhs.time;
}

// Operator== overloading
// Parameters: Time object lhs and Time object rhs
// passed by reference
// Return true if lhs.time_hours == rhs.time_hours
bool operator==(const Time& lhs, const Time& rhs)
{
	return lhs.time == rhs.time;
}

// Operator>= overloading
// Parameters: Time object lhs and Time object rhs
// passed by reference
// Return true if lhs.time_hours >= rhs.time_hours
bool operator>=(const Time& lhs, const Time& rhs)
{
	return lhs.time >= rhs.time;
}

// Operator!= overloading
// Parameters: Time object lhs and Time object rhs
// passed by reference
// Return true if lhs.time_hours != rhs.time_hours
bool operator!=(const Time& lhs, const Time& rhs)
{
	return lhs.time != rhs.time;
}
