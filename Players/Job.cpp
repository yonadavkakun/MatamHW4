#include "Job.h"

//Job
Job::Job(const string &jobName) : jobName(jobName) {
}

void Job::solarEclipseEffect(std::shared_ptr<Stats> playerStats) {
    playerStats->setForce(-1);
}

void Job::wonBattle(int loot,std::shared_ptr<Stats> playerStats) {
    playerStats->setCoins(loot);
}

void Job::lostBattle(int damage, std::shared_ptr<Stats> playerStats) {
    playerStats->setHealthPoints(-damage);
}

int Job::getCombatPower(std::shared_ptr<Stats> playerStats) const {
    return playerStats->getForce()+playerStats->getLevel();
}

//Warrior

Warrior::Warrior(const string &jobName, std::shared_ptr<Stats> playerStats): Job(jobName) {
    playerStats->setHealthPoints(50);
    playerStats->setMaxHealthPoints(50);
}

string Warrior::getJob() const {
    return jobName;
}

void Warrior::wonBattle(int loot, std::shared_ptr<Stats> playerStats) {
    playerStats->setCoins(loot);
    playerStats->setHealthPoints(-10);
}

int Warrior::getCombatPower(std::shared_ptr<Stats> playerStats) const {
    return 2*playerStats->getForce()+playerStats->getLevel();
}

//Archer

Archer::Archer(const string &jobName, std::shared_ptr<Stats> playerStats) : Job(jobName){
    playerStats->setCoins(10);
}

string Archer::getJob() const {
    return jobName;
}

//Magician

Magician::Magician(const string &jobName) : Job(jobName){}

string Magician::getJob() const {
    return jobName;
}

void Magician::solarEclipseEffect(std::shared_ptr<Stats> playerStats) {
    playerStats->setForce(1);
}






