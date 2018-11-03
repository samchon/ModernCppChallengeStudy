#pragma once

#include <string>
#include <string_view>
#include <exception>

#include "split.hpp"
#include "join.hpp"

#include "../utils/console.hpp"

namespace ch3
{
namespace uri
{
	struct URI
	{
		std::string protocol;
		std::string domain;
		unsigned short port;
		std::string path;
		std::string query;
	};

	struct URI parse(std::string_view str)
	{
		struct URI ret;

		//----
		// PROTOCOL
		//----
		static const std::string PROTOCOL_SYMBOL = "://";
		size_t protocol_idx = str.find(PROTOCOL_SYMBOL);
		
		ret.protocol = str.substr(0, protocol_idx);
		str = str.substr(protocol_idx + PROTOCOL_SYMBOL.size());

		//----
		// SEGMETNS
		//----
		auto segments = split::split(str, { "/" });

		// DOMAIN & PROTOCOL
		size_t port_idx = segments.front().find(":");
		if (port_idx == std::string_view::npos)
		{
			ret.domain = segments.front();
			ret.port = 80;
		}
		else
		{
			ret.domain = segments.front().substr(0, port_idx);
			ret.port = std::stoi(segments.front().substr(port_idx + 1).data());
		}
		segments.erase(segments.begin());
		
		// PATH & QUERY
		if (segments.empty())
			return ret;

		ret.path = "/" + join::join(segments, "/");
		size_t question_idx = ret.path.find("?");

		if (question_idx != std::string_view::npos)
		{
			ret.query = ret.path.substr(question_idx + 1);
			ret.path.erase(ret.path.begin() + question_idx, ret.path.end());
		}
		return ret;
	};

	void main()
	{
		using namespace std;

		console::print_title(3, 30, "Extracting URL parts");
		string str = console::get_input<std::string>("URL");

		static URI uri = parse(str);
		cout << "protocol: " << uri.protocol << endl;
		cout << "domain: " << uri.domain << endl;
		cout << "port: " << uri.port << endl;
		cout << "path: " << uri.path << endl;
		cout << "query: " << uri.query << endl;
	};
};
};