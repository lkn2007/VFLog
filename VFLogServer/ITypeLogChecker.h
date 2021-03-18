#pragma once
#ifndef _ITYPELOGCHECKER_
#define _ITYPELOGCHECKER_
#include <string>

class ITypeLogChecker
{
public:	
	virtual bool check(const std::string& vflogclient_id, const std::string& client_handler, const std::string& log_string)const = 0;
};
#endif
