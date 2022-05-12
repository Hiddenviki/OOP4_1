//
// Created by Виктория Веселкова on 09.05.2022.
//

#include "FIO.h"

std::string FIO::show_pretty_fio() const {
    std::string full_fio = person_surname + " " + person_name + " " + person_patronymic;
    return full_fio;
}

