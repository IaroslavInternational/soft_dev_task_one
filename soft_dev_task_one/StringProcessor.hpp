#include <string>
#include <vector>

class StringProcessor
{
public:
	StringProcessor();
public:
	double Process(std::string& str);
private:
	std::vector<std::string> operators;
};