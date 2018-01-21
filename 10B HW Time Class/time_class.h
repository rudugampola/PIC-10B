#ifndef TIME_CLASS_H
#define TIME_CLASS_H
#include <ostream>

class Time
{
private:
	double time;
	static int hour_in_day;
	static int minute_in_hour;

public:

	// Overloading Time()
	Time();
	Time(int minutes);
	Time(double hours);
	Time(double hours, double minutes);

	// Deconstructor
	~Time();

	// minutes() return minutes
	int minutes();

	// set_minutes() set minutes to value passed
	void set_minutes(int i);
	void set_minutes(double i);

	// set_hours() set minutes to value passed
	void set_hours(int i);
	void set_hours(double i);

	// set_hr_in_day sets the number of hours in the day
	static void set_hr_in_day(int i);

	//set_min_in_hr sets the number of minutes in the hour
	static void set_min_in_hr(int i);

	// Overloading of operator<<
	friend std::ostream& operator<<(std::ostream&, const Time&);

	// Overloading of operator+
	friend Time operator+(const Time& lhs, const Time& rhs);
	friend Time operator+(int add_time, const Time& rhs);
	friend Time operator+(double add_time, const Time& rhs);

	// Overloading of operator+=
	Time& operator+=(const int& i);
	Time& operator+=(const double& i);

	// Overloading of operator>
	friend bool operator<(const Time& lhs, const Time& rhs);

	// Overloading of operator==
	friend bool operator==(const Time& lhs, const Time& rhs);
	// Overloading of operator>=
	friend bool operator>=(const Time& lhs, const Time& rhs);
	// Overloading of operator!=
	friend bool operator!=(const Time& lhs, const Time& rhs);
};
#endif // TIME_CLASS_H
