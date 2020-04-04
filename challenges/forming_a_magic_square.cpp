#include <cmath>
#include <cstdint>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <climits>

using namespace std;

typedef vector<vector<int> > square;

square s1 {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}};
square s2 {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}};
square s3 {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}};
square s4 {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}};
square s5 {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}};
square s6 {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}};
square s7 {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}};
square s8 {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}};

vector<square> solutions = {s1, s2, s3, s4, s5, s6, s7, s8};

int subtractSquares(const square &s1, const square &s2)
{
  int diff = 0;

  for (size_t i = 0; i < s1.size(); ++i)
    for (size_t j = 0; j < s1[0].size(); ++j)
      diff += abs( s1[i][j] - s2[i][j] );

  return diff;
}



int formingMagicSquare(square s)
{
  int best_diff = INT_MAX;
  int cur_diff;

  for (auto sol : solutions) {
    cur_diff = subtractSquares(sol, s);

    if (cur_diff < best_diff)
      best_diff = cur_diff;
  }

  return best_diff;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
