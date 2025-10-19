#pragma once

#include <ostream>
#include "spdlog/fmt/fmt.h"	
#include "Pekan/Events/Event.h"

template<typename T>
struct fmt::formatter<T, std::enable_if_t<std::is_base_of<Pekan::Event, T>::value, char>> : formatter<std::string>
{
    auto format(const Pekan::Event& e, fmt::format_context& ctx) const {
        return formatter<std::string>::format(e.ToString(), ctx);
    }
};