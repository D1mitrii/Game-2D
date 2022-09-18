cmake_minimum_required(VERSION 3.23)
project(OOP)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(OOP
        main.cpp src/Game.cpp src/Game.h src/Background/Cell.cpp src/Background/Cell.h src/Background/Field.cpp src/Background/Field.h src/Events/Event.cpp src/Events/Event.h src/Views/CellView.cpp src/Views/CellView.h src/Views/FieldView.cpp src/Views/FieldView.h src/Entities/Player.cpp src/Entities/Player.h)
