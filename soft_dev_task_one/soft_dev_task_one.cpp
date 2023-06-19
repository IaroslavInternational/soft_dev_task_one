#include <iostream>

#include "StringProcessor.hpp"

int main()
{
    setlocale(LC_ALL, "Russian");

    std::string str;
    bool flag = true;

    StringProcessor str_proc;
    double res;

    while (flag)
    {
        std::cout << "Введите выражение:" << std::endl;

        std::getline(std::cin, str);

        if (str == "E")
        {
            flag = false;
        }

        res = str_proc.Process(str);

        if (res != -1.0)
        {
            std::cout << "Ответ: " << res << std::endl;
        }
    }

    return 0;
}