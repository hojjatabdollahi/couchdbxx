#include "couchdbxx.hpp"

int main(int argc, char* argv[])
{
    wezside::CouchDBXX couch;

    // Create a db
    jsonxx::Object o = couch.put("test");
    std::cout << o.json() << std::endl;

    // Create design doc 'test' from json file
    o = couch.put("test", "test", "test.json");
    std::cout << o.json() << std::endl;
    
    // Fetch design document called 'test'
    o = couch.get("test", "test");
    std::cout << o.json() << std::endl;

    // Delete a db
    o = couch.del("test");
    std::cout << o.json() << std::endl;

    return 0;
}