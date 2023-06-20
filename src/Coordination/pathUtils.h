#pragma once

#include <string>
namespace DB
{

std::string_view parentPath(std::string_view path);

std::string_view getBaseName(std::string_view path);

}
