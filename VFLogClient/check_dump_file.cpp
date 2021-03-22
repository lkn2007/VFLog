#include "check_dump_file.h"

std::vector<std::string> check_dump_file()
{
	std::ifstream ifs;
	std::vector<std::string> dump_data;
	ifs.open("dump");
	while (!ifs.eof())
	{
		std::string tmp;
		getline(ifs, tmp);
		if (tmp.size())
		{
			dump_data.push_back(tmp);
		}
		else
		{
			break;
		}
	}
	ifs.close();
  return dump_data;
}