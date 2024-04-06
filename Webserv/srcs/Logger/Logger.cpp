#include "Logger.hpp"
#include <fstream>
#include <sstream>

Logger::Logger() {}

Logger::Logger(const Logger &obj) { (void)obj; }

Logger::~Logger() {}

Logger::VerboseNoMatchException::VerboseNoMatchException(): std::invalid_argument("invalid verbose level") {}

void Logger::log_error(string const &message)
{
    cout << BOLDRED << "[ERROR] " << NC << message << "\n";
}

void Logger::log_warning(string const &message)
{
    if (VERBOSE <= WARNING)
        cout << BOLDMAGENTA << "[WARNING] " << NC << message << "\n";
}

void Logger::log_info(string const &message)
{
    if (VERBOSE <= INFO)
        cout << BOLDGREEN << "[INFO] " << NC << message << "\n";
}

void Logger::log(string const &message, levels level)
{

    switch (level)
    {
        case ERROR:
            log_error(message);
            break;
        case WARNING:
            log_warning(message);
            break;
        case INFO:
            log_info(message);
            break;
    }
}
