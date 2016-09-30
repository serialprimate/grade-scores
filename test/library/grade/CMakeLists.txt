# Configure the test-library-grade module.

# Determine the sources.
file(GLOB SOURCES "*.cpp")

# Set the include directories.
include_directories(${GradeScores_SOURCE_DIR}/library)

# Define the executable.
add_executable(test-library-grade ${SOURCES})

# Link it with boost unit test and the grade library.
target_link_libraries(test-library-grade grade ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

# Add it as a test.
add_test(NAME test-library-grade COMMAND $<TARGET_FILE:test-library-grade> "--log_level=all" "--report_level=detailed")

# Set the installation path.
install(TARGETS test-library-grade RUNTIME DESTINATION bin)
