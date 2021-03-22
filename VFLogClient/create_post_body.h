#pragma once
#ifndef _CREATE_POST_BODY_
#define _CREATE_POST_BODY_
#include <vector>
#include <string>
#include "struct_configuration.h"
std::string create_post_body(std::vector<std::string> data_log, const configuration& conf);
#endif