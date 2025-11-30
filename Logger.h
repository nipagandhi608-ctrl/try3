/**
 * @file Logger.h
 * @brief Declaratddion of for logging messages with different severity levels.
 */

#pragma once
#include <string>
#include <iostream>

/**
 * @enum Log_Level
 * @brief Defines the severity levels for log messages.
 * Levels include INFO, WARNING, ERROR, and DEBUG. 
  */

enum Log_Level {
    LOG_INFO,     /**< Informational message */
    LOG_WARNING,  /**< Warning about possible issues */
    LOG_ERROR,    /**< Error condition */
    LOG_DEBUG     /**< Debugging message */
};

/**
 * @class Logger
 * @brief A simple logging class to log messages with different severity levels.
 */

class Logger {
public:
    /** 
     * @brief Constructor that initializes the logger with a file name.
     * @param filename The name of the log file where messages will be written.
     * @return void
     */
    Logger(const std::string& filename) : log_file_name(filename) {}

    /**
     * @brief Logs a message with a specific severity level.
     * @param level The severity level (from Log_Level enum).
     * @param message The text message to log.
     * @return void
     * \pre The Logger object must be properly initialized.
     * \post The log message is written to the file defined by log_file_name.
     */
    void log(Log_Level level, const std::string& message);
private:
    std::string log_file_name;
    
    /**
     * @brief Converts Log_Level enum to a string representation.
     * @param level The Log_Level enum value.
     * @return A string representing the log level.
     */
    std::string levelToString(Log_Level level) const;
};

// Simple implementation for compilation only
inline void Logger::log(Log_Level level, const std::string& message) {
    std::cout << "[" << levelToString(level) << "] " << message << " (to " << log_file_name << ")" << std::endl;
}

inline std::string Logger::levelToString(Log_Level level) const {
    switch (level) {
        case LOG_INFO: return "INFO";
        case LOG_WARNING: return "WARNING";
        case LOG_ERROR: return "ERROR";
        case LOG_DEBUG: return "DEBUG";
    }
    return "UNKNOWN";
}
