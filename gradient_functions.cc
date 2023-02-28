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

#include "gradient_functions.h"

// The function returns true if file_name ends with extension.
// For example, the function will return true if the file_name is
// "output_image.png" and extension is ".png". The function will
// return false if file_name is "output_image.bmp" and extension is
// ".png".
bool HasMatchingFileExtension(const std::string& file_name,
                              const std::string& extension) {
  int file_name_length{int(file_name.length())};
  int extension_length{int(extension.length())};

  int has_matching_file_extension = file_name.compare(
      file_name_length - extension_length, extension_length, extension);

  if (has_matching_file_extension == 0) {
    return true;
  }

  return false;
}
