#include "main.h"

using namespace std;

int main(int argc, char **argv)
{
	vector<string> names;
	get_names("names.txt", &names);
	alpha_sort(&names);
	int total = 0;
	for(int i = 0; i < names.size(); i++)
	{
		total += get_value(&names, i);
	}
	cout << total << endl;
	return 0;
}

int get_value(vector<string> *list, int pos)
{
	int total = 0;
	string str = list->at(pos);
	for(int i = 0; i < str.length(); i++)
	{
		total += int(str[i]) - 64;
	}
	return total * (pos + 1);
}

void get_names(string filepath, vector<string> *names)
{
	ifstream file(filepath);
	string name;
	while(file >> name)
	{
		names->push_back(name);
	}
	file.close();
}

void alpha_sort(vector<string> *list)
{
	for(int i = 0; i < list->size() - 1; i++)
	{
		for(int j = 0; j < list->size() - 1; j++)
		{
			s_sort(&(list->at(j)), &(list->at(j+1)));
		}
	}
}

void flip(string *a, string *b)
{
	string tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void s_sort(string *a, string *b)
{
	for(int i = 0; i < min(a->length(), b->length()); i++)
	{
		if(i == b->length() - 1 && i != a->length() - 1 && b->at(i) == a->at(i))
		{
			flip(a, b);
			break;
		}
		if(a->at(i) == b->at(i))
		{
			continue;
		}
		else if(a->at(i) < b->at(i))
		{
			break;
		}
		else if(a->at(i) > b->at(i))
		{
			flip(a, b);
			break;
		}
	}
}