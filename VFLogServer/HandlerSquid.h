#pragma once
#ifndef _HANDLERSQUID_
#define _HANDLERSQUID_
#include <sstream>
#include <vector>
#include <mysql.h>
#include "ITypeLogChecker.h"

class HandlerSquid : public ITypeLogChecker
{
public:		
	bool check(const std::string& vflogclient_id, const std::string& client_handler, const std::string& log_string)const override;
	bool write_data_in_database(const std::string& vflogclient_id, const std::string& str);
};
#endif
