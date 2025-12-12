#include <iostream>
#include "Manager.h"

using namespace std;

int main() {
    Manager manager;

    try {
        manager.addEvent("Rock Festival", "Music", 3);
        manager.addEvent("Painting Expo", "Art", 2);
        manager.addEvent("Summer Concert", "Music", 5);

        manager.addParticipant("Ali");
        manager.addParticipant("Sara");
        manager.addParticipant("Reza");

        auto& p1 = Participant::getAll()[0];
        auto& p2 = Participant::getAll()[1];
        auto& p3 = Participant::getAll()[2];
        auto& e1 = Event::getAll()[0];
        auto& e2 = Event::getAll()[1];

        manager.registerParticipantToEvent(p1.getId(), e1.getId());
        manager.registerParticipantToEvent(p2.getId(), e1.getId());
        manager.registerParticipantToEvent(p3.getId(), e1.getId());
        manager.registerParticipantToEvent(p1.getId(), e2.getId());

        cout << "Events sorted by type:\n";
        for (const auto& e : manager.listEventsSortedByType()) {
            cout << e.getName() << " - " << e.getType() << " (ID: " << e.getId() << ")\n";
        }

        cout << "\nEvents sorted by participant count:\n";
        for (const auto& e : manager.listEventsSortedByParticipantCount()) {
            cout << e.getName() << " - " << e.getRegisteredCount() << " participants\n";
        }

    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}