//
// Created by Виктория Веселкова on 08.05.2022.
//Supplier

#pragma once
#include "Common.h"
#include <iostream>
#include "Address.h"
#include <fstream>

//#include "Box.h"

class Firm_info: public Common {
    friend class Box;
protected:

    std::string firm_name; //НАЗВАНИЕ ФИРМЫ
    enum Type{ RAW_MATERIAL_SUPPLIER = 1 , EQUIPMENT_SUPPLIER = 2 };
    Type type_of_supplier;
    Address address_class;

public:
    Firm_info();
    ~Firm_info();

    void show_data2() override;
    void add_data() override; //inside BOX'S method "addElement"
    void sort() override;

    friend void find_by_firm_name(Firm_info* Obj);

    Firm_info& operator = (const Firm_info &equal);

};



