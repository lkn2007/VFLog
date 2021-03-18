#include "read_data_in_file.h"
#include "struct_configuration.h"

std::vector<std::string> read_data_in_file(std::string path, const configuration& conf)
{
	std::vector<std::string> file_data;
	std::ifstream ifs;
	std::ofstream ofs;
	std::string counter;

	ifs.open("counter");
	if (!ifs.is_open())
	{
		ofs.open("counter");
		ofs.close();
	}
	std::getline(ifs, counter);
	ifs.close();

	ifs.open(path);
	if (!ifs)
	{
		std::cout << "file " << path << " not found\n";
		exit(1);
	}
	ifs.seekg(atoi(counter.c_str()), std::ios::beg);

	while (!ifs.eof())
	{
		std::string tmp;
		std::getline(ifs, tmp);
		if (tmp.size() == 0)
		{
			continue;
		}
		file_data.push_back(tmp);
		if (file_data.size() == atoi(conf.max_transmitted_ll.c_str()))
		{
			break;
		}
	}
	ifs.clear();
	//std::cout << "transmitted_log_lines = " << file_data.size() << '\n';
	//std::cout << "pozitions after transmitted = " << ifs.tellg() << " bytes" << "\n\n";
	ofs.open("counter");
	if (!ofs)
	{
		std::cerr << "File Counter could not be opened" << '\n';
		exit(1);
	}
	ofs << ifs.tellg();
	ofs.close();
	ifs.close();

	return file_data;
}