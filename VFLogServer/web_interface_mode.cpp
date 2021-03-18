#include "web_interface_mode.h"
#include "handler_post.h"

void web_interface_mode()
{
	crow::SimpleApp app;

	CROW_ROUTE(app, "/")
		.methods("GET"_method, "POST"_method)
		([]()
			{
				crow::mustache::set_base(".");
				crow::mustache::context ctx;
				return crow::mustache::load("index.html").render();
			});

	/*
	CROW_ROUTE(app, "/comments")
		.methods("POST"_method, "GET"_method)
		([](const crow::request& req)
			{
			std::ostringstream os;
			std::string count_start;
			std::string count_stop;
			std::string count_lrt;
			std::string count_exact;

			if (req.url_params.get("start_timestamp") != nullptr)
			{
				count_start = boost::lexical_cast<std::string>(req.url_params.get("start_timestamp"));
			}
			if (req.url_params.get("stop_timestamp") != nullptr)
			{
				count_stop = boost::lexical_cast<std::string>(req.url_params.get("stop_timestamp"));
			}
			if (req.url_params.get("lrt") != nullptr)
			{
				count_lrt = boost::lexical_cast<std::string>(req.url_params.get("lrt"));
			}
			if (req.url_params.get("exact_timestamp") != nullptr)
			{
				count_exact = boost::lexical_cast<std::string>(req.url_params.get("exact_timestamp"));
			}

			std::vector<std::string> database_data = read_data_in_database();


		if (count_lrt.size() == 0)
		{
			return crow::response("Error Log Record Type");
		}

		if (count_lrt != "INFO" && count_lrt != "WARNING" && count_lrt != "ERROR" && count_lrt != "TRACE")
		{
			return crow::response("Error Log Record Type");
		}

		if (count_lrt.size() > 0 && count_exact.size() == 0 && count_start.size() == 0 && count_stop.size() == 0)
		{
			std::vector<std::string> rez;
			CheckTimestampAny any;

			rez = log_parser(database_data, count_lrt, any);

			for (size_t i = 0; i < rez.size(); i++)
			{
				os << rez[i] << '\n';
			}
			return crow::response{ os.str() };
		}

		if (count_lrt.size() > 0 && count_exact.size() > 0)
		{
			std::vector<std::string> rez;
			CheckTimestampExact exact;
			exact.set_parameter(converter_input_timestamp_to_log_format(count_exact));

			rez = log_parser(database_data, count_lrt, exact);

			for (size_t i = 0; i < rez.size(); i++)
			{
				os << rez[i] << '\n';
			}
			return crow::response{ os.str() };
		}
		if (count_lrt.size() > 0 && count_start.size() > 0 && count_stop.size() > 0)
		{
			std::vector<std::string> rez;
			CheckTimestampInterval interval;
			interval.set_parameter(converter_input_timestamp_to_log_format(count_start),
				converter_input_timestamp_to_log_format(count_stop));

			rez = log_parser(database_data, count_lrt, interval);

			for (size_t i = 0; i < rez.size(); i++)
			{
				os << rez[i] << '\n';
			}
			return crow::response{ os.str() };

		}

		return crow::response(404);

			});


	*/

	CROW_ROUTE(app, "/send_post_data").methods("POST"_method)
		([](const crow::request& req)
			{				
				if (handler_post(req.body))
				{
					return crow::response(200);
				}
				return crow::response(500);
				
			});

	app.port(8080)
		.multithreaded()
		//.loglevel(crow::LogLevel::Debug)
		//.loglevel(crow::LogLevel::Warning)
		.run();
}
