#include <iostream>
#include <string>
#include <filesystem>
#include "./src/app/Processes/ProcessManagement.hpp"
#include "./src/app/Processes/Task.hpp"

namespace fs = std::filesystem;

int main(int arg, char *argv[]) {
    std::string directory;
    std::string action;

    std::cout << "Enter the directory: ";
    std::getline(std::cin, directory);

    std::cout << std::endl;

    std::cout << "Enter the action: ";
    std::getline(std::cin, action);

    try{
        if (fs::exists(directory) && fs::is_directory(directory)){
            ProcessManagement processManagement;
            for (const auto &entry : fs::recursive_directory_iterator(directory)){
                if (entry.is_regular_file()){
                    std::string file_path = entry.path().string();
                    std::cout << "Processing file : " << file_path << std::endl; 
                    IO io(file_path);
                    std::fstream f_stream = std::move(io.get_file_stream());
                    if (f_stream.is_open()){
                        Action task_action = (action == "encrypt") ? Action::ENCRYPT : Action::DECRYPT;
                        auto task = std::make_unique<Task>(std::move(f_stream), file_path, task_action);
                        processManagement.submit_to_queue(std::move(task));
                    }else{
                        std::cerr << "Error : Unable to open file " << file_path << std::endl;
                    }
                }
            }
            processManagement.execute_task();
        }else{
            std::cerr << "Error : Directory " << directory << " does not exist" << std::endl;
        }
    }catch(const std::exception &e){
        std::cerr << "Error : " << e.what() << std::endl;
    }
}