cmake_minimum_required(VERSION 3.9)
project(DyalogUsageExampleClient)

set(CMAKE_CXX_STANDARD 11)

find_package(Boost REQUIRED COMPONENTS system)
find_package(Threads)

include_directories(${Boost_INCLUDE_DIRS})
add_executable(DyalogUsageExampleClient src/main.cpp lib/dyalog/Dyalog.cpp lib/dyalog/Dyalog.h lib/dyalog/Model/Configuration.cpp lib/dyalog/Model/Configuration.h lib/dyalog/Model/MessageAbstract.h lib/dyalog/Model/Messages/DebugMessage.h lib/dyalog/Model/Messages/NoticeMessage.h lib/dyalog/Model/Messages/WarningMessage.h lib/dyalog/Model/Messages/ErrorMessage.h lib/dyalog/Model/Messages/CriticalMessage.h lib/dyalog/Model/LogQueue.cpp lib/dyalog/Model/LogQueue.h lib/dyalog/Service/LogManager.cpp lib/dyalog/Service/LogManager.h lib/dyalog/Service/LogWriterAbstract.cpp lib/dyalog/Service/LogWriterAbstract.h lib/dyalog/Service/LogSenderAbstract.h lib/dyalog/Service/LogWriters/AsyncSimpleLogWriter.cpp lib/dyalog/Service/LogWriters/AsyncSimpleLogWriter.h lib/dyalog/Service/LogWriters/SimpleLogWriter.cpp lib/dyalog/Service/LogWriters/SimpleLogWriter.h lib/dyalog/Service/LogHandlerAbstract.cpp lib/dyalog/Service/LogHandlerAbstract.h lib/dyalog/Helper/MessageFormatterAbstract.h lib/dyalog/Model/MessageAbstract.cpp lib/dyalog/Helper/MessageFormatters/BasicMessageFormatter.cpp lib/dyalog/Helper/MessageFormatters/BasicMessageFormatter.h lib/dyalog/lib/date.h lib/dyalog/Service/LogSenders/SimpleTCPLogSender.cpp lib/dyalog/Service/LogSenders/SimpleTCPLogSender.h lib/dyalog/Service/LogSenderAbstract.cpp)
target_link_libraries(DyalogUsageExampleClient ${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES})
