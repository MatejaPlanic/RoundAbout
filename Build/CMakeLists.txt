CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

PROJECT(Seminarski)

SET (CMAKE_CXX_STANDARD 14)

SET (POOP
    ../Code/main.cpp
    ../Code/Vozila/Vozilo.cpp
    ../Code/KruzniTok/KruzniTok.cpp

)

add_executable(exe ${POOP})