#include<fstream>
#include<iostream>
#include "io.hpp"

IO::IO(const std::string &file_path){
    file_stream.open(file_path, std::ios::in | std::ios::out | std::ios::binary);

    if (!file_stream.is_open()){
        std::cerr << "Error: Could not open file" << std::endl;
    }
}

std::fstream IO::get_file_stream(){
    return std::move(file_stream);
}

IO::~IO(){
    if (file_stream.is_open()){
        file_stream.close();
    }
}