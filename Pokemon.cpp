/*
* 
* 
*	Brenan Patrick
*	Pokemon.cpp
* 
* 
*/
// Inclusions
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Pokemon.h"



// Adding Namespace For "cout", "floor", Etc.
using namespace std;



// Basic Stats Getter
constexpr int Stats::get_stat(STAT stat) const {
	switch (stat) {
	case HP:
		return hp;
	case ATK:
		return atk;
	case DEF:
		return def;
	case SPATK:
		return spAtk;
	case SPDEF:
		return spDef;
	case SPD:
		return spd;
	}
}

// Determine How Much XP Is Needed To Level Up
void BasePokemon::determineNeededXPFromLevel() {
	if (level == 100) { neededXP = 0; }
	else {
		switch (xpType) {
		case Erratic:
			if (level < 50) {
				neededXP = ((level + 1 * level + 1 * level + 1) * (100 - level + 1)) / 50;
			}
			else if (level < 68) {
				neededXP = ((level + 1 * level + 1 * level + 1) * (150 - level + 1)) / 100;
			}
			else if (level < 98) {
				neededXP = ((level + 1 * level + 1 * level + 1) * floor((1911 - 10 * level + 1) / 3)) / 500;
			}
			else {
				neededXP = ((level + 1 * level + 1 * level + 1) * (160 - level + 1)) / 100;
			}
			break;
		case Fast:
			neededXP = (4 * (level + 1 * level + 1 * level + 1)) / 5;
			break;
		case MediumFast:
			neededXP = (level + 1 * level + 1 * level + 1);
			break;
		case MediumSlow:
			neededXP = ((6 / 5) * (level + 1 * level + 1 * level + 1)) - (15 * (level + 1 * level + 1)) + (100 * level + 1) - 140;
			break;
		case Slow:
			neededXP = (5 * (level + 1 * level + 1 * level + 1)) / 4;
			break;
		case Fluctuating:
			if (level < 15) {
				neededXP = ((level + 1 * level + 1 * level + 1) * (floor((level + 1 + 1) / 3) + 24)) / 50;
			}
			else if (level < 36) {
				neededXP = ((level + 1 * level + 1 * level + 1) * (level + 1 + 14)) / 50;
			}
			else {
				neededXP = ((level + 1 * level + 1 * level + 1) * (floor(level + 1 / 2) + 32)) / 50;
			}
			break;
		}
	}
}

// Determine How Much XP A Generated Pokemon Has, Based On Their Level
void BasePokemon::determineTotalXPFromLevel() {
	if (level == 1) { totalXP = 0; }
	else {
		switch (xpType) {
		case Erratic:
			if (level < 50) {
				totalXP = ((level * level * level) * (100 - level)) / 50;
			}
			else if (level < 68) {
				totalXP = ((level * level * level) * (150 - level)) / 100;
			}
			else if (level < 98) {
				totalXP = ((level * level * level) * floor((1911 - 10 * level) / 3)) / 500;
			}
			else {
				totalXP = ((level * level * level) * (160 - level)) / 100;
			}
			break;
		case Fast:
			totalXP = (4 * (level * level * level)) / 5;
			break;
		case MediumFast:
			totalXP = (level * level * level);
			break;
		case MediumSlow:
			totalXP = (int)((1.2f * (level * level * level)) - (15 * (level * level)) + (100 * level) - 140);
			break;
		case Slow:
			totalXP = (5 * (level * level * level)) / 4;
			break;
		case Fluctuating:
			if (level < 15) {
				totalXP = ((level * level * level) * (floor((level + 1) / 3) + 24)) / 50;
			}
			else if (level < 36) {
				totalXP = ((level * level * level) * (level + 14)) / 50;
			}
			else {
				totalXP = ((level * level * level) * (floor(level / 2) + 32)) / 50;
			}
			break;
		}
	}
}

// Random Nature From Nature Typings
void BasePokemon::determineNature() {
	nature = (NATURES)(rand() % 26);
}

// Random IVs From 0 - 31
void BasePokemon::generateIVs() {
	IVs = new Stats(rand() % 32, rand() % 32, rand() % 32, rand() % 32, rand() % 32, rand() % 32);
}

