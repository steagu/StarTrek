/*
    @author: Samuel Teague
    @date: 05 Dec 2018 (most recent)
    @file: randomST.cpp
    @description: This file contains a C++ program to choose a random Star Trek episode.
        This is for when a life crisis hits and you can't choose what Star Trek episode to watch.
*/

#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <time.h>



std::vector<std::string> getEpisodesFromFile(std::string fileName)
{
    /*
        @param: takes a string fileName, the file to read the Star Trek episodes from.
        @return: a vector of strings, each string holding the name and description of a 
            single Star Trek episode
    */
    std::vector<std::string> toFill;
    std::ifstream file;

    file.open(fileName);

    if (file.is_open())
    {

        std::string episodeData;
        while(!file.eof())
        {

            std::getline(file, episodeData);

            toFill.push_back(episodeData);

            episodeData = "";
        }
        file.close();
    }

    return toFill;
}

int main(int argc, char* argv[])
{
    const std::string FILENAME = "./STList.txt";

    std::vector<std::string> episodeList = getEpisodesFromFile(FILENAME);

    srand(time(NULL));
    std::string input;

    do {
        std::cout << episodeList[rand() % episodeList.size()] << std::endl;
        if (argc > 1)
        {
            std::cout << "Another? ";
            std::cin >> input;
        }
    }while (input.length() > 0 && input[0] == 'y');


    return 0;


}