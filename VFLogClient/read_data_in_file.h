#pragma once
#ifndef _READ_DATA_IN_FILE_
#define _READ_DATA_IN_FILE_

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
std::vector<std::string> read_data_in_file(std::string path, const struct configuration& conf);
#endif

