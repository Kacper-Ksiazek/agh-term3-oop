#include "SchoolGirl.h"

SchoolGirl::SchoolGirl(const string name, int age, const string className) noexcept: Pupil(name, age, className
) {
    this->m_ID = "F_12345" + this->m_ID;
}

void SchoolGirl::printOutfit() {
    cout << "biala bluzka z krawatem, szkolna marynarka, granatowa/czarna spodniczka, plaskie obuwie";
}
