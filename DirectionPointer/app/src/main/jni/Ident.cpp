// This class responsible for storing and retrieving Identification data from Device
// Created by shifuddin on 5/7/2016.
//
#include "Ident.h"

/*
 * Class:     Ident
 * Method:    fetch_current_ident
 * Signature: ()vector
 * Purpose: Fetch current device information
 * Parameter: None
 */
std::vector<std::string> fetch_current_ident()
{
    char package_name[1000], package_info[1000];
    FILE *temp;
    std::vector<std::string> package_list;
    std::vector <std::string> v;
    std::string non_sys = "non";
    std::string comma = ",";
    int i;

    //command: pm list packages -f
    //Purpose: Find out all the installed packages
    if(!(temp = popen("pm list packages -f", "r")))
            {
                return v;
            }
            while(fgets(package_name, 1000, temp))
            {
                // Check whether it's a system package or not
                if (strcmp(filter_package(package_name), non_sys.c_str()) != 0)
                {
                        package_list.push_back(filter_package(package_name));

                }
            }
            pclose(temp);

            for(i = 0; i < package_list.size(); i++)
            {

                // Command: stat packagename
                // Purpose: Retrieve information of each package
                if ( ! (temp = popen(("stat " + package_list[i]).c_str(), "r")) )
                {
                        return v;
                }

                while(fgets(package_info, 1000, temp))
                {
                    // We are dealing with modification data of a system package
                    // Here package info is filtered and only modification info is taken into granted
                    if(is_modification_date(package_info))
                    {
                        v.push_back(str_concat(package_list[i],comma, package_info));
                    }
                }
            }
            pclose(temp);
            return v;
}

/*
 * Class:     Ident
 * Method:    fetch_previous_ident
 * Signature: ()vector
 * Purpose: Fetch previously loaded device information
 * Parameter: File name
 */

std::vector<std::string> fetch_previous_ident(const char *full_file_name)
{
    FILE *file;
    std::vector<std::string> v;
    char line[1000];

    file = fopen(full_file_name, "r");

    while(fgets(line, 1000, file))
    {
        v.push_back(line);
    }

    fclose(file);
    return v;
}

/*
 * Class:     Ident
 * Method:    write_false_dent
 * Signature: ()V
 * Purpose: Load false data
 * Parameter: File name
 */
void write_false_ident(const char *full_file_name)
{
    FILE *file;
    int i;

    if(!(file = fopen(full_file_name, "w")))
    {
        return;
    }

    fputs("false identification", file);
    fclose(file);
}

/*
 * Class:     Ident
 * Method:    write_ident_file
 * Signature: ()vector
 * Purpose: Write identification information into a file
 * Parameter: Vector with identification information, File Name
 */
void write_ident_file(std::vector<std::string> v, const char* full_file_name)
{
    FILE *file;
    int i;

    if(!(file = fopen(full_file_name, "w")))
    {
        return;
    }

    for(i = 0; i < v.size(); i++)
    {
        fputs(v[i].c_str(), file);
    }
    fclose(file);
}

/*
 * Class:     Ident
 * Method:    is_ident_match
 * Signature: ()b
 * Purpose: Check whether two identification information matches
 * Parameter: Vector with current identification information, Vector with previous identification information
 */
bool is_ident_match(std::vector<std::string> v1, std::vector<std::string> v2)
{
    int count, i, j;

            // First we enquire the size of two vectors
            if(v1.size() == v2.size())
             {
             return true;

                for(i = 0; i < v1.size(); i++)
                {
                    count = 0;

                    for(j = 0; j < v2.size(); j++)
                    {
                        //Finally check each entry of vectors
                         if (strcmp(v1[i].c_str(), v2[j].c_str()) == 0)
                         count++;
                    }

                    if (count == 0)
                    {
                        return false;
                    }
                }
                return true;
             }
             else
             {
                  return false;
             }
}