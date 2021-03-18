#include "parsing_conf_file.h"

configuration parsing_conf_file(configuration conf)
{
	std::string path = "vflogclient.conf";
	
	std::fstream fs(path, std::ios::in);
	if (fs.is_open())
	{
		while (!fs.eof())
		{
			std::string str;
			std::getline(fs, str);
			str.erase(std::remove(str.begin(), str.end(), ' '), str.end());

			if (str.find('#') != std::string::npos)
			{
				continue;
			}

			std::stringstream ss(str);
			std::string tmp;
			std::getline(ss, tmp, '=');
			tmp.erase(std::remove(tmp.begin(), tmp.end(), ' '), tmp.end());

			if (tmp == "vflogserver")
			{
				std::getline(ss, tmp);
				if (tmp.size() == 0)
				{
					std::cerr << "ERROR: value parametr vflogserver is null\n";
					//break;
					exit(0);
				}
				conf.vflogserver = tmp;
				//std::cout << "value parametr vflogserver = " << conf.vflogserver << '\n';
			}

			if (tmp == "vflogserver_port")
			{
				std::getline(ss, tmp);
				conf.vflogserver_port = tmp;
				//std::cout << "value parametr = " << conf.vflogserver_port << '\n';				
			}

			if (tmp == "vflogserver_url")
			{
				std::getline(ss, tmp);
				conf.vflogserver_url = tmp;
				//std::cout << "value parametr = " << conf.vflogserver_url << '\n';
			}

			if (tmp == "log_file")
			{
				std::getline(ss, tmp);
				conf.log_file = tmp;
				//std::cout << "value parametr = " << conf.log_file << '\n';
			}

			if (tmp == "vflogclient_id")
			{
				std::getline(ss, tmp);
				conf.vflogclient_id = tmp;
				//std::cout << "value parametr = " << conf.vflogclient_id << '\n';
			}

			if (tmp == "vflogclient_handler_id")
			{
				std::getline(ss, tmp);
				conf.vflogclient_handler_id = tmp;
				//std::cout << "value parametr = " << conf.vflogclient_handler_id << '\n';
			}

			if (tmp == "read_log_file_interval")
			{
				std::getline(ss, tmp);
				conf.read_log_file_interval = tmp;
				//std::cout << "value parametr = " << conf.read_log_file_interval << '\n';
			}

			if (tmp == "max_transmitted_ll")
			{
				std::getline(ss, tmp);
				conf.max_transmitted_ll = tmp;
				//std::cout << "value parametr = " << conf.max_transmitted_ll << '\n';
			}

		}

		if (conf.vflogserver == "")
		{
			std::cerr << "ERROR: missing vflogserver parameter\n";
			exit(0);
		}


	}
	else
	{
		std::cout << "file " << path << " not found\n";
		//exit(0);
	}

	return conf;
}