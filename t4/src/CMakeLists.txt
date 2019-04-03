# libtest
include_directories(${PROJECT_SOURCE_DIR}/libtest)

# libzwhosts.a
# link_directories(${PROJECT_SOURCE_DIR}/lib/zwhost/lib_static)
set(ZWHOST_DIR ${PROJECT_SOURCE_DIR}/lib/zwhost)
include_directories(${ZWHOST_DIR}/include)
find_library(ZWHOSTS_LIBRARY zwhosts PATHS ${ZWHOST_DIR}/include/lib_static)
# message(STATUS "ZWHOSTS_LIBRARY= " ${ZWHOSTS_LIBRARY})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

add_executable(demo main.cpp)
#target_link_libraries(demo commonbase)
target_link_libraries(demo ${ZWHOSTS_LIBRARY})
