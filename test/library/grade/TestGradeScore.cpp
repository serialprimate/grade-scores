/**
 * \file TestGradeScore.cpp
 * \copyright Copyright (C) 2016 Matt Davies - All Rights Reserved.
 *
 * Implementation of the GradeScore class unit tests.
 */

#include <grade/GradeScore.h>

#include <boost/test/unit_test.hpp>

#include <sstream>

BOOST_AUTO_TEST_SUITE (GradeScoreClass)

BOOST_AUTO_TEST_CASE (defaultConstructor) {

    GradeScore gradeScore;

    // Test initialisation.
    BOOST_CHECK_EQUAL(gradeScore.lastName(), "");
    BOOST_CHECK_EQUAL(gradeScore.firstName(), "");
    BOOST_CHECK_EQUAL(gradeScore.score(), 0);
}

BOOST_AUTO_TEST_CASE (constructor) {

    GradeScore gradeScore("SMITH", "JOHN", 50);

    // Test initialisation.
    BOOST_CHECK_EQUAL(gradeScore.lastName(), "SMITH");
    BOOST_CHECK_EQUAL(gradeScore.firstName(), "JOHN");
    BOOST_CHECK_EQUAL(gradeScore.score(), 50);
}

BOOST_AUTO_TEST_CASE (fromCSV) {

	GradeScore gradeScore;
    std::istringstream input;
	bool fromCSVStatus;

	// Verify basic functionality.
	gradeScore = GradeScore("SMITH", "JOHN", 50);
	input.str("CITIZEN,FRED,60\n");
	fromCSVStatus = gradeScore.fromCSV(input);
	BOOST_CHECK(fromCSVStatus);
	BOOST_CHECK_EQUAL(gradeScore.lastName(), "CITIZEN");
	BOOST_CHECK_EQUAL(gradeScore.firstName(), "FRED");
	BOOST_CHECK_EQUAL(gradeScore.score(), 60);

	// Check fail on malformed line. No change.
    gradeScore = GradeScore("SMITH", "JOHN", 50);
    input.str("FRED,");
    fromCSVStatus = gradeScore.fromCSV(input);
    BOOST_CHECK(!fromCSVStatus);
    BOOST_CHECK_EQUAL(gradeScore.lastName(), "SMITH");
    BOOST_CHECK_EQUAL(gradeScore.firstName(), "JOHN");
    BOOST_CHECK_EQUAL(gradeScore.score(), 50);

	// Check fail on malformed score. No change.
    gradeScore = GradeScore("SMITH", "JOHN", 50);
    input.str("CITIZEN,FRED,XX\n");
    fromCSVStatus = gradeScore.fromCSV(input);
	BOOST_CHECK(!fromCSVStatus);
    BOOST_CHECK_EQUAL(gradeScore.lastName(), "SMITH");
    BOOST_CHECK_EQUAL(gradeScore.firstName(), "JOHN");
    BOOST_CHECK_EQUAL(gradeScore.score(), 50);
}

BOOST_AUTO_TEST_CASE (toCSV) {

    GradeScore gradeScore;
    std::ostringstream output;
    bool toCSVStatus;

    // Verify basic functionality.
    gradeScore = GradeScore("SMITH", "JOHN", 50);
    toCSVStatus = gradeScore.toCSV(output);
    BOOST_CHECK(toCSVStatus);
    BOOST_CHECK_EQUAL(output.str(), "SMITH,JOHN,50\n");
}

BOOST_AUTO_TEST_CASE (operatorLT) {

    GradeScore smithJohn50("SMITH", "JOHN", 50);
    GradeScore johnsonJohn50("JOHNSON", "JOHN", 50);
    GradeScore smithWilliam60("SMITH", "WILLIAM", 60);
    GradeScore smithJames50("SMITH", "JAMES", 50);

    // Sort by score.
    BOOST_CHECK(smithWilliam60 < smithJohn50);

    // Sort by score then by last name.
    BOOST_CHECK(johnsonJohn50 < smithJames50);

    // Sort by score then by last name then by first name.
    BOOST_CHECK(smithJames50 < smithJohn50);

    // Check not less than self.
    BOOST_CHECK(!(smithJohn50 < smithJohn50));
}

BOOST_AUTO_TEST_CASE (lastName) {

    GradeScore smithJohn50("SMITH", "JOHN", 50);

    // Verify basic functionality.
    BOOST_CHECK_EQUAL(smithJohn50.lastName(), "SMITH");
}

BOOST_AUTO_TEST_CASE (firstName) {

    GradeScore smithJohn50("SMITH", "JOHN", 50);

    // Verify basic functionality.
    BOOST_CHECK_EQUAL(smithJohn50.firstName(), "JOHN");
}

BOOST_AUTO_TEST_CASE (score) {

    GradeScore smithJohn50("SMITH", "JOHN", 50);

    // Verify basic functionality.
    BOOST_CHECK_EQUAL(smithJohn50.score(), 50);
}

BOOST_AUTO_TEST_SUITE_END ()
