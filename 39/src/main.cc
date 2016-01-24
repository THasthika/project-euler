#include "main.h"

using namespace std;

bool is_right_angled(int p, int a, int b)
{
  return (p*p == 2*(p*(a+b)-a*b));
}

int main(int argc, char **argv)
{
  int max = 0;
  int max_p = 0;
  for(int p = 1; p <= 1000; p++) {
    vector<Solution> solutions;
    for(int a = 1; ; a++) {
      for(int b = 1; ; b++) {
        if(a + b >= p) break;
        if(is_right_angled(p, a, b)) {
          bool found = false;
          for(auto iter = solutions.begin(); iter != solutions.end(); iter++) {
            if((iter->a == a || iter->b == a) && (iter->a == b || iter->b == a)) {
              found = true;
            }
          }
          if(!found) {
            Solution s;
            s.a = a;
            s.b = b;
            s.c = p - a - b;
            solutions.push_back(s);
          }
        }
      }
      if(a >= p) break;
    }
    if(max < solutions.size()) {
      max = solutions.size();
      max_p = p;
    }
  }
  cout << max_p << endl;
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
