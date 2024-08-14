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
    /**
     * creates a shared_ptr to a job in accordance with jobType
     * throws an exception if a job is invalid
     *
     * @param jobType, stats
     * @return shared_ptr<Job> job
     */
    static std::shared_ptr<Job> createJob(const std::string &jobType, std::shared_ptr<Stats> stats);
};
