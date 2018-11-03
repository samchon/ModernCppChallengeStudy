#pragma once

namespace ch2
{
namespace insert
{
	template <typename Container>
	void push_back(Container &container, Container::value_type &&value)
	{
		container.push_back(std::forward(value));
	};
};
};