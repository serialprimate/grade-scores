/**
 * \file GradeScore.h
 * \copyright Copyright (C) 2016 Matt Davies - All Rights Reserved.
 *
 * Declaration of the GradeScore class.
 */

#ifndef GRADESCORE_H_
#define GRADESCORE_H_

#include <iosfwd>
#include <string>

/**
 * A class for grade score records.
 *
 * Grade score records are persisted in simple CSV streams.
 */
class GradeScore {

public:

    /**
     * Default constructor.
     */
	GradeScore();

	/**
	 * Constructor.
	 */
	GradeScore(std::string lastName, std::string firstName, unsigned score);

	/* Explicitly use compiler generated copy and move operations. */
	GradeScore( GradeScore const & ) = default;
	GradeScore & operator=( GradeScore const & ) = default;
	GradeScore( GradeScore && ) = default;
	GradeScore & operator=( GradeScore && ) = default;

	/**
	 * Restore a grade score record from CSV.
	 *
	 * \param input The input stream from which to read the CSV.
	 * \return True if the record was restored successfully. False otherwise.
	 */
	bool fromCSV(std::istream & input);

    /**
     * Persist a grade score record to CSV.
     *
     * \param output The output stream to write the CSV to.
     * \return True if the record was persisted successfully. False otherwise.
     */
	bool toCSV(std::ostream & output) const;

	/**
	 * Provide an ordering on GradeScore objects for sorting.
	 */
	bool operator<(GradeScore const & rhs) const;

	/**
	 * Get the last name associated with a grade score.
	 */
	std::string const & lastName() const &;

	/**
	 * Get the first name associated with a grade score.
	 */
	std::string const & firstName() const &;

	/**
	 * Get the score associated with a grade score.
	 */
	unsigned score() const;

private:

	std::string m_lastName;   /**< The last name of a graded person. */
	std::string m_firstName;  /**< The first name of a graded person. */
	unsigned m_score;         /**< The grade score. */
};

#endif /* GRADESCORE_H_ */
