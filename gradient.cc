// Anthony Vasquez
// CPSC 120-04
// 2022-11-13
// s950tx16wasr10@csu.fullerton.edu
// @dskoman
//
// Lab 10-03
// Partners: @rtrinh02, @rchristian6
//
// Creates a rainbow gradient image
//

#include <Magick++.h>

#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "gradient_functions.h"

// Please do not change the size of the image. This will break
// the automated tests.
const int kImageWidth{512};
const int kImageHeight{512};

int main(int argc, char* argv[]) {
  // Initialize the GraphicsMagick library. It must be the first thing
  // that happens in the main function.
  // Do not change or remove the line below.
  Magick::InitializeMagick(*argv);

  std::vector<std::string> arguments(argv, argv + argc);

  if (arguments.size() != 2) {
    std::cout << "Please provide a path to a file.\n";

    return 1;
  }

  std::string output_file_name;
  output_file_name = arguments.at(1);
  std::string image_format{".png"};

  if (!HasMatchingFileExtension(output_file_name, image_format)) {
    std::cout << output_file_name << " is missing the required file extension "
              << image_format << ".\n";

    return 1;
  }

  Magick::ColorRGB white(1, 1, 1);
  Magick::Image image(Magick::Geometry(kImageWidth, kImageHeight), white);

  for (int col = image.columns() - 1; col >= 0; col--) {
    for (int row = 0; row < image.rows(); row++) {
      double red{0.0};
      double green{0.0};
      double blue{0.0};

      red = double(row) / double(image.columns() - 1);
      green = double(col) / double(image.rows() - 1);
      blue = 0.25;

      Magick::ColorRGB color{red, green, blue};
      image.pixelColor(row, col, color);
    }
  }

  image.write(output_file_name);

  return 0;
}
