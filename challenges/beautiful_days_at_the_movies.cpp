#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

int reverse_number(int x)
{
  int reversed = 0;
  while(x > 0) {
    reversed = reversed*10 + x%10;
    x /= 10;
  }

  return reversed;
}


int beautiful_day(int i, int j, int k)
{

  int bdays = 0;

  for (int ii = i; ii <= j; ++ii) {
    int reversed = reverse_number(ii);
    if (abs(ii - reversed) % k == 0) bdays++;
  }

  return bdays;
}


int main()
{

  string ijk_temp;
  getline(cin, ijk_temp);

  int i, j, k;

  std::stringstream iss(ijk_temp);
  iss >> i;
  iss >> j;
  iss >> k;

  int result = beautiful_day(i, j, k);

  std::cout << result << endl;

  return EXIT_SUCCESS;
}
