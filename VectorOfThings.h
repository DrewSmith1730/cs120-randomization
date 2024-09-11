//
// Created by jackm on 3/15/2021.
//

#ifndef RANDOMIZATION_VECTOROFTHINGS_H
#define RANDOMIZATION_VECTOROFTHINGS_H

#include <time.h>

template<typename T>
class VectorOfThings {
protected:
    vector<T> item;
public:
    /* Constructors */
    explicit VectorOfThings(vector<T> item) {
        setItem(item);
    }

    /* Getters */
    vector<T> getItem() const {
        return item;
    }

    /* Setters */
    void setItem(vector<T> item) {
        this->item = item;
    }

    /* Print function */
    void printItem(std::ostream &outs) {
        for (int i = 0; i < item.size(); i++) {
            outs << item[i] << std::endl;
        }
    }

    /* Drew Smith Shuffle Function */
    vector<T> asmith16_shuffle() {
        // loop number of items in the vector selecting a random location every time
        for (int i = 0; i < 10000; i++){
            int swapIndex = rand() % item.size();
            // if the last item in the array it will swap with the first
            if (swapIndex == item.size()-1){
                T temp = item[0];
                item[0] = item[swapIndex];
                item[swapIndex] = temp;
            // swaps the adjacent indexes
            } else {
                T temp = item[swapIndex + 1];
                item[swapIndex + 1] = item[swapIndex];
                item[swapIndex] = temp;
            }
        }
        return item;
    }

    /* Jack McGowan Shuffle Function */
    bool jcmcgowa_shuffle() {
        /* Declaring variables */
        bool passed = false, empty = true;
        vector<T> temp = item;
        vector<int> placed;

        /* Loop to go through each item in the vector, and shuffle it */
        for (int i = 0; i < item.size(); i++) {
            int newIndex = rand() % item.size();
            //make sure the vector of used indexes has at least one entry
            if (!empty) {
                bool exists = false;
                //Check to make sure the generated index is not already used
                for (int j = 0; j < placed.size(); j++) {
                    if (placed[j] == newIndex) {
                        exists = true;
                    }
                }
                //Index is not empty, keep generating a new index until it is empty, add to vector of used indexes and then set the value in the original vector
                if (exists) {
                    while (exists) {
                        newIndex = rand() % item.size();
                        exists = false;
                        for (int j = 0; j < placed.size(); j++) {
                            if (placed[j] == newIndex) {
                                exists = true;
                            }
                        }
                    }
                    placed.push_back(newIndex);
                    item[newIndex] = temp[i];
                    passed = true;
                }
                //Index is empty, add to vector of used indexes and then set the value in the original vector
                else {
                    placed.push_back(newIndex);
                    item[newIndex] = temp[i];
                    passed = true;
                }
            }
            //Vector of used indexes is empty, so shuffle to any index.
            else {
                placed.push_back(newIndex);
                item[newIndex] = temp[i];
                passed = true;
                empty = false;
            }
        }
        return passed;
    }

    /* Find */
    T find(int idNum) const {
        int toReturn = 0;
        for (int i = 0; i < item.size(); i++) {
            if (idNum == item[i].getIdNum()) {
                toReturn = i;
            }
        }
        return item[toReturn];
    }

    T find(string name) {
        int toReturn = 0;
        for (int i = 0; i < item.size(); i++) {
            if (name == item[i].getName()) {
                toReturn = i;
            }
        }
        return item[toReturn];
    }

    /* Sort */
    void sort() {
        bool haveSwapped = true;
        int numPasses = 0, i;
        User temp;
        while (haveSwapped) {
            haveSwapped = false;
            for (i = 0; i + 1 < item.size() - numPasses; ++i) {
                if (item[i].getIdNum() > item[i + 1].getIdNum()) {
                    // The two elements are out of order. Swap them.
                    temp = item[i];
                    item[i] = item[i + 1];
                    item[i + 1] = temp;
                    // Update haveSwapped
                    haveSwapped = true;
                }
            }
            ++numPasses;
        }
    }

    /* Overloaded output operator */
    friend std::ostream& operator << (std::ostream& outs, const VectorOfThings &v) {
        for (int i = 0; i < (v.item).size(); i++) {
            outs << v.item[i] << std::endl;
        }
        return outs;
    }


};


#endif //RANDOMIZATION_VECTOROFTHINGS_H
