cmake_minimum_required(VERSION 3.8)
project(OGMA)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#--GLFW-RELATED----------------------------------------
set(GLFW_BUILD_DOCS OFF CACHE BOOL "GLFW lib only")
set(GLFW_INSTALL OFF CACHE BOOL "GLFW lib only")
add_subdirectory("Externals/GLFW")

find_package( OpenGL REQUIRED )
include_directories( ${OPENGL_INCLUDE_DIRS} )
#--IMGUI-RELATED---------------------------------------
set(EXTERNALS_SOURCES
"Externals/IMGUI/imgui.cpp"
"Externals/IMGUI/imgui_demo.cpp"
"Externals/IMGUI/imgui_draw.cpp"
"Externals/IMGUI/imgui_tables.cpp"
"Externals/IMGUI/imgui_widgets.cpp"
"Externals/IMGUI/backends/imgui_impl_glfw.cpp"
"Externals/IMGUI/backends/imgui_impl_opengl3.cpp"
)
include_directories("Externals/IMGUI")
#------------------------------------------------------
include_directories("Externals" PUBLIC)

include_directories("Headers")

set(PRECOMPILED_HEADER "Headers/stdafx.hpp")

set(SOURCES
    "Sources/main.cpp"
    "Sources/App.cpp"
)

if(NOT CMAKE_BUILD_TYPE MATCHES Debug)
    #Disable console for Window application
    message(STATUS "Console Disabled")
    if( MSVC )
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup" )
    else()
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mwindows")
    endif()
else()
    add_compile_definitions(DEBUG)
endif()

#add flags to make the executable static
if(MSVC)
  # Set the compiler options to statically link the C runtime library
  set(CompilerFlags
        CMAKE_CXX_FLAGS
        CMAKE_CXX_FLAGS_DEBUG
        CMAKE_CXX_FLAGS_RELEASE
        CMAKE_CXX_FLAGS_MINSIZEREL
        CMAKE_CXX_FLAGS_RELWITHDEBINFO
        CMAKE_C_FLAGS
        CMAKE_C_FLAGS_DEBUG
        CMAKE_C_FLAGS_RELEASE
        CMAKE_C_FLAGS_MINSIZEREL
        CMAKE_C_FLAGS_RELWITHDEBINFO
        )
  foreach(CompilerFlag ${CompilerFlags})
    string(REPLACE "/MD" "/MT" ${CompilerFlag} "${${CompilerFlag}}")
    set(${CompilerFlag} "${${CompilerFlag}}" CACHE STRING "msvc flags" FORCE)
  endforeach()
else()
    set(FLAGS_LINKER "-static -static-libgcc -static-libstdc++")
    set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${FLAGS_LINKER}") 
endif()

add_executable(${PROJECT_NAME} ${SOURCES} ${EXTERNALS_SOURCES})

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} glfw)

target_precompile_headers(${PROJECT_NAME} PRIVATE ${PRECOMPILED_HEADER})
#target_link_libraries(${PROJECT_NAME} PUBLIC OpenGL32)