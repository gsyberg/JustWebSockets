#pragma once

#include "App.h"

#include <memory>

#define DATA_FIELD_NAME "string"

namespace jw
{

class JustWebSocket  
{
public:
	JustWebSocket(unsigned short int port);
	~JustWebSocket() {};

	void run();
private:
	std::unique_ptr<uWS::SSLApp> m_app;
	unsigned int m_port;
};

} // namespace jw