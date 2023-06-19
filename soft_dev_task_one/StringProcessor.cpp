#include "StringProcessor.hpp"

StringProcessor::StringProcessor()
{
	operators = 
    {
        "+",
        "-",
        "*",
        "/",
        ">"
        "<",
        "==",
        "!="
    };
}

double StringProcessor::Process(std::string& str)
{
    std::pair<int, std::string> proc_operator = { -20, ""};

    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ')
        {
            str.erase(str.begin() + i, str.begin() + i + 1);
        }
    }

    for (auto& o : operators)
    {
        if (str.find(o) != -1)
        {
            proc_operator.first  = str.find(o);
            proc_operator.second = o;

            break;
        }
    }

    if (proc_operator.second != "")
    {
        std::string num_lhs, num_rhs;
        double      d_num_lhs, d_num_rhs;

        num_lhs.append(str.begin(), str.begin() + proc_operator.first);
        num_rhs.append(str.begin() + proc_operator.first + proc_operator.second.size(), str.end());

        d_num_lhs = std::atof(num_lhs.c_str());
        d_num_rhs = std::atof(num_rhs.c_str());

        if (proc_operator.second == "+")
        {
            return d_num_lhs + d_num_rhs;
        }
        else if (proc_operator.second == "-")
        {
            return d_num_lhs - d_num_rhs;
        }
        else if (proc_operator.second == "*")
        {
            return d_num_lhs * d_num_rhs;
        }
        else if (proc_operator.second == "/")
        {
            return d_num_lhs / d_num_rhs;
        }
        else if (proc_operator.second == ">")
        {
            return d_num_lhs > d_num_rhs;
        }
        else if (proc_operator.second == "<")
        {
            return d_num_lhs < d_num_rhs;
        }
        else if (proc_operator.second == "==")
        {
            return d_num_lhs == d_num_rhs;
        }
        else if (proc_operator.second == "!=")
        {
            return d_num_lhs != d_num_rhs;
        }
    }
    else
    {
        return -1.0;
    }
}