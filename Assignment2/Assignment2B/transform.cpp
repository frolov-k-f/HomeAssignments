/* 
 * Kirill Frolov
 * st141840@student.spbu.ru
 * Assignment 2B
 */
 
#include <iostream>
#include <string>
#include "transform.h"
void Allfunctions::transform() {

    std::string notation;
    std::getline(std::cin, notation);
    char* stack = new char[notation.length()];
    char* polish = new char[notation.length()];
    
    int stack_pos = -1;
    int polish_pos = -1;
    char operators[] = {'+','-','*','/'};
    std::string bignum = "";
    
    for (int i=0; i<notation.length(); i++) {
        
        if (notation[i] >= '0' && notation[i] <= '9'){
            bignum += notation[i];
            if (notation[i+1] == ' ' || notation[i] == notation[notation.length()-1]){
                for (int k=0; k < bignum.length(); k++){
                polish_pos++;
                polish[polish_pos] = bignum[k];
                }
            polish_pos++;
            polish[polish_pos] = ' ';
            bignum = "";
            }
        }
        for (int j=0; j<4; j++){
            if (notation[i] == operators[j]){
                stack_pos++;
                stack[stack_pos] = notation[i];
                stack_pos++;
                stack[stack_pos] = ' ';
            }
        }
        
    }
    while (stack_pos >= 0){
        polish[polish_pos] = stack[stack_pos];
        polish_pos++;
        polish[polish_pos] = ' ';
        stack_pos--;
    }
    
    polish_pos++;
    polish[polish_pos] = '\0';
    std::cout << polish << std::endl;
    
    int* answer = new int[notation.length()];
    int answer_pos = -1;
    
    for (int i=0; i <= polish_pos; i++){
        if (polish[i] >= '0' && polish[i] <= '9'){
            bignum += polish[i];
        }
        if (polish[i] == ' ') {
            if (!bignum.empty()) {
                answer_pos++;
                answer[answer_pos] = std::stoi(bignum);
                bignum = "";
            }
        }

        for (int j=0; j<4; j++){
            if (polish[i] == operators[j]){
                int result = 0;
                int b = answer[answer_pos];
                answer_pos--;
                int a = answer[answer_pos];
                if (polish[i] == '+'){result = a + b;}
                if (polish[i] == '-'){result = a - b;}
                if (polish[i] == '*'){result = a * b;}
                if (polish[i] == '/'){result = a/b;}
                answer[answer_pos] = result;
            }
        }
        
    }
    std::cout << answer[answer_pos] << std::endl;
    delete[] stack;
    delete[] answer;
    delete[] polish;
}

