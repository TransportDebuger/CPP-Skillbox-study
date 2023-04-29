#include <iostream>
#include <string>
#include <sstream>

//Перечисление состояний выключателей
enum switches {
  MASTER_POWER_SWITCH = 1,
  HOUSE_OUTLETS = 2,
  INNER_LIGHT = 4,
  OUTER_LIGHT = 8,
  HOUSE_WARMING= 16,
  WATER_WARMING = 32,
  CLIMATE_CONTROL = 64
};

//Задаем состояние переключателя.
int setSwitchState(int state, switches key, bool isOn=true) {
    return state  = isOn?(state | key):(state & (~key)); 
};

//Преобразуем текстовые ответы к булеву значению.
bool stob(std::string text) {
  return text=="YES" || text=="yes" || text=="Y" || text=="y" || text=="ON" || text=="on";
}

//Вывод событий на экран.
void printEvents(int curState, int changes, int time) {
  //Пока нашел только такой способ последовательного перебора значений перечислений.
  //TO DO: погуглить на тему иного способа перебора констант по индексам. Можно наверное map создать, это было бы удобнее перебирать чем 2 массива.
  switches arr1[7] = {MASTER_POWER_SWITCH, HOUSE_OUTLETS, INNER_LIGHT,
                   OUTER_LIGHT, HOUSE_WARMING, WATER_WARMING, CLIMATE_CONTROL};
  //Массив человекопонятного вывода.
  std::string swcall[7] = {"Master Power switch: ", "House outles: ", 
                          "Indoor light: ", "Outdoor light: ", 
                          "House warming system: ", "Water warming system: ",
                          "Air conditioner: "};
  //Поехали смотреть изменение состояний и измененые состояния. Ну и выводим на экран соответственно.
  std::cout << "-----Changes report------------------------------------------------" << std::endl;
  for (int i=0; i<7; i++) {
    if (changes & arr1[i]) {
      std::cout << swcall[i];
      if (!(curState & arr1[i])) {std::cout << "OFF" << std::endl;} 
      else {
        std::cout << "ON" << std::endl; 
        //Вообще криво. Надо бы к содержанию флага привязываться, а не к индексу массива:).
        if (i==2) {
          if (time>16) {
            std::cout << "Light color temperature: " << 5000 - ((5000-2700)/6)*(time-16) << "K" << std::endl; 
          } else if (time>22) {
          std::cout << "Light color temperature: 2700K" << std::endl;
          } else {
            std::cout << "Light color temperature: 5000K" << std::endl;
          }
        }
      }
    }
  } 
  std::cout << "-------------------------------------------------------------------" << std::endl; 
}

int main() {
  std::cout << "SMART HOUSE." << std::endl;
  
  //Инициализация состояний переключателей (все выключено).
  int swState = 0;
  
  //Симуляция.
  for (int days=0; days<2; days++ ) {
    //Каждый час вводим состояние датчиков.
    for (int hours=0; hours<=23; hours++) {
      //Предыдущее состояние переключателей
      std::cout << "Current day: " << days << " Current time: " << hours << ":00" << std::endl;
      int prevState = swState;
      //std::cout << "Do you want to print report? (Yes=Y/No=Any other): ";
      std::string answer;
      std::stringstream curInfo;
      //std::cin >> answer;
      //if (stob(answer)) {printEvents(swState, 127);}
      std::cout << "You must enter information for Smart House in one string by next order:" << std::endl;
      std::cout << "State of Master Power switch (ON/OFF)" << std::endl;
      std::cout << "State of house outlets (ON/OFF)" << std::endl;
      std::cout << "State of light inside house (ON/OFF)" << std::endl;
      std::cout << "Any movements outside house (YES/NO)" << std::endl;
      std::cout << "Air temperature inside house (integer value)" << std::endl;
      std::cout << "Air temperature outside house (integer value)" << std::endl;
      std::cout << "Enter the information: ";
      //Принимаем данные от пользователя и отправляем их в буфер.
      std::getline(std::cin, answer);
      curInfo << answer;
      std::string MPSwitch, HOSwitch, LISwitch, MOHpresence;
      int inTemperature, outTemperature;
      curInfo >> MPSwitch >> HOSwitch >> LISwitch >> MOHpresence >> inTemperature  >> outTemperature;
      if (!stob(MPSwitch)) {
        swState = setSwitchState(swState, MASTER_POWER_SWITCH, stob(MPSwitch));
        swState = setSwitchState(swState, HOUSE_OUTLETS, stob(MPSwitch));
        swState = setSwitchState(swState, INNER_LIGHT, stob(MPSwitch));
        swState = setSwitchState(swState, OUTER_LIGHT, stob(MPSwitch));
        swState = setSwitchState(swState, HOUSE_WARMING, stob(MPSwitch));
        swState = setSwitchState(swState, WATER_WARMING, stob(MPSwitch));
        swState = setSwitchState(swState, CLIMATE_CONTROL, stob(MPSwitch));
      } else {
        swState = setSwitchState(swState, MASTER_POWER_SWITCH, stob(MPSwitch));
        swState = setSwitchState(swState, HOUSE_OUTLETS, stob(HOSwitch));
        swState = setSwitchState(swState, INNER_LIGHT, stob(LISwitch));
        if (inTemperature < 22) {swState = setSwitchState(swState, HOUSE_WARMING);} if (inTemperature <= 25) {swState = setSwitchState(swState, CLIMATE_CONTROL, false);}
        if (inTemperature >= 25) {swState = setSwitchState(swState, HOUSE_WARMING, false);}
        if (inTemperature >= 30) {swState = setSwitchState(swState, CLIMATE_CONTROL);}
        if (outTemperature < 0) {swState = setSwitchState(swState, WATER_WARMING);}
        else if (outTemperature > 5) {swState = setSwitchState(swState, WATER_WARMING, false);}
        if (hours<5 || hours>16) {swState = setSwitchState(swState, OUTER_LIGHT, stob(MOHpresence));} else {swState = setSwitchState(swState, OUTER_LIGHT, false);}

      }
      int diff = prevState^swState;
      printEvents(swState, diff, hours);
    }
  }
}