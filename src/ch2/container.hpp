#pragma once

namespace ch2
{
namespace container
{
	template <typename Container, typename Predicator>
	bool any(const Container &container, Predicator &&predicator)
	{
		for (auto &&elem : container)
			if (predicator(elem))
				return true;
		return false;
	};

	template <typename Container, typename Predicator>
	bool all(const Container &container, Predicator &&predicator)
	{
		for (auto &&elem : container)
			if (!predicator(elem))
				return false;
		return true;
	};

	template <typename Container, typename Predicator>
	bool none(const Container &container, Predicator &&predicator)
	{
		return !any(container, std::forward(predicator));
	};
};
};