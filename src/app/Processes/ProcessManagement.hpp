#ifndef PROCESSMANAGEMENT_HPP
#define PROCESSMANAGEMENT_HPP

#include "Task.hpp"
#include <queue>
#include <memory>

class ProcessManagement{
    public:
        ProcessManagement();
        bool submit_to_queue(std::unique_ptr<Task> task);
        void execute_task();
    private:
        std::queue<std::unique_ptr<Task>> task_queue;
};


#endif // !PROCESSMANAGEMENT_HPP