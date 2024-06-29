#include "ProcessManagement.hpp"
#include <iostream>
#include <cstring>
// #include <sys/wait.h>
#include "../encryptDecrypt/Cryption.hpp"


ProcessManagement::ProcessManagement() {}

bool ProcessManagement::submit_to_queue(std::unique_ptr<Task> task) {
    task_queue.push(std::move(task));
    return true;
}

void ProcessManagement::execute_task(){
    while (!task_queue.empty()){
        std::unique_ptr<Task> task_to_execute = std::move(task_queue.front());
        task_queue.pop();
        std::cout << "Executing task: " << task_to_execute -> toString() << std::endl;
        execute_cryption(task_to_execute -> toString());
    }
}
