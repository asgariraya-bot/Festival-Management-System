#pragma once
#include "DataManagement.h"
#include <string>
#include <vector>

using namespace std;

// Represents a festival event with name, type, capacity, and participants
class Event : public DataManagement<Event> 
{
    string eventName;
    string eventType;
    int capacity;
    vector<int64_t> participants;

public:
    Event(const string& name, const string& type, int cap)
        : eventName(name), eventType(type), capacity(cap) {}

    int64_t getId() const { return DataManagement<Event>::getId(); }
    const string& getName() const { return eventName; }
    const string& getType() const { return eventType; }
    int getCapacity() const { return capacity; }
    int getRegisteredCount() const { return (int)participants.size(); }

    bool isFull() const { return getRegisteredCount() >= capacity; }

    void addParticipant(int64_t participantId) { participants.push_back(participantId); }

    string toCSVLine() const {
        return eventName + "," + eventType + "," + to_string(capacity);
    }

    bool operator==(const Event& other) const {
        return eventName == other.eventName && eventType == other.eventType;
    }
};
