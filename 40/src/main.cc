#include "main.h"

using namespace std;

int main(int argc, char **argv)
{
  vector<int> fraction;
  for(int i = 1; ; i++) {
    auto v = get_digits(i);
    reverse(v.begin(), v.end());
    fraction.insert(fraction.end(), v.begin(), v.end());
    if(fraction.size() > 1000000)
      break;
  }

  int total = 1;
  for(int i = 0; i < 7; i++) {
    int j = (int)pow(10, i);
    total *= fraction.at(j - 1);
  }
  cout << total << endl;
	return 0;
}

vector<int> get_digits(int i)
{
  vector<int> v;
  do {
    int j = i % 10;
    i = i / 10;
    v.push_back(j);
  } while (i > 0);
  return v;
}

int get_int(vector<int> v)
{
  int i = 0;
  int p = 0;
  for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
  {
    i += (*it) * pow(10, p);
    p++;
  }
  return i;
}
