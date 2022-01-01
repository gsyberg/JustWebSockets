#include "JustWebSocket.h"  

#include "Utils.h"

#include <string>
#include <iostream>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

namespace jw
{

JustWebSocket::JustWebSocket(unsigned short int port)
    : m_port(port)
{
    std::string key_file_name = "cert/server.key";
    std::string cert_file_name = "cert/server.crt";

    if (!Utils::fileExists(key_file_name))
    {
        std::cout << "Could not find file: " << key_file_name << "\n";
        return;
    }

    if (!Utils::fileExists(cert_file_name))
    {
        std::cout << "Could not find file: " << cert_file_name << "\n";
        return;
    }

    uWS::SocketContextOptions options;
    options.key_file_name = key_file_name.c_str();
    options.cert_file_name = cert_file_name.c_str();

    m_app = std::make_unique<uWS::SSLApp>(options);

    struct PerSocketData
    {
        // Add stuff you want to keep track of for each socket here.
    };

    m_app->ws<PerSocketData>("/*", {
       .open = [](auto *)
        {
            std::cout << "Opened WebSocket.\n";
        },
        .message = [](auto *ws, std::string_view message, uWS::OpCode opCode)
        {
            std::cout << "Got data:\n  Size: " << message.size() << "\n";
            
            // deserialize from JSON 
            rapidjson::Document d;
            d.Parse(std::string(message).c_str());
            rapidjson::Value& v = d[DATA_FIELD_NAME];
            std::string msg(v.GetString());

            std::cout << "  Data: " << msg.c_str() << "\n";

            // pack in DOM again. Creating a new rapidjson::Document for demo purposes.
            rapidjson::Document s;
            s.SetObject();
            rapidjson::Value jsonMsg(msg.c_str(), msg.size(), s.GetAllocator());
            s.AddMember(DATA_FIELD_NAME, jsonMsg, s.GetAllocator());

            // serialize to JSON string
            rapidjson::StringBuffer buffer;
            rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
            s.Accept(writer);

            // send back to client
            ws->send(buffer.GetString(), uWS::OpCode::TEXT, false);
        },
       .close = [](auto */*ws*/, int /*code*/, std::string_view /*message*/)
        {
            std::cout << "Closed WebSocket.\n";
        }
    });
}
	
void JustWebSocket::run()
{
    m_app->listen(m_port, [&](auto *listen_socket)
    {
        if (listen_socket)
        {
            std::cout << "Listening on port: " << m_port << "\n";
        }
        else
        {
            std::cout << "Failed to listen to port:  " << m_port << "\n";
        }
    });

    m_app->run();
}

} // namespace jw