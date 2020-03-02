cmake_minimum_required (VERSION 3.8)
project(project_BetterMap)
add_subdirectory(CWSDK)
add_subdirectory(imgui-1.73)
add_library (BetterMap SHARED 
"main.cpp" 
"BetterMapMod.cpp"
"BetterMapWindow.cpp"
"DButton.cpp"
)
target_link_libraries (BetterMap LINK_PUBLIC CWSDK)
target_link_libraries (BetterMap LINK_PUBLIC IMGUI)