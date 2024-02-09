# Pokemon
This is a C++ program attempting to recreate the early Pokemon games.
I have restricted myself to using C++ for this project to better my
understanding of the language and data types. Currently, I have decided
to move forward with the SFML library for developing the GUI and handling
the actual sprite manipulation. The program, so far, has several header
files that can be used:
## Pokemon.h
This header file defines the default 'BasePokemon' class that will
handle keeping IVs, EVs, typings, etc. This header has several functions
and classes that can be called:
### TYPES
An enum containing all of the typings
### TYPES_STRINGS
A const char array of the typings in string format for converting to and
from readable format.
### XPTYPE
An enum for the different XP types a pokemon can have
### XPTYPE_STRINGS
Same as the TYPES_STRINGS, but for XPTYPE instead
### STAT
An enum to more easily call specific stats
### NATURES
An enum to keep all of the natures a pokemon can have
### NATURES_STRINGS
Same as the last two STRINGS arrays but for NATURES
### Stats
A class to hold one of each type of stat. Easier to work with than saving
100 variables to the BasePokemon class
### DatabaseInfo
A class for holding information that is pulled from the database of pokemon
### BasePokemon
The class that keeps all of the variables and methods that a pokemon will use.
Some of these methods include: TakeDamage, Heal, and print_stats.
### ReadFromDatabase
The function for reading a pokemon's data based on its species index
### CreateBasePokemonFromTable
Creates a pokemon based on its species index and level
### CreateBasePokemonFromStats
Creates a pokemon based on its given stats. Useful for recreating a saved pokemon
back to its original state
## Party.h
### Party
A class to hold the array of pokemon that will be the user's party.
Also holds several useful methods for this function such as: InsertPokemon,
RemovePokemon, and PrintParty.
## PC.h
### PC
A class to handle loading, saving, and presenting of a user's saved pokemon.
Holds multiple useful functions, like DepositPokemonLast, SwapPokemon, and
savePC.
## GUI.h
### Button
A class that keeps the variables and functions necessary to present a
button to the user. Has functionality for hover shading, clicking, and
drawing.
## pokemonData.csv
This is the csv file that will eventually hold of the pokemons' base data
for loading and creating
## PCData.csv
This is the csv file created by the PC to save and load pokemon from
## pokemonData.py
Not completed yet, but this is a python program that will be used to webscrape
all of the pokemon data needed to fill out the pokemonData.csv
