#include "main.h"

using namespace std;

int main(int argc, char **argv)
{
  vector<int> decArr;
  vector<char> binArr;
  int total = 0;
  for(int i = 0; i < 1000000; i++)
  {
    decArr = get_digits(i);
    binArr = dec_to_bin(i);
    if(is_palidrome(decArr) && is_palidrome(binArr))
    {
      total += i;
    }
  }
  cout << total << endl;
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

template <class type> bool is_palidrome(vector<type> arr)
{
  bool palidrome = true;
  int mid = (arr.size() / 2) - 1;
  if(arr.size() % 2 == 1)
    mid++;
  for(int i = 0; i <= mid;i++) {
    int j = arr.size() - (i + 1);
    if(arr.at(i) != arr.at(j)) {
      palidrome = false;
      break;
    }
  }
  return palidrome;
}

vector<char> dec_to_bin(int num)
{
  vector<char> arr;
  if(num == 0){
    arr.push_back(0);
    return arr;
  }
  while(num > 0) {
    int r = num % 2;
    arr.push_back(r + 48);
    num = num / 2;
  }
  reverse(arr.begin(), arr.end());
  return arr;
}
