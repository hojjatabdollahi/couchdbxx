#include "couchdbxx.hpp"

int main(int argc, char* argv[])
{
    wezside::CouchDBXX couch;

    // Create a db
    jsonxx::Object o = couch.put("test");
    std::cout << "----- Create DB 'test' -----" << std::endl;
    std::cout << o.json() << std::endl;

    // Create design doc 'test' from json file
    o = couch.put("test", "my_design", "test.json");
    std::cout << "----- Create Design Doc -----" << std::endl;
    std::cout << o.json() << std::endl;
    
    // Fetch design document called 'test'
    o = couch.get("test", "my_design");
    std::cout << "----- Fetch design doc 'test' -----" << std::endl;
    std::cout << o.json() << std::endl;

    // View 
    o = couch.view("test", "my_design", "all");
    std::cout << "----- Fetch view doc 'all' -----" << std::endl;
    std::cout << o.json() << std::endl;	

    // View + Params
    jsonxx::Object params = jsonxx::Object("key", "somevalue");
    o = couch.view("test", "my_design", "all", params);
    std::cout << "----- Fetch view doc 'all' + params -----" << std::endl;
    std::cout << o.json() << std::endl;	

    // Delete a db
    o = couch.del("test");
    std::cout << "----- Delete db 'test' -----" << std::endl;
    std::cout << o.json() << std::endl;

    return 0;
}