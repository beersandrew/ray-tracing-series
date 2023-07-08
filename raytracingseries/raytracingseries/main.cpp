//
//  main.cpp
//  raytracingseries
//
//  Created by Andrew Beers on 7/8/23.
//

#include <iostream>
#include <fstream>

int main(int argc, const char * argv[]) {
    
    // file stuff for Xcode
    std::streambuf* coutbuf = std::cout.rdbuf();
    std::ofstream out("image.ppm");
    std::cout.rdbuf(out.rdbuf());
    
    // image
    const int image_width = 256;
    const int image_height = 256;
    
    // render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    
    for (int j = image_height - 1; j >= 0; --j){
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i){
            auto r = double(i) / (image_width-1);
            auto g = double(j) / (image_height-1);
            auto b = 0.25;
            
            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);
            
            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
    std::cerr << "\nDone.\n";
    
    std::cout.rdbuf(coutbuf);
}
