# Windows compilation hasn't really been tested.


cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -O3 -march=native -std=c++11 -msse -msse2 -msse3 -ffast-math")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread -O3 -march=native -std=c++11 -msse -msse2 -msse3 -ffast-math")

# You shouldn't have to modify anything below this line 
########################################################


set (CMAKE_CXX_LINK_EXECUTABLE "${CMAKE_CXX_LINK_EXECUTABLE}")

find_package(PkgConfig REQUIRED)
find_package( OpenCV REQUIRED )

INCLUDE_DIRECTORIES(
    ./include

    ${OpenCV_INCLUDE_DIRS}
)

LINK_DIRECTORIES(
    
)

LINK_LIBRARIES(
    ${OpenCV_LIBS}
    pthread
)

# tests

ADD_EXECUTABLE(videoScreenshot
    ./src/videoScreenshot.cpp
)