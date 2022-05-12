//
// Created by Виктория Веселкова on 08.05.2022.
//

#include "Supplier_info.h"
#include "StreamTable.h" //for showing the data
#include "Box.h" //for variable int

int CheckDay();
std::string CheckMonth();
int CheckYear();

std::string CheckPersonName();
std::string CheckPersonSurname();
std::string CheckPersonPatronymic();

Supplier_info::Supplier_info() {

}
Supplier_info::~Supplier_info() {

}

void Supplier_info::show_data1() {} //таблица про поставщика

Supplier_info &Supplier_info::operator=(const Supplier_info &equal) {
    if (this == &equal)
        return *this;

    date_class.day=equal.date_class.day;
    date_class.month=equal.date_class.month;
    date_class.year = equal.date_class.year;

    fio_class.person_surname=equal.fio_class.person_surname;
    fio_class.person_name = equal.fio_class.person_name;
    fio_class.person_patronymic = equal.fio_class.person_patronymic;

    return *this;
}

void Supplier_info::add_data() {

    this->fio_class.person_name=CheckPersonName();
    this->fio_class.person_surname=CheckPersonSurname();
    this->fio_class.person_patronymic=CheckPersonPatronymic();

    this->date_class.day=CheckDay();
    this->date_class.month=CheckMonth();
    this->date_class.year=CheckYear();

}

void Supplier_info::sort() {}




