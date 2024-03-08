The classes ‘Archmage’, ‘DeathKnight’ and ‘DrawRanger’ represents your 3 heroes.

Each hero has the following attributes:

➢ name – the name of the character;

➢ maxMaxa – the character mana pool for casting spells. (If you don’t know what ‘mana’ is – think of it as
  a currency required to cast a spell).

➢ baseManaRegenRate – tell you how much mana points your character restores when an

ActionType::REGENERATE_MANA is performed. Keep in mind that your character can NOT have more mana points than his “maxMaxa”. Your character can restore mana points UP to his “maxMaxa”.

NOTE: The Archmage class has a special bonus attribute: “manaRegenModifier”, which scales up his mana
regeneration (multiplies baseManaRegenRate to manaRegenModifier) each time the character performs an
ActionType::REGENERATE_MANA.

Each character has his unique BASIC and ULTIMATE spells that are already predefined.
    struct Spell {
    std::string name; //name of the spell
    int manaCost; //mana requirement to cast this spell
  };

You are given the main() function, which first populates Archmange, DeathKnight, and DrawRanger classes constructors and then reads a single integer value of memory (N).
  - The next N whitespace separated integer are special ActionType commands;
    enum ActionType {
      CAST_BASIC_SPELL,
      CAST_ULTIMATE_SPELL,
      REGENERATE_MANA
    };

➢ “0” or ActionType::CAST_BASIC_SPELL command – all heroes should TRY to casts their BASIS spells (if they have enough mana points);

➢ “1” or ActionType::CAST_ ULTIMATE _SPELL command – all heroes should TRY to cast their ULTIMATE spells (if they have enough mana points);

➢ “2” or ActionType::REGENERATE_MANA command – all heroes should use their ability to regenerate mana;

Your task is to study the provided Skeleton and implement the missing functionalities for Archmage.cpp, DeathKnight.cpp and DrawRanger.cpp files with a few things in mind:

After each ActionType::CAST_BASIC_SPELL or ActionType::CAST_ULTIMATE_SPELL each hero should print to the console a result of his actions.

➢ For a successful cast you should print: ‘spell name’ casted for ‘spell mana’ followed by a newline.

➢ For unsuccessful cast you should print: ‘spell name’ – not enough mana to cast ‘spell name’ followed by a newline.

Note: ActionType::REGENERATE_MANA does NOT print any result to the console.

Special hero abilities:

➢ Archmage – if SpellType::ULTIMATE is successfully casted the Archmage gets immediately a free ActionType::REGENERATE_MANA.

➢ DeathKnight – if SpellType::ULTIMATE is successfully casted the DeathKnight gets immediately a free
   ActionType::CAST_BASIC_SPELL. Important note: on the free basic cast spell you should print to the
   console – ‘spell name’ casted for 0 mana.

➢ DrawRanger – if SpellType::BASIC is successfully casted the DrawRanger gets immediately a free
   ActionType::CAST_BASIC_SPELL. Important note: on the free basic cast spell you should print to the
   console – ‘spell name’ casted for 0 mana.

Your task is to study the code and implement the function so that the code accomplishes the task described.

You should submit a single .zip file for this task, containing ONLY the files you created.

The Judge system has a copy of the other files and will compile them, along with your file, in the same directory.

Restrictions:
All heroes at any time can have mana points from [0, individual ‘maxMana’] inclusively;

EXAMPLE:
INPUT:

Values 180 50 3

Are-not 220 80

Hardcoded 160 90

1 1

OUTPUT:

Values casted Mass Teleport for 180 mana

Are-not casted Animate Dead for 200 mana

Are-not casted Death Coil for 0 mana

Hardcoded casted Charm for 150 mana

Values - not enough mana to cast Mass Teleport

Are-not - not enough mana to cast Animate Dead

Hardcoded - not enough mana to cast Charm
