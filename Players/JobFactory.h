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

    static std::shared_ptr<Job> createJob(const std::string &jobType, std::shared_ptr<Stats> stats);
};
