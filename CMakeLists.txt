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
        GameEngine.cpp
        GameEngine.h
        CombatSystem.cpp
        CombatSystem.h
        Logger.cpp
        Logger.h
        Level.cpp
        Level.h
        Item.h
        ItemManager.cpp
        ItemManager.h
        Ability.h
        KnightAbility.cpp
        KnightAbility.h
        RogueAbility.cpp
        RogueAbility.h
        WizardAbility.cpp
        WizardAbility.h
        PriestAbility.cpp
        PriestAbility.h
        Inventory.cpp
        Inventory.h
        EventSystem.cpp
        EventSystem.h
)
