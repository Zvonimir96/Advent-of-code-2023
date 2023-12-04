#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

#define FILE_NAME "Task4/input.txt"


int main()
{
    std::ifstream engine_schematic(FILE_NAME);
    std::string line;

    int sum = 0;

    while (std::getline(engine_schematic, line)){
        line = line.substr(line.find(":") + 2, line.length());
        std::vector<int> winning_numbers;

        std::string spelled_number;
        bool is_winning_number = true;
        int row_sum = 0;
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
                                row_sum == 0 ? row_sum = 1 : row_sum = row_sum << 1;
                                break;
                            }
                        }
                    }
                }
            }else if (c == '|'){
                is_winning_number = false;
            }
        }
        sum += row_sum;
    }

    std::cout << "Points: " << sum << std::endl;

    return 0;
}