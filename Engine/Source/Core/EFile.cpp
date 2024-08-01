#include "../Core/EFile.h"

std::string File::GetFilePath()
{
    return FILE::current_path().string();
}

bool File::SetFilePath(const std::string& filepath)
{
    std::error_code ec;
    FILE::current_path(filepath, ec);

    return !ec;
}
