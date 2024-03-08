#include "Hero.h"
#include "DrawRanger.h"
#include "Structs.h"

#include <iostream>

DrawRanger::DrawRanger(const std::string& name, const int maxMana, const int baseManaRegenRate) :
    Hero(name, maxMana, baseManaRegenRate) {}

void DrawRanger::castSpell(const SpellType spell) {

    // updated version
    if (_currMana < _spells[spell].manaCost) {
        std::cout << _name << " - not enough mana to cast " << _spells[spell].name << std::endl;
    }
    else {
        _currMana -= _spells[spell].manaCost;

        std::cout << _name << " casted " << _spells[spell].name << " for " << _spells[spell].manaCost << " mana" << std::endl;

        if (SpellType::BASIC == spell) {
            std::cout << _name << " casted " << _spells[BASIC].name << " for 0 mana" <<  std::endl;
        }
    }

    // not updated
    //switch (spell) {
    //case SpellType::BASIC:
    //    ActionType::CAST_BASIC_SPELL;
    //    if ((_currMana - _spells[0].manaCost) >= 0) {
    //        _currMana -= _spells[0].manaCost;
    //        std::cout << _name << " casted " << _spells[0].name << " for " << _spells[0].manaCost << " mana" << std::endl;
    //        std::cout << _name << " casted " << _spells[0].name << " for 0 mana" << std::endl;
    //    }
    //    else {
    //        std::cout << _name << " - not enough mana to cast " << _spells[0].name << std::endl;
    //    }
    //    break;
    //case SpellType::ULTIMATE:
    //    ActionType::CAST_ULTIMATE_SPELL;
    //    if ((_currMana - _spells[1].manaCost) >= 0) {
    //        _currMana -= _spells[1].manaCost;
    //        std::cout << _name << " casted " << _spells[1].name << " for " << _spells[1].manaCost << " mana" << std::endl;
    //    }
    //    else {
    //        std::cout << _name << " - not enough mana to cast " << _spells[1].name << std::endl;
    //    }
    //    break;
    //}
}

void DrawRanger::regenerateMana() {
    _currMana += _manaRegenRate;

    if (_currMana > _maxMana) {
        _currMana = _maxMana;
    }
}
