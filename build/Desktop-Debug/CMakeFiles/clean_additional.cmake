# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Fractals_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Fractals_autogen.dir/ParseCache.txt"
  "Fractals_autogen"
  )
endif()