// Getting Stat Modifier From Current Nature
constexpr float BasePokemon::getNatureModifier(STAT stat) const {
	float modifier = 1;
	switch (stat) {
	case ATK:
		if (nature == Lonely || nature == Adamant || nature == Naughty || nature == Brave) {
			modifier = 1.1f;
		}
		else if (nature == Bold || nature == Modest || nature == Calm || nature == Timid) {
			modifier = 0.9f;
		}
		break;
	case DEF:
		if (nature == Bold || nature == Impish || nature == Lax || nature == Relaxed) {
			modifier = 1.1f;
		}
		else if (nature == Lonely || nature == Mild || nature == Gentle || nature == Hasty) {
			modifier = 0.9f;
		}
		break;
	case SPATK:
		if (nature == Modest || nature == Mild || nature == Rash || nature == Quiet) {
			modifier = 1.1f;
		}
		else if (nature == Adamant || nature == Impish || nature == Careful || nature == Jolly) {
			modifier = 0.9f;
		}
		break;
	case SPDEF:
		if (nature == Calm || nature == Gentle || nature == Careful || nature == Sassy) {
			modifier = 1.1f;
		}
		else if (nature == Naughty || nature == Lax || nature == Rash || nature == Naive) {
			modifier = 0.9f;
		}
		break;
	case SPD:
		if (nature == Timid || nature == Hasty || nature == Jolly || nature == Naive) {
			modifier = 1.1f;
		}
		else if (nature == Brave || nature == Relaxed || nature == Quiet || nature == Sassy) {
			modifier = 0.9f;
		}
		break;
	}
	return modifier;
}

// Determining Overall Stats From Base, IVs, And EVs Stats, Level, And Nature Modifier
void BasePokemon::determineCombinedStats() {
	combinedStats = new Stats(
		floor(0.01 * (2 * baseStats->get_stat(HP) + IVs->get_stat(HP) + floor(0.25 * EVs->get_stat(HP))) * level) + level + 10,
		(floor(0.01 * (2 * baseStats->get_stat(ATK) + IVs->get_stat(ATK) + floor(0.25 * EVs->get_stat(ATK))) * level) + 5) * getNatureModifier(ATK),
		(floor(0.01 * (2 * baseStats->get_stat(DEF) + IVs->get_stat(DEF) + floor(0.25 * EVs->get_stat(DEF))) * level) + 5) * getNatureModifier(DEF),
		(floor(0.01 * (2 * baseStats->get_stat(SPATK) + IVs->get_stat(SPATK) + floor(0.25 * EVs->get_stat(SPATK))) * level) + 5) * getNatureModifier(SPATK),
		(floor(0.01 * (2 * baseStats->get_stat(SPDEF) + IVs->get_stat(SPDEF) + floor(0.25 * EVs->get_stat(SPDEF))) * level) + 5) * getNatureModifier(SPDEF),
		(floor(0.01 * (2 * baseStats->get_stat(SPD) + IVs->get_stat(SPD) + floor(0.25 * EVs->get_stat(SPD))) * level) + 5) * getNatureModifier(SPD));
}

// BasePokemon Constructor From Table
BasePokemon::BasePokemon(int speciesIndex, int level, DatabaseInfo* databaseInfo)
	: speciesIndex{speciesIndex}, name{databaseInfo->name}, level{level}, xpType{databaseInfo->xpType},
	  type1{databaseInfo->type1}, type2{databaseInfo->type2}, baseStats{databaseInfo->baseStats}
	{
	determineTotalXPFromLevel();
	determineNeededXPFromLevel();
	determineNature();
	generateIVs();
	EVs = new Stats(0, 0, 0, 0, 0, 0);
	determineCombinedStats();
	currHP = combinedStats->get_stat(HP);
}

// BasePokemon Constructor From Table And Given Stats
BasePokemon::BasePokemon(int speciesIndex, int level, int totalXP, Stats* IVs, Stats* EVs, int currHP, NATURES nature, DatabaseInfo* databaseInfo)
	: speciesIndex{speciesIndex}, name{databaseInfo->name}, level{level}, xpType{databaseInfo->xpType},
	totalXP{ totalXP }, type1{databaseInfo->type1}, type2{databaseInfo->type2}, nature{nature},
	baseStats{databaseInfo->baseStats}, IVs{IVs}, EVs{EVs}, currHP{currHP}
	{
	determineNeededXPFromLevel();
	determineCombinedStats();
	delete databaseInfo;
}

