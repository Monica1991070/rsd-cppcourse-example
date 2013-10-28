#include "Species.h" // Include the code that we are testing
#include <gtest/gtest.h> // Include the google test framework

using namespace reactor;


// Test that the system has a name as expected.
TEST(SpeciesTest, SpeciesHasAName) { // First argument is test group, second is test name
  Species mySpecies("SomeName"); // Create a species with a specified name
  EXPECT_EQ("SomeName", mySpecies.GetName()); // Assert that the name should be as expected
}

TEST(SpeciesTest, SpeciesHasADefaultConcentration) { // First argument is test group, second is test name
  Species mySpecies("SomeName"); // Create a species with a specified name
  EXPECT_EQ(0, mySpecies.GetConcentration()); // Assert that the name should be as expected
}

TEST(SpeciesTest, CanSetSpeciesConcentration) { // First argument is test group, second is test name
  Species mySpecies("SomeName"); // Create a species with a specified name
  EXPECT_EQ(0, mySpecies.GetConcentration()); // Assert that the name should be as expected
  mySpecies.SetConcentration(2.0);
  EXPECT_EQ(2.0, mySpecies.GetConcentration()); // Assert that the name should be as expected
}

TEST(SpeciesTest, SpeciesHasADefaultRateOfChange) { // First argument is test group, second is test name
  Species mySpecies("SomeName"); // Create a species with a specified name
  EXPECT_EQ(0, mySpecies.GetRateOfChange()); // Assert that the name should be as expected
}

TEST(SpeciesTest, CanContributeToSpeciesRateOfChange) { // First argument is test group, second is test name
  Species mySpecies("SomeName"); // Create a species with a specified name
  EXPECT_EQ(0, mySpecies.GetConcentration()); // Assert that the name should be as expected
  mySpecies.ContributeToRateOfChange(2.0);
  EXPECT_EQ(2.0, mySpecies.GetRateOfChange()); // Assert that the name should be as expected

  mySpecies.ContributeToRateOfChange(3.0);
  EXPECT_EQ(5.0, mySpecies.GetRateOfChange()); // Assert that the name should be as expected
}

TEST(SpeciesTest, CanResetRateOfChange) { // First argument is test group, second is test name
  Species mySpecies("SomeName"); // Create a species with a specified name
  EXPECT_EQ(0, mySpecies.GetConcentration()); // Assert that the name should be as expected
  mySpecies.ContributeToRateOfChange(2.0);
  EXPECT_EQ(2.0, mySpecies.GetRateOfChange()); // Assert that the name should be as expected
  mySpecies.ReSetRateOfChange();
  mySpecies.ContributeToRateOfChange(3.0);
  EXPECT_EQ(3.0, mySpecies.GetRateOfChange()); // Assert that the name should be as expected
}

int main(int argc, char **argv) { // A main function scaffold to call the tests
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
