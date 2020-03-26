#include <string>
#include "Character.h"

using namespace std;

#ifndef _ELF_H_
#define _ELF_H_

class Elf : public Character {
    private:
        string family;
        
    public:
        void attack(Character &) override;
        Elf (const string &name, double health, double attackStrength, string family);
};    

#endif
