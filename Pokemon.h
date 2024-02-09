#ifndef POKEMON_H
#define POKEMON_H



#include <string>



// Adding "std" Namespace For "cout", "floor", Etc.
using namespace std;



// Creating Typings
enum TYPES {
	None,
	Normal,
	Fire,
	Water,
	Grass,
	Electric,
	Ice,
	Fighting,
	Poison,
	Ground,
	Flying,
	Psychic,
	Bug,
	Rock,
	Ghost,
	Dragon,
	Dark,
	Steel,
	Fairy
};

// Conversion List For "TYPES" To String For Printing And Database Generation
constexpr const char* TYPES_STRINGS[] = {
	"None",
	"Normal",
	"Fire",
	"Water",
	"Grass",
	"Electric",
	"Ice",
	"Fighting",
	"Poison",
	"Ground",
	"Flying",
	"Psychic",
	"Bug",
	"Rock",
	"Ghost",
	"Dragon",
	"Dark",
	"Steel",
	"Fairy"
};

// Creating XP Typings
enum XPTYPE {
	Erratic,
	Fast,
	MediumFast,
	MediumSlow,
	Slow,
	Fluctuating
};

// Conversion List For "XPTYPE" To String For Printing And Database Generation
constexpr const char* XPTYPE_STRINGS[] = {
	"Erratic",
	"Fast",
	"MediumFast",
	"MediumSlow",
	"Slow",
	"Fluctuating"
};

// Creating Stat Identifiers
enum STAT {
	HP,
	ATK,
	DEF,
	SPATK,
	SPDEF,
	SPD
};

// Creating Nature Typings
enum NATURES {
	Hardy,
	Lonely,
	Adamant,
	Naughty,
	Brave,
	Bold,
	Docile,
	Impish,
	Lax,
	Relaxed,
	Modest,
	Mild,
	Bashful,
	Rash,
	Quiet,
	Calm,
	Gentle,
	Careful,
	Quirky,
	Sassy,
	Timid,
	Hasty,
	Jolly,
	Naive,
	Serious
};

// Conversion List For "NATURES" To String For Printing
constexpr const char* NATURES_STRINGS[] = {
	"Hardy",
	"Lonely",
	"Adamant",
	"Naughty",
	"Brave",
	"Bold",
	"Docile",
	"Impish",
	"Lax",
	"Relaxed",
	"Modest",
	"Mild",
	"Bashful",
	"Rash",
	"Quiet",
	"Calm",
	"Gentle",
	"Careful",
	"Quirky",
	"Sassy",
	"Timid",
	"Hasty",
	"Jolly",
	"Naive",
	"Serious"
};

// Class To Hold Stats Together
class Stats {
private:
	int hp;
	int atk;
	int def;
	int spAtk;
	int spDef;
	int spd;
public:
	Stats(int, int, int, int, int, int);
	int get_stat(STAT);
};

// Class To Hold Database Info For Creating Pokemon
class DatabaseInfo {
public:
	string name;
	XPTYPE xpType;
	TYPES type1;
	TYPES type2;
	Stats* baseStats;
	DatabaseInfo(string, XPTYPE, TYPES, TYPES, Stats*);
};

// Base Pokemon Class That Will Hold All Information About Any Generated Pokemon
class BasePokemon {
private:
	int speciesIndex;
	string name;
	int totalXP;
	int neededXP;
	XPTYPE xpType;
	int level;
	TYPES type1;
	TYPES type2;
	NATURES nature;
	Stats* baseStats;
	Stats* IVs;
	Stats* EVs;
	Stats* combinedStats;
	int currHP;
	void determineNeededXPFromLevel();
	void determineTotalXPFromLevel();
	void determineNature();
	void generateIVs();
	float getNatureModifier(STAT);
	void determineCombinedStats();
public:
	BasePokemon(int, int, DatabaseInfo*);
	BasePokemon(int, int, int, Stats*, Stats*, int, NATURES, DatabaseInfo*);
	inline string get_name() { return name; }
	inline int get_currHP() { return currHP; }
	inline int get_speciesIndex() { return speciesIndex; }
	inline int get_level() { return level; }
	inline int get_totalXP() { return totalXP; }
	inline NATURES get_nature() { return nature; }
	TYPES* get_types();
	int get_IV(STAT);
	int get_EV(STAT);
	int get_stat(STAT);
	void TakeDamage(int);
	void Heal(int);
	void print_stats();
};

// Pokemon Creation And Reading Functions
DatabaseInfo* ReadFromDatabase(int);
BasePokemon* CreateBasePokemonFromTable(int, int);
BasePokemon* CreateBasePokemonFromStats(int, int, int, Stats*, Stats*, int, NATURES);



#endif