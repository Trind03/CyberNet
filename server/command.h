#pragma once
#include <string>
#include "session.h"

struct command
{
    session_details* Session;
    command::command(session_details *session);
    void command_handler();
    void list_connections()const;
};