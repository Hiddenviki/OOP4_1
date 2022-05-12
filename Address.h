//
// Created by Виктория Веселкова on 09.05.2022.
//

#pragma once
#include <iostream>

class Address {

public:
    std::string country;
    std::string city;
    std::string building_number;

    std::string show_pretty_address();
};


