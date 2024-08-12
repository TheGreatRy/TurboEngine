#pragma once
#include <string>
#include <algorithm>

std::string ToLower(const std::string& str);
std::string ToUpper(const std::string& str);
bool IsEqualIgnoreCase(const std::string& strOne, const std::string& strTwo);