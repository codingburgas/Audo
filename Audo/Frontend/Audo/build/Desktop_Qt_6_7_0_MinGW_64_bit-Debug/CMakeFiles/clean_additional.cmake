# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "Audo_autogen"
  "CMakeFiles\\Audo_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Audo_autogen.dir\\ParseCache.txt"
  )
endif()
