#include <bits/stdc++.h>
using namespace std;


void print_arr(vector<int> &scores) {
  for (auto &s: scores)
    cout << s << ", ";
  cout << endl;
}

int designerPdfViewer(vector<int> h, string word) {
  size_t max_height = 0;

  for (char const &c : word) {
    if (h[c - 'a'] > max_height) {
      max_height = h[c - 'a'];
    }
  }

  return max_height * word.size();
}

int main()
{
  string h_temp;
  getline(cin, h_temp);

  vector<int> heights;


  std::stringstream iss(h_temp);
  int number;
  while (iss >> number)
    heights.push_back(number);

  string word;
  getline(cin, word);

  int result = designerPdfViewer(heights, word);
  cout << result << endl;

  return 0;
}
