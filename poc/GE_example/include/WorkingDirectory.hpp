/*
** EPITECH PROJECT, 2022
** TGG
** File description:
** WorkingDirectory
*/

#pragma once

#include <string>

#ifdef MACOS 
#include "CoreFoundation/CoreFoundation.h"
#endif

class WorkingDirectory {
    public:
        WorkingDirectory();
        ~WorkingDirectory();
        inline const std::string& Get() // 1
        {
            return _path;
        }
    protected:
    private:
        std::string _path;
};
