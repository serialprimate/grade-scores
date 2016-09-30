/**
 * \file GradeScore.cpp
 * \copyright Copyright (C) 2016 Matt Davies - All Rights Reserved.
 *
 * Implementation of the GradeScore class.
 */

#include "GradeScore.h"

#include <istream>
#include <ostream>
#include <sstream>

GradeScore::GradeScore()
: GradeScore("", "", 0)
{}

GradeScore::GradeScore(std::string lastName, std::string firstName, unsigned score)
: m_lastName(std::move(lastName)),
  m_firstName(std::move(firstName)),
  m_score(score)
{}

bool GradeScore::fromCSV(std::istream & input)
{
	std::string record;

	// Read the record from input.
	bool readOK = std::getline(input, record).good();

	if (readOK) {

		std::istringstream recordStream(record); // Stream to parse fields from.

		std::string lastNameField;  // The last name field.
		std::string firstNameField; // The first name field.
		std::string scoreField;     // The score field.

		unsigned score = 0;         // The score converted to an integer.

		// Input the string fields.
		readOK = std::getline(recordStream, lastNameField, ',') &&
				 std::getline(recordStream, firstNameField, ',') &&
				 std::getline(recordStream, scoreField);

		if (readOK) {

			try {

				// Convert score to an integer.
				score = std::stoi(scoreField); // May throw.

				// Everything is OK. Apply update atomically.
				m_lastName = std::move(lastNameField);
				m_firstName = std::move(firstNameField);
				m_score = score;

			} catch (...) {

				readOK = false;
			}
		}
	}

	return readOK;
}

bool GradeScore::toCSV(std::ostream & output) const
{
	output << m_lastName << ',' << m_firstName << ',' << m_score << '\n';

	return output.good();
}

bool GradeScore::operator<(GradeScore const & rhs) const
{
	return this != &rhs &&
	        (m_score > rhs.m_score ||
			(m_score == rhs.m_score && m_lastName < rhs.m_lastName) ||
			(m_score == rhs.m_score && m_lastName == rhs.m_lastName && m_firstName < rhs.m_firstName));
}

std::string const & GradeScore::lastName() const &
{
    return m_lastName;
}

std::string const & GradeScore::firstName() const &
{
    return m_firstName;
}

unsigned GradeScore::score() const
{
    return m_score;
}
