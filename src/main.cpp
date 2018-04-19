#include <iostream>
#include <memory>
#include <thread>
#include "../lib/dyalog/Dyalog.h"
#include "../lib/dyalog/Service/LogWriters/SimpleLogWriter.h"
#include "../lib/dyalog/Service/LogWriters/AsyncSimpleLogWriter.h"
#include "../lib/dyalog/Model/Messages/CriticalMessage.h"
#include "../lib/dyalog/Model/Messages/DebugMessage.h"
#include "../lib/dyalog/Model/Messages/NoticeMessage.h"
#include "../lib/dyalog/Service/LogSenders/SimpleTCPLogSender.h"

#define TARGET_SERVER_IP "127.0.0.1"
#define TARGET_SERVER_PORT 6000

void testSyncWriting(){
    //init dyalog lib
    std::shared_ptr<Dyalog> logger(new Dyalog());

    //setup dyalog configs
    logger->getConfig()->setCodeTraceLogged(true);

    //add handler
    std::shared_ptr<LogHandlerAbstract> writer(new SimpleLogWriter("test.txt"));
    logger->registerLogHandler(writer);

    //log a custom type message
    std::shared_ptr<DebugMessage> message(new DebugMessage());
    message->setMessage("sync test");
    logger->log(message);
}

void testTCPSending(){
    //init dyalog lib
    std::shared_ptr<Dyalog> logger(new Dyalog());

    //setup dyalog configs
    logger->getConfig()->setCodeTraceLogged(true);

    //add handler
    std::shared_ptr<LogHandlerAbstract> sender(new SimpleTCPLogSender(TARGET_SERVER_IP, TARGET_SERVER_PORT));
    logger->registerLogHandler(sender);

    //log a custom type message
    std::shared_ptr<DebugMessage> message(new DebugMessage());
    message->setMessage("Sending log through tcp!");
    logger->log(message);
}

void testAsyncWriting(){
    //init dyalog lib
    std::shared_ptr<Dyalog> logger(new Dyalog());

    //setup dyalog configs
    logger->getConfig()->setCodeTraceLogged(true);

    //add handler
    std::shared_ptr<LogHandlerAbstract> writer(new AsyncSimpleLogWriter("test.txt"));
    logger->registerLogHandler(writer);

    //log a custom type message
    std::shared_ptr<NoticeMessage> message(new NoticeMessage());
    message->setMessage("async test");
    logger->log(message);

    //wait for 2 seconds
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    //log another message
    std::shared_ptr<CriticalMessage> message2(new CriticalMessage());
    message2->setMessage("async test after 2 seconds");
    logger->log(message2);

    //keep app working for a little longer to observe results;
    std::this_thread::sleep_for(std::chrono::milliseconds(15000));
}

int main() {
    testTCPSending();
    testSyncWriting();
    testAsyncWriting();

    return 0;
}
