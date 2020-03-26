#include <string>
#include "Character.h"

using namespace std;

#ifndef _WIZARD_H_
#define _WIZARD_H_

class Wizard : public Character {
    private:
        int rank;
        
    public:
        void attack(Character &) override;
        Wizard (const string &name, double health, double attackStrength, int rank);
};    

#endif
