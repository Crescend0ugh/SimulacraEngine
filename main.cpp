#include <iostream>
#include "Source/color.h"
#include "Source/ray.h"
#include "Source/vec3.h"

color ray_color(const ray& r)
{
    return color (0,0,0);
}


int main() {

    // Image

    auto aspect_ratio = 16.0/9.0;

    int image_width = 256;
    int image_height = static_cast<int>(image_width/aspect_ratio);
    image_height = (image_height<1) ? 1 : image_height;

    //Camera
    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (static_cast<double>(image_width)/image_height);
    auto camera_center = point3(0,0,0);

    // Render

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; ++j)
    {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i)
        {
            auto pixel_color = color(double(i)/(image_width-1), double(j)/(image_height-1),.25);
            write_color(std::cout, pixel_color);
        }
    }
    std::clog << "\rDone.                 \n";
}

//cmake --build build
// cmake -B build
// build\Debug\SimulacraEngine.exe | set-content image.ppm -encoding String