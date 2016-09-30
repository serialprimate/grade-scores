/**
 * \file main.cpp
 * \copyright Copyright (C) 2016 Matt Davies - All Rights Reserved.
 *
 * Implementation of the grade library test module.
 */

#define STRIFY(x) # x
#define TOSTR(x) STRIFY (x)

#define BOOST_TEST_MODULE test-library-grade

#include <boost/test/unit_test.hpp>

#include <fstream>
#include <iostream>

namespace
{

/**
 * RAII handler for unit test log file output setup.
 */
struct LogFileFixture
{
    /**
     * Constructor.
     *
     * Open the unit test log file and set the unit test log to use it.
     */
    LogFileFixture()
    : m_testLogOutput ( TOSTR(BOOST_TEST_MODULE) ".log" )
    {
        boost::unit_test::unit_test_log.set_stream ( m_testLogOutput );
    }

    /**
     * Destructor.
     *
     * Reset the unit test log back to std output.
     */
    ~LogFileFixture()
    {
        boost::unit_test::unit_test_log.set_stream ( std::cout );
    }

    std::ofstream m_testLogOutput; /**< The output file stream. */
};

BOOST_GLOBAL_FIXTURE ( LogFileFixture );

} // Anonymous Namespace
