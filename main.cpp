#include <iostream>
#include "Firm_info.h"
#include "Supplier_info.h"
#include "Box.h"

int showMenu()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {

        std::cout<<std::endl;
        std::cout << "____________________МЕНЮ____________________" << std::endl;
        std::cout << " 1.      Вывести бАзУ" << std::endl;
        std::cout << " 2.      Добавить новую информацию" << std::endl;
        std::cout << " 3.      Найти информацию по названию фирмы" << std::endl;
        std::cout << " 4.      Рассортировать таблицу по уменьшению sAldO" << std::endl;
        std::cout << " 5.      Сохранить все новые поля нА дИсК и выйти из программы" << std::endl;
        std::cout<<std::endl;
        std::cout << "Введите число [1 , 6]" << std::endl;
        int a;
        std::cin >> a;

        if (std::cin.fail() or (a <= 0) or (a>5)) // если предыдущее извлечение оказалось неудачным
        {
            std::cout<<"НЕПРАВИЛЬНЫЙ ВВОД В МЕНЮ"<<std::endl;
            std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
            std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
        }
        else // если всё хорошо, то возвращаем a

            return a;
    }
}

int Box::the_longest_FIO=35;
int Box::the_longest_Address=30;
int Box::the_longest_Name=15;
int Box::count = 0;

int main(){
    setlocale(LC_ALL,"rus");

    Supplier_info supplier_element;
    Firm_info firm_element;
    Box box;

    box.readDataFromDisk();

    int a;
    do {

        a = showMenu();

        switch (a)
        {
            case 1: //вывести то что есть в бАзЕ
                if (Box::count == 0)
                {
                    std::cout<<"Еще ничего нет, начинайте добавлять объекты"<<std::endl;
                }
                else
                {
                    box.show_data1();
                    std::cout<<"\n";
                    box.show_data2();
                }
                break;

            case 2: //добавить новый товар
                box.addElement();
                break;

            case 3: //Найти товар по названию
                  find_by_firm_name(box.firmInfo_array);
                break;

            case 4: //Рассортировать это по уменьшению sAldO
                box.sort();
                break;

            case 5: //Сохранить всё и завершить работу
                box.saveDataOnDisk();
                break;

            default:
                std::cout<<"Неверно введен номер действия"<<std::endl;
                break;

        }

    } while (a != 5);

    return 0;
};