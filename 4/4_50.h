#ifndef _4_50_H_
#define _4_50_H_

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#define MAX_BUFFER 1024

#define STEP " "

void load_cpp_file(const std::string &filepath)
{
    //按照行 load file

    std::ifstream file;
    file.open(filepath);
    std::string line;
    char buff[MAX_BUFFER + 1];
    bool jump = false;
    int linenum = -1;
    while (getline(file,line))
    {   
        linenum++;
        memset(buff, 0 ,MAX_BUFFER + 1);
        memcpy(buff,line.c_str(),MAX_BUFFER);
        char* token  = std::strtok(buff, STEP);
        while (token != nullptr)
        {
            std::cout << token ;
            token  = std::strtok(NULL, STEP);
        }
        std::cout << std::endl ;
    }

    // 排序 按照字母顺序

    std::cout << "end" << std::endl;
    // 输出
}

#endif