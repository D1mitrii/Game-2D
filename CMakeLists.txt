cmake_minimum_required(VERSION 3.23)
project(OOP)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(OOP
        main.cpp src/Game.cpp src/Game.h src/Background/Field.cpp src/Background/Field.h src/Events/Event.h src/Views/CellView.cpp src/Views/CellView.h src/Views/FieldView.cpp src/Views/FieldView.h src/Entities/Player.cpp src/Entities/Player.h src/Events/Event.h src/Events/PlayerEvents/PlayerEvents.h src/Events/PlayerEvents/PoisonTrap.h src/Events/PlayerEvents/PoisonTrap.cpp src/Events/PlayerEvents/FrozenTrap.h src/Events/PlayerEvents/FrozenTrap.cpp src/Utils/Obs/ISubject.cpp src/Utils/Obs/ISubject.h src/Utils/Obs/IObserver.cpp src/Utils/Obs/IObserver.h src/Utils/IOCommander.cpp src/Utils/IOCommander.h src/Views/PlayerView.cpp src/Views/PlayerView.h src/Events/PlayerEvents/CoinEvent.cpp src/Events/PlayerEvents/CoinEvent.h src/Utils/RNG/RNGenerator.cpp src/Utils/RNG/RNGenerator.h src/Events/FieldEvents/FieldEvents.h src/Events/FieldEvents/FieldChangePos.cpp src/Events/FieldEvents/FieldChangePos.h src/Events/PlayerEvents/Buff.cpp src/Events/PlayerEvents/Buff.h src/Events/FieldEvents/FieldRegen.cpp src/Events/FieldEvents/FieldRegen.h src/Events/PlayerEvents/HealEvent.cpp src/Events/PlayerEvents/HealEvent.h src/Utils/Med/IMediator.h src/Utils/Med/MediatorObject.cpp src/Utils/Med/MediatorObject.h src/Utils/Med/Mediator.cpp src/Utils/Med/Mediator.h src/Background/Cell.cpp src/Background/Cell.h src/Background/CellFactory/CellFactory.cpp src/Background/CellFactory/CellFactory.h src/Events/EventGenerator/EventGenerator.cpp src/Events/EventGenerator/EventGenerator.h)
