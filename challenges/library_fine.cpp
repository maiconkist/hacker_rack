/*
 * Link:  https://www.hackerrank.com/challenges/library-fine
 */
/*
 *  Author: MK
 */
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

typedef struct date {
  int day;
  int month;
  int year;
} date;

int library_fine(date rned, date exped)
{
  /*  Different year */
  if (rned.year > exped.year) return 10000;
  if (rned.year < exped.year) return 0;

  /*  Same year, different month */
  if (rned.month > exped.month) return 500 * (rned.month - exped.month);
  if (rned.month < exped.month) return 0;

  /*  Same month, different day */
  if (rned.day > exped.day) return (rned.day - exped.day) * 15;
  return 0;
}


int main()
{
  date rned, exped;

  cin >> rned.day  >> rned.month  >> rned.year;
  cin >> exped.day >> exped.month >> exped.year;

  std::cout << library_fine(rned, exped) << std::endl;

  exit (EXIT_SUCCESS);
}
