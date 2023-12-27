#pragma once

#include "iostream"

using namespace std;

class TESTDLL_API Utils {
public:
    static unsigned short *
    readDateFromUser(const string &messageToUser, char separator, bool displayMessageAboutSeparator = false);
};