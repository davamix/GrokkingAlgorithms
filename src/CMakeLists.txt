file(GLOB SOURCE_FILES *.cpp *.h)

add_library(libproject STATIC ${SOURCE_FILES})
set_target_properties(libproject PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(libproject PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
