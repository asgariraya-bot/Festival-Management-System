# Festival Management System

C++ Project – Advanced Programming  
A complete festival and participant management system using modern C++ features.

## Team Members
- Fateme Zaree 
- Raya Asgari

## Features Implemented
- Add new events and participants
- Register participants to events with capacity control
- Search event/participant by unique auto-generated ID
- List all events sorted by type or by number of registered participants
- Full exception handling (capacity full, not found, duplicate, etc.)
- Unique ID auto-increment using generic template (AutoIncremental)
- Multi-file project structure with proper header guards
- Heavy use of STL (vector, algorithm, templates, exceptions)
- Clean and standard-compliant C++17 code
- Full Git history with meaningful commits (Group Coding Workflow followed)

## How to Compile & Run

```bash
g++ main.cpp -o festival -std=c++17
./festival          # Linux / macOS / Git Bash
# or
festival.exe       # Windows

Sample Output
Events sorted by type:
Painting Expo - Art (ID: 1)
Rock Festival - Music (ID: 0)
Summer Concert - Music (ID: 2)

Events sorted by participant count:
Summer Concert - 0 participants
Painting Expo - 1 participants
Rock Festival - 3 participants