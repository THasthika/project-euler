#include "main.h"

using namespace std;

long factorial(long i, long n) {
  if(i == 0) return n;
  return factorial(i - 1, n * i);
}

void swap(vector<int> *v, int i, int j) {
  int t = v->at(i);
  v->at(i) = v->at(j);
  v->at(j) = t;
}

void permutate(vector<int> *v, int l, int r, vector<long> *ret) {
  if(l == r) {
    ret->push_back(get_int(*v));
  } else {
    for(int i = l; i <= r; i++) {
      swap(v, l, i);
      permutate(v, l+1, r, ret);
      swap(v, l, i);
    }
  }
}

bool is_prime(long num) {
  if(num == 1) return false;
  for(int i = 2; i*i <= num; i++) {
    if(num % i == 0) {
      return false;
    }
  }
  return true;
}

void swap(long *a, long *b) {
  long t;
  t = *a;
  *a = *b;
  *b = t;
}

void sortABC(long *a, long *b, long *c) {
  if(*b > *c) {
    swap(c, b);
  }
  if(*a > *b) {
    swap(b, a);
    if(*b > *c) {
      swap(c, b);
    }
  }
}

bool is_perm(long a, long b) {
  int arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  int temp;
  temp = a;
  while(temp > 0) {
    arr[temp%10]++;
    temp /= 10;
  }

  temp = b;
  while(temp > 0) {
    arr[temp%10]--;
    temp /= 10;
  }

  for(int i = 0; i < 10; i++) {
    if(arr[i] != 0) {
      return false;
    }
  }
  return true;
}

int main(int argc, char **argv)
{

  vector<long> p;
  for(long i = 1000; i < 10000; i++) {
    if(is_prime(i)) {
      p.push_back(i);
    }
  }

  for(int i = 0; i < p.size(); i++) {
    for(int j = 0; j < p.size(); j++) {
      if(i == j) continue;
      long a = p.at(i);
      long b = p.at(j);
      if(!is_perm(a, b)) continue;
      if(b > a) swap(&a, &b);
      long c = b + b - a;
      if(c < 1000 || c >= 10000) continue;
      if(!is_perm(b, c)) continue;
      if(is_prime(c) && (pow(a, 2)-2*a*b == pow(c,2)-2*b*c)) {
        sortABC(&a, &b, &c);
        printf("%li%li%li\n", a, b, c);
      }
    }
  }

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
