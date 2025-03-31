#include "Story.h"


// TODO: Default constructor
Story::Story() : description(""), eventNumber(0), leftEventNumber(-1), rightEventNumber(-1) {}

// TODO: Parameterized constructor
Story::Story(int eventNumber, string &description, int leftEventNumber, int rightEventNumber)
    : eventNumber(eventNumber), description(description), leftEventNumber(leftEventNumber), rightEventNumber(rightEventNumber) {}