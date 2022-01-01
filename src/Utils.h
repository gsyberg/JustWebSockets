#pragma once

#include <string>

namespace jw
{

class Utils
{
public:
	static bool fileExists(const std::string& path);
	static const char* getLogo();
};

} // namespace jw