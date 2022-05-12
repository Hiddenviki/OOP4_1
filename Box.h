//
// Created by Виктория Веселкова on 10.05.2022.
//

#pragma once
#include <iostream>
#include "Firm_info.h"
#include "Supplier_info.h"

class Box: public Firm_info, public Supplier_info{
public:

    Firm_info* firmInfo_array;
    Supplier_info* supplierInfo_array;
    Common* common_array;

    static int the_longest_Address;//для таблицы
    static int the_longest_Name ; //для таблицы
    static int the_longest_FIO; //для таблицы
    static int count;

    Box(){
        the_longest_Address = 25;
        the_longest_Name = 25;
        the_longest_FIO = 25;
        count = 0;
        firmInfo_array = nullptr;
        supplierInfo_array = nullptr;
        common_array = nullptr;

    };

    void addElement();

    void show_data1() override; //about supplier
    void show_data2() override; //about firm
    void sort() override;

    void saveDataOnDisk();
    void readDataFromDisk();

};
