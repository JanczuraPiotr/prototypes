#include "Logger.hpp"

#include <chrono>
#include <iostream>
#include <iomanip>


Logger::Logger(int firstColumn)
    : _firstColumn(firstColumn)
{

}

void Logger::printComment(const std::string &comment) const
{
//    std::cout << std::setw(_firstColumn) << " // " << comment;
    std::cout << " // " << comment;
}

void Logger::line(const char *file, int line, const std::string &comment)
{
    std::cout << moment();
    std::cout << file << ':' << line;

    if (!comment.empty()) {
        printComment(comment);
    }

    std::cout << std::endl;
}

void Logger::log(const KeyValue& msg, const std::string &comment)
{
    std::cout << moment();
    if (msg.second.empty()) {
        std::cout << std::setw(5) << "\t" << msg.first;
    } else {
        std::cout << std::setw(5) << "\t" << msg.first << " => " << msg.second;
    }
    if (!comment.empty()) {
        printComment(comment);
    }

    std::cout << std::endl;
}

void Logger::log(const KeyValue& msg, int lineNr, const std::string &comment)
{
    std::cout << moment();
    if (msg.second.empty()) {
        std::cout << std::setw(5) << std::right << lineNr << ":\t" << msg.first;
    } else {
        std::cout << std::setw(5) << std::right << lineNr << ":\t" << msg.first << " => " << msg.second;
    }

    if (!comment.empty()) {
        printComment(comment);
    }

    std::cout << std::endl;
}

void Logger::log(const std::string &s, int lineNr, const std::string &comment)
{
    std::cout << moment();
    std::cout << std::setw(_firstColumn) << std::right << lineNr << ":\t" << s;

    if (!comment.empty()) {
        printComment(comment);
    }

    std::cout << "\n";
}


std::string Logger::moment()
{
    auto now    = std::chrono::system_clock::now();
    auto floor  = std::chrono::floor<std::chrono::milliseconds>(now);
    auto moment = std::chrono::zoned_time{std::chrono::current_zone(), floor};
    auto formatted_time = std::format("{:%H:%M:%S}", moment);
    return formatted_time;

}
