cmake_minimum_required(VERSION 3.5)

# Set the vcpkg toolchain file path
set(CMAKE_TOOLCHAIN_FILE "F:/repositories/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
set(VCPKG_PATH "F:/Repositories/vcpkg")
set(CMAKE_PREFIX_PATH "C:/Qt/6.5.2/msvc2019_64" ${CMAKE_PREFIX_PATH})

project(cpp-auth VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Network)

# --- Packages | Don't forget to manually copy DLL files! ---

# Curl:
set(CURL_INCLUDE_DIRS "${VCPKG_PATH}/installed/x64-windows/include")
set(CURL_LIBRARIES "${VCPKG_PATH}/installed/x64-windows/lib/libcurl.lib")
find_package(CURL REQUIRED)

# Nlohmann/JSON:
find_package(nlohmann_json 3.11.2 REQUIRED)

set(PROJECT_SOURCES
        src/PCH.h
        src/Main.cpp
        src/Config.h

        src/Authentication/Authentication.cpp

        src/Authentication/VerifyLicense.cpp
        src/Authentication/VerifyLicense.h
        src/Authentication/VerifyLicense.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(cpp-auth
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
endif()

target_link_libraries(cpp-auth
    PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Network
    CURL::libcurl
    nlohmann_json::nlohmann_json
)

set_target_properties(cpp-auth PROPERTIES
    WIN32_EXECUTABLE TRUE
    LINK_FLAGS "/MANIFESTUAC:\"level='requireAdministrator' uiAccess='false'\""
)

install(TARGETS cpp-auth
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(cpp-auth)
endif()
