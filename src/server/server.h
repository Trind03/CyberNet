#pragma once
#include <asio.hpp>
#include <memory>
#include <deque>
#include <vector>
#include "session.h"
#include "../internet_computer.h"

class command;

class server : public ::internet_computer
{
public:
    explicit server(unsigned short port,bool title);
    server(server&) = delete;

    int start(std::shared_ptr<command>Command);
    void running();
    void stop();

    bool get_running_status();
    
    const std::deque<session>& get_connections();
    void add_connection(asio::ip::tcp::socket &&Sock);
    void disconnect_client(std::deque<session>::iterator it);
    void session_status();
    void show_clients();
    void validate_live_connection();
private:
    /* assets */
    asio::io_context Io_context;
    asio::ip::tcp::endpoint Endpoint;
    asio::ip::tcp::acceptor Acceptor;
    asio::error_code Error;
    asio::ip::tcp::socket Sock;
    unsigned short Port;
    bool Running;
    std::deque<session>Connections;
    std::vector<unsigned char>Buffer(1240);
    std::mutex resource_lock;
};