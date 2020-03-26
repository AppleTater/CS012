#include <string>
#include <iostream>

#include "Wizard.h"
#include "Character.h"


using namespace std;

Wizard::Wizard(const string &name, double health, double attackStrength, int rank) : Character (WIZARD, name, health, attackStrength), rank(rank) {}
    
void Wizard::attack(Character &enemy) {
    double dmg = 0;
    if (enemy.getType() != WIZARD) {
        dmg = attackStrength;
        enemy.damage(dmg);
        
        cout << "Wizard " << name << " attacks " << enemy.getName() << " --- POOF!!" << endl;
        cout << enemy.getName() << " takes " << attackStrength << " damage." << endl;
    }
    else {
        Wizard &opp = dynamic_cast<Wizard &>(enemy);

        dmg = (attackStrength * rank) / opp.rank;
        opp.damage(dmg);
        cout << "Wizard " << name << " attacks " << opp.getName() << " --- POOF!!" << endl;
        cout << opp.getName() << " takes " << dmg << " damage." << endl;
    }
}
