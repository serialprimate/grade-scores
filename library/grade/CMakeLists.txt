# Configure the grade library.

# Determine the sources.
file(GLOB SOURCES "*.cpp")

# Set the include directories.
include_directories(${GradeScores_SOURCE_DIR}/library)

# Create the library.
add_library(grade STATIC ${SOURCES})

# Set the installation path.
install(TARGETS grade RUNTIME DESTINATION bin
                      LIBRARY DESTINATION lib
                      ARCHIVE DESTINATION lib)