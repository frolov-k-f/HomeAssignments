/* 
 * Kirill Frolov
 * st141840@student.spbu.ru
 * Assignment 2A
 */
 
#include <iostream>
#include <fstream>
#include <cstdint>
#include <filesystem>
#include <algorithm>
#include "reverse.h"

void Allfunctions::reverseFile(){

    std::uintmax_t filesize = std::filesystem::file_size("source.pdf"); 
    char* file_Memory = new char[filesize]; 
    
    std::ifstream infile;
    infile.open("source.pdf", std::ios::binary|std::ios::in);
    infile.read(file_Memory, filesize);
    
    std::reverse(file_Memory, file_Memory+filesize);
    
    std::ofstream outfile("newfile.pdf", std::ios::binary|std::ios::out);
    outfile.write(file_Memory, filesize);
    
    infile.close();
    outfile.close();
    delete[] file_Memory;
    
 }
 
