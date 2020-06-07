cmake_minimum_required (VERSION 3.1)

project (Stellar)

add_executable(main
 ${PROJECT_SOURCE_DIR}/src/main.cpp
 ${PROJECT_SOURCE_DIR}/src/Shader.cpp
 ${PROJECT_SOURCE_DIR}/src/Window.cpp
 ${PROJECT_SOURCE_DIR}/src/Renderer.cpp
 ${PROJECT_SOURCE_DIR}/src/Texture.cpp
 ${PROJECT_SOURCE_DIR}/Dependencies/imgui/imconfig.h
 ${PROJECT_SOURCE_DIR}/Dependencies/imgui/imgui_demo.cpp
 ${PROJECT_SOURCE_DIR}/Dependencies/imgui/imgui_draw.cpp
 ${PROJECT_SOURCE_DIR}/Dependencies/imgui/imgui_impl_glfw.cpp
 ${PROJECT_SOURCE_DIR}/Dependencies/imgui/imgui_impl_glfw.h
 ${PROJECT_SOURCE_DIR}/Dependencies/imgui/imgui_impl_opengl3.cpp
 ${PROJECT_SOURCE_DIR}/Dependencies/imgui/imgui_impl_opengl3.h
 ${PROJECT_SOURCE_DIR}/Dependencies/imgui/imgui_internal.h
 ${PROJECT_SOURCE_DIR}/Dependencies/imgui/imgui_widgets.cpp
 ${PROJECT_SOURCE_DIR}/Dependencies/imgui/imgui.cpp
 ${PROJECT_SOURCE_DIR}/Dependencies/imgui/imgui.h
 ${PROJECT_SOURCE_DIR}/Dependencies/imgui/imstb_rectpack.h
 ${PROJECT_SOURCE_DIR}/Dependencies/imgui/imstb_textedit.h
 ${PROJECT_SOURCE_DIR}/Dependencies/imgui/imstb_truetype.h
)

set_property(TARGET main PROPERTY CXX_STANDARD 11)
target_compile_options(main PRIVATE -Wall)

add_subdirectory(${PROJECT_SOURCE_DIR}/Dependencies/glfw EXCLUDE_FROM_ALL)
target_link_libraries(main PRIVATE glfw)

add_definitions(-DGLEW_STATIC)
add_subdirectory(${PROJECT_SOURCE_DIR}/Dependencies/glew EXCLUDE_FROM_ALL)
target_link_libraries(main PRIVATE libglew_static)

add_subdirectory(${PROJECT_SOURCE_DIR}/Dependencies/glm EXCLUDE_FROM_ALL)
target_link_libraries(main PRIVATE glm)

target_include_directories(main PRIVATE
    ${PROJECT_SOURCE_DIR}/Dependencies/imgui ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/Dependencies/stb_image
)
IF(WIN32)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT main)
ENDIF()

