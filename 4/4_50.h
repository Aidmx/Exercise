#ifndef _4_50_H_
#define _4_50_H_

#include <iostream>
#include <fstream>
#include <string>

void load_cpp_file(const std::string &filepath)
{
    //按照行 load file

    std::ifstream file;
    file.open(filepath);
    std::string line;
    while (getline(file,line))
    {


    }

    // 排序 按照字母顺序

    // 输出
}

#endif