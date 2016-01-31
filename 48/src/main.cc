#include "main.h"

using namespace std;

int main(int argc, char **argv)
{
	long result = 0;
	long modulo = 10000000000;

	for (int i = 1; i <= 1000; i++) {
	    long temp = i;
	    for (int j = 1; j < i; j++) {
	        temp *= i;
					temp %= modulo;
	    }

	    result += temp;
	    result %= modulo;
	}

	cout << result << endl;

	return 0;
}
