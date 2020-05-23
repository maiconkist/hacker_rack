#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int sherlock_and_squares(int min, int max)
{
  int res = 0;

  int ival = sqrt(min);

  if (ival == sqrt(min) && ival * ival <= max) ++res;
  ival++;

  while (ival * ival <= max) {
      res++;
      ival++;
  }

  return res;
}

int main()
{
  int q, min, max;
  std::string test_case;

  cin >> q;
  while (q-- > 0) {
    cin >> min;
    cin >> max;

    std::cout << sherlock_and_squares(min, max) << std::endl;
  }

  return 1;
}
