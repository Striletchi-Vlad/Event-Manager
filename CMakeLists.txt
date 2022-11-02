cmake_minimum_required(VERSION 3.21)
project(a8_9_917_Striletchi_Vlad)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(a8_9_917_Striletchi_Vlad
        Controller.cpp
        Controller.h
        Event.cpp
        Event.h
        Repo.cpp
        Repo.h
        Start.cpp
        Tests.cpp
        Tests.h
        UI.cpp
        UI.h
        Validations.cpp
        Validations.h Controller_User.cpp Controller_User.h CSV_HTML_Writer.h
        Comparator.cpp Comparator.h
        ComparatorAscendingTitle.cpp
        ComparatorAscendingTitle.h
        ComparatorDescendingNoPeople.cpp
        ComparatorDescendingNoPeople.h)
