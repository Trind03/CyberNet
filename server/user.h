#pragma once

struct user
{
    user::user(const char* ip, int id);
    int ID;
    const char* IPV4;
}; 

user::user(const char* ip, int id): IPV4(ip), ID(id)
{}