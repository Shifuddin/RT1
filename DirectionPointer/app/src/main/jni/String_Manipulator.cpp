// This class responsible for custom string manipulation on package names
// Created by shifuddin on 5/7/2016.
//

#include "String_Manipulator.h"
using namespace std;


/*
 * Class:     String_Manipulator
 * Method:    str_concat
 * Signature: ()S
 * Purpose: Concat three sequences of charters
 * Parameter: string, string, char*
 */
std::string str_concat(std::string first_sequence, std::string delimiter, char* last_sequence)
{

    first_sequence.append(delimiter);
    return first_sequence.append(last_sequence);
}

/*
 * Class:     String_Manipulator
 * Method:    is_modification_date
 * Signature: ()b
 * Purpose: Check whether string contains modification date
 * Parameter: string
 */
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

/*
 * Class:     String_Manipulator
 * Method:    is_system_package
 * Signature: ()b
 * Purpose: Check whether given package is a system package
 * Parameter: string
 */
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
/*
 * Class:     String_Manipulator
 * Method:    filter_packages
 * Signature: ()char*
 * Purpose: Erases some part of the string comes from pm command and return package name if its a system package
 * Parameter: string
 */
const char* filter_package(string package)
{
    string not_sys = "non";
    package.erase(0, package.find(COLON)+1);
    package.erase(package.find(EQUAL), package.size());

    if(is_system_package(package))
    {
        return package.c_str();
    }
    else
        return not_sys.c_str();
}