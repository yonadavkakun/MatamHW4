#include "JobFactory.h"

std::unique_ptr<Job> JobFactory::createJob(const std::string &jobType, Stats *stats) {
    const static std::map<std::string, JobCreator> jobMap = {
        {string("Warrior"), [&]() { return std::make_unique<Warrior>(jobType, *stats); }},
        {string("Archer"), [&]() { return std::make_unique<Archer>(jobType, *stats); }},
        {string("Magician"), [&]() { return std::make_unique<Magician>(jobType); }}
    };

    auto it = jobMap.find(jobType);
    if (it != jobMap.end()) {
        return it->second();
    }
    throw std::runtime_error("Invalid Players File");
}
