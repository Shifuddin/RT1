//
// Created by shifuddin on 5/7/2016.
//

#include "Ident.h"

std::vector<std::string> fetch_current_ident()
{
    char package_name[1000], package_info[1000];
    FILE *temp;
    std::vector<std::string> package_list;
    std::vector <std::string> v;
    std::string non_sys = "non";
    char *comma = ",";
    int i;

    if(!(temp = popen("pm list packages -f", "r")))
            {
                return v;
            }
            while(fgets(package_name, 1000, temp))
            {
                if (strcmp(filter_package(package_name), non_sys.c_str()) != 0)
                {
                        package_list.push_back(filter_package(package_name));

                }
            }
            pclose(temp);

            for(i = 0; i < package_list.size(); i++)
            {

                if ( ! (temp = popen(("stat " + package_list[i]).c_str(), "r")) )
                {
                        return v;
                }

                while(fgets(package_info, 1000, temp))
                {
                    if(is_modification_date(package_info))
                    {
                        v.push_back(str_append(package_list[i],comma, package_info));
                    }
                }
            }
            pclose(temp);
            return v;
}

std::vector<std::string> fetch_previous_ident(const char *full_file_name)
{
    FILE *file;
    std::vector<std::string> v;
    char line[1000];

    if(!(file = fopen(full_file_name, "r")))
    {
        //return ;//env->NewStringUTF("Can't open file for writing");
    }

    while(fgets(line, 1000, file))
    {
        v.push_back(line);
    }

    fclose(file);
    return v;
}

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

bool is_ident_match(std::vector<std::string> v1, std::vector<std::string> v2)
{
    int count, i, j;

            if(v1.size() == v2.size())
             {
             return true;

                for(i = 0; i < v1.size(); i++)
                {
                    count = 0;

                    for(j = 0; j < v2.size(); j++)
                    {

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