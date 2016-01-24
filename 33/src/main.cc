#include "main.h"

using namespace std;

int gcd(int p, int q)
{
  if(p == 0) return q;
  int r = p % q;
  return gcd(r, p);
}

int main(int argc, char **argv)
{
  int denproduct = 1;
  int numproduct = 1;

  for(int i = 1; i < 10; i++)
  {
    for(int den = 1; den < i; den++)
    {
      for(int num = 1; num < den; num++)
      {
        if((den * (10 * num + i)) == (num * (10 * i + den)))
        {
          denproduct *= den;
          numproduct *= num;
        }
      }
    }
  }

  denproduct /= gcd(numproduct, denproduct);

  cout << denproduct << endl;

	return 0;
}
