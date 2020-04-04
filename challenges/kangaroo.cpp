#include <bits/stdc++.h>

using namespace std;

string kangaroo(int x1, int v1, int x2, int v2) {
  // https://math.stackexchange.com/questions/1656120/formula-to-find-the-first-intersection-of-two-arithmetic-progressions

  // This being 0 indicates that both AP cross, we dont know if its at the SAME TIME
  if ((abs(x1 - x2) % __gcd(v1, v2)) == 0){
    // Yeah, check if its feasible fo them to cross at some iterationg N
    if ((x1 < x2 && v1 < v2) ||
        (x2 < x1 && v2  < v1))
      return "NO";

    // Now check if  they cross at the same time N.
    // Derived from x1 + N v1 = x2 + N v2
    if (((x1 - x2) % (v2 - v1)) == 0)
      return "YES";
  }
  return "NO";
}

int main() {
  int x1;
  int v1;
  int x2;
  int v2;
  cin >> x1 >> v1 >> x2 >> v2;
  string result = kangaroo(x1, v1, x2, v2);
  cout << result << endl;
  return 0;
}
