#include "main.h"

#define LIMIT 5000

using namespace std;

int main(int argc, char **argv)
{
  bool set = false;
  int minD = 0;
  for(int i = 1; i <= LIMIT; i++) {
    for(int j = 1; j <= LIMIT; j++) {
      if(i == j) continue;
      int sum = get_pentagonal(i) + get_pentagonal(j);
      int diff = abs(get_pentagonal(i) - get_pentagonal(j));
      if(is_pentagonal(diff) && is_pentagonal(sum)) {
        if(!set) {
          minD = diff;
          set = true;
        }
        if(diff < minD) minD = diff;
      }
    }
  }
  cout << minD << endl;
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

int get_pentagonal(int n)
{
  return (n*(3*n - 1)) / 2;
}

bool is_pentagonal(int i)
{
  float n = ((float)1 + sqrt(1 + 24 * i))/(float)6;
  if(n - round(n) != 0)
    return false;
  return true;
}
