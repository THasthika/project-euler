#include "main.h"

using namespace std;

int main(int argc, char **argv)
{
	BigInt fab1 = 1;
	BigInt fab2 = 1;
	BigInt fab3 = 0;
	int i;
	for(i = 1; ; i++)
	{
		if(fab3.length() == 1000) break;
		if(i == 1 || i == 2)
			fab3 = 1;
		else
		{
			fab3 = fab1 + fab2;
			fab2 = fab1;
			fab1 = fab3;
		}
	}
	cout << "fab(" << i - 1 << ") = " << fab3 << endl;
	return 0;
}