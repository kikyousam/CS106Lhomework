#include "class.h"

Country::Country() : name(""), population(0), hiddenMilitaryCapacity(0), economicStrength(0) {}

Country::Country(std::string name, int num):name(name), population(num), hiddenMilitaryCapacity(0), economicStrength(0){}

const int Country::getEconomicStrength() const
{
    return economicStrength;
}

const int Country::getHiddenMilitaryCapacity() const
{
    return hiddenMilitaryCapacity;
}

void Country::setEconomicStrength(int growth)
{
    economicStrength += growth;
}

bool Country::isBigCountry()
{
    return hiddenMilitaryCapacity > 10000 && economicStrength > 10000;
}
