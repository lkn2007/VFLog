#include "web_server.h"
#include "handler_post.h"

void web_server()
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
	
	CROW_ROUTE(app, "/get_post_data").methods("POST"_method)
		([](const crow::request& req)
		{				
			if (handler_post(req.body))
			{
				return crow::response(200);
			}
			return crow::response(500);				
		});

	CROW_ROUTE(app, "/dashboard").methods("GET"_method)
		([](const crow::request& req)
		{	
	
			return crow::response("Test");
		});

	app.port(8080)
		.multithreaded()
		//.loglevel(crow::LogLevel::Debug)
		//.loglevel(crow::LogLevel::Warning)
		.run();
}
