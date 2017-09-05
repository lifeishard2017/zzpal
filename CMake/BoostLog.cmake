set(Boost_NO_SYSTEM_PATHS TRUE) 
set(Boost_USE_STATIC_LIBS OFF)

###############################
# set flags
###############################
# for Boost.Log
add_definitions("-DBOOST_LOG_DYN_LINK")

if (Boost_NO_SYSTEM_PATHS)
  set(BOOST_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/build/boost")
  set(BOOST_INCLUDE_DIRS "${BOOST_ROOT}/include")
  set(BOOST_LIBRARY_DIRS "${BOOST_ROOT}/lib")
endif (Boost_NO_SYSTEM_PATHS)

find_package(Boost COMPONENTS log REQUIRED)
if (Boost_FOUND)
  message(STATUS "Found 'boost library'")
  include_directories(${Boost_INCLUDE_DIR})
  message(STATUS "  boost lib dir: ${Boost_LIBRARY_DIRS}")
  message(STATUS "  boost include dir: ${Boost_INCLUDE_DIR}")
  message(STATUS "  boost link:")
  foreach(var ${Boost_LIBRARIES})
    message(STATUS "    ${var}")
  endforeach(var)
else()
  message(FATAL_ERROR "Couldn't find Boost library.")
endif()