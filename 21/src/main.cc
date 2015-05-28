#include "main.h"

using namespace std;

int main(int argc, char **argv)
{

	int total = 0;
	int a, b;

	for(int i = 1; i < 10000; i++)
	{
		a = i;
		b = sum_of_divs(a);
		if(sum_of_divs(b) == a && a != b)
		{
			total += a;
		}
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
