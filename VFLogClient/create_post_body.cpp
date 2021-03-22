#include "create_post_body.h"

std::string create_post_body(std::vector<std::string> data_log, const configuration& conf)
{
	std::string data_log_str = "vflogclient_id=" + conf.vflogclient_id + '&' +
		"client_handler_id=" + conf.vflogclient_handler_id + '&' +
		"data=";

	for (size_t i = 0; i < data_log.size(); i++)
	{
		data_log_str += data_log[i] + '\n';
	}
  return data_log_str;
}