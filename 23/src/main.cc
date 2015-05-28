#include "main.h"

#define MAX_VAL 28124

using namespace std;

int main(int argc, char **argv)
{
	long total = 0;
	vector<int> nums = get_abundant_nums();
	cout << nums.size() << endl;
	map<long, int> sums = get_all_sums(&nums);

	for(int i = 1; i < MAX_VAL; i++)
	{
		if(sums[i] != 1)
			total += i;
	}

	cout << total << endl;

	return 0;
}

int sum_of_divs(int num)
{
	int total = 0;
	int inv;
	for(int i = 1; i <= (int)sqrt(num); i++)
	{
		if(num % i == 0)
		{
			total += i;
			inv = num / i;
			if(inv == num || inv == i) continue;
			total += inv;
		}
	}
	return total;
}

vector<int> get_abundant_nums()
{
	vector<int> nums;
	for(int i = 1; i < MAX_VAL; i++)
	{
		if(sum_of_divs(i) > i) {
			nums.push_back(i);
		}
	}
	return nums;
}

map<long, int> get_all_sums(vector<int> *nums)
{
	map<long, int> sums;
	long val;
	for(int i = 0; i < nums->size(); i++)
	{
		for(int j = 0; j < nums->size(); j++)
		{
			val = nums->at(i) + nums->at(j);
			if(val < MAX_VAL)
			{
				sums[val] = 1;
			}
		}
	}
	return sums;
}