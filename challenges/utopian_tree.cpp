#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

const size_t INITIAL_HEIGHT = 1;

size_t utopian_tree(int n)
{
  size_t res = INITIAL_HEIGHT;
  for (size_t i = 1; i <= n; i++)
    if (i % 2 == 0)
      res += 1;
    else
      res *= 2;
  return res;
}

int main()
{
  string n_temp;
  getline(cin, n_temp);

  int n_inputs = stoi(n_temp);

  while (n_inputs-- > 0 && getline(cin, n_temp))
    std::cout << utopian_tree(stoi(n_temp)) << std::endl;

  return EXIT_SUCCESS;
}
