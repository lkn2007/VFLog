#pragma once
#ifndef _ITYPELOGSAVER_
#define _ITYPELOGSAVER_
#include <string>

class ITypeLogSaver
{
public:	
	virtual bool write(const std::string& vflogclient_id, const std::string& client_handler, const std::string& log_string)const = 0;
};
#endif
