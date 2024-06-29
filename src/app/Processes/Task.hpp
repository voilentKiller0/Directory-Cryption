#ifndef TASK_HPP
#define TASK_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../fileHandling/io.hpp"

enum class Action {
    ENCRYPT,
    DECRYPT
};

struct Task{
    std::string file_path;
    std::fstream f_stream;
    Action action;

    Task(std::fstream &&stream, std::string filePath, Action act) : f_stream(std::move(stream)), file_path(filePath), action(act) {}

    std::string toString() const{
        std::ostringstream buffer;
        buffer << file_path << "," << (action == Action::ENCRYPT ? "ENCRYPT" : "DECRYPT");
        return buffer.str();
    }

    static Task from_string(const std::string taskData){
        std::istringstream buffer(taskData);    
        std::string file_path;
        std::string action_str;

        if (std::getline(buffer, file_path, ',') && std::getline(buffer, action_str)){
            Action action = action_str == "ENCRYPT" ? Action::ENCRYPT : Action::DECRYPT;
            IO io(file_path);
            std::fstream f_stream = std::move(io.get_file_stream());
            if (f_stream.is_open()){
                return Task(std::move(f_stream), file_path, action);
            }
            else{
                std::runtime_error("Error: Could not open file : " + file_path);
            }
        }else{
            std::runtime_error("Error: Could not parse task data : " + file_path);
        }
    }

};


#endif // !TASK_HPP
