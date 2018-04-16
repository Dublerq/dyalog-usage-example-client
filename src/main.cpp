#include <iostream>
#include <memory>
#include "../lib/dyalog/Dyalog.h"
#include "../lib/dyalog/Service/LogWriters/SimpleLogWriter.h"
#include "../lib/dyalog/Model/Messages/CriticalMessage.h"

int main() {
    //init dyalog lib
    std::shared_ptr<Dyalog> logger(new Dyalog());

    //setup dyalog configs
    logger->getConfig()->setCodeTraceLogged(true);

    //add handlers
    std::shared_ptr<LogHandlerAbstract> writer(new SimpleLogWriter("test.txt"));
    logger->registerLogHandler(writer);

    //log a custom type message
    std::shared_ptr<CriticalMessage> message(new CriticalMessage());
    message->setMessage("test");
    logger->log(message);

    return 0;
}
