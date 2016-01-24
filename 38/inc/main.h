#ifndef _MAIN_H
#define _MAIN_H


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> get_multiples(int i);
vector<int> get_digits(int i);
int get_int(vector<int> v);
void rotate(vector<int> *v);
bool is_pandigital(vector<int> v);

#endif
