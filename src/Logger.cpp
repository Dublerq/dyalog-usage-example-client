#include "Logger.h"
#include "../lib/dyalog/Service/LogWriters/AsyncSimpleLogWriter.h"
#include "../lib/dyalog/Service/LogWriters/SimpleLogWriter.h"
#include "../lib/dyalog/Service/LogSenders/SimpleTCPLogSender.h"
#include "../lib/dyalog/Service/ConsoleLogger.h"

Logger::Logger() {
    this->dyalog = std::unique_ptr<Dyalog>(new Dyalog());
    this->configure();
}

void Logger::configure() {
    //log code trace details
    this->dyalog->getConfig()->setCodeTraceLogged(true);

    // log debug information to debug.log
    std::shared_ptr<LogHandlerAbstract> debugWriter(new AsyncSimpleLogWriter("debug.log", 200, 0, 100));
    this->dyalog->registerLogHandler(debugWriter);

    //log information above debug to errors.log
    std::shared_ptr<LogHandlerAbstract> errorsWriter(new SimpleLogWriter("errors.log",101));
    this->dyalog->registerLogHandler(errorsWriter);

    //send all logs to remote tcp server accessible via 127.0.0.1:6000
    std::shared_ptr<LogHandlerAbstract> logSender(new SimpleTCPLogSender("127.0.0.1",6000));
    this->dyalog->registerLogHandler(logSender);

    //show all logs in console
    std::shared_ptr<LogHandlerAbstract> consoleLogger(new ConsoleLogger());
    this->dyalog->registerLogHandler(consoleLogger);
}
