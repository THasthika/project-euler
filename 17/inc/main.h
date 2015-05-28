#include <iostream>
#include <string>

using namespace std;

#ifndef _MAIN_H
#define _MAIN_H

#define POSTFIX_HUNDRED 0
#define POSTFIX_THOUSAND 1

static string onetonine[] = {
	"ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};

static string tens[] = {
	"TEN", "TWENTY", "THIRTY", "FORTY", "FIFTY", "SIXTY", "SEVENTY", "EIGHTY", "NINETY"
};

static string teens[] = {
	"ELEVEN", "TWELVE", "THIRTEEN", "FOURTEEN", "FIFTEEN", "SIXTEEN", "SEVENTEEN", "EIGHTEEN", "NINETEEN"
};

static string postfixes[] = {
	"HUNDRED", "THOUSAND"
};


string parse_number(int num);
string get_word(int prev, int num, int power);
int reverse_number(int num);
int get_word_number_length(int num);

#endif