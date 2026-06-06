cmake_minimum_required(VERSION 4.1)
project(ProyectoII)

set(CMAKE_CXX_STANDARD 20)

add_executable(ProyectoII main.cpp
        Characters.cpp
        Characters.h
        Entity.cpp
        Entity.h
        Utiles.h
        Enemy.cpp
        Enemy.h
        CharacterManager.cpp
        CharacterManager.h
        Menu.cpp
        Menu.h
        EnemyManager.cpp
        EnemyManager.h
        Room.cpp
        Room.h
        SimpleRoom.cpp
        SimpleRoom.h
        BossRoom.cpp
        BossRoom.h
)
