void load_cpp_file(const std::string &filepath)
{
    //按照行 load file

    std::ifstream file;
    file.open(filepath);
    std::string line;
    char buff[MAX_BUFFER + 1];
    while (getline(file,line))
    {
        memset(buff, 0 ,MAX_BUFFER + 1);
        memcpy(buff,line.c_str(),MAX_BUFFER);
        char *token  = std::strtok(buff, STEP);
        while (token != nullptr)
        {
            std::cout << token <<std::endl;
            token  = std::strtok(NULL, STEP);
        }
    }

    // 排序 按照字母顺序

    std::cout << "end" << std::endl;
    // 输出
}