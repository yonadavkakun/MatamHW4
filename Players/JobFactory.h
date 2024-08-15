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
    using JobCreator = std::function<std::unique_ptr<Job>()>;
    /**
     * creates a unique_ptr to a job in accordance with jobType
     * throws an exception if a job is invalid
     *
     * @param jobType, stats
     * @return unique_ptr<Job> job
     */
    static std::unique_ptr<Job> createJob(const std::string &jobType, Stats *stats);
};
