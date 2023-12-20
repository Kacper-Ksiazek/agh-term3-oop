#include "SchoolBoy.h"

SchoolBoy::SchoolBoy(const string name, int age, const string className) noexcept: Pupil(name, age, className
) {
    this->m_ID = "M_00100" + this->m_ID;
}

void SchoolBoy::printOutfit() {
    cout << "biala/niebieska koszula z krawatem, szkolna marynarka, polbuty, granatowa/czarna spodnie.";

}

