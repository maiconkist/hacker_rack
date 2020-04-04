#include <sstream>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <climits>

#include <iterator>
#include <set>
#include <deque>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> Array;
typedef vector<string> ArrayStr;
typedef deque<int> Deque;

/* Set custom comparator: decreasing ordering */
typedef std::set<int, std::greater<int> > Set;

size_t find_rank(Set scores, int val)
{
  auto it    = std::find(scores.cbegin(), scores.cend(), val);
  size_t pos = std::distance(scores.cbegin(), it);

  return pos + 1;
}

const std::string &  climbingLeaderboard(Set &scores, Deque &alice)
{
    static std::string solution;

    while (!alice.empty()) {
        scores.insert(alice[0]);
        size_t rank = find_rank(scores, alice[0]);

        solution.append(to_string(rank) + "\n");
        alice.pop_front();
    }

    return solution;
}

int main()
{
    string nl_temp;
    getline(cin, nl_temp);

    string l_temp;
    getline(cin, l_temp);

    string na_temp;
    getline(cin, na_temp);

    string a_temp;
    getline(cin, a_temp);

    Set leaderboard;
    int number;
    std::stringstream iss(l_temp);
    while (iss >> number)
      leaderboard.insert(number);

    Deque alice_scores;
    iss = std::stringstream(a_temp);
    while (iss >> number)
      alice_scores.push_back(number);

    const auto & result = climbingLeaderboard(leaderboard, alice_scores);
    cout << result;

    return 0;
}
