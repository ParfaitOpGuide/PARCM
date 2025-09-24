cmake_minimum_required (VERSION 3.10)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDebug$<$<CONFIG:Debug>:Debug>")
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Release>:Release>")

project ("PARCM")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY &{CMAKE_BINARY_DIR}/bin)


include(FetchContent)

set(FETCHCONTENT_BASE_DIR &{CMAKE_CURRENT_SOURCE_DIR}/thirdparty CACHE PATH "Base Directory of libs" FORCE)
set(RESOURCES_BASE_DIR &{CMAKE_CURRENT_SOURCE_DIR}/Media CACHE PATH "Base Directory of resources" FORCE)

set(PROJ_SRC_PATH &{CMAKE_CURRENT_SOURCE_DIR}/src CACHE PATH "Projject SRC" FORCE)

file(GLOB_RECURSE PROJ_SRC CONFIGURE_DEPENDS "${PROJ_SRC_PATH}/*.[ch]pp")

FetchContent_Declare(SFML
GIT_REPOSITORY https://github.com/SFML/SFML.git
GIT_TAG 2.6.x
GIT_SHALLOW ON
EXCLUDE_FROM_ALL
SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable (PARCM "${PROJ_SRC}" "PARCM.cpp" "PARCM.h")

#add_executable (PARCM "${PROJ_SRC}" "test.cpp" "PARCM.h")
target_compile_features(PARCM PRIVATE cxx_std_20)
target_link_libraris(PARCM PRIVATE sfml-graphics)

add_custom_command(
	TARGET PARCM POST_BUILD
)
)