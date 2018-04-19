#ifndef DYALOGUSAGEEXAMPLECLIENT_SIMULATION_H
#define DYALOGUSAGEEXAMPLECLIENT_SIMULATION_H

#define NUMBER_OF_CLIENTS 10

#include <memory>
#include "Logger.h"
#include <random>

class Simulation {

public:
    Simulation();
    void run();

    void worker(int id);

private:
    std::shared_ptr<Logger> logger;
    std::mt19937_64 rng;
};


#endif //DYALOGUSAGEEXAMPLECLIENT_SIMULATION_H
