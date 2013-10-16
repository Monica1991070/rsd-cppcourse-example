#include "Reaction.h" // Include the code that we are testing
#include <gtest/gtest.h> // Include the google test framework

using namespace reactor;

class ReactionTest: public ::testing::Test {
protected:
	Reaction myReaction;
	Reaction emptyReaction;
	Species calcium;
	Species carbon;
	Species oxygen;
	Species calcium_carbonate;
	ReactionTest():
		myReaction(5.0), 
		emptyReaction(5.0),
		calcium("Ca"), 
		carbon("C"), 
		oxygen("O"), 
		calcium_carbonate("CaCO3")
	{
		calcium.SetConcentration(2.0);
		carbon.SetConcentration(3.0);
		oxygen.SetConcentration(5.0);
		calcium_carbonate.SetConcentration(7.0);
		myReaction.AddReactant(calcium);
		myReaction.AddReactant(carbon);
		myReaction.AddReactant(oxygen);
		myReaction.AddProduct(calcium_carbonate);
	};
};

TEST_F(ReactionTest, ReactionHasRate) { // First argument is test group, second is test name
  EXPECT_EQ(5.0, myReaction.GetRate()); // Assert that the reaction rate should be as expected
}

TEST_F(ReactionTest, ReactionCanHaveReactant) {
	emptyReaction.AddReactant(calcium);
	EXPECT_EQ(emptyReaction.GetReactants()[0].GetName(),"Ca");
}

TEST_F(ReactionTest, ReactionCanHaveMultipleReactants) {
	emptyReaction.AddReactant(calcium);
	emptyReaction.AddReactant(carbon);
	emptyReaction.AddReactant(oxygen);
	ASSERT_EQ(emptyReaction.GetReactants().size(),3);
	EXPECT_EQ(emptyReaction.GetReactants()[0].GetName(),"Ca");
}

TEST_F(ReactionTest, ReactionCanHaveProduct) {
	emptyReaction.AddProduct(calcium_carbonate);
	EXPECT_EQ(emptyReaction.GetProducts()[0].GetName(), "CaCO3");
}

TEST_F(ReactionTest, ReactionCanCalculateFlux) {
	EXPECT_EQ(5.0*2.0*3.0*5.0, myReaction.GetFlux());
}

int main(int argc, char **argv) { // A main function scaffold to call the tests
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}