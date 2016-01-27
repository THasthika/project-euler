#include "main.h"

using namespace std;

int main(int argc, char **argv)
{
  long n = 8000;
  for(;;n++) {
    long t = get_triangular(n);
    cout << n << " --> " << t << endl;
    if(is_pentagonal(t) && is_hexagonal(t) && t >= 1533776805) {
      cout << t << endl;
      break;
    }
  }
  return 0;
}

long get_triangular(long n)
{
  return (n*(n+1)) / 2;
}

long get_pentagonal(long n)
{
  return (n*(3*n-1)) / 2;
}

long get_hexagonal(long n)
{
  return n*(2*n-1);
}

bool is_triangular(long i)
{
  float n = ((-1 + sqrt(8*i + 1)) / 2);
  if(n - round(n) != 0) return false;
  return true;
}

bool is_pentagonal(long i)
{
  float n = ((float)1 + sqrt(1 + 24 * i))/(float)6;
  if(n - round(n) != 0) return false;
  return true;
}

bool is_hexagonal(long i)
{
  float n = (1 + sqrt(1 + 8*i)) / 4;
  if(n - round(n) != 0) return false;
  return true;
}
