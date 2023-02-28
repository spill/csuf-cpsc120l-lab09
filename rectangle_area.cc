// Anthony Vasquez
// CPSC 120-04
// 2022-11-13
// s950tx16wasr10@csu.fullerton.edu
// @dskoman
//
// Lab 10-01
// Partners: @rtrinh02, @rchristian6
//
// Finds the area of a rectangle
//

#include <iostream>
#include <string>
#include <vector>

#include "rectangle_area_functions.h"

int main(int argc, char const* argv[]) {
  std::vector<std::string> arguments(argv, argv + argc);

  if (arguments.size() != 3) {
    std::cout << "error: invalid number of arguments";

    return 1;
  }

  int length{0};
  int width{0};

  length = std::stoi(arguments.at(1));
  width = std::stoi(arguments.at(2));

  std::cout << length << " x " << width << " = " << RectangleArea(length, width)
            << "\n";

  return 0;
}
