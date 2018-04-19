#include <thread>
#include <ctime>
#include <iostream>
#include "Simulation.h"

Simulation::Simulation() {
    this->logger = std::shared_ptr<Logger>(new Logger());
    const auto seed = static_cast<const unsigned int>(time(0));
    this->rng = std::mt19937_64(seed);
}

void Simulation::run() {
    std::cout << "Run simulation" << std::endl;
    std::thread threads[NUMBER_OF_CLIENTS];

    for (int i = 0; i < NUMBER_OF_CLIENTS; ++i) {
        threads[i] = std::thread(&Simulation::worker, this, i + 1);
    }

    for (auto &i : threads) {
        i.join();
    }
}

void Simulation::worker(int id) {
    std::uniform_int_distribution<int> loginAwaitTime(1, 20);
    std::uniform_int_distribution<int> logoutAwaitTime(8, 15);
    std::uniform_int_distribution<int> shortBreak(3,5);
    std::uniform_int_distribution<int> chanceOneInSix(1,6);
    std::uniform_int_distribution<int> chanceOneInThree(1,3);

    std::this_thread::sleep_for(std::chrono::seconds(loginAwaitTime(this->rng)));
    this->logger->logDebug("User " + std::to_string(id) + " just logged in.");

    std::this_thread::sleep_for(std::chrono::seconds(shortBreak(this->rng)));

    if (chanceOneInThree(this->rng) == 1) {
        this->logger->logNotice("Some minor failure occurred when user " + std::to_string(id) + " was using the application.");
    } else if (chanceOneInSix(this->rng) == 1) {
        this->logger->logError("Some terrible failure occurred for user " + std::to_string(id) + ". Forcing logout");
        this->logger->logDebug("User " + std::to_string(id) + " forced to log out.");
        return this->worker(id);
    }

    std::this_thread::sleep_for(std::chrono::seconds(logoutAwaitTime(this->rng)));
    this->logger->logDebug("User " + std::to_string(id) + " just logged out.");

    return this->worker(id);
}