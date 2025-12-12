#pragma once
#include <vector>
#include <algorithm>   
#include <fstream>      
#include <string>      
#include <exception>     
#include <utility>   

#include "AutoIncremental.h"
//fixing
class ItemNotFound : public runtime_error {
public:
    ItemNotFound() : runtime_error("Item not found") {}
};

class UniqueConstraintFailed : public runtime_error {
public:
    UniqueConstraintFailed() : runtime_error("Unique constraint failed") {}
};
//fixing

using namespace std;

// Manage objects with unique ID, support save, delete, CSV export
template<typename datatype>
class DataManagement 
{
protected:
    AutoIncremental<datatype> id;   // unique ID
    //fixing
    static inline vector<datatype> all;    // all objects
    //fixing

public:
    // Create a new object
    template<typename... Args>
    static datatype& create(Args&&... args) 
    {
        //fixing
		datatype obj(args...);
		//fixing

        if (exists(obj))
            throw UniqueConstraintFailed();

        obj.id.assignNext();
        all.push_back(obj);

        return all.back();
    }

    // Get object by ID
    static datatype& getById(int64_t id) 
    {
        for (auto& item : all)
            if ((int64_t)item.id == id)
                return item;

        throw ItemNotFound();
    }

    // Check if object exists
    static bool exists(const datatype& value) 
    {
        return any_of(all.begin(), all.end(),
            [&](const datatype& x) { return x == value; });
    }

    // Delete object at index
    static bool delAt(int index) 
    {
        if (index < 0 || index >= all.size()) return false;
        all.erase(all.begin() + index);
        return true;
    }

    // Save all objects to CSV
    static void saveCSV(const string& filename) 
    {
        ofstream out(filename);
        for (auto& item : all) out << item.toCSVLine() << "\n";
    }

    // Get ID of this object
    int64_t getId() const { return (int64_t)id; }
    
    //fixing
    static const vector<datatype>& getAll() { return all; }
    //fixing
};

template<typename datatype>
vector<datatype> DataManagement<datatype>::all;
