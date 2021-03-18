#pragma once
#ifndef _STRUCT_CONFIGURATION_
#define _STRUCT_CONFIGURATION_

#include <string>
struct configuration
{
	std::string vflogserver = "";
	std::string vflogserver_port = "";
	std::string vflogserver_url = "";
	std::string log_file = "";
	std::string vflogclient_id = "";
	std::string vflogclient_handler_id = "";
	std::string max_transmitted_ll = "2000";
	std::string read_log_file_interval = "60000";
};
#endif
