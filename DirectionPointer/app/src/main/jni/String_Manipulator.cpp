//
// Created by shifuddin on 5/7/2016.
//

#include "String_Manipulator.h"
using namespace std;


std::string str_append(std::string first_sequence, char* delimiter, char* last_sequence)
{

    first_sequence.append(delimiter);
    return first_sequence.append(last_sequence);
}

bool is_modification_date(std::string message)
{
    std::string modify_msg= "Modify:";
    if(message.find(modify_msg) != std::string::npos)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool is_system_package(std::string package)
{
    string system = "system";
    string sub_package = package.substr(1, 6);

    if(strcmp(system.c_str(), sub_package.c_str()) == 0)
    {
        return true;
    }
    else
        return false;
}

const char* filter_package(string package)
{
    string not_sys = "non";
    package.erase(0, package.find(COLON)+1);
    package.erase(package.find(EQUAL), package.size());
    string sub_package = package.substr(1, 6);

    if(is_system_package(package))
    {
        return package.c_str();
    }
    else
        return not_sys.c_str();

}