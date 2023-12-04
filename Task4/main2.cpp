#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>

#define FILE_NAME "Task4/puzzle_input.txt"


int main()
{
    std::ifstream schematic(FILE_NAME);
    std::string line;
    int number_of_lines = 0;

    while (std::getline(schematic, line))
        number_of_lines++;

    std::vector<int> copys(number_of_lines, 1);

    std::ifstream engine_schematic(FILE_NAME);
    int sum = 0;
    int card_number = 1;

    while (std::getline(engine_schematic, line)){
        line = line.substr(line.find(":") + 2, line.length());
        std::vector<int> winning_numbers;

        std::string spelled_number;
        bool is_winning_number = true;
        int same_numbers = 0;

        for(int i=0; i<line.size(); i++){
            const char& c = line[i];

            if(c >= '0' && c <= '9')
                spelled_number += c;

            if(c == ' ' || i == line.size()-1){
                if(spelled_number.size() > 0){
                    if(is_winning_number){
                        winning_numbers.push_back(stoi(spelled_number));
                        spelled_number = "";
                    }else{
                        int number = stoi(spelled_number);
                        spelled_number = "";

                        for(int j=0; j<winning_numbers.size(); j++){
                            if(number == winning_numbers[j]){
                                same_numbers++;
                                break;
                            }
                        }
                    }
                }
            }else if (c == '|'){
                is_winning_number = false;
            }
        }

        for(int i=0; i<same_numbers; i++){
            int index = card_number + i;
            if(index <= number_of_lines){
                copys[index] += copys[card_number-1];
            }
        }

        card_number ++;
    }

    for(int i=0; i<copys.size(); i++){
        sum += copys[i];
    }

    std::cout << "Points: " << sum << std::endl;

    return 0;
}