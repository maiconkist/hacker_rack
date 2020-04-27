#include <bits/stdc++.h>

int findDigits(int n) {
  std::string s = std::to_string(n);

  int divs = 0;
  for (int i = 0; i < s.size(); ++i ){
    int c = s.c_str()[i] - 48; /*  convert digit to int */

    if (c == 0) continue;
    if (n % c == 0) divs++;
  }

  return divs;
}

int main()
{
  int t;
  std::cin >> t;

  int n;
  for (int t_itr = 0; t_itr < t; t_itr++) {
    std::cin >> n;
    int result = findDigits(n);
    std::cout << result << std::endl;;
  }

  return EXIT_SUCCESS;
}
