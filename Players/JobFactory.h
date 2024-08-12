#pragma once
#include <map>
#include <memory>
#include <functional>
#include <stdexcept>
#include <string>
#include "Job.h"
using std::string;


class JobFactory {
public:
    using JobCreator = std::function<std::shared_ptr<Job>()>;

    static std::shared_ptr<Job> createJob(const std::string &jobType, std::shared_ptr<Stats> stats) {
        const static std::map<std::string, JobCreator> jobMap = {
            {string("Warrior"), [&]() { return std::make_shared<Warrior>(jobType, stats); }},
            {string("Archer"), [&]() { return std::make_shared<Archer>(jobType, stats); }},
            {string("Magician"), [&]() { return std::make_shared<Magician>(jobType); }}
        };

        auto it = jobMap.find(jobType);
        if (it != jobMap.end()) {
            return it->second();
        }
        throw std::runtime_error("Invalid job type");
    }
};
