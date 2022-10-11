cmake_minimum_required(VERSION 3.23)
project(OOP)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(OOP
        main.cpp src/Game.cpp src/Game.h src/Background/Cell.cpp src/Background/Cell.h src/Background/Field.cpp src/Background/Field.h src/Events/Event.h src/Views/CellView.cpp src/Views/CellView.h src/Views/FieldView.cpp src/Views/FieldView.h src/Entities/Player.cpp src/Entities/Player.h src/Utils/CommandReader.cpp src/Utils/CommandReader.h src/Utils/Mediator.cpp src/Utils/Mediator.h src/Events/Event.h src/Events/PlayerEvents/PlayerEvents.h src/Events/PlayerEvents/PoisonTrap.h src/Events/PlayerEvents/PoisonTrap.cpp src/Events/PlayerEvents/FrozenTrap.h src/Events/PlayerEvents/FrozenTrap.cpp src/Utils/Obs/ISubject.cpp src/Utils/Obs/ISubject.h src/Utils/Obs/IObserver.cpp src/Utils/Obs/IObserver.h src/Views/PlayerView.cpp src/Views/PlayerView.h src/Events/PlayerEvents/CoinEvent.cpp src/Events/PlayerEvents/CoinEvent.h src/Utils/RNG/RNGenerator.cpp src/Utils/RNG/RNGenerator.h src/Events/FieldEvents/FieldEvents.h src/Events/FieldEvents/FieldChangePos.cpp src/Events/FieldEvents/FieldChangePos.h src/Events/FieldEvents/RegenField.cpp src/Events/FieldEvents/RegenField.h src/Background/Cell/ICell.h src/Background/Cell/CellTrap.cpp src/Background/Cell/CellTrap.h src/Background/Cell/CellWall.h src/Background/Cell/CellCoin.cpp src/Background/Cell/CellCoin.h src/Background/Cell/CellBase.h)
