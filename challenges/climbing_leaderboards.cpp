#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>

#include <map>
#include <deque>
#include <iterator>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> Array;
typedef vector<string> ArrayStr;
typedef deque<int> Deque;

/* Set custom comparator: decreasing ordering */
typedef std::set<int, std::greater<int>> Set;


Array slow_climbingLeaderboard(Set &scores, const Array &alice)
{
  Array solution;

  auto pos = scores.begin();
  for (auto it = alice.cbegin(); it != alice.cend(); ++it) {
    pos = scores.insert(scores.begin(), *it);

    size_t rank = std::distance(scores.begin(), pos) + 1;
    solution.push_back(rank);
  }

  return std::move(solution);
}

void print_arr(Array &scores) {
  for (auto &s: scores)
    cout << s << ", ";
  cout << endl;
}

Array fast_climbingLeaderboard(Array &scores, const Array &alice)
{
  Array solution;

#ifdef WITH_DUPLICATES
   scores.erase(std::unique(scores.begin(), scores.end()), scores.end());
#endif
   std::sort(scores.begin(), scores.end());

  auto pos = scores.begin();
  for (auto it = alice.cbegin(); it != alice.cend(); ++it) {
    pos = scores.insert(upper_bound(scores.begin(), scores.end(), *it), *it);
    size_t rank = scores.size() - std::distance(scores.begin(), pos);
    solution.push_back(rank);
  }

  return std::move(solution);
}


int main() {
  int number;

  string n_temp;
  getline(cin, n_temp);

  string N_temp;
  getline(cin, N_temp);

  string m_temp;
  getline(cin, m_temp);

  string M_temp;
  getline(cin, M_temp);

  Array leaderboard;
  std::stringstream iss(N_temp);
  int prev = 0;
  while (iss >> number)
    /* remove duplicates */
    if (number != prev) {
      leaderboard.push_back(number);
      prev = number;
    }

  Array alice_scores;
  iss = std::stringstream(M_temp);
  while (iss >> number)
    alice_scores.push_back(number);

  auto &&result = fast_climbingLeaderboard(leaderboard, alice_scores);

  string output = "";
  for (auto &&i : result)
      output +=  to_string(i) + "\n";
  cout << output;
  return 0;
}
