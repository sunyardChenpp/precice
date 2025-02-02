#ifndef PRECICE_NO_MPI

#include "../helper.hpp"
#include "testing/Testing.hpp"

#include <precice/precice.hpp>
#include <vector>

BOOST_AUTO_TEST_SUITE(Integration)
BOOST_AUTO_TEST_SUITE(Serial)
BOOST_AUTO_TEST_SUITE(MapIfNecessary)
BOOST_AUTO_TEST_SUITE(TwoSolvers)
BOOST_AUTO_TEST_SUITE(MixedSubsteps)

PRECICE_TEST_SETUP("One"_on(1_rank), "Two"_on(1_rank))
BOOST_AUTO_TEST_CASE(ParallelImplicit)
{
  PRECICE_TEST();

  std::vector<int> readMappings{1, 1, 1, 1, 1, 1};
  std::vector<int> writeMappings{2, 2, 2, 2, 2, 2};

  runTwoSolversMappingCountImplicit(context, readMappings, writeMappings);
}

BOOST_AUTO_TEST_SUITE_END() // MixedSubsteps
BOOST_AUTO_TEST_SUITE_END() // TwoSolvers
BOOST_AUTO_TEST_SUITE_END() // MapIfNecessary
BOOST_AUTO_TEST_SUITE_END() // Serial
BOOST_AUTO_TEST_SUITE_END() // Integration

#endif // PRECICE_NO_MPI
