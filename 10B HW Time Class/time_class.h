
#ifndef TIME_CLASS_H
#define TIME_CLASS_H
#include <ostream>

class Time
{
private:
	int time_hours;
	int time_minutes;
	static int hour_in_day;
	static int minute_in_hour;

public:
	Time(int hours, int minutes);
	Time(int minutes);
	Time();
	Time(double hours);

	~Time();

	int minutes();
	void set_minutes(int i);
	void set_hours(int i);
	static void set_hr_in_day(int i);
	static void set_min_in_hr(int i);

	friend std::ostream& operator<<(std::ostream&, const Time&);
	friend Time operator+(const Time& lhs, const Time& rhs);
	friend Time operator+(int add_time, const Time & rhs);
	friend Time operator+(double add_time, const Time & rhs);
	Time& operator+=(const int& i);
	Time& operator+=(const double& i);

	friend bool operator<(const Time& lhs, const Time& rhs);
	friend bool operator==(const Time& lhs, const Time& rhs);
	friend bool operator>=(const Time& lhs, const Time& rhs);
	friend bool operator!=(const Time& lhs, const Time& rhs);
};
#endif // TIME_CLASS_H
