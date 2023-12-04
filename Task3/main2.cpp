#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

#define FILE_NAME "Task3/puzzle_input.txt"

/*
-2 ništa
-1 *
0 pa na dalje brojevi
*/

int main()
{
    std::ifstream engine_schematic(FILE_NAME);
    std::string line;

    std::vector<std::vector<int32_t>> schematic;
    std::vector<uint32_t> numbers;

    while (std::getline(engine_schematic, line))
    {
        std::vector<int32_t> shematic_line;
        bool is_number = false;
        std::string spelled_number;

        for (int i = 0; i < line.size(); i++)
        {
            if (line[i] >= '0' && line[i] <= '9')
            {
                shematic_line.push_back(numbers.size());

                spelled_number += line[i];

                is_number = true;
            }
            else if (line[i] == '*')
            {
                shematic_line.push_back(-1);
                is_number = false;
            }
            else
            {
                shematic_line.push_back(-2);
                is_number = false;
            }

            if ((!is_number && spelled_number.size() > 0) || ((i == line.size() - 1) && is_number))
            {
                numbers.push_back(std::stoi(spelled_number));
                spelled_number = "";
            }
        }

        schematic.push_back(shematic_line);
    }

    std::vector<bool> activ_numbers(numbers.size(), false);
    uint32_t sum = 0;

    for (int i = 0; i < schematic.size(); i++)
    {
        for (int j = 0; j < schematic[i].size(); j++)
        {
            if (schematic[i][j] == -1)
            {
                int x = i - 1, y = j - 1;
                int number_of_parts=0;
                uint32_t gear_sum=1;
                int last_number = -1;

                for (int xx = x; xx <= x + 2; xx++)
                {
                    for (int yy = y; yy <= y + 2; yy++)
                    {
                        if ((xx >= 0 && xx < schematic.size()) && (yy >= 0 && yy < schematic[xx].size()))
                            if ((schematic[xx][yy] >= 0) && (last_number != schematic[xx][yy])){
                                last_number = schematic[xx][yy];
                                number_of_parts++;
                                gear_sum *= numbers[schematic[xx][yy]];
                            }
                    }
                }

                if(number_of_parts == 2)
                    sum += gear_sum;
            }
        }
    }

    std::cout << "Sum of numbers: " << sum << std::endl;

    return 0;
}