#include "./sendvitals.h"
#include <iostream>
#include <string>
#include <random>

using namespace std;

void sendVitals(int numOfVitals, string& vitals) {
    for(int itr = 0; itr < 50; itr++) {
        float vitalValue;
        vitalValue = randomNumberGenerator(0, 102);
        vitals += to_string(vitalValue);
        vitalValue = randomNumberGenerator(0, 100);
        vitals +=" " + to_string(vitalValue);
        vitalValue = randomNumberGenerator(0, 90);
        if(itr == numOfVitals - 1)
            vitals +=" " + to_string(vitalValue);
        else
            vitals +=" " + to_string(vitalValue) +  ",";
    }
    cout << "Vitals : " << vitals << endl;
}

float randomNumberGenerator(float min, float max) {
    // Initialize a random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(min, max);

    // Generate random number in the range [min, max]
    float randomValue = distrib(gen);
    return randomValue;
}
