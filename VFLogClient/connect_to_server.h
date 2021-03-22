#pragma once
#ifndef _CONNECT_TO_SERVER_
#define _CONNECT_TO_SERVER_
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>
bool connect_to_server(std::vector<std::string> data_log, const struct configuration& conf);
#endif