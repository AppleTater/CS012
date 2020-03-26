#include <string>
#include <iostream>

#include "Elf.h"
#include "Character.h"


using namespace std;

Elf::Elf(const string &name, double health, double attackStrength, string family) : Character(ELF, name, health, attackStrength), family(family) {}

void Elf::attack(Character &enemy) {
    if (enemy.getType() == ELF) {
        Elf &opp = dynamic_cast<Elf &>(enemy);

        if(opp.family == family) {
            cout << "Elf " << name << " does not attack Elf " << opp.getName() << "." << endl;
            cout << "They are both members of the " << family << " family." << endl;
        }
        
        else {
            double dmg;
            dmg = (health / MAX_HEALTH) * (attackStrength);
    
            enemy.damage(dmg);
        
            cout << "Elf " << name << " shoots an arrow at " << enemy.getName() << " --- TWANG!!" << endl;
            cout << enemy.getName() <<  " takes " << dmg << " damage." << endl;
        }
    }
    
    else {
        double dmg;
        dmg = (health / MAX_HEALTH) * (attackStrength);
    
        enemy.damage(dmg);
    
        cout << "Elf " << name << " shoots an arrow at " << enemy.getName() << " --- TWANG!!" << endl;
        cout << enemy.getName() <<  " takes " << dmg << " damage." << endl;
    }
}
