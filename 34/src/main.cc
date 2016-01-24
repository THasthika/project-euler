#include "main.h"

using namespace std;

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

int factorial(int i)
{
  if(i == 0)
    return 1;
  return i * factorial(i - 1);
}

int main(int argc, char **argv)
{
  int total = 0;
  for(int i = 10; i < 200000; i++)
  {
    vector<int> j = get_digits(i);
    int sub_t = 0;
    for(vector<int>::iterator it = j.begin(); it != j.end(); it++)
    {
      int fac = factorial(*it);
      sub_t += fac;
    }
    if(sub_t == i)
      total += i;
  }

  cout << total << endl;

	return 0;
}