// Function To Return The Typings
TYPES* BasePokemon::get_types() const { static TYPES tempTypes[2]; tempTypes[0] = type1; tempTypes[1] = type2; return tempTypes; }

// Function To Get IVs
int BasePokemon::get_IV(STAT stat) const {
	switch (stat) {
	case HP:    return IVs->get_stat(HP);
	case ATK:   return IVs->get_stat(ATK);
	case DEF:   return IVs->get_stat(DEF);
	case SPATK: return IVs->get_stat(SPATK);
	case SPDEF: return IVs->get_stat(SPDEF);
	default:   return IVs->get_stat(SPD);
	}
}

// Function To Get EVs
int BasePokemon::get_EV(STAT stat) const {
	switch (stat) {
	case HP:    return EVs->get_stat(HP);
	case ATK:   return EVs->get_stat(ATK);
	case DEF:   return EVs->get_stat(DEF);
	case SPATK: return EVs->get_stat(SPATK);
	case SPDEF: return EVs->get_stat(SPDEF);
	default:   return EVs->get_stat(SPD);
	}
}

// Function To Get Combined Stats
int BasePokemon::get_stat(STAT stat) const {
	switch (stat) {
	case HP:    return combinedStats->get_stat(HP);
	case ATK:   return combinedStats->get_stat(ATK);
	case DEF:   return combinedStats->get_stat(DEF);
	case SPATK: return combinedStats->get_stat(SPATK);
	case SPDEF: return combinedStats->get_stat(SPDEF);
	default:   return combinedStats->get_stat(SPD);
	}
}

// Set Current HP To "0" or "currHP-damage", Whichever Is Larger, To Prevent Negative Health
void BasePokemon::TakeDamage(int damage) {
	currHP = max(0, currHP - damage);
}

// Set Current HP To Max HP or "currHP+amount", Whichever Is Smaller, To Prevent More Than Full HP
void BasePokemon::Heal(int amount) {
	currHP = min(combinedStats->get_stat(HP), currHP + amount);
}

// Printing The Generated Pokemon's Stats To The Console
void BasePokemon::print_stats() const{
	cout << "--- Pokemon Stats ---\n";
	cout << name << "\n";
	cout << "Type 1: " << TYPES_STRINGS[(int)type1] << "\n";
	cout << "Type 2: " << TYPES_STRINGS[(int)type2] << "\n";
	cout << "Total XP: " << totalXP << "\n";
	cout << "XP Type:  " << XPTYPE_STRINGS[xpType] << "\n";
	cout << "Level:    " << level << "\n";
	cout << "XP To Level Up: " << neededXP << "\n";
	cout << "HP Left: " << currHP << "\n";
	cout << "Nature:   " << NATURES_STRINGS[nature] << "\n";
	cout << "--  Overrall Stats --\n";
	cout << "HP:       " << combinedStats->get_stat(HP) << "\n";
	cout << "ATK:      " << combinedStats->get_stat(ATK) << "\n";
	cout << "DEF:      " << combinedStats->get_stat(DEF) << "\n";
	cout << "SPATK:    " << combinedStats->get_stat(SPATK) << "\n";
	cout << "SPDEF:    " << combinedStats->get_stat(SPDEF) << "\n";
	cout << "SPD:      " << combinedStats->get_stat(SPD) << "\n";
	cout << "------ Base -------\n";
	cout << "HP:       " << baseStats->get_stat(HP) << "\n";
	cout << "ATK:      " << baseStats->get_stat(ATK) << "\n";
	cout << "DEF:      " << baseStats->get_stat(DEF) << "\n";
	cout << "SPATK:    " << baseStats->get_stat(SPATK) << "\n";
	cout << "SPDEF:    " << baseStats->get_stat(SPDEF) << "\n";
	cout << "SPD:      " << baseStats->get_stat(SPD) << "\n";
	cout << "------- IVs -------\n";
	cout << "HP:       " << IVs->get_stat(HP) << "\n";
	cout << "ATK:      " << IVs->get_stat(ATK) << "\n";
	cout << "DEF:      " << IVs->get_stat(DEF) << "\n";
	cout << "SPATK:    " << IVs->get_stat(SPATK) << "\n";
	cout << "SPDEF:    " << IVs->get_stat(SPDEF) << "\n";
	cout << "SPD:      " << IVs->get_stat(SPD) << "\n";
	cout << "------- EVs -------\n";
	cout << "HP:       " << EVs->get_stat(HP) << "\n";
	cout << "ATK:      " << EVs->get_stat(ATK) << "\n";
	cout << "DEF:      " << EVs->get_stat(DEF) << "\n";
	cout << "SPATK:    " << EVs->get_stat(SPATK) << "\n";
	cout << "SPDEF:    " << EVs->get_stat(SPDEF) << "\n";
	cout << "SPD:      " << EVs->get_stat(SPD) << "\n";
	cout << "\n";
}

