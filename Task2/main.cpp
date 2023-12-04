#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <streambuf>
#include <map>

#define FILE_NAME "Task2/puzzle_input.txt"
#define RED_CUBES 12
#define GREEN_CUBES 13
#define BLUE_CUBES 14

int main()
{
    std::ifstream colaboration_doc(FILE_NAME);
    std::string line;

    std::map<std::string, int> colors{{"red", RED_CUBES}, {"green", GREEN_CUBES}, {"blue", BLUE_CUBES}};
    std::map<std::string, int> colors_repetition{{"red", 0}, {"green", 0}, {"blue", 0}};

    uint16_t game_id = 1;
    uint16_t sum_id = 0;
    int second_task_sum = 0;

    while (std::getline(colaboration_doc, line))
    {
        int semicolon_index, start_index = line.find(":") + 2;
        std::string subset = line.substr(start_index, line.size());

        bool is_game_valid = true;
        do
        {
            semicolon_index = subset.find(";");
            std::string batch = subset.substr(0, semicolon_index == std::string::npos ? subset.size() : semicolon_index) + ',';
            subset = subset.substr(semicolon_index + 2, subset.size());

            int coma_index;
            while((coma_index = batch.find(",")) != std::string::npos){
                std::string color_string = batch.substr(0, coma_index+1);
                int number = stoi(color_string);

                std::for_each(colors.begin(), colors.end(), [&](const std::pair<std::string, int> &key_valuet){
                    if(color_string.find(key_valuet.first) != std::string::npos){
                        if(number > key_valuet.second)
                            is_game_valid = false;

                        if (colors_repetition[key_valuet.first] < number)
                            colors_repetition[key_valuet.first] = number;
                    } 
                });

                batch = batch.substr(coma_index+1, batch.size());
            }
        } while (semicolon_index != -1);

        int row_sum = 1;
        std::for_each(colors_repetition.begin(), colors_repetition.end(), [&](const std::pair<std::string, int> &key_valuet){
            row_sum *= key_valuet.second;
            colors_repetition[key_valuet.first] = 0;
        });
        
        second_task_sum += row_sum;

        if(is_game_valid)  
            sum_id += game_id;

        game_id++;
    }

    std::cout << "1. resoult: " << sum_id << std::endl;
    std::cout << "2. resoult: " << second_task_sum << std::endl;
    return 0;
}