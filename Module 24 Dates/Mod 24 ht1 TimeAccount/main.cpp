#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

int main() {
  std::cout << "Timer!" << std::endl;
  std::cout << "Enter timer interval (MM:SS) > ";
  string bufStr;
  getline(cin, bufStr);
  stringstream bs;
  bs << bufStr;
  struct tm destTime = {0};
  bs >> get_time(&destTime, "%M:%S");
  time_t now = time(nullptr), t_delta = destTime.tm_sec + destTime.tm_min * 60,
         t_new = now + t_delta;
  cout << "Current time: " << put_time(localtime(&now), "%Y/%m/%d %H:%M:%S")
       << endl;
  cout << "Destination time: "
       << put_time(localtime(&t_new), "%Y/%m/%d %H:%M:%S") << endl;
  do {
    time_t tnow = time(nullptr);
    if (tnow > now) {
      now = tnow;
      destTime = *(localtime(&now));
      cout << destTime.tm_min << ":" << destTime.tm_sec << endl;
      if (now >= t_new)
        cout << "DING! DING! DING!" << endl;
    }
  } while (now < t_new);
  return 0;
}
