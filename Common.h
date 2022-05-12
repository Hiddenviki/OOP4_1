//
// Created by Виктория Веселкова on 09.05.2022.
//

#pragma once
#include <iostream>


class Common {

friend class Box;
protected:

    double saldo; //вынесла сюда потому что оно есть в обоих классах

public:

    virtual void show_data1();
    virtual void show_data2();
    virtual void add_data();
    virtual void sort();


};
