#include "stdafx.h"
#include "time_class.h"
#include <iostream>
#include <iomanip>

int Time::hour_in_day = 0;
int Time::minute_in_hour = 0;

// Time constructor, initialize time_hours 
// and time_minutes 
// Parameters: int hours and int minutes
Time::Time(int hours, int minutes)
{
	if (minutes >= minute_in_hour)
	{
		time_hours = hours + (minutes - (minutes % minute_in_hour)) / 
			minute_in_hour;
		time_minutes = minutes % minute_in_hour;
	}
	else
	{
		time_hours = hours;
		time_minutes = minutes;
	}
}

// Time constructor, initialize time_hours 
// and time_minutes 
// Parameters: int minutes
Time::Time(int minutes)
{
	time_hours = 0;
	if (minutes >= minute_in_hour)
	{
		time_hours = time_hours + (minutes - (minutes % minute_in_hour)) / 
			minute_in_hour;
		time_minutes = minutes % minute_in_hour;
	}
	else
	{
		time_hours = 0;
		time_minutes = minutes;
	}
}

// Time constructor, initialize time_hours 
// and time_minutes 
// Parameters: none
Time::Time()
{
	time_hours = 0;
	time_minutes = 0;
}

// TODO: Fix the rounding in the output!!!

// Time constructor, initialize time_hours 
// and time_minutes 
// Parameters: double hours
Time::Time(double hours)
{
	hours = round (hours*10)/10;
	time_hours = static_cast<int>(hours);
	time_minutes = ((hours - time_hours) * minute_in_hour);
}

// Deconstructor
Time::~Time()
= default;

// Return time_minutes
// Parameters: none
int Time::minutes()
{
	return time_minutes;
}

// Set time_minutes to int i
// Parameters: int i
void Time::set_minutes(int i)
{
	if (i >= minute_in_hour)
	{
		time_minutes = i%minute_in_hour;
	}
	else
	{
		time_minutes = i;
	}
}

// Set time_hours to int i
// Parameters: int i
void Time::set_hours(int i)
{
	if (i >= hour_in_day)
	{
		time_hours = i%hour_in_day;
	}
	else
	{
		time_hours = i;
	}
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

// Operator+= overloading
// Parameters: const int by reference
Time & Time::operator+=(const int & i)
{
	this->time_hours += i/minute_in_hour;
	this->time_minutes += i%minute_in_hour;
	return *this;
}

// Operator+= overloading
// Parameters: const double by reference
Time & Time::operator+=(const double & i)
{
	this->time_hours += floor(i);
	if (((i-static_cast<int>(i))*100)>=minute_in_hour)
	{
		time_hours += ((i-static_cast<int>(i))*100)/minute_in_hour;
	}
	return *this;
}

// Operator< overloading
// Parameters: Time object lhs and Time object rhs
// passed by reference
// Return true if lhs.time_hours < rhs.time_hours
bool operator<(const Time & lhs, const Time & rhs)
{
	return lhs.time_hours < rhs.time_hours;
}

// Operator== overloading
// Parameters: Time object lhs and Time object rhs
// passed by reference
// Return true if lhs.time_hours == rhs.time_hours
bool operator==(const Time & lhs, const Time & rhs)
{
	return lhs.time_hours == rhs.time_hours;
}

// Operator>= overloading
// Parameters: Time object lhs and Time object rhs
// passed by reference
// Return true if lhs.time_hours >= rhs.time_hours
bool operator>=(const Time & lhs, const Time & rhs)
{
	return lhs.time_hours >= rhs.time_hours;
}

// Operator!= overloading
// Parameters: Time object lhs and Time object rhs
// passed by reference
// Return true if lhs.time_hours != rhs.time_hours
bool operator!=(const Time & lhs, const Time & rhs)
{
	return lhs.time_hours != rhs.time_hours;
}

// Operator+ overloading
// Parameters: lhs and rhs Time objects
Time operator+(const Time & lhs, const Time & rhs)
{
	int sum_minutes = lhs.time_minutes + rhs.time_minutes;
	int sum_hours = lhs.time_hours + rhs.time_hours; 
	return Time(sum_hours, sum_minutes);
}

// Operator+ overloading
// Parameters: int add_time and rhs Time object by reference
Time operator+(int add_time, const Time & rhs)
{
	int sum_minutes = rhs.time_minutes + static_cast<int>(add_time); 
	return Time(rhs.time_hours, sum_minutes);
}

// Operator+ overloading
// Parameters: double add_time and rhs Time object by reference
Time operator+(double add_time, const Time & rhs)
{
	int sum_minutes = rhs.time_minutes + floor(((add_time - static_cast<int>(add_time))
		*Time::minute_in_hour)); 
	int sum_hours = rhs.time_hours + add_time;
	return Time(sum_hours, sum_minutes);
}

// Operator<< overloading
// Parameters: ostream object and Time object by reference
std::ostream& operator<<(std::ostream& out, const Time& time)
{
	out << time.time_hours % Time::hour_in_day << ":" 
		<< (time.time_minutes) / 10
		<< (time.time_minutes) % 10;
	return out;
}
