#pragma once
#include <asio.hpp>
#include <memory>
#include <deque>
#include "session.h"


class command;

class server
{
public:
    explicit server(unsigned short port,const char* filename);
    server(server&) = delete;

    int start(std::shared_ptr<command>Command);
    void running();
    void stop() const;

    bool get_running_status() const;
    std::deque<session> get_connections()const;
    
    void add_connection(asio::ip::tcp::endpoint &&Endpoint);
    void disconnect_client(int index);
    void session_status();
    int broadcast_client(session *Session);
    
private:
    /* assets */
    asio::io_context Io_context;
    asio::ip::tcp::endpoint Endpoint;
    asio::ip::tcp::acceptor Acceptor;
    std::unique_ptr<asio::ip::tcp::socket>Sock;
    asio::error_code Error;
    unsigned short Port;
    mutable bool Running;
    std::deque<session>Connections;
};