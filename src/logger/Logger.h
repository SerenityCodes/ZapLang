#pragma once

#include <memory>
#include "spdlog/spdlog.h"

class Logger {
    static std::shared_ptr<spdlog::logger> m_core_logger_;
    static std::shared_ptr<spdlog::logger> m_client_logger_;
public:
    static void Init();
    
    static std::shared_ptr<spdlog::logger> core_logger();
    static std::shared_ptr<spdlog::logger> client_logger();
};

#define ZAP_LOG_INFO(...) ::Logger::core_logger()->info(__VA_ARGS__);
#define ZAP_LOG_WARN(...) ::Logger::core_logger()->warn(__VA_ARGS__);
#define ZAP_LOG_ERROR(...) ::Logger::core_logger()->error(__VA_ARGS__);
#define ZAP_LOG_DEBUG(...) ::Logger::core_logger()->debug(__VA_ARGS__);
#define ZAP_LOG_TRACE(...) ::Logger::client_logger()->trace(__VA_ARGS__);

#define APP_LOG_INFO(...) ::Logger::client_logger()->info(__VA_ARGS__);
#define APP_LOG_WARN(...) ::Logger::client_logger()->warn(__VA_ARGS__);
#define APP_LOG_ERROR(...) ::Logger::client_logger()->error(__VA_ARGS__);
#define APP_LOG_DEBUG(...) ::Logger::client_logger()->debug(__VA_ARGS__);
#define APP_LOG_TRACE(...) ::Logger::client_logger()->trace(__VA_ARGS__);
