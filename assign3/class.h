#include <string>

class Country
{
    public:
        int population;
        std::string name;

        Country();
        Country(std::string name, int number);
        const int getEconomicStrength() const;
        const int getHiddenMilitaryCapacity() const;
        void setEconomicStrength(int growth);

    private:
        int hiddenMilitaryCapacity;
        int economicStrength;
        bool isBigCountry();
};