#pragma once

struct user
{
    user::user(std::string ip, int id);
    int ID;
    std::string IPV4;
}; 
/*
user::user(std::string ip, int id): IPV4(ip), ID(id)
{}*/