#include "main.h"

using namespace std;

int main(int argc, char **argv)
{
  int j = 0;
  int total = 0;
  for(int i = 10; i < 1000000; i++)
  {
    if(!is_prime(i)) continue;
    auto vl = get_digits(i);
    auto vr = get_digits(i);
    bool p = true;
    while(vl.size() > 0 || vr.size() > 0) {
      if(!is_prime(get_int(vl)) || !is_prime(get_int(vr))) {
        p = false;
        break;
      }
      truncate_l(&vl);
      truncate_r(&vr);
    }
    if(p) {
      total += i;
      j++;
    }
    if(j == 12)
      break;
  }
  cout << j << " " << total << endl;
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

void truncate_l(vector<int> *v)
{
  if(v->size() <= 0)
    return;
  auto iter = v->end() - 1;
  v->erase(iter);
}

void truncate_r(vector<int> *v)
{
  if(v->size() <= 0)
    return;
  auto iter = v->begin();
  v->erase(iter);
}