// Function To Read Variables From Pokemon Database
DatabaseInfo* ReadFromDatabase(int pokemonIndex) {
	// Generating Variables For Pokemon Creation
	string name = "";
	XPTYPE xpType = Erratic;
	TYPES type1 = None;
	TYPES type2 = None;
	int hp = 0;
	int atk = 0;
	int def = 0;
	int spAtk = 0;
	int spDef = 0;
	int spd = 0;

	// Reading File For Specific Pokemon's Stats
	// Based On Given Index Number
	fstream database;
	database.open("pokemonData.csv", ios::in);
	string temp;
	while (getline(database, temp, ',')) {
		stringstream as;
		as.str(temp);
		int tempIndex;
		as >> tempIndex;
		if (tempIndex == pokemonIndex) {
			getline(database, name, ',');
			getline(database, temp, ',');
			xpType = (XPTYPE)distance(XPTYPE_STRINGS, find(XPTYPE_STRINGS, XPTYPE_STRINGS + sizeof XPTYPE_STRINGS, temp));
			getline(database, temp, ',');
			type1 = (TYPES)distance(TYPES_STRINGS, find(TYPES_STRINGS, TYPES_STRINGS + sizeof TYPES_STRINGS, temp));
			getline(database, temp, ',');
			type2 = (TYPES)distance(TYPES_STRINGS, find(TYPES_STRINGS, TYPES_STRINGS + sizeof TYPES_STRINGS, temp));
			getline(database, temp, ',');
			hp = stoi(temp);
			getline(database, temp, ',');
			atk = stoi(temp);
			getline(database, temp, ',');
			def = stoi(temp);
			getline(database, temp, ',');
			spAtk = stoi(temp);
			getline(database, temp, ',');
			spDef = stoi(temp);
			getline(database, temp);
			spd = stoi(temp);
			break;
		}
		else {
			getline(database, temp, ',');
			getline(database, temp, ',');
			getline(database, temp, ',');
			getline(database, temp, ',');
			getline(database, temp, ',');
			getline(database, temp, ',');
			getline(database, temp, ',');
			getline(database, temp, ',');
			getline(database, temp, ',');
			getline(database, temp);
		}
		if (database.eof()) { break; }
	}

	database.close();
	return new DatabaseInfo(name, xpType, type1, type2, new Stats(hp, atk, def, spAtk, spDef, spd));
}

// Lookup Pokemon Stats Based On Given Index, And Generate New Pokemon At Given Level
BasePokemon* CreateBasePokemonFromTable(int pokemonIndex, int level) {
	// Creating And Returning A Pointer To The New Pokemon
	return new BasePokemon(pokemonIndex, level, ReadFromDatabase(pokemonIndex));
}

// Lookup Pokemon Stats Based On Given Index, And Generate New Pokemon With Given Stats
BasePokemon* CreateBasePokemonFromStats(int pokemonIndex, int level, int totalXP, Stats* IVs, Stats* EVs, int currHP, NATURES nature) {
	// Creating And Returning A Pointer To The New Pokemon
	return new BasePokemon(pokemonIndex, level, totalXP, IVs, EVs, currHP, nature, ReadFromDatabase(pokemonIndex));
}
