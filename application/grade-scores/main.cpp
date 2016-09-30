/**
 * \file main.cpp
 * \copyright Copyright (C) 2016 Matt Davies - All Rights Reserved.
 *
 * Implementation grade-score application.
 */

#include <grade/GradeScore.h>

#include <algorithm>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <iostream>
#include <vector>

/**
 * Sort the supplied input file of grade scores and output them in a
 * simple CSV format.
 */
int main(int argc, char * argv[])
{
    int result = EXIT_FAILURE;

    if (argc == 2) {

    	try {

	    	std::vector<GradeScore> gradeList; // The grade scores to sort.
	    	GradeScore inputGradeScore;        // An input grade score.

    		// Set the input and output filenames from command line arguments.

    		std::string inputFilename(argv[1]); // The input filename.
    		std::string outputFilename = inputFilename.substr(0, inputFilename.find_last_of('.')) + "-graded.txt"; // The output filename.

    		// Open the input file.

			std::ifstream input(inputFilename); // The input file stream.

	    	// Read the input grade scores.

	    	while (inputGradeScore.fromCSV(input)) {

	    		gradeList.push_back(inputGradeScore);
	    	}

	    	// Sort the grade scores.

	    	std::sort(std::begin(gradeList), std::end(gradeList));

	    	// Open the output file.

	    	std::ofstream output(outputFilename); // The output file stream.

	    	// Write the sorted grade scores.

	    	for (const auto & outputGradeScore: gradeList) {

	    		outputGradeScore.toCSV(output);
	    	}

	    	// Report completion

	    	for (const auto & reportGradeScore: gradeList) {

	    	    reportGradeScore.toCSV(std::cout);
	    	}

	    	std::cout << "Finished: created " + outputFilename;

    		result = EXIT_SUCCESS;

    	} catch (const std::exception & e) {

    		std::cerr << "Caught exception \"" << e.what() << "\"\n";

    	} catch (...) {

    		std::cerr << "Caught unknown exception\n";
    	}

    } else {

    	std::cerr << "Usage: grade_scores <filename>\n" << std::endl;
    }

    return result;
}
