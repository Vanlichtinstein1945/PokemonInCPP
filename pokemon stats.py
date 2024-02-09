# Importations
from selenium import webdriver
from selenium.webdriver.common.by import By

# Global Variables
POKEMON = []
INDEX = 0
POKEMON_STATS = []

# Initialize the Web Driver
options = webdriver.FirefoxOptions()
options.add_argument('--ignore-ssl-errors=yes')
options.add_argument('--ignore-certificate-errors')
driver = webdriver.Firefox(options=options)

# Read Name File for Pokemon Names
inputFile = open("pokemon names.txt", "r")
for line in inputFile.readlines():
    POKEMON.append(line.strip())
inputFile.close()

# Defining the Process of Pulling Each Individual Stat
def pullStat(rows, rowIndex):
    col = rows[rowIndex].find_element(By.TAG_NAME, "th")
    num = col.find_elements(By.TAG_NAME, "div")
    return num[1].text

# Defininting the Process of Pulling a Specific Pokemon's Stats
def pullStats(pokemonName):
    global INDEX, POKEMON_STATS
    INDEX += 1
    # Opening the Specific Pokemon's Bulbapedia Page
    driver.get("https://bulbapedia.bulbagarden.net/wiki/"+pokemonName+"_(Pokémon)")
    # Finding the Stats Table
    table = driver.find_element(By.XPATH, '//*[@id="mw-content-text"]/div//*[@id="Base_stats"]/following::table')
    rows = table.find_elements(By.TAG_NAME, "tr")
    # Pulling the Specific Stats
    hp = pullStat(rows, 2)
    atk = pullStat(rows, 3)
    defe = pullStat(rows, 4)
    spAtk = pullStat(rows, 5)
    spDef = pullStat(rows, 6)
    spd = pullStat(rows, 7)
    # Adding the Found Stats to Our 'POKEMON_STATS' array
    POKEMON_STATS.append("{0}\n{1}\n{2}\n{3}\n{4}\n{5}\n{6}\n{7}\n\n".format("pokeIndex: "+str(INDEX), pokemonName, "HP: "+str(hp), "Attack: "+str(atk), "Defense: "+str(defe), "Special Attack: "+str(spAtk), "Special Defense: "+str(spDef), "Speed: "+str(spd)))

# Pulling Stats for Each Pokemon in 'POKEMON'
for poke in POKEMON:
    pullStats(poke)

# Closing the Selenium Window
driver.close()
driver.quit()

# Outputting the Pokemon Stats to 'pokemon.txt'
outputFile = open("pokemon.txt", "w")
outputFile.writelines(POKEMON_STATS)
outputFile.close()

# Exiting the Program
exit()
