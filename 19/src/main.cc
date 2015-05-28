#include "main.h"

using namespace std;

static int days[] = { 1, 2, 3, 4, 5, 6, 7 };

int main(int argc, char **argv)
{
	int year = 1900;
	int month = 1;
	int first = 1;

	int days = 0;
	
	for(; year <= 2000;)
	{
		if(year > 1900) {
			if(first == SUN)
				days++;
		}
		first = get_next_month_first(first, get_month_days(month, year));
		month++;
		if(month > 12) {
			month = 1;
			year++;
		}
	}

	cout << days << endl;

	return 0;
}

int get_month_days(int month, int year)
{
	if(month < 0 || month > 13)
		return 0;
	switch(month)
	{
		case 2:
			if(year % 100 == 0)
				if(year % 400 == 0)
					return 29;
				else
					return 28;
			else if(year % 4 == 0)
				return 29;
			else
				return 28;
			break;
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
			break;
		default:
			return 30;
	}
}

int get_next_month_first(int first, int days)
{
	for(int i = 1; i <= days; i++)
	{
		first++;
		if(first > 7)
			first = 1;
	}
	return first;
}