//
// Created by Виктория Веселкова on 09.05.2022.
//


#pragma once
#include <iostream>

class Date {

public:
    int day;
    std::string month;
    int year;

    std::string show_pretty_date() const;

};

