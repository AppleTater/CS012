#include <string>
#include <iostream>

#include "Warrior.h"
#include "Character.h"


using namespace std;

Warrior::Warrior(const string &name, double health, double attackStrength, string allegiance) : 
                Character(WARRIOR, name, health, attackStrength), allegiance(allegiance) {}

void Warrior::attack(Character &enemy) {
    if (enemy.getType() == WARRIOR) {
        Warrior &opp = dynamic_cast<Warrior &>(enemy);
        
        if(opp.allegiance == allegiance) {
            cout << "Warrior " << name << " does not attack Warrior " << opp.getName() << "." << endl;
            cout << "They share an allegiance with " << allegiance  << "." << endl;
        }
        else {
            double dmg;
            dmg = (health / MAX_HEALTH) * attackStrength;
    
            enemy.damage(dmg);
            cout << "Warrior " << name << " attacks " << enemy.getName() << " --- SLASH!!" << endl;
            cout << enemy.getName() << " takes " << dmg << " damage." << endl;
        }
    }
    
    else {
        double dmg;
        dmg = (health / MAX_HEALTH) * attackStrength;
    
        enemy.damage(dmg);
        cout << "Warrior " << name << " attacks " << enemy.getName() << " --- SLASH!!" << endl;
        cout << enemy.getName() << " takes " << dmg << " damage." << endl;
    }
}
