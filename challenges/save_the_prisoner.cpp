#include <bits/stdc++.h>

using namespace std;

int save_the_prisoner(int prisoners, int sweets, int f_chair)
{
  int shift = f_chair + sweets-1;
  int res = shift % prisoners;
  return res == 0? prisoners : res;
}


int main()
{
  int tcases;
  cin >> tcases;

  for (int i = 0; i < tcases; ++i) {
    int n, m, s;

    cin >> n;
    cin >> m;
    cin >> s;

    int result = save_the_prisoner(n, m, s);

    std::cout << result << endl;
  }
}
