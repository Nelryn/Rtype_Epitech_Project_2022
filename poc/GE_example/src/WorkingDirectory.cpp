/*
** EPITECH PROJECT, 2022
** TGG
** File description:
** WorkingDirectory
*/

#include "../include/WorkingDirectory.hpp"

WorkingDirectory::WorkingDirectory()
{
    _path = "./Resources/Textures/";
    #ifdef MACOS  // 2
    // Change the default working directory to that of 
    // the XCode resource path on MacOS.
    CFBundleRef mainBundle = CFBundleGetMainBundle();
    CFURLRef resourcesURL =
    CFBundleCopyResourcesDirectoryURL(mainBundle);
    char _path[PATH_MAX];
    if (CFURLGetFileSystemRepresentation(
    resourcesURL, TRUE, (UInt8 *)_path, PATH_MAX))
    {
    CFRelease(resourcesURL);
    chdir(_path);
    }
    #endif
}

WorkingDirectory::~WorkingDirectory()
{
}