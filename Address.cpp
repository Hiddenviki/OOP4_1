//
// Created by Виктория Веселкова on 09.05.2022.
//

#include "Address.h"

std::string Address::show_pretty_address() {
    std::string full_address = "Country: "+country+"; "+"City: "+city+"; "+"Building: "+building_number;
    return full_address;
}

//есди надо прайват то просто сделать геттеры и паблик поменять на прайват итут делать через геттеры но нахй это надо