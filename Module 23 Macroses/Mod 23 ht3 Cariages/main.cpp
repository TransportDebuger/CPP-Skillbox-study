#include <iostream>

#define NUM_CARIAGES 10
#define MAX_SEATS 20
#define LOOP(IT, MAXINDEX) for(int IT=0; IT<int(MAXINDEX); ++IT)


using namespace std;

inline bool isNotFull(int passengers) {
    return (passengers < MAX_SEATS);
}

inline bool isOverloaded(int passengers) {
    return (passengers > MAX_SEATS);
}

int passTotal(int pas[]) {
    int res = 0, it = 0;
    LOOP(it, NUM_CARIAGES) {
        res += pas[it];
    }
    return  res;
}

void PrintOverCar(int pas[]) {
    int it = 0;
    LOOP(it, NUM_CARIAGES) {
        if (pas[it]>MAX_SEATS) cout << pas[it] << " ";
    }
}

void PrintNotFullCar(int pas[]) {
    int it = 0;
    LOOP(it, NUM_CARIAGES) {
        if (pas[it]<MAX_SEATS) cout << pas[it] << " ";
    }
}

int main() {
    int pCount[NUM_CARIAGES]; // = {1, 20, 19, 22, 20, 20, 18, 17, 25, 20};
    int cCount = 0;
    do {
      int pas;
      cout << "Enter number of passenger in carige " << cCount+1 <<": ";
      cin >> pas;
      if (pas>=0) {
        pCount[cCount] = pas;
        cCount++;
      };
    } while (cCount < NUM_CARIAGES);
    cout << endl;
    cout << "Overloaded cariages: ";
    PrintOverCar(pCount);
    cout << endl;
    cout << "Not full cariages: ";
    PrintNotFullCar(pCount);
    cout << endl;
    cout << "Passenger total: " << passTotal(pCount) << endl;
}