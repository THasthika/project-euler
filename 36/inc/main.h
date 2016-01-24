#ifndef _MAIN_H
#define _MAIN_H


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> get_digits(int i);
int get_int(vector<int> v);
template <class type> bool is_palidrome(vector<type> arr);
vector<char> dec_to_bin(int num);

#endif
