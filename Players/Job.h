#pragma once
#include <string>
using std::string;

class Job {
    string jobName;

public:
    Job(const string &jobName);

    virtual string getJob() const =0;

    virtual string solarEclipseEffect();

    virtual ~Job() = default;
};

//Warrior
class Warrior : Job {
public:
    Warrior(const string &jobName);

    string getJob() const override;

    ~Warrior() override = default;
};

//Archer
class Archer : Job {
public:
    Archer(const string &jobName);

    string getJob() const override;

    ~Archer() override = default;
};

//Magician
class Magician : Job {
public:
    Magician(const string &jobName);

    string getJob() const override;

    string solarEclipseEffect() override;

    ~Magician() override = default;
};

