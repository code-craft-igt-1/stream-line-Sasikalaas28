#include "./sendvitals.h"
#include "gtest/gtest.h"
#include <string>
#include <vector>
#include <sstream>

using std::string, std::vector, std::stringstream;

// Function to split a string by a delimiter
vector<string> split(const string &s, char delimiter) {
    vector<string> tokens;
    string token;
    stringstream ss(s);
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

bool isVitalsInformat() {
    string vitals = "";
    sendVitals(5, &vitals);
    vector<string> vitalValues = split(vitals, ',');
    vector<string> singleVital = split(vitalValues[0], ' ');
    if (singleVital.size() != 3) {
        return false;
    }
    return true;
}

TEST(Sender, CheckVitalsAreInformat) {
    ASSERT_TRUE(isVitalsInformat());
}
