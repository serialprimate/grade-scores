# Configure the grade-scores application.

# Determine the sources.
file(GLOB SOURCES "*.cpp")

# Set the include directories.
include_directories(${GradeScores_SOURCE_DIR}/library)

# Define the executable.
add_executable(grade-scores ${SOURCES})

# Link with the grade library.
target_link_libraries(grade-scores grade)

# Set the installation path.
install(TARGETS grade-scores RUNTIME DESTINATION bin)