/*
*
*
*	Brenan Patrick
*	Party.cpp
*
*
*/
// Inclusions
#include "Party.h"
#include "Pokemon.h"
#include <iostream>
#include <vector>



// Adding Namespace For "cout", "floor", Etc.
using namespace std;



// Constructor That Sets All Party Slots To NULL
Party::Party() { for (int i = 0; i < 7; i++) { slots.push_back(nullptr); } }

// Destructor
Party::~Party() {
	for (auto i : slots)
		delete i;
	slots.clear();
}

// Returns The Pokemon In Slot "index"
BasePokemon* Party::GetSlot(int index) {
	return slots[index];
}

// Sets Slot "index" To The Given Pokemon
void Party::InsertPokemon(int index, BasePokemon* pokemon) {
	slots[index] = pokemon;
}

// Sets Slot "index" To NULL And Returns The Pokemon That Was There
BasePokemon* Party::RemovePokemon(int index) {
	BasePokemon* temp = slots[index];
	slots[index] = nullptr;
	return temp;
}

// Swaps The Pokemon In Any Two Slots
void Party::SwapSlots(int index1, int index2) {
	BasePokemon* temp = slots[index1];
	slots[index1] = slots[index2];
	slots[index2] = temp;
	temp = nullptr;
}

// Prints The Names Of Each Party Member
// Prints "EMPTY" If The Slot Has No Member
void Party::PrintParty() {
	if (slots[0] != nullptr) { cout << "Slot1: " << slots[0]->get_name() << "\n"; }
	else { cout << "Slot1: EMPTY\n"; }
	if (slots[1] != nullptr) { cout << "Slot2: " << slots[1]->get_name() << "\n"; }
	else { cout << "Slot2: EMPTY\n"; }
	if (slots[2] != nullptr) { cout << "Slot3: " << slots[2]->get_name() << "\n"; }
	else { cout << "Slot3: EMPTY\n"; }
	if (slots[3] != nullptr) { cout << "Slot4: " << slots[3]->get_name() << "\n"; }
	else { cout << "Slot4: EMPTY\n"; }
	if (slots[4] != nullptr) { cout << "Slot5: " << slots[4]->get_name() << "\n"; }
	else { cout << "Slot5: EMPTY\n"; }
	if (slots[5] != nullptr) { cout << "Slot6: " << slots[5]->get_name() << "\n"; }
	else { cout << "Slot6: EMPTY\n"; }
	cout << "\n";
}

// Returning The Index Of The First Empty Slot
// If All Slots Are Full, Return "-1"
int Party::GetFirstEmptySlot() {
	for (int i = 0; i < 7; i++) {
		if (slots[i] == nullptr) {
			return i;
		}
	}
	return -1;
}

// Return The Index Of The First Pokemon Who Has Health
// If No Pokemon Has Health, Return "-1"
int Party::GetFirstPokemonWithHealth() {
	for (int i = 0; i < 7; i++) {
		if (slots[i] != nullptr) {
			if (slots[i]->get_currHP() != 0) { return i; }
		}
	}
	return -1;
}
