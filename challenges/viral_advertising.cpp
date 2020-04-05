#include <bits/stdc++.h>
using namespace std;

const int LAUNCH_HIT = 5;

int viral_advertising(int n)
{
  int result = 0;

  int hit = LAUNCH_HIT;


  for (size_t i = 0; i < n; ++i) {
    hit = std::floor(hit/2);
    result += hit;
    hit *=3;
  }


  return result;
}


int main()
{

  string n_temp;
  getline(cin, n_temp);

  int n = stoi(n_temp);

  int result = viral_advertising(n);

  std::cout << result << endl;

  return EXIT_SUCCESS;
}
