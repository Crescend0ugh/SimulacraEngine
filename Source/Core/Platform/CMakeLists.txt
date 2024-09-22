if(APPLE)
target_include_directories(SimulacraLibrary PUBLIC Mac)
endif ()

if(WIN32)
target_include_directories(SimulacraLibrary PUBLIC Windows)
endif ()
