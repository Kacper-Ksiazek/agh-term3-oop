#include "SchoolGirl.h"

SchoolGirl::SchoolGirl(string name, int age, string className, int average) noexcept: Pupil(name, age, className,
                                                                                            average) {
    this->m_ID = "F_12345" + this->m_ID;
}

void SchoolGirl::printOutfit() const {
    cout << "biala bluzka z krawatem, szkolna marynarka, granatowa/czarna spodniczka, plaskie obuwie";
}

