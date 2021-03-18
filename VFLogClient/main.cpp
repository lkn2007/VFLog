#include "parsing_conf_file.h"
#include "read_data_in_file.h"
#include "connect_to_server.h"
#include "struct_configuration.h"
#include "check_dump_file.h"
#include <iostream>

int main(int argc, char* argv[])
{
	/*
		struct tm newtime;
		char buf[80];

		std::time_t t = std::time(0);
		localtime_s(&newtime, &t);
		strftime(buf, sizeof(buf), "%d-%m-%Y  %X", &newtime) << '\n';
		//strftime(buf, sizeof(buf), "%d-%m-%Y  %X", std::localtime(&t)) << '\n';

		//std::cout << buf << '\n';
		parsing_conf_file();

	*/

	configuration conf;
	conf = parsing_conf_file(conf);

	while (true)
	{
		while (true)
		{
			std::vector<std::string> dump_data = check_dump_file();
			if (dump_data.size())
			{
				if (!connect_to_server(dump_data, conf))
				{
					std::cerr << "Failed to transfer dump data" << '\n';
				}
				else
				{
					std::ofstream ofs;
					ofs.open("dump", std::ios::out);
					ofs.close();
				}
			}

			std::vector<std::string> data_log = read_data_in_file(conf.log_file, conf);
			if (data_log.size() == 0)
			{
				break;
			}

			if (!connect_to_server(data_log, conf))
			{
				std::cerr << "Failed to Connect" << '\n';

				std::ofstream ofs;
				ofs.open("dump", std::ios::app);
				if (!ofs)
				{
					std::cerr << "Error, file dump not created\n";
					exit(1);
				}
				for (size_t i = 0; i < data_log.size(); i++)
				{
					ofs << data_log[i] + '\n';
				}

			}
		}
		Sleep(atoi(conf.read_log_file_interval.c_str()));
	}
	return 0;
}