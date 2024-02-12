/*
*
*
*	Brenan Patrick
*	PC.cpp
*
*
*/
// Inclusions
#include "PC.h"
#include "Pokemon.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>



// Adding Namespace For "cout", "floor", Etc.
using namespace std;



// PC Deconstructor
PC::~PC() {
	for (auto i : pokemon)
		delete i;
	pokemon.clear();
}

// Grabbing The Pokemon At "index" From PC For Printing And Data Checking Purposes
BasePokemon* PC::GetPokemonAtIndex(int index) const {
	return pokemon[index];
}

// Deposit A Given Pokemon Into The Last Position In The PC
void PC::DepositPokemonLast(BasePokemon* poke) {
	pokemon.push_back(poke);
}

// Remove Pokemon At Given Index From The PC And Return It
BasePokemon* PC::RemovePokemonSpecific(int index) {
	BasePokemon* temp = pokemon[index];
	pokemon.erase(pokemon.begin() + index);
	return temp;
}

// Swap PC Pokemon At Any Two Indexes
void PC::SwapPokemon(int index1, int index2) {
	BasePokemon* temp = pokemon[index1];
	pokemon[index1] = pokemon[index2];
	pokemon[index2] = temp;
	temp = nullptr;
}

// Printing All Pokemon's Names That Are Currently In The PC, And Their Index
void PC::printPC() const {
	cout << "------- PC --------\n";
	int index = 0;
	for (BasePokemon* i : pokemon) {
		cout << index << ": " << i->get_name() << "\n";
		index++;
	}
	cout << "\n";
}

// Function For Saving Pokemon Store In PC To A ".csv" File
void PC::savePC() const {
	// Remove Old Saved PC Data If It Exists.
	// Prevents Corrupt Or Cheated Data
	remove("PCData.csv");
	ofstream pcData("PCData.csv");
	for (BasePokemon* i : pokemon) {
		pcData << i->get_speciesIndex() << ","
			<< i->get_level() << ","
			<< i->get_totalXP() << ","
			<< i->get_IV(HP) << ","
			<< i->get_IV(ATK) << ","
			<< i->get_IV(DEF) << ","
			<< i->get_IV(SPATK) << ","
			<< i->get_IV(SPDEF) << ","
			<< i->get_IV(SPD) << ","
			<< i->get_EV(HP) << ","
			<< i->get_EV(ATK) << ","
			<< i->get_EV(DEF) << ","
			<< i->get_EV(SPATK) << ","
			<< i->get_EV(SPDEF) << ","
			<< i->get_EV(SPD) << ","
			<< i->get_currHP() << ","
			<< i->get_nature() << "\n";
	}
	pcData.close();
}

// Function For Loading Saved PC Pokemon From A ".csv" File
void PC::loadPC() {
	// Clear Current PC Since Loading Will Be Destructive
	pokemon.clear();
	fstream pcData;
	pcData.open("PCData.csv", ios::in);
	string temp;
	while (getline(pcData, temp, ',')) {
		int index = stoi(temp);
		getline(pcData, temp, ',');
		int level = stoi(temp);
		getline(pcData, temp, ',');
		int totalXP = stoi(temp);
		getline(pcData, temp, ',');
		int IVHP = stoi(temp);
		getline(pcData, temp, ',');
		int IVAttack = stoi(temp);
		getline(pcData, temp, ',');
		int IVDefense = stoi(temp);
		getline(pcData, temp, ',');
		int IVSpAttack = stoi(temp);
		getline(pcData, temp, ',');
		int IVSpDefense = stoi(temp);
		getline(pcData, temp, ',');
		int IVSpeed = stoi(temp);
		getline(pcData, temp, ',');
		int EVHP = stoi(temp);
		getline(pcData, temp, ',');
		int EVAttack = stoi(temp);
		getline(pcData, temp, ',');
		int EVDefense = stoi(temp);
		getline(pcData, temp, ',');
		int EVSpAttack = stoi(temp);
		getline(pcData, temp, ',');
		int EVSpDefense = stoi(temp);
		getline(pcData, temp, ',');
		int EVSpeed = stoi(temp);
		getline(pcData, temp, ',');
		int currHP = stoi(temp);
		getline(pcData, temp);
		NATURES nature = (NATURES)stoi(temp);
		BasePokemon* tempPoke = CreateBasePokemonFromStats(index, level, totalXP, new Stats(IVHP, IVAttack, IVDefense, IVSpAttack, IVSpDefense, IVSpeed), new Stats(EVHP, EVAttack, EVDefense, EVSpAttack, EVSpDefense, EVSpeed), currHP, nature);
		// Push New Pokemon To The End Of The Vector (Keeps Same PC Order From When It Was Saved)
		pokemon.push_back(tempPoke);
		tempPoke = nullptr;
		if (pcData.eof()) { break; }
	}
	pcData.close();
}
