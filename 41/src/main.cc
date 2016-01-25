#include "main.h"

using namespace std;

int main(int argc, char **argv)
{
  long max = 0;
  for(long i = 100; i < 10000000; i++) {
    for(int j = 1; j < 10; j++) {
      if(is_pandigital(get_digits(i), j) && is_prime(i)) {
        if(max < i) max = i;
        cout << max << endl;
      }
    }
  }
  cout << max << endl;
	return 0;
}

vector<int> get_digits(long i)
{
  vector<int> v;
  do {
    int j = i % 10;
    i = i / 10;
    v.push_back(j);
  } while (i > 0);
  return v;
}

long get_int(vector<int> v)
{
  long i = 0;
  int p = 0;
  for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
  {
    i += (*it) * pow(10, p);
    p++;
  }
  return i;
}

bool is_prime(long i)
{
  if(i == 0 || i == 1)
    return false;
  if(i == 2)
    return true;
  for(long j = 2; j*j <= i; j++)
  {
    if(i % j == 0)
      return false;
  }
  return true;
}

bool is_pandigital(vector<int> v, int n)
{
  if(v.size() != n) return false;
  vector<bool> vb(n);
  for(auto iter = v.begin(); iter != v.end(); iter++) {
    if(*iter == 0) return false;
    if(*iter > n) return false;
    if(vb[*iter - 1] == true)
      return false;
    vb[*iter - 1] = true;
  }
  return true;
}
