#include "Cryption.hpp"
#include "../Processes/Task.hpp"
#include "../fileHandling/ReadEnv.cpp"

int execute_cryption(const std::string &task_data){
    Task task = Task::from_string(task_data);
    ReadEnv env;

    std::string env_key = env.get_env();
    int key = std::stoi(env_key);

    if (task.action == Action::ENCRYPT){
        char ch;
        while (task.f_stream.get(ch)){
            ch = (ch + key)%256;
            task.f_stream.seekp(-1, std::ios::cur);
            task.f_stream.put(ch);
        }
        task.f_stream.close();
    }else{
        char ch;
        while (task.f_stream.get(ch)){
            ch = (ch - key + 256)%256;
            task.f_stream.seekp(-1, std::ios::cur);
            task.f_stream.put(ch);
        }
        task.f_stream.close();
    }
    return 0;
}