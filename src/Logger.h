#ifndef DYALOGUSAGEEXAMPLECLIENT_LOGGER_H
#define DYALOGUSAGEEXAMPLECLIENT_LOGGER_H

#include "../lib/dyalog/Dyalog.h"
#include "../lib/dyalog/Model/Messages/DebugMessage.h"
#include "../lib/dyalog/Model/Messages/NoticeMessage.h"
#include "../lib/dyalog/Model/Messages/ErrorMessage.h"

class Logger {
public:
    Logger();

    template <typename T>
    void logDebug(T message, std::string file = __builtin_FILE(), std::string function = __builtin_FUNCTION(), int fileLine = __builtin_LINE()){
        std::shared_ptr<DebugMessage> msg(new DebugMessage());
        msg->setMessage(message);
        dyalog->log(msg, file, function, fileLine);
    }

    template <typename T>
    void logNotice(T message, std::string file = __builtin_FILE(), std::string function = __builtin_FUNCTION(), int fileLine = __builtin_LINE()){
        std::shared_ptr<NoticeMessage> msg(new NoticeMessage());
        msg->setMessage(message);
        dyalog->log(msg, file, function, fileLine);
    }

    template <typename T>
    void logError(T message, std::string file = __builtin_FILE(), std::string function = __builtin_FUNCTION(), int fileLine = __builtin_LINE()){
        std::shared_ptr<ErrorMessage> msg(new ErrorMessage());
        msg->setMessage(message);
        dyalog->log(msg, file, function, fileLine);
    }

private:
    void configure();

    std::unique_ptr<Dyalog> dyalog;
};


#endif //DYALOGUSAGEEXAMPLECLIENT_LOGGER_H
