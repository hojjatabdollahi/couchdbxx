#ifndef __COUCHDB_XX__
#define __COUCHDB_XX__

#include <string>
#include <curl/curl.h>
#include "jsonxx/jsonxx.h"
#include "curlrequest.hpp"

namespace wezside
{
	class CouchDBXX
	{
	private:
		std::string uri;
		CurlRequest curlrequest;

		jsonxx::Object request(std::string req, std::string req_params)
		{
			jsonxx::Object o;
			std::ostringstream res;
			if (CURLE_OK == curlrequest.curl_read(req, res, 30, req_params))
			{
				o.parse(res.str().c_str());
			}			
			else o << "error" << "An error occured when CURL request was made.";
			return o;
		}

	public:
		CouchDBXX() : uri("http://127.0.0.1:5984/"){}
		~CouchDBXX() {}

		void set_db(std::string uri)
		{
			this->uri = uri;
		}
		jsonxx::Object put(std::string db_name)
		{
			if (db_name.empty()) return jsonxx::Object("error", "Database name cannot be empty.");
			if (uri.at(uri.length()-1) != '/') uri += '/';
			return request(uri + db_name, "PUT");
		}
		jsonxx::Object put(std::string design_name, std::string view_name)
		{

		}
		jsonxx::Object del(std::string db_name)
		{
			if (db_name.empty()) return jsonxx::Object("error", "Database name cannot be empty.");
			if (uri.at(uri.length()-1) != '/') uri += '/';
			return request(uri + db_name, "DELETE");	
		}
		jsonxx::Object view(std::string design, std::string view)
		{

		}
	};
}
#endif // __COUCHDB_XX__