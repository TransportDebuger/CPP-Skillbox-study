#include <iostream>

using namespace std;

#define WDAY(day) ((day) == (1) ? "MONDAY" : WDAY2(day))
#define WDAY2(day) ((day) == (2) ? "TUESDAY" : WDAY3(day))
#define WDAY3(day) ((day) == (3) ? "WEDNESDAY" : WDAY4(day))
#define WDAY4(day) ((day) == (4) ? "THIRSDAY" : WDAY5(day))
#define WDAY5(day) ((day) == (5) ? "FRIDAY" : WDAY6(day))
#define WDAY6(day) ((day) == (6) ? "SATURDAY" : "SUNDAY")

int main() {
  cout << "Weekday\n";
  cout << "Enter order number the day of the week (1-7):";
  int day;
  cin >> day;
  cout << WDAY(day) << endl;
}