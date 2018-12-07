// launchproc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>       // std::cout
#include <string>         // std::string
#include <locale>         // std::locale, std::tolower
#include <algorithm>
#include <fstream>
#include <sys/stat.h>
#include <stdlib.h>

using namespace std;

bool replace(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if (start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

inline bool exists(const std::string& name) {
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
}

int main(int argc, char *argv[])
{
    //get the cfg file name
    string exeFilePath = argv[0];
    string cmdLine = "";

    for (int index = 1;index < argc ;index++)
    {
        cmdLine.append(" ");
        cmdLine.append(argv[index]);
    }

    std::transform(exeFilePath.begin(), exeFilePath.end(), exeFilePath.begin(), ::tolower);
    string cfgFilePath = exeFilePath;
    string psFilePath = exeFilePath;

    replace(cfgFilePath, ".exe", ".cfg");
    replace(psFilePath, ".exe", ".ps1");

    if (exists(psFilePath))
    {
        string finalCmd = "powershell.exe -file ";
        finalCmd.append(psFilePath);
        finalCmd.append(cmdLine);

        system(finalCmd.c_str());
    }
    else if(exists(cfgFilePath))
    {
        //read the first line and run the command.
        string line = "";
        ifstream myfile(cfgFilePath);
        if (myfile.is_open())
        {
            getline(myfile, line);
            myfile.close();
        }

        if (line.length() > 0)
        {
            string finalCmd = line;
            finalCmd.append(cmdLine);

            system(finalCmd.c_str());
        }
    }
}




