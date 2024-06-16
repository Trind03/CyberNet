#include <iostream>
#include <functional>
#include <memory>
#include <fstream>
#include <string>

template <typename T>
extern std::function<int(T)>boot_message_client = [](T&& filename);
