#include <string>
#include "Character.h"

using namespace std;

#ifndef _WARRIOR_H_
#define _WARRIOR_H_

class Warrior : public Character {
    private:
        string allegiance;
        
    public:
        void attack(Character &) override;
        Warrior (const string &name, double health, double attackStrength, string allegiance);
};

#endif
