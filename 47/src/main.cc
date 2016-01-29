#include "main.h"

using namespace std;

int main(int argc, char **argv)
{
  int targetpf = 4;
  int targetConsec = 4;
  int consec = 1;
  int result = 2 * 3 * 5 *7;

  while (consec < targetConsec) {
    result++;
    if (no_of_prime_factors(result) >= targetpf) {
      consec++;
    } else {
      consec = 0;
    }
  }

  printf("%li\n", result - 3);

  return 0;
}

int no_of_prime_factors(long n) {
  int nopf = 0;
  bool pf = false;
  long remainder = n;
  for(long i = 1; i <= n; i++) {
    if(!is_prime(i)) continue;
    pf = false;
    while(remainder % i == 0) {
      pf = true;
      remainder = remainder / i;
    }
    if(pf)
      nopf++;
    if(remainder == 1)
      return nopf;
  }
  return nopf;
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
