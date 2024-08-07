#include "../Core/EFile.h"
#include <filesystem>
#include <iostream>
#include <fstream>

std::string File::GetFilePath()
{
    return FILESYS::current_path().string();
}

bool File::SetFilePath(const std::string& filepath)
{
    std::error_code ec;
    FILESYS::current_path(filepath, ec);

    return !ec;
}

bool File::FileExists(const std::string& filepath)
{
    return FILESYS::exists(filepath);
}

bool File::GetFileSize(const std::string& filepath, int& size)
{
    std::error_code ec;
    size = (int)FILESYS::file_size(filepath, ec);
    return !ec;
}

bool File::ReadFile(const std::string& filepath, std::string& buffer)
{
    if (!FileExists(filepath))
    {
        std::cerr << "File does not exists: " << filepath << std::endl;
        return false;
    }
    std::ifstream stream(filepath, std::ios::in);
    if (!stream.is_open())
    {
        std::cerr << "Could not open file: " << filepath << std::endl;
        return false;
    }
    std::ostringstream ostream;
    ostream << stream.rdbuf();

    buffer = ostream.str();

    return true;
}
