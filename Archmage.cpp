#include "Hero.h"
#include "Archmage.h"
#include "Structs.h"

#include <iostream>

Archmage::Archmage(const std::string& name, const int maxMana, const int baseManaRegenRate, const int manaRegenModifier_) :
    Hero(name, maxMana, baseManaRegenRate) {
    this->_manaRegenModifier = manaRegenModifier_;
}
void Archmage::castSpell(const SpellType spell) {

    // updated version
    if (_currMana < _spells[spell].manaCost) {
        std::cout << _name << " - not enough mana to cast " << _spells[spell].name << std::endl;
    }
    else {
        _currMana -= _spells[spell].manaCost;

        std::cout << _name << " casted " << _spells[spell].name << " for " << _spells[spell].manaCost << " mana" << std::endl;

        if (SpellType::ULTIMATE == spell) {
            regenerateMana();
        }
    }

    // not updated
    /*switch (spell) {
    case SpellType::BASIC:
        ActionType::CAST_BASIC_SPELL;
        if ((_currMana - _spells[0].manaCost) >= 0) {
            _currMana -= _spells[0].manaCost;
            std::cout << _name << " casted " << _spells[0].name << " for " << _spells[0].manaCost << " mana" << std::endl;
        }
        else {
            std::cout << _name << " - not enough mana to cast " << _spells[0].name << std::endl;
        }
        break;

    case SpellType::ULTIMATE:
        ActionType::CAST_ULTIMATE_SPELL;
        if ((_currMana - _spells[1].manaCost) >= 0) {
            _currMana -= _spells[1].manaCost;
            std::cout << _name << " casted " << _spells[1].name << " for " << _spells[1].manaCost << " mana" << std::endl;
            regenerateMana();
        }
        else {
            std::cout << _name << " - not enough mana to cast " << _spells[1].name << std::endl;
        }
        break;
    }*/
}

void Archmage::regenerateMana() {
    if (_manaRegenModifier == 0) {
        if ((_currMana + _manaRegenRate) <= _maxMana) {
            _currMana += _manaRegenRate;
        }
        else {
            _currMana = _maxMana;
        }
    }
    else {
        int effectiveManaRegenRate = _manaRegenRate * _manaRegenModifier;
        if ((_currMana + effectiveManaRegenRate) <= _maxMana) {
            _currMana += effectiveManaRegenRate;
        }
        else {
            _currMana = _maxMana;
        }
    }


}
//archMage 240 101 2
//knight 190 101
//asd 100 23
//1 1 2