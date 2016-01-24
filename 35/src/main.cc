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

void rotate(vector<int> *v)
{
  vector<int>::iterator it = v->begin();
  int t = *it;
  for(; it != v->end(); it++)
  {
    if(it+1 != v->end())
      *it = *(it+1);
    else
      *it = t;
  }
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

int main(int argc, char **argv)
{
  vector<int> list;
  int count = 0;
  for(int i = 1; i < 1000000; i++)
  {
    vector<int> v = get_digits(i);
    bool circular = true;
    for(int j = 0; j < v.size(); j++)
    {
      if(!is_prime(get_int(v)))
        circular = false;
      rotate(&v);
    }
    if(circular)
    {
      for(int k = 0; k < v.size(); k++)
      {
        if(find(list.begin(), list.end(), get_int(v)) == list.end())
          list.push_back(get_int(v));
        rotate(&v);
      }
    }
  }
  cout << list.size() << endl;

	return 0;
}
