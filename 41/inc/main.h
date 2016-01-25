#ifndef _MAIN_H
#define _MAIN_H


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> get_digits(long i);
long get_int(vector<int> v);
bool is_prime(long i);
bool is_pandigital(vector<int> v, int n);

#endif
