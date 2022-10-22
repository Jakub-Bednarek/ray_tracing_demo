#ifndef GLOBAL_CONFIG_HPP
#define GLOBAL_CONFIG_HPP

namespace Config
{
constexpr auto imageWidth = 1920;
constexpr auto imageHeight = 1080;
constexpr auto aspectRatio = static_cast<double>(imageWidth) / static_cast<double>(imageHeight);
}

#endif // GLOBAL_CONFIG_HPP