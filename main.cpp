//
// Created by Jack McGowan on 3/15/21.
//
#include <iostream>
#include <vector>
#include "User.h"
#include "VectorOfThings.h"
#include <time.h>
#include <cmath>

void testingMetric(VectorOfThings<User> v, int numTrials, std::string who);

int main() {
    /* Setting the seed for rand() */
    srand(time(0));

    /* Changing the cout to display true/false rather than 1/0 */
    std::cout << std::boolalpha;

    /* Making a tracking object of the user class */
    User jimbo("Jimbo TEST", 9500001, true);
    //Making a vector of users
    vector<User> users = {jimbo};

    /* Building more users to be put in the vector */
    vector<std::string> firstNames = {"James", "Michael", "Robert", "Maria", "Mary", "Thomas", "Sarah", "Liza","Jane"};
    vector<std::string> lastNames = {"Smith", "Clark", "Miller", "Johnson", "Davis", "Taylor", "Williams", "Brown"};
    std::string fullName;
    int userCount = 1;
    for (int i = 0; i < firstNames.size(); i++) {
        for (int j = 0; j < lastNames.size(); j++) {
            fullName = firstNames[i] + " " + lastNames[j];
            User user(fullName, 9500000 + userCount + 1);
            userCount++;
            users.push_back(user);
        }
    }

    /* Creating custom vectors to be passed into our individual shuffle function objects using the intialize vector of users */
    vector<User> jcmcgowa_users = users;
    vector<User> asmith16_users = users;
    VectorOfThings jcmcgowa(jcmcgowa_users);
    VectorOfThings asmith16(asmith16_users);


    /* Running our testing metrics */
    testingMetric(jcmcgowa, 10000, "jcmcgowa");
    testingMetric(asmith16, 10000, "asmith16");
    return 0;
}

void testingMetric(VectorOfThings<User> v, int numTrials, std::string who) {
    vector<int> howMany;
    time_t begin,end;

    /* Initialize all the values in how many as zero */
    for (int i = 0; i < v.getItem().size(); i++) {
        howMany.push_back(0);
    }
    //Display the expected distribution
    std::cout << "Expected Distribution: " << (1.0 / v.getItem().size()) * numTrials << std::endl << std::endl;

    //Display whose method is being called using the who string
    std::cout << who << "'s shuffle method" << std::endl;

    //Begin a timer
    time (&begin);

    if (who == "jcmcgowa") {
        //Run the shuffle numTrials times
        for (int i = 0; i < numTrials; i++) {
            //Sort the vector
            v.sort();
            //Shuffle it
            v.jcmcgowa_shuffle();

            //Look for the tracking variable in each item of the vector
            for (int j = 0; j < v.getItem().size(); j++) {
                if (v.getItem()[j].getTracking()) {
                    howMany[j] += 1;
                }
            }

            //Loading bar to show something is happening in cout
            if (i % (numTrials / 20) == 0) std::cout << "***|";
        }
        //Add an empty line
        std::cout << std::endl;

        int positionMax = 0, positionMin = numTrials;
        double wholeAvg = 0.0;
        //Check for min and max, and add the values up into the total (wholeAvg)
        for (int i = 0; i < howMany.size(); i++) {
            if (howMany[i] > positionMax) positionMax = howMany[i];
            if (howMany[i] < positionMin) positionMin = howMany[i];
            wholeAvg += howMany[i];
        }

        //Divide by the number of items to get the average
        wholeAvg /= howMany.size();

        /* Calculate the standard deviation */
        double standardDev = 0;
        for (int i = 0; i < howMany.size(); i++) {
            standardDev += pow(howMany[i] - (wholeAvg),2);
        }
        standardDev = sqrt(standardDev / howMany.size());

        /* Output the results */
        std::cout << "Found Max Distrubtion per vector index: " << positionMax << std::endl;
        std::cout << "Found Min Distrubtion per vector index: " << positionMin << std::endl;
        std::cout << "Found Mean Distrubtion per vector index: " << wholeAvg << std::endl;
        std::cout << "Found Standard Deviation across vector index: " << standardDev << std::endl;
        std::cout <<"-----------------------------------------------------------------" << std::endl << std::endl;
        howMany.clear();
    }
    else if (who == "asmith16") {
        //Run the shuffle numTrials times
        for (int i = 0; i < numTrials; i++) {
            //Sort the vector
            v.sort();
            //Shuffle it
            v.asmith16_shuffle();

            //Look for the tracking variable in each item of the vector
            for (int j = 0; j < v.getItem().size(); j++) {
                if (v.getItem()[j].getTracking()) {
                    howMany[j] += 1;
                }
            }

            //Loading bar to show something is happening in cout
            if (i % (numTrials / 20) == 0) std::cout << "***|";
        }
        //Add an empty line
        std::cout << std::endl;

        int positionMax = 0, positionMin = numTrials;
        double wholeAvg = 0.0;
        //Check for min and max, and add the values up into the total (wholeAvg)
        for (int i = 0; i < howMany.size(); i++) {
            if (howMany[i] > positionMax) positionMax = howMany[i];
            if (howMany[i] < positionMin) positionMin = howMany[i];
            wholeAvg += howMany[i];
        }

        //Divide by the number of items to get the average
        wholeAvg /= howMany.size();

        /* Calculate the standard deviation */
        double standardDev = 0;
        for (int i = 0; i < howMany.size(); i++) {
            standardDev += pow(howMany[i] - (wholeAvg),2);
        }
        standardDev = sqrt(standardDev / howMany.size());

        /* Output the results */
        std::cout << "Found Max Distrubtion per vector index: " << positionMax << std::endl;
        std::cout << "Found Min Distrubtion per vector index: " << positionMin << std::endl;
        std::cout << "Found Mean Distrubtion per vector index: " << wholeAvg << std::endl;
        std::cout << "Found Standard Deviation across vector index: " << standardDev << std::endl;
        std::cout <<"-----------------------------------------------------------------" << std::endl << std::endl;
        howMany.clear();
    }
    else {
        std::cout << "Please enter a valid shuffle function NetID" << std::endl;
    }
    //End timer
    time(&end);
    double executionTime = difftime(end,begin);
    std::cout << "The function took { " << (executionTime > 0 ? std::to_string(executionTime) : "less than 1") << " } seconds to execute" << std::endl;
}