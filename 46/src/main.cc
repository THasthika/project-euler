#include "main.h"

using namespace std;

int main(int argc, char **argv)
{
  for(int c = 2; ; c++) {
    bool found = false;
    if(!is_prime(c) && c%2!=0) {
      for(int p = 1; p < c; p++) {
        if(!is_prime(p)) continue;
        for(int x = 1; 2*pow(x,2) < c; x++) {
          int s = 2*pow(x,2);
          if(c == p + s) {
            printf("%i = %i + 2 * %i ^ 2\n", c, p, s);
            found = true;
            break;
          }
        }
        if(found) break;
      }
      if(!found) {
        cout << c << endl;
        break;
      }
    }
  }
  return 0;
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
