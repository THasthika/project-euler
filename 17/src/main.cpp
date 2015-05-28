#include "main.h"

using namespace std;

int main(int argc, char **argv)
{
	int total = 0;
	for(int i = 1; i <= 1000; i++)
	{
		total += get_word_number_length(i);
	}
	cout << total << endl;
	return 0;
}

int get_word_number_length(int num)
{
	return parse_number(num).length();
}

string parse_number(int num)
{
	int rem = 0;
	int prev = 0;
	int i = 0;
	string word = "";
	string tmp_word;
	bool has_and = false;
	if(num >= 100)
		has_and = true;
	while(num > 0)
	{
		prev = rem;
		rem = num % 10;
		num = num / 10;
		i++;
		tmp_word = get_word(prev, rem, i);
		if(tmp_word.length() > 0)
			if(i == 2 && prev != 0 && rem == 1)
				word = tmp_word;
			else
				word = tmp_word + word;
		if(i == 2 && word.length() > 0 && has_and)
		{
			word = "AND" + word;
		}
	}
	return word;
}

string get_word(int prev, int num, int power)
{
	if(num == 0) return "";
	switch(power)
	{
		case 1:
			return onetonine[num - 1];
			break;
		case 2:
			if(prev != 0 && num == 1)
				return teens[prev - 1];
			return tens[num - 1];
			break;
		case 3:
			return onetonine[num - 1] + postfixes[POSTFIX_HUNDRED];
			break;
		case 4:
			return onetonine[num - 1] + postfixes[POSTFIX_THOUSAND];
			break;
	}
	return "";
}