#pragma once
#include <string>
#include "session.h"
#include <vector>
#include "session.h"
struct command
{
    session_details* session;
    command::command(session_details *Session);
    void command_handler();
    int list_connections();
};