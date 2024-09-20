if (APPLE)
    target_link_libraries(SimulacraLibrary
            "-framework AppKit"
            "-framework Foundation"
    )
    target_sources(SimulacraLibrary PRIVATE Mac/MacWindow.mm Mac/MacApplicationDelegate.mm Mac/CocoaWindow.mm )


endif ()

if (WIN32)
    target_sources(SimulacraLibrary PRIVATE Windows/WindowsWindow.cpp)
endif ()