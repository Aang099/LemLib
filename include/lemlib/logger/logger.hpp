#pragma once

#include "baseSink.hpp"

#include "infoSink.hpp"

#define FMT_HEADER_ONLY
#include "fmt/core.h"

#include <memory>
#include <array>

namespace lemlib {
class Logger {
    public:
        /**
         * @brief Get the info sink
         *
         * @return InfoSink
         */
        static InfoSink& getInfoSink();

        /**
         * @brief Log to the info logger
         *
         * @tparam T
         * @param level
         * @param format
         * @param args
         */
        template <typename... T> static void log(Level level, fmt::format_string<T...> format, T&&... args) {
            getInfoSink().log(level, format, std::forward<T>(args)...);
        }

        /**
         * @brief Log a debug message to the info logger
         *
         * @tparam T
         * @param format
         * @param args
         */
        template <typename... T> static void logDebug(fmt::format_string<T...> format, T&&... args) {
            log(Level::DEBUG, format, std::forward<T>(args)...);
        }

        /**
         * @brief Log an info message to the info logger
         *
         * @tparam T
         * @param format
         * @param args
         */
        template <typename... T> static void logInfo(fmt::format_string<T...> format, T&&... args) {
            log(Level::INFO, format, std::forward<T>(args)...);
        }

        /**
         * @brief Log an warn message to the info logger
         *
         * @tparam T
         * @param format
         * @param args
         */
        template <typename... T> static void logWarn(fmt::format_string<T...> format, T&&... args) {
            log(Level::WARN, format, std::forward<T>(args)...);
        }

        /**
         * @brief Log an error message to the info logger
         *
         * @tparam T
         * @param format
         * @param args
         */
        template <typename... T> static void logError(fmt::format_string<T...> format, T&&... args) {
            log(Level::ERROR, format, std::forward<T>(args)...);
        }

        /**
         * @brief Log a fatal message to the info logger
         *
         * @tparam T
         * @param format
         * @param args
         */
        template <typename... T> static void logFatal(fmt::format_string<T...> format, T&&... args) {
            log(Level::FATAL, format, std::forward<T>(args)...);
        }
};
} // namespace lemlib