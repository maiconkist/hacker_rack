#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>  /* cin */
#include <algorithm>
#include <fstream>   /* ofstream */
#include <climits>

using namespace std;

vector<string> split_string(string);

typedef vector<int> Clouds;
typedef vector<int> Solution;


int minSteps(const Clouds &cl, int n) {
  if (n == 0) return 0;
  if (n == -1) return INT_MAX;
  if (cl[n] == 1) return INT_MAX;

  return min(minSteps(cl, n-1), minSteps(cl, n-2)) + 1;
}

// Complete the jumpingOnClouds function below.
int jumpingOnClouds(Clouds c) {
    size_t csize = c.size();
    return min(minSteps(c, csize-2), minSteps(c, csize-3)) + 1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = jumpingOnClouds(c);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
