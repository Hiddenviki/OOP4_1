//
// Created by Виктория Веселкова on 10.05.2022.
//

#include "Box.h"
#include "StreamTable.h"

std::ofstream record; //поток для записи в файл
std::ifstream read; //поток для чтения из файла

void Box::addElement()
{

    Firm_info *tmpFirmInfo;
    Supplier_info *tmpSupplierInfo;
    Common *tmpCommon;

    if (count == 0)
    {
        firmInfo_array = new Firm_info[count + 1];
        supplierInfo_array = new Supplier_info[count + 1];
        common_array = new Common[count + 1];

        supplierInfo_array[count].add_data();
        firmInfo_array[count].add_data();
        common_array[count].add_data();

        count++;
    }
    else if(count != 0)
    {

        tmpFirmInfo = new Firm_info[count+1];
        tmpSupplierInfo = new Supplier_info[count+1];
        tmpCommon = new Common[count+1];

        for (int i = 0; i < count; i++)
        {
            tmpFirmInfo[i] = firmInfo_array[i];
            tmpSupplierInfo[i] = supplierInfo_array[i];
            tmpCommon[i] = common_array[i];
        }

        delete[] firmInfo_array;
        delete[] supplierInfo_array;
        delete[] common_array;
        firmInfo_array = tmpFirmInfo;
        supplierInfo_array = tmpSupplierInfo;
        common_array = tmpCommon;

        supplierInfo_array[count].add_data();
        firmInfo_array[count].add_data();
        common_array[count].add_data();

        count++;
    }
    else{
        std::cout<<"Ошибка в Box.cpp--addElement()"<<std::endl;
    }


}

void Box::saveDataOnDisk()
{
    record.open("file.txt"); //открываю файл для ЗАПИСИ
    record<<count<<std::endl; //сначала записываю количество данных в первую строку

    for (int i=0; i < count; i++)
    {

        record<<supplierInfo_array[i].fio_class.person_name<<" "<<supplierInfo_array[i].fio_class.person_surname<<" "<<supplierInfo_array[i].fio_class.person_patronymic<<
        " "<<firmInfo_array[i].firm_name<<" "<<firmInfo_array[i].type_of_supplier<<" "<<firmInfo_array[i].address_class.country<<" "<<firmInfo_array[i].address_class.city<<" "<<firmInfo_array[i].address_class.building_number<<
        " "<<common_array[i].saldo<<" "<< supplierInfo_array[i].date_class.day<<" "<<supplierInfo_array[i].date_class.month<<" "<<supplierInfo_array[i].date_class.year<<std::endl;

    } //ну вот, записали

    record.close(); //закрываю файл окончательно, типа знаю хороший тон АХАХА
}

void Box::readDataFromDisk()
{
    if (std::filesystem::is_empty("file.txt")){std::cout<<"Ранее добавленных объектов не найдено"<<std::endl;}
    else
    {
        read.open("file.txt"); //открываю файл для ЧТЕНИЯ
        int current_count;

        read>>current_count; //сначала записываю количество данных из первой строки в память
        count=current_count;

        firmInfo_array = new Firm_info[count];
        supplierInfo_array = new Supplier_info[count];
        common_array = new Common[count];

        for(int i=0; i<count; i++)
        {
            std::string personName,personSurname,personPatronymic,firmName,country,city,building,current_month;
            double new_saldo;
            int current_type,current_day,current_year;
            read >>personName>>personSurname>>personPatronymic>>firmName>>current_type>>country>>city>>building>>new_saldo
                 >>current_day>>current_month>>current_year;

            supplierInfo_array[i].fio_class.person_name = personName;
            supplierInfo_array[i].fio_class.person_surname = personSurname;
            supplierInfo_array[i].fio_class.person_patronymic = personPatronymic;

            supplierInfo_array[i].date_class.day = current_day;
            supplierInfo_array[i].date_class.month = current_month;
            supplierInfo_array[i].date_class.year = current_year;

            firmInfo_array[i].firm_name = firmName;
            firmInfo_array[i].type_of_supplier = (current_type == 1 ? Firm_info::RAW_MATERIAL_SUPPLIER : Firm_info::EQUIPMENT_SUPPLIER);

            firmInfo_array[i].address_class.country = country;
            firmInfo_array[i].address_class.city = city;
            firmInfo_array[i].address_class.building_number = building;
            common_array[i].saldo = new_saldo;


            if ((supplierInfo_array[i].fio_class.show_pretty_fio()).length() > the_longest_FIO){the_longest_FIO=(supplierInfo_array[i].fio_class.show_pretty_fio()).length();}
            if ((firmInfo_array[i].firm_name).length() > the_longest_Name){the_longest_Name=(firmInfo_array[i].firm_name).length();}
            if((firmInfo_array[i].address_class.show_pretty_address()).length()>the_longest_Address){the_longest_Address = (firmInfo_array[i].address_class.show_pretty_address()).length();}
        }
        read.close();
        std::cout<<"Количество считанных объектов: "<<count<<std::endl;
    }


}


//read data from disk

void Box::show_data1() {

    StreamTable st(std::cout);

    st.AddCol(10);
    st.AddCol(the_longest_FIO+2);
    st.AddCol(30);
    st.AddCol(10);

    st.MakeBorderExt(true);
    st.SetDelimRow(true, '-');//st.SetDelimRow(false);//без символов-разделителей строк
    st.SetDelimCol(true, '|');//st.SetDelimCol(false);//без символов-разделителей строк

    std::cout<<"INFORMATION ABOUT SUPPLIERS:"<<std::endl;
    st <<"NUM" <<"SUPPLIER'S FIO" << "DATE"<< "SALDO" ;
    for (int i = 0; i < count; i++)
    {
        st << i+1 << supplierInfo_array[i].fio_class.show_pretty_fio() << supplierInfo_array[i].date_class.show_pretty_date()<< common_array[i].saldo;
    }

} //shows suppliers
void Box::show_data2() {

    StreamTable st(std::cout);

    st.AddCol(10);
    st.AddCol(the_longest_Name+2);
    st.AddCol(the_longest_Address+2);
    st.AddCol(20);
    st.AddCol(10);

    st.MakeBorderExt(true);
    st.SetDelimRow(true, '-');//st.SetDelimRow(false);//без символов-разделителей строк
    st.SetDelimCol(true, '|');//st.SetDelimCol(false);//без символов-разделителей строк

    std::cout<<"INFORMATION ABOUT FIRMS:"<<std::endl;
    st << "NUM" << "FIRM" << "ADDRESS" << "SUPPLIER'S TYPE" << "SALDO" ;
    for (int i = 0; i < count; i++)
    {
        st << i+1 << firmInfo_array[i].firm_name << firmInfo_array[i].address_class.show_pretty_address() << firmInfo_array[i].type_of_supplier << common_array[i].saldo;
    }


} //shows firm

void Box::sort() {

    for (int i = Box::count - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            // сравниваем элементы по уменьшению sAlDo
            if (common_array[j].saldo < common_array[j + 1].saldo) {
                std::swap(common_array[j],common_array[j+1]);
                std::swap(supplierInfo_array[j],supplierInfo_array[j+1]);
                std::swap(firmInfo_array[j],firmInfo_array[j+1]);

            }
        }
    }
    show_data1();
    show_data2();

} //sorted suppliers
