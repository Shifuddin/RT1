//
// Created by shifuddin on 5/7/2016.
//

#ifndef DIRECTIONPOINTER_STRING_MANIPULATOR_H
#define DIRECTIONPOINTER_STRING_MANIPULATOR_H
#include "Headers.h"

#define START 1
#define END 6
#define EQUAL '='
#define COLON ':'

//Method Declaration
std::string str_append(std::string first_sequence, char* delimiter, char* last_sequence);
bool is_modification_date(std::string message);
bool is_system_package(std::string package);
const char* filter_package(std::string package);
#endif //DIRECTIONPOINTER_STRING_MANIPULATOR_H
