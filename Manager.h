#pragma once
#include "Event.h"
#include "Participant.h"
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

class Manager {
public:
    void addEvent(const string& name, const string& type, int capacity) {
        Event::create(name, type, capacity);
    }

    void addParticipant(const string& name) {
        Participant::create(name);
    }

    void registerParticipantToEvent(int64_t participantId, int64_t eventId) {
        Event& e = Event::getById(eventId);
        Participant& p = Participant::getById(participantId);

        if (e.isFull())
            throw runtime_error("Event capacity is full");

        e.addParticipant(participantId);
        p.addEvent(eventId);
    }

    Event& findEvent(int64_t eventId) {
        return Event::getById(eventId);
    }

    Participant& findParticipant(int64_t participantId) {
        return Participant::getById(participantId);
    }

    vector<Event> listEventsSortedByType() {
        vector<Event> events = Event::getAll();
        sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
            return a.getType() < b.getType();
        });
        return events;
    }

    vector<Event> listEventsSortedByParticipantCount() {
        vector<Event> events = Event::getAll();
        sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
            return a.getRegisteredCount() < b.getRegisteredCount();
        });
        return events;
    }
};