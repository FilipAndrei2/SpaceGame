file(glob SOURCES "src/*.cpp")

add_library(filphysics STATIC ${SOURCES})

target_include_directories(filphysics PUBLIC ${PROJECT_SOURCE_DIR}/include)