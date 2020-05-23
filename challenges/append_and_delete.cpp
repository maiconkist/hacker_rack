#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

std::string append_and_delete(std::string &s,
                              std::string &t,
                              int k)
{
  /*  abaaaa */
  /*  abcc   */
  int e = 0;
  while (s[e] == t[e] &&
         e < s.length() &&
         e < t.length()) {
    ++e;
  }

  int rm  = s.length() - e;
  int add = t.length() - e;

  /*  No possible combination */
  if (k < (rm + add)) return "No";

  /*  Exact combination */
  if (k == (rm + add)) return "Yes";

  /* Can delete everything and append */
  if (k >= (s.length() + t.length())) return "Yes";

  /* Make strings equal + (delete,append) until k */
  if ((k - (rm + add)) % 2 == 0) return "Yes";

  return "No";

}


int main()
{
  std::string s, t;
  int k;

  getline(std::cin, s);
  getline(std::cin, t);

  std::cin >> k;

  auto result = append_and_delete(s, t, k);

  std::cout << result << std::endl;
}
