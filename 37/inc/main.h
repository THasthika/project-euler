#ifndef _MAIN_H
#define _MAIN_H


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> get_digits(int i);
int get_int(vector<int> v);
bool is_prime(int i);
void truncate_l(vector<int> *v);
void truncate_r(vector<int> *v);

#endif
