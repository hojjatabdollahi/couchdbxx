#include "couchdbxx.hpp"

int main(int argc, char* argv[])
{
	wezside::CouchDBXX couch;

	// Create a db
	jsonxx::Object o = couch.put("tesdt");
	std::cout << o.json() << std::endl;

	// Delete a db
	o = couch.del("tesdt");
	std::cout << o.json() << std::endl;

	return 0;
}