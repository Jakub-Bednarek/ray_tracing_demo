#ifndef GLOBAL_CONFIG_HPP
#define GLOBAL_CONFIG_HPP

namespace Config
{
constexpr auto imageWidth = 1920;
constexpr auto imageHeight = 1080;
constexpr auto aspectRatio = static_cast<double>(imageWidth) / static_cast<double>(imageHeight);
constexpr auto viewportHeight = 10.0;
constexpr auto focalLength = 1.0;
}

#endif // GLOBAL_CONFIG_HPP