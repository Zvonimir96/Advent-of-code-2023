#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <streambuf>
#include <map>

#define FILE_NAME "Task1/puzzle_input.txt"

int main()
{
    std::ifstream colaboration_doc(FILE_NAME);
    std::string line;

    std::map<std::string, int> numbers{{"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};

    int colaboration_sum = 0;

    while (std::getline(colaboration_doc, line))
    {
        std::string spelled_number;
        int8_t first_digit{-1}, last_digit;

        std::for_each(line.begin(), line.end(), [&](const char &c){
            spelled_number += c;

            if (c >= '0' && c <= '9')
            {
                if (first_digit == -1)
                    first_digit = last_digit = c - 48;
                else
                    last_digit = c - 48;
                
                spelled_number = "";
            }

            std::for_each(numbers.begin(), numbers.end(), [&](const std::pair<std::string, int> &key_valuet){
                if(spelled_number.find(key_valuet.first) != std::string::npos){
                    if (first_digit == -1)
                        first_digit = last_digit = key_valuet.second;
                    else
                        last_digit = key_valuet.second;

                    char c = spelled_number[spelled_number.length() - 1];
                    spelled_number = c;
                } 
            }); 
        });

        colaboration_sum += last_digit + first_digit * 10;
    }

    std::cout << "Sum of all calibration numbers: " << colaboration_sum;

    return 0;
}