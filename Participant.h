#pragma once
#include "DataManagement.h"
#include <string>
#include <vector>
using namespace std;

// Represents a festival participant with name and registered events
class Participant : public DataManagement<Participant> {
    string name;
    vector<int64_t> registeredEvents;

public:
    Participant(const string& name) : name(name) {}

    const string& getName() const { return name; }
    int64_t getId() const { return DataManagement<Participant>::getId(); }

    // Add an event ID to the participant's registered events
    void addEvent(int64_t eventId) { registeredEvents.push_back(eventId); }

    // Convert participant data to CSV line
    string toCSVLine() const { return name; }

    // Compare participants by name
    bool operator==(const Participant& other) const { return name == other.name; }
};
