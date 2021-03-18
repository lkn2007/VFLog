#include "HandlerSquid.h"

#include <iostream>

bool HandlerSquid::check(const std::string& vflogclient_id, const std::string& client_handler,
						 const std::string& log_string)const
{			

	return true;
}

bool HandlerSquid::write_data_in_database(const std::string& vflogclient_id, const std::string& str)
{
	MYSQL* conn;
	//MYSQL_RES* res;
	//MYSQL_ROW row;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "lbvtlhjk", "vflog_db", 3306, NULL, 0);
	int qstate;

	if (conn)
	{
		std::stringstream ss(str);
		std::string data;
		std::string tmp;
		std::string tmp2;
		while (std::getline(ss, data, '\n'))
		{
			std::stringstream ss2(data);
			tmp = "('" + vflogclient_id + "',";
			int counter = 0;
			while (std::getline(ss2, data, ' '))
			{				
				if (data.size() == 0)
				{
					continue;
				}
				if (counter < 9 )
				{
					tmp += "'" + data + "'" + ",";
				}
				counter++;
			}
			tmp.erase(tmp.size() - 1);
			tmp += ")";
			
			tmp2 += tmp + ",";			
		}
		tmp2.erase(tmp2.size() - 1);

		std::string query = "INSERT INTO squids(`clients_id`,`linux_time`, `time_response`, `request_source`, `request_status/http_status_code`, `size_request`, `metod_request`, `url_reques`, `user_name`, `hierarchy_status/requesting_server`)  VALUES"	+ tmp2;		
		
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);

		if (qstate != 0)
		{
			std::cout << "Insert Error\n" << mysql_error(conn) << "\n";
			return false;
		}
		mysql_close(conn);
	}
	else
	{
		std::cout << "Connection to database has failed!\n";
		return false;
	}
  return true;
}