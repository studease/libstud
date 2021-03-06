#include "event.h"

const std::string Event::ACTIVATE = "activate";
const std::string Event::ADDED = "added";
const std::string Event::CANCEL = "cancel";
const std::string Event::CHANGE = "change";
const std::string Event::CLEAR = "clear";
const std::string Event::CLOSE = "close";
const std::string Event::COMPLETE = "complete";
const std::string Event::CONNECT = "connect";
const std::string Event::DEACTIVATE = "deactivate";
const std::string Event::IDLE = "idle";
const std::string Event::INIT = "init";
const std::string Event::OPEN = "open";
const std::string Event::REMOVED = "removed";

Event::Event(const std::string &type, void *source)
{
    m_type = type;
    m_source = source;
}

Event::~Event()
{
}

std::string Event::type()
{
    return m_type;
}

void *Event::source()
{
    return m_source;
}

void *Event::target()
{
    return m_target;
}

void Event::set_target(void *target)
{
    m_target = target;
}

bool Event::stoppedPropagation()
{
    return !!(m_result & ER_CONSUMED);
}

void Event::stopPropagation()
{
    m_result = static_cast<EventResult>(m_result | ER_CONSUMED);
}

std::shared_ptr<IEvent> Event::clone()
{
    return std::make_shared<Event>(m_type, m_target);
}

std::string Event::toString()
{
    return "[Event type=" + m_type + "]";
}
