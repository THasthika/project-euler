#include "main.h"

using namespace std;

bool is_triangular_word(string word);

int main(int argc, char **argv)
{
  int total = 0;
  ifstream file("words.txt");
  if(file.is_open()) {
    string word = "";
    char c;
    while(file >> c) {
      if(c == ',') {
        if(is_triangular_word(word)) {
          total++;
        }
        word = "";
      }

      if(c != '"' && c != ',') {
        word += c;
      }
    }
    file.close();
  }
  cout << total << endl;
	return 0;
}

bool is_triangular_word(string word)
{
  int b = (int) 'A' - 1;
  int t = 0;
  for(int i = 0; i < word.size(); i++) {
    int val = (int) word[i] - b;
    t += val;
  }
  return is_triangular(t);
}

bool is_triangular(int i)
{
  float x = ((-1 + sqrt(8*i + 1)) / 2);
  if(x - round(x) != 0) return false;
  return true;
}
