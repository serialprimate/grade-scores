# Configure the grade-scores application tests.

# Set the input and output files.
configure_file(scores.txt scores.txt COPYONLY)
configure_file(scores-graded.txt scores-graded.txt.expected COPYONLY)

# Test the application.
add_test(NAME test-grade-scores COMMAND $<TARGET_FILE:grade-scores> "scores.txt")

# Test the application output file.
add_test(NAME test-grade-scores-output-file COMMAND ${CMAKE_COMMAND} -E compare_files scores-graded.txt scores-graded.txt.expected)
