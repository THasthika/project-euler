#include "main.h"

using namespace std;

void permutate(string nums, string h, vector<string> *out)
{
	if(nums.length() == 0) {
		out->push_back(h);
	}
	else
	{
		for(int i = 0; i < nums.length(); i++)
		{
			string tmp = nums;
			string h_tmp = h;
			h_tmp += tmp[i];
			tmp.erase(i, 1);
			permutate(tmp, h_tmp, out);
		}
	}
	return;
}

int main(int argc, char **argv)
{
	string nums = "0123456789";

	vector<string> permutations;

	permutate(nums, "", &permutations);

	cout << permutations[999999] << endl;

	return 0;
}