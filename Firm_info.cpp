//
// Created by Виктория Веселкова on 08.05.2022.
//

#include "Firm_info.h"
#include "StreamTable.h" //for showing the data
#include "Box.h" //for static variable int count


int CheckType();

std::string CheckFirmName();
std::string CheckCountry();
std::string CheckCity();
std::string CheckBuilding();

double CheckSaldo();

Firm_info::Firm_info(){}
Firm_info::~Firm_info(){}

void Firm_info::show_data2() {}//таблица о фирме

Firm_info &Firm_info::operator=(const Firm_info &equal) {
    if (this == &equal)
        return *this;

    firm_name=equal.firm_name;
    type_of_supplier = equal.type_of_supplier;

    address_class.country=equal.address_class.country;
    address_class.city = equal.address_class.city;
    address_class.building_number = equal.address_class.building_number;

    return *this;

}

void Firm_info::add_data() {

    this->firm_name=CheckFirmName();
    int current_type = CheckType();
    this->type_of_supplier=(current_type == 1 ? Firm_info::RAW_MATERIAL_SUPPLIER : Firm_info::EQUIPMENT_SUPPLIER);
    this->address_class.country=CheckCountry();
    this->address_class.city=CheckCity();
    this->address_class.building_number=CheckBuilding();
    if ((this->firm_name).length() > Box::the_longest_Name){Box::the_longest_Name=(this->firm_name).length();}
    if ((this->address_class.show_pretty_address()).length() > Box::the_longest_Address){Box::the_longest_Address = (this->address_class.show_pretty_address()).length();}

}

void Firm_info::sort() {}

void find_by_firm_name(Firm_info* Obj) {

    std::string wanted_name = CheckFirmName();

    StreamTable st(std::cout);
    st.AddCol(Box::the_longest_Name+2);
    st.AddCol(Box::the_longest_Address+2);
    st.AddCol(Box::the_longest_FIO+2);
    //st.AddCol(10);

    st.MakeBorderExt(true);
    st.SetDelimRow(true, '-');//st.SetDelimRow(false);//без символов-разделителей строк
    st.SetDelimCol(true, '|');//st.SetDelimCol(false);//без символов-разделителей строк

    st << "FIRM" << "ADDRESS" << "SUPPLIER'S TYPE" ;//<< "SALDO" ;
    bool no_any = true;
    for (int i = 0; i < Box::count; i++)
    {
        std::string s1=Obj[i].firm_name;
        std::string s2=wanted_name;
        std::transform(s1.begin(), s1.end(), s1.begin(), tolower);
        std::transform(s2.begin(), s2.end(), s2.begin(), tolower);

        if ( (s1) == s2)
        {
            st << Obj[i].firm_name << Obj[i].address_class.show_pretty_address() << Obj[i].type_of_supplier; //<< Obj[i]. saldo;
            no_any=false;
        }
    }
    if (no_any)
    {
        st << "name"  << "address" << "type" << "saldo" ;
        std::cout<<"В базе нет такого"<<std::endl;
    }
}







