#include "main.h"

using namespace std;

int main(int argc, char **argv)
{
  int max = 0;
  for(int i = 1; i <= 10000; i++) {
    auto v = get_multiples(i);
    if(is_pandigital(v)) {
      int j = get_int(v);
      printf("%9i --> %9i\n", i, j);
      if(max < j)
        max = j;
    }
  }
  cout << max << endl;
	return 0;
}

vector<int> get_multiples(int i)
{
  vector<int> total;
  if(i == 0) return total;
  for(int j = 1; ; j++) {
    auto v = get_digits(i*j);
    total.insert(total.begin(), v.begin(), v.end());
    if(total.size() >= 9)
      break;
  }
  return total;
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

bool is_prime(int i)
{
  if(i == 0 || i == 1)
    return false;
  if(i == 2)
    return true;
  for(int j = 2; j*j <= i; j++)
  {
    if(i % j == 0)
      return false;
  }
  return true;
}

bool is_pandigital(vector<int> v)
{
  if(v.size() != 9) return false;
  bool vb[9] = {false, false, false, false, false, false, false, false, false};
  for(auto iter = v.begin(); iter != v.end(); iter++) {
    if(*iter == 0) return false;
    if(vb[*iter - 1])
      return false;
    vb[*iter - 1] = true;
  }
  return true;
}
