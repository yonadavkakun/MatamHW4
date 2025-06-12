# MatamStory – Turn-Based RPG  
**Intro to System Programming (234124) – Wet HW 4, Spring 2025, Technion**

> Personal implementation of a compact turn-based RPG (inspired by MapleStory)  
> 📄 Full assignment spec: see `hw4.pdf` in this repository.

---

## ✨ Game highlights

| Category | Details |
|----------|---------|
| **Players** | 2 – 6 heroes, each built from a **Job** + **Character Trait** |
| **Jobs** | *Warrior* (melee), *Archer* (ranged), *Magician* (caster) |
| **Traits** | *Responsible* (plays safe) • *RiskTaking* (high-risk/high-reward) |
| **Core stats** | `Level`, `Force`, `HP`, `Coins` |
| **Events** | Monster fights (*Snail*, *Slime*, *Balrog*, *Pack*), global buffs (*SolarEclipse*), shops (*PotionsMerchant*), more |
| **Victory** | First hero to reach **Level 10** wins • if every hero is KO → no winner |
| **Leaderboard** | Re-sorted after every round: Level ↓ Coins ↓ Name |

---
Run the compilation command **from the project root** 

g++ --std=c++17 -o MatamStory -Wall -pedantic-errors -Werror -DNDEBUG *.cpp Events/*.cpp Players/*.cpp -I. -I./Players -I./Events
# run the game with example input files
./MatamStory tests/test1.events tests/test2.players > test1.out