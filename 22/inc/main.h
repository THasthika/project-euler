#include <iostream>
#include <fstream>
#include <vector>

#ifndef _MAIN_H
#define _MAIN_H

using namespace std;

void get_names(string filepath, vector<string> *names);
void alpha_sort(vector<string> *list);
void flip(string *a, string *b);
void s_sort(string *a, string *b);
int get_value(vector<string> *list, int pos);

#endif