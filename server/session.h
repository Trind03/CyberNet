#pragma once
#include <vector>
#include "user.h"


struct session_details
{
    session_details::session_details(int Port): port(Port) {}
    std::vector<user>(User);
    int curr_connections;
    int port;
};