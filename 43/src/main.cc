#include "main.h"

using namespace std;

int main(int argc, char **argv)
{
  long total = 0;
  auto num_a = vector<int> {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int divs[] = {2, 3, 5, 7, 11, 13, 17};
  do {
    bool found = true;
    long j = get_int(num_a);
    for(int i = 0; i < 7; i++) {
      vector<int> v;
      v.insert(v.begin(), num_a.end() - (4 + i), num_a.end() - (1 + i));
      if(get_int(v) % divs[i] != 0)
        found = false;
    }
    if(found) {
      total += j;
      cout << total << endl;
    }
  } while(next_permutation(num_a.begin(), num_a.end()));
  cout << total << endl;
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

bool is_pandigital(vector<int> v, int j)
{
  if(v.size() != j) return false;
  vector<bool> vb(j);
  for(auto iter = v.begin(); iter != v.end(); iter++) {
    if(vb[*iter])
      return false;
    vb[*iter] = true;
  }
  return true;
}
