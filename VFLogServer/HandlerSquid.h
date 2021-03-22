#pragma once
#ifndef _HANDLERSQUID_
#define _HANDLERSQUID_
#include <sstream>
#include <vector>
#include <mysql.h>
#include <iostream>
#include "ITypeLogSaver.h"

class HandlerSquid : public ITypeLogSaver
{
public:				
	bool write(const std::string& vflogclient_id, const std::string& client_handler, const std::string& log_string)const override;
};
#endif
