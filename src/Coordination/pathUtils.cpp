#include <Coordination/pathUtils.h>
#include <iostream>

namespace DB
{

static size_t findLastSlash(std::string_view path)
{
    if (path.empty())
        return std::string::npos;

    for (size_t i = path.size() - 1; i > 0; --i)
    {
        if (path[i] == '/')
            return i;
    }

    if (path[0] == '/')
        return 0;

    return std::string::npos;
}

std::string_view parentPath(std::string_view path)
{
    auto rslash_pos = findLastSlash(path);
    if (rslash_pos > 0)
        return path.substr(0, rslash_pos);
    return "/";
}

std::string_view getBaseName(std::string_view path)
{
    size_t basename_start = findLastSlash(path);
    return path.substr(basename_start + 1);
}

}
