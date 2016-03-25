#include "main.h"

using namespace std;

// 9951191

int main(int argc, char **argv)
{
  vector<long> primes;
  vector<long> sums;

  long limit = 10000000;

  printf("finding primes...");
  fflush(stdout);
  for(long i = 0; i < limit; i++) { // 10000000
    if(is_prime(i)) {
      primes.push_back(i);
    }
  }
  printf("done\n");
  fflush(stdout);

  printf("finding sums...");
  fflush(stdout);
  sums.push_back(0);
  for(int i = 0; i < primes.size(); i++) {
    sums.push_back(primes.at(i) + sums.at(i));
  }
  printf("done\n");
  fflush(stdout);

  int len = 0;
  long num = 0;

  for(int i = 0; i < sums.size(); i++) {
    for(int j = i; j < sums.size(); j++) {
      if(i >= j) continue;
      long n = sums.at(j) - sums.at(i);
      if(n >= limit) continue;
      if(find(primes.begin(), primes.end(), n) != primes.end()) {
        if(j - i > len) {
          len = j - i;
          num = n;
        }
      }
    }
    printf("%i/%li\n", i, sums.size());
  }

  printf("%li --> %i\n", num, len);

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

bool is_prime(long i)
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
