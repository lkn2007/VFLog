#include "connect_to_server.h"
#include "struct_configuration.h"
#include "create_post_body.h"

bool connect_to_server(std::vector<std::string> data_log, const configuration& conf)
{
	std::string url_str = conf.vflogserver + ":" + conf.vflogserver_port + conf.vflogserver_url;
	const char* url = url_str.c_str();

	std::string post_data = create_post_body(data_log, conf);

	try
	{
		curlpp::Cleanup cleaner;
		curlpp::Easy request;
		request.setOpt(new curlpp::options::Url(url));
		request.setOpt(new curlpp::options::Verbose(true));
		std::list<std::string> header;

		//header.push_back("Content-Type: application/octet-stream");			
		//header.push_back("Content-Type: application/json");
		//header.push_back("Content-Type: multipart/form-data");
		header.push_back("Content-Type: application/x-www-form-urlencoded");

		request.setOpt(new curlpp::options::HttpHeader(header));
		request.setOpt(new curlpp::options::PostFields(post_data));
		request.setOpt(new curlpp::options::PostFieldSize(post_data.size()));							
		request.perform();
	}
	catch (curlpp::LogicError& e)
	{
		std::cout << e.what() << std::endl;
		return false;
	}
	catch (curlpp::RuntimeError& e)
	{
		std::cout << e.what() << std::endl;
		return false;
	}
  return true;
}