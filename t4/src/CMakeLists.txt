# libzwhosts.a
# link_directories(${PROJECT_SOURCE_DIR}/lib/zwhost/lib_static)
set(ZWHOST_DIR ${PROJECT_SOURCE_DIR}/lib/zwhost)
message(STATUS "ZWHOST_DIR= " ${ZWHOST_DIR})
include_directories(${ZWHOST_DIR}/include)
find_library(ZWHOSTS_LIBRARY zwhosts PATHS ${ZWHOST_DIR}/lib_static)
# message(STATUS "ZWHOSTS_LIBRARY= " ${ZWHOSTS_LIBRARY})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(demo main.cpp)
target_link_libraries(demo pthread)
target_link_libraries(demo ${ZWHOSTS_LIBRARY})
