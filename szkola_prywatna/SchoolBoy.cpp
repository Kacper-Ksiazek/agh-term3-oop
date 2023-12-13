#include "SchoolBoy.h"

SchoolBoy::SchoolBoy(string name, int age, string className, int average) noexcept: Pupil(name, age, className,
                                                                                          average) {
    this->m_ID = "M_00100" + this->m_ID;
}

void SchoolBoy::printOutfit() const {
   cout << "biala/niebieska koszula z krawatem, szkolna marynarka, polbuty, granatowa/czarna spodnie."
}
