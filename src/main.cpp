#include <iostream>
#include <memory>
#include "../lib/dyalog/Dyalog.h"
#include "../lib/dyalog/Service/LogWriters/SimpleLogWriter.h"
#include "../lib/dyalog/Model/Messages/CriticalMessage.h"

int main() {
    std::shared_ptr<Dyalog> logger(new Dyalog());

    std::shared_ptr<LogHandlerAbstract> writer(new SimpleLogWriter("test.txt"));
    logger->registerLogHandler(writer);

    std::shared_ptr<CriticalMessage> message(new CriticalMessage());
    message->setMessage("test");

    logger->log(message);

    return 0;
}
