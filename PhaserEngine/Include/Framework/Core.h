#pragma once
#include <stdio.h>
#include <memory>
#include <map>
#include <unordered_map>

namespace ph
{
	template<typename T>
	using TUniquePtr = std::unique_ptr<T>;

	template<typename T>
	using TSharedPtr = std::shared_ptr<T>;

	template<typename T>
	using TWeakPtr = std::weak_ptr<T>;

	template<typename T>
	using TArray = std::vector<T>;

	template<typename keyType, typename valType, typename Pr = std::less<keyType>>
	using TSortedMap = std::map<keyType, valType, Pr>;

	template<typename keyType, typename valType, typename hasher = std::hash<keyType>>
	using TMap = std::unordered_map<keyType, valType, hasher>;

#define LOG(format, ...) printf(format "\n", ##__VA_ARGS__)
}