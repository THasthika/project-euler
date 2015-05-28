#include <iostream>

#ifndef _MAIN_H
#define _MAIN_H

#define MON 1
#define TUE 2
#define WED 3
#define THU 4
#define FRI 5
#define SAT 6
#define SUN 7

using namespace std;

int get_next_month_first(int first, int days);
int get_month_days(int month, int year);

#endif