#include "handler_post.h"

bool url_decode(const std::string& in, std::string& out)
{
	out.clear();
	out.reserve(in.size());
	for (std::size_t i = 0; i < in.size(); ++i)
	{
		if (in[i] == '%')
		{
			if (i + 3 <= in.size())
			{
				int value = 0;
				std::istringstream is(in.substr(i + 1, 2));
				if (is >> std::hex >> value)
				{
					out += static_cast<char>(value);
					i += 2;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else if (in[i] == '+')
		{
			out += ' ';
		}
		else
		{
			out += in[i];
		}
	}
	return true;
}

std::map<std::string, std::string>parse_crow_post_data(const std::string& req_body)
{
	std::map<std::string, std::string> body;

	std::vector<std::string> vec;
	std::string tmp;
	bool result = url_decode(req_body, tmp);
	if (result)
	{
		boost::algorithm::split(vec, tmp, [](char x) {return x == '&'; }); //!!!!!!!!!!!!!!!
		for (auto& it : vec)
		{
			auto pos = it.find("=");
			if (pos != std::string::npos)
			{
				body[it.substr(0, pos)] = it.substr(pos + 1);
			}
			else
			{
				break;
			}
		}
	}
	return body;
}

bool handler_post(const std::string& body)
{	
	std::map<std::string, std::string> post_body = parse_crow_post_data(body);	
	std::string vflogclient_id = post_body["vflogclient_id"];
	std::string client_handler = post_body["client_handler_id"];
	std::string log_string = post_body["data"];
	if (client_handler == "squid")
	{
		HandlerSquid a;		

		return a.write_data_in_database(vflogclient_id, log_string);
	} 
}