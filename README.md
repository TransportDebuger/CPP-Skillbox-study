# CPP-Study
Задачи курса "Профессия Разработчик на C++ с нуля" (SkillBox)

## 1. Вводный модуль. Первая программа
## 2. Целочисленные переменные. Данные и вычисления 
#### Задание 1. Улучшаем гонщика
Исправьте код программы так, чтобы значение скорости рассчитывалось автоматически.
Скорость — это сумма показателей двигателя, колёс и руля минус показатели дождя и ветра.

#include <iostream> 
int main() { 
int lap = 4; 
int speed = 358; 
int engine = 254; 
int wheels = 93; 
int steerinWheel = 49; 
int wind = 21; 
int rain = 17; 
std::cout << "===================\n"; 
std::cout << "Супер гонки. Круг " << lap << "\n"; 
std::cout << "===================\n"; 
std::cout << "Шумахер (" << speed << ")\n"; 
std::cout << "===================\n"; 
std::cout << "Водитель: Шумахер\n"; 
std::cout << "Скорость: " << speed << "\n"; 
std::cout << "-------------------\n"; 
std::cout << "Оснащение\n"; 
std::cout << "Двигатель: +" << engine << "\n"; 
std::cout << "Колеса: +" << wheels << "\n"; 
std::cout << "Руль: +" << steerinWheel << "\n"; 
std::cout << "-------------------\n"; 
std::cout << "Действия плохой погоды\n"; 
std::cout << "Ветер: -" << wind << "\n"; 
std::cout << "Дождь: -" << rain << "\n"; 
}

 
#### Задание 2. Калькулятор стоимости товара
Напишите калькулятор для расчёта полной стоимости товара. Она рассчитывается так: стоимость товара  + стоимость доставки – скидка. Все значения сохраните в переменные и выводите в нужных местах, имитируя ввод данных (речь про cout).

 
#### Задание 3. Время, время!
Напишите программу для ресторана быстрого питания «Крылышки и ножки». Компания хочет знать, какое количество клиентов успеет обслужить один кассир за рабочую смену. Время на обслуживание складывается из времени, за которое клиент делает заказ, и времени, за которое кассир собирает заказ и выдаёт его клиенту. Все расчёты проводите в минутах. Все значения сохраните в переменные и выводите в нужных местах, имитируя ввод данных.

Пример работы программы: 

Эта программа рассчитает, сколько клиентов успеет обслужить кассир за смену. 
Введите длительность смены в минутах: 480 
Сколько минут клиент делает заказ? 2 
Сколько минут кассир собирает заказ? 4 
-----Считаем----- 
За смену длиной 480 минут кассир успеет обслужить 80 клиентов.

 
#### Задание 4. Непонятная квитанция
Управляющая компания рассылает странные квитанции: в них указана только полная стоимость ремонта многоквартирного дома, а сколько должна платить конкретная квартира — непонятно. Напишите программу, с помощью которой жители квартир смогут посчитать, какую сумму им надо заплатить. Сумма делится на все квартиры вне зависимости от площади, количества жильцов и комнат. Все значения сохраните в переменные и выводите в нужных местах, имитируя ввод данных.

Пример работы программы: 

Приветствуем вас в калькуляторе квартплаты!  
  
Введите сумму, указанную в квитанции: 4000000 
Сколько подъездов в вашем доме? 10 
Сколько квартир в каждом подъезде? 40 
----Считаем----- 
Каждая квартира должна платить по 10 000 руб.

Что оценивается
    Программы запускаются и корректно работают, нет синтаксических ошибок.
    Правильно проводятся расчёты.
    Числа выводятся переменными, а не текстом.
    Переменные названы в соответствии со стилем именования переменных в C++. Имена переменных корректные, отражают суть хранимых данных, удобочитаемые.
    Выполнено три (или более) задания.
