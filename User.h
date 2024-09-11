//
// Created by Jack McGowan on 3/15/21.
//

#ifndef M2OEP_RANDOMIZATION_JCMCGOWA_ASMITH16_USER_H
#define M2OEP_RANDOMIZATION_JCMCGOWA_ASMITH16_USER_H

#include <string>
#include <vector>
#include <optional>
using std::ostream;
using std::string;
using std::vector;

class User {
private:
    string name;
    int idNum;
    bool hidden;
    bool tracking;
public:
    /* Constructor */
    User();
    explicit User(string name);
    explicit User(string name, int idNum);
    explicit User(string name, int idNum, bool tracking);

    /* Getters */
    string getName() const;
    int getIdNum() const;
    bool getTracking() const;

    /* Setters */
    void setName(string name);
    void setIdNum(int idNum);
    void setTracking(bool track);

    /* Makes the idNum either visible or not */
    bool makePrivate();
    bool makePublic();

    /* Overloaded output operator */
    friend ostream& operator << (ostream& outs, const User& u);
};

#endif //M2OEP_RANDOMIZATION_JCMCGOWA_ASMITH16_USER_H
