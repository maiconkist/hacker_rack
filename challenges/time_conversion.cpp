#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>

using namespace std;

enum TIME_POS { HOUR = 0, MINUTE = 1, SECOND = 2, END_TIME_POS };

template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
            *(result++) = item;
        }
}

std::vector<std::string>
split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

string timeConversion(string s) {
  /*
   *    * Write your code here.
   *       */
  vector<string> t = split(s, ':');

  string &second = t[TIME_POS::SECOND];
  bool is_pm = second.substr(2) == "PM";

  second = second.substr(0, 2);
  int hour = stoi(t[TIME_POS::HOUR]);
  if (is_pm) {
    t[TIME_POS::HOUR] = hour + 12 < 24? to_string(hour + 12) : "12";
  }
  else if (hour == 12)
  {
    t[TIME_POS::HOUR] = "00";
  }

  return std::accumulate(t.begin(), t.end(), string(),
            [](string &ss, string &s) { return ss.empty() ? s : ss + ":" + s; });
}

int main() {

  string s;
  getline(cin, s);

  string result = timeConversion(s);

  cout << result << endl;

  return 0;
}
