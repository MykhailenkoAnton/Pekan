#pragma once

#include <memory>
#include "Core.h"
#include "Events/Event.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"


namespace Pekan {

	class PEKAN_API Log
	{
	public:

		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:

		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

// Core log macros
#define PK_CORE_TRACE(...)    ::Pekan::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PK_CORE_INFO(...)     ::Pekan::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PK_CORE_WARN(...)     ::Pekan::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PK_CORE_ERROR(...)    ::Pekan::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PK_CORE_CRITICAL(...) ::Pekan::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define PK_TRACE(...)         ::Pekan::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PK_INFO(...)          ::Pekan::Log::GetClientLogger()->info(__VA_ARGS__)
#define PK_WARN(...)          ::Pekan::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PK_ERROR(...)         ::Pekan::Log::GetClientLogger()->error(__VA_ARGS__)
#define PK_CRITICAL(...)      ::Pekan::Log::GetClientLogger()->critical(__VA_ARGS__)


//// event custom log
template<typename T>
struct fmt::formatter<T, std::enable_if_t<std::is_base_of_v<Pekan::Event, T>, char>>
	: fmt::ostream_formatter {
};

inline std::ostream& operator<<(std::ostream& os, const Pekan::Event& e)
{
	return os << e.ToString();
}
