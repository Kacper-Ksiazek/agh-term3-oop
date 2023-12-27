#include "pch.h"
#include "testDll.h"

#include "CUtils.h"
#include <cstdlib>

unsigned short* Utils::readDateFromUser(const string& messageToUser, char separator, bool displayMessageAboutSeparator) {
    auto* result = (unsigned short*)calloc(3, sizeof(unsigned short));

    string userInput;
    string separatorMessage;

    if (displayMessageAboutSeparator) {
        separatorMessage = " ( znak '" + string(1, separator) + "' jako separator jest wymagany!)";
    }

    cout << messageToUser << separatorMessage << ": ";
    cin >> userInput;

    char currentChar;
    unsigned int positionInString = 0;
    unsigned int positionInArray = 0;

    while (userInput[positionInString]) {
        currentChar = userInput[positionInString++];

        if (currentChar == ' ') continue;
        else if (currentChar == separator) {
            positionInArray++;
            continue;
        }
        result[positionInArray] = result[positionInArray] * 10 + (currentChar - '0');
    }

    return result;
}