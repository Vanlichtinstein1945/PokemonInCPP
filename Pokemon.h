#ifndef POKEMON_H
#define POKEMON_H



#include <iostream>



// Creating Typings
constexpr enum TYPES {
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
const std::string TYPES_STRINGS[] = {
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
constexpr enum XPTYPE {
	Erratic,
	Fast,
	MediumFast,
	MediumSlow,
	Slow,
	Fluctuating
};

// Conversion List For "XPTYPE" To String For Printing And Database Generation
const std::string XPTYPE_STRINGS[] = {
	"Erratic",
	"Fast",
	"MediumFast",
	"MediumSlow",
	"Slow",
	"Fluctuating"
};

// Creating Stat Identifiers
constexpr enum STAT {
	HP,
	ATK,
	DEF,
	SPATK,
	SPDEF,
	SPD
};

// Creating Nature Typings
constexpr enum NATURES {
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
const std::string NATURES_STRINGS[] = {
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
	const int hp;
	const int atk;
	const int def;
	const int spAtk;
	const int spDef;
	const int spd;

public:
	inline Stats(int hp, int atk, int def, int spAtk, int spDef, int spd)
		: hp{ hp }, atk{ atk }, def{ def }, spAtk{ spAtk }, spDef{ spDef }, spd{ spd } {}
	
	constexpr int get_stat(STAT) const;
};

// Class To Hold Database Info For Creating Pokemon
class DatabaseInfo {
public:
	const std::string name;
	const XPTYPE xpType;
	const TYPES type1;
	const TYPES type2;
	Stats* baseStats;
	
	inline DatabaseInfo(std::string name, XPTYPE xpType, TYPES type1, TYPES type2, Stats* baseStats)
		: name{ name }, xpType{ xpType }, type1{ type1 }, type2{ type2 }, baseStats{ baseStats } {}
	
	inline ~DatabaseInfo() { delete baseStats; }
};


// Base Pokemon Class That Will Hold All Information About Any Generated Pokemon
class BasePokemon {
private:
	const int speciesIndex;
	const std::string name;
	int totalXP;
	int neededXP;
	const XPTYPE xpType;
	int level;
	const TYPES type1;
	const TYPES type2;
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
	
	constexpr float getNatureModifier(STAT) const;
	
	void determineCombinedStats();

public:
	BasePokemon(int, int, DatabaseInfo*);
	
	BasePokemon(int, int, int, Stats*, Stats*, int, NATURES, DatabaseInfo*);
	
	inline ~BasePokemon() {
		delete baseStats;
		delete IVs;
		delete EVs;
		delete combinedStats;
	}
	
	inline std::string get_name() const { return name; }
	
	inline constexpr int get_currHP() const { return currHP; }
	
	inline constexpr int get_speciesIndex() const { return speciesIndex; }
	
	inline constexpr int get_level() const { return level; }
	
	inline constexpr int get_totalXP() const { return totalXP; }
	
	inline constexpr NATURES get_nature() const { return nature; }
	
	TYPES* get_types() const;
	
	int get_IV(STAT) const;
	
	int get_EV(STAT) const;
	
	int get_stat(STAT) const;
	
	void TakeDamage(int);
	
	void Heal(int);
	
	void print_stats() const;
};


// Pokemon Creation And Reading Functions
DatabaseInfo* ReadFromDatabase(int);

BasePokemon* CreateBasePokemonFromTable(int, int);

BasePokemon* CreateBasePokemonFromStats(int, int, int, Stats*, Stats*, int, NATURES);



#endif
