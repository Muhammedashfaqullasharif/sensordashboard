cmake_minimum_required(VERSION 3.16)

project(sensormonitor VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appsensormonitor
    main.cpp
)

qt_add_qml_module(appsensormonitor
    URI sensormonitor
    VERSION 1.0
    QML_FILES

    SOURCES
        SOURCES
        SOURCES
        QML_FILES qml/Main.qml
        SOURCES SensorController.h
        SOURCES SensorModel.h
        SOURCES controler/SensorController.cpp
        SOURCES model/SensorModel.cpp
        QML_FILES qml/Circularmeter.qml
        QML_FILES qml/UVgraph.qml
        QML_FILES qml/Aqigraph.qml

)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appsensormonitor PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appsensormonitor
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appsensormonitor
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appsensormonitor
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
