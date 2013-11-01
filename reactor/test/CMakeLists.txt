cxx_test(SpeciesTest SpeciesTest.cpp reactor_library) #specify a new test, and which files it depends on
cxx_test(ReactionSystemTest ReactionSystemTest.cpp reactor_library)
cxx_test(ReactionTest ReactionTest.cpp reactor_library)
cxx_test(IntegrationTest IntegrationTest.cpp reactor_library)
cxx_test(ReactionSystemParserTest ReactionSystemParserTest.cpp reactor_library)