//
// Created by shifuddin on 5/7/2016.
//

#ifndef DIRECTIONPOINTER_IDENT_H
#define DIRECTIONPOINTER_IDENT_H
#include "Headers.h"
#include "String_Manipulator.h"
std::vector<std::string> fetch_current_ident();
std::vector<std::string> fetch_previous_ident();
void write_false_ident();
void write_ident_file(std::vector<std::string> v);
bool is_ident_match(std::vector<std::string> v1, std::vector<std::string> v2);
#endif //DIRECTIONPOINTER_IDENT_H
