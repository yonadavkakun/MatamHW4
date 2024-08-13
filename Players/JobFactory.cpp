#include "JobFactory.h"

std::shared_ptr<Job> JobFactory::createJob(const std::string &jobType, std::shared_ptr<Stats> stats) {
    const static std::map<std::string, JobCreator> jobMap = {
        {string("Warrior"), [&]() { return std::make_shared<Warrior>(jobType, stats); }},
        {string("Archer"), [&]() { return std::make_shared<Archer>(jobType, stats); }},
        {string("Magician"), [&]() { return std::make_shared<Magician>(jobType); }}
    };

    auto it = jobMap.find(jobType);
    if (it != jobMap.end()) {
        return it->second();
    }
    throw std::runtime_error("Invalid Players File");
}
