cmake_minimum_required(VERSION 3.16)
project(Lab7_New)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab7_New main.cpp src/Person.cpp header/Person.h src/Prepod.cpp header/Prepod.h src/Database.cpp header/Database.h header/PrepodComparer.h)