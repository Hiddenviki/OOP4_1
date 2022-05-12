//
// Created by Виктория Веселкова on 08.05.2022.
//supplier1

#pragma once
#include "Common.h"
#include "FIO.h"
#include "Date.h"
#include <fstream>

class Supplier_info: public Common{
    friend class Box;
protected:
    FIO fio_class;
    Date date_class;

public:

    Supplier_info();
    ~Supplier_info();

    void show_data1() override;
    void add_data() override;
    void sort() override;

    Supplier_info& operator = (const Supplier_info &equal);


};
