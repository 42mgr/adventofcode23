#include <iostream>
#include <fstream>
#include <string>

void replaceSubstring(std::string subString, std::string newString, std::string &line)
{
    size_t pos = line.find(subString);
    if (pos != std::string::npos)
    {
        line.replace(pos, line.length(), newString);
    }
    std::cout << line << std::endl;
}

void replaceNumbers(std::string &inputString)
{
    std::pair<std::string, std::string> replacements[] = {
        {"eightwo", "82"}, {"oneight", "18"}, {"threeight", "38"}, {"fiveight", "58"}, {"nineight", "98"}, {"one", "1"}, {"two", "2"}, {"three", "3"}, {"four", "4"}, {"five", "5"}, {"six", "6"}, {"seven", "7"}, {"eight", "8"}, {"nine", "9"}};
    for (const auto &replacement : replacements)
    {
        size_t pos = inputString.find(replacement.first);
        while (pos != std::string::npos)
        {
            inputString.replace(pos, replacement.first.length(), replacement.second);
            pos = inputString.find(replacement.first);
        }
    }
}

int main()
{
    int sum = 0;

    // Open the file
    std::ifstream inputFile("input.txt");

    // Check if the file is open
    if (!inputFile.is_open())
    {
        std::cerr << "Error opening file!" << std::endl;
        return 1; // Return an error code
    }

    // Read the file line by line
    std::string line;
    while (std::getline(inputFile, line))
    {
       //std::cout << line << " " << std::endl;
        replaceNumbers(line);
        //std::cout << line << " " << std::endl;
        int length = line.length();
        int i = 0;
        while (!isdigit(line[i]))
        {
            i++;
        }
        int first = line[i] - '0';
        i = length - 1;
        while (!isdigit(line[i]))
        {
            i--;
        }
        int second = line[i] - '0';
        // Process each line here
        int number = first * 10 + second;
        // std::cout << number << std::endl;
        sum += number;
    }

    // Close the file
    inputFile.close();
    std::cout << "The sum is: " << sum << std::endl;

    return 0; // Return success
}
