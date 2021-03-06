//
// Created by Виктория Веселкова on 08.05.2022.
//

#include <iostream>
#include <vector>


int CheckDay()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        std::cout << "День: ";
        int a;
        std::cin >> a;

        if (std::cin.fail() or (a <=0) or (a>31)) // если предыдущее извлечение оказалось неудачным,
        {
            std::cout<<"Введите нормально день\n";
            std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
            std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
        }
        else // если всё хорошо, то возвращаем a
            return a;
    }
}

double CheckSaldo()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        std::cout << "Сальдо: ";
        double a;
        std::cin >> a;

        if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
        {
            std::cout<<"Введите нормально пожалуйста тут везде точно есть проверка клянусь президентом РФ\n";
            std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
            std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
        }
        else // если всё хорошо, то возвращаем a
            return a;
    }
}

int CheckYear()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        std::cout << "Год: ";
        int a;
        std::cin >> a;

        if (std::cin.fail() or (a <=0) or (a>2022)) // если предыдущее извлечение оказалось неудачным,
        {
            std::cout<<"Год нужно вводить без посторонних символов в промежутке [1,2022]\n";
            std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
            std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
        }
        else // если всё хорошо, то возвращаем a
            return a;
    }
}

int CheckType()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        std::cout << "Выберите тип поставщика (1 - поставщик сырья, 2 - поставщик оборудования) "<<std::endl;
        int a;
        std::cin >> a;

        if (std::cin.fail() or (a < 1) or (a > 2)) // если предыдущее извлечение оказалось неудачным,
        {
            std::cout<<"ЕСТЬ ТОЛЬКО 1 И 2\n";
            std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
            std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
        }
        else // если всё хорошо, то возвращаем a
            return a;
    }
}

//////4 CheckMonth//////
std::vector<std::string>months {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
bool in_array(const std::string &value, const std::vector<std::string> &array)
{
    return std::find(array.begin(), array.end(), value) != array.end();
}
bool found(const std::string& any_str){
    if (in_array(any_str, months)){
        return true;
    }
    else{
        return false;
    }
}
//////4 CheckMonth//////

std::string CheckMonth()
{

    std::string str;
    bool not_found;
    do{
        std::cout<<"Месяц: ";
        std::cin>>str;

        if (not found(str)){
            std::cout<<"Месяц нужно вводить СЛОВАМИ и с БОЛЬШОЙ буквы"<<std::endl<<"Повторите ввод"<<std::endl;
            not_found = true; //не нашли
        }
        else{
            not_found = false; //опа, нашли
        }

    }while(not_found);

    return str;
}

std::string CheckFirmName()
{
    int i;
    std::string str;
    do{
        std::cout<<"Название: ";
        std::cin>>str;

        for(i=0;str[i];i++)
        {
            if((str[i]>='0' and str[i]<='9' and str[i]) or (str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{') or (str[0]!=toupper(str[0])) )
                break;
        }

        if( str[i]){std::cout<<"Название нужно вводить с Большой буквы и без посторонних символов"<<std::endl<<"Повторите ввод"<<std::endl; }



    }while(str[i]);

    return str;
} //название фирмы

std::string CheckCountry()
{
    int i;
    std::string str;
    do{
        std::cout<<"Страна: ";
        std::cin>>str;

        for(i=0;str[i];i++)
        {
            if((str[i]>='0' and str[i]<='9' and str[i]) or (str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{') or (str[0]!=toupper(str[0])) )
                break;
        }

        if( str[i]){std::cout<<"Страну нужно вводить с Большой буквы и без посторонних символов"<<std::endl<<"Повторите ввод"<<std::endl; }



    }while(str[i]);

    return str;
}

std::string CheckCity()
{
    int i;
    std::string str;
    do{
        std::cout<<"Город: ";
        std::cin>>str;

        for(i=0;str[i];i++)
        {
            if((str[i]>='0' and str[i]<='9' and str[i]) or (str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{') or (str[0]!=toupper(str[0])) )
                break;
        }

        if( str[i]){std::cout<<"Город нужно вводить с Большой буквы и без посторонних символов"<<std::endl<<"Повторите ввод"<<std::endl; }



    }while(str[i]);

    return str;
}

std::string CheckBuilding()
{
    int i;
    std::string str;
    do{
        std::cout<<"Строение: ";
        std::cin>>str;

        for(i=0;str[i];i++)
        {
            if( (str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{') )
                break;
        }

        if( str[i]){std::cout<<"Строение нужно вводить без посторонних символов"<<std::endl<<"Повторите ввод"<<std::endl; }



    }while(str[i]);

    return str;
}


std::string CheckPersonName()
{
    int i;
    std::string str;
    do{
        std::cout<<"Имя поставщика: ";
        std::cin>>str;

        for(i=0;str[i];i++)
        {
            if((str[i]>='0' and str[i]<='9' and str[i]) or (str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{') or (str[0]!=toupper(str[0])) )
                break;
        }

        if( str[i]){std::cout<<"Имя нужно вводить с Большой буквы и без посторонних символов"<<std::endl<<"Повторите ввод"<<std::endl; }



    }while(str[i]);

    return str;
}

std::string CheckPersonSurname()
{
    int i;
    std::string str;
    do{
        std::cout<<"Фамилия поставщика: ";
        std::cin>>str;

        for(i=0;str[i];i++)
        {
            if((str[i]>='0' and str[i]<='9' and str[i]) or (str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{') or (str[0]!=toupper(str[0])) )
                break;
        }

        if( str[i]){std::cout<<"Фамилию нужно вводить с Большой буквы и без посторонних символов"<<std::endl<<"Повторите ввод"<<std::endl; }



    }while(str[i]);

    return str;
}

std::string CheckPersonPatronymic()
{
    int i;
    std::string str;
    do{
        std::cout<<"Отчество поставщика: ";
        std::cin>>str;

        for(i=0;str[i];i++)
        {
            if((str[i]>='0' and str[i]<='9' and str[i]) or (str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{') or (str[0]!=toupper(str[0])) )
                break;
        }

        if( str[i]){std::cout<<"Отчество нужно вводить с Большой буквы и без посторонних символов"<<std::endl<<"Повторите ввод"<<std::endl; }



    }while(str[i]);

    return str;
}

