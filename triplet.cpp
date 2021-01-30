#include <vector>
#include <algorithm>
#include <iostream>

template<typename T1, typename T2, typename T3>
class triplet
{
	public:
	
	triplet():
		item {std::make_pair<std::pair<T1, T2>, T3>(std::make_pair<T1, T2>(T1(), T2()), T3())},
		first {item.first.first}, second {item.first.second}, third{item.second}
			{}
	
	triplet(T1 item1, T2 item2, T3 item3) :
		item {std::make_pair<std::pair<T1, T2>, T3>(std::make_pair<T1, T2>(std::forward<T1>(item1), std::forward<T2>(item2)), std::forward<T3>(item3))},
		first {item.first.first}, second {item.first.second}, third{item.second}
			{}
	
	triplet(const triplet<T1, T2, T3>& rhs) : 
		item {rhs.item},
		first {item.first.first},
		second {item.first.second},
		third {item.second}
			{}
			
	triplet(triplet<T1, T2, T3>&& rhs) :
		item {std::move(rhs.item)},
		first {item.first.first},
		second {item.first.second},
		third {item.second}
			{}
			
	
	triplet<T1, T2, T3>& make_triplet(T1 item1, T2 item2, T3 item3)
	{
		item = std::make_pair<std::pair<T1, T2>, T3>(std::make_pair<T1, T2>(item1, item2), item3);
		
		return *this;
	}
	
	triplet<T1, T2, T3>& operator=(const triplet<T1, T2, T3>& rhs)
	{
		first = std::forward<T1>(rhs.first);
		second = std::forward<T2>(rhs.second);
		third = std::forward<T3>(rhs.third);
		
		return *this;
	}

	std::pair<std::pair<T1, T2>, T3> item;
	T1& first;
	T2& second;
	T3& third;
};

template<typename T1, typename T2, typename T3>
void print_triplet(const triplet<T1, T2, T3>& t)
{
	std::cout << t.first << std::endl;
	std::cout << t.second << std::endl;
	std::cout << t.third << std::endl;
}

int main()
{
	triplet<int, int, int> mytriplet {1, 2, 3};
	print_triplet(mytriplet);
	
	mytriplet = triplet<int, int, int> (4, 5, 6);
	print_triplet(mytriplet);
	
	
	triplet<int, int, int> othertriplet (mytriplet);
	print_triplet(othertriplet);
	
	triplet<std::vector<int>, std::vector<int>, std::vector<int>> vtrip {{1,2,3}, {2,3,4}, {5,6,7}};
	
	std::cout << "first item :" << std::endl;
	for (auto& x : vtrip.first)
		std::cout << x << ' ' ;
	std::cout << std::endl;
	
	std::cout << "second item :" << std::endl;
	for (auto& x : vtrip.second)
		std::cout << x << ' ' ;
	std::cout << std::endl;
	
	std::cout << "third item :" << std::endl;
	for (auto& x : vtrip.third)
		std::cout << x << ' ' ;
	std::cout << std::endl;
	
	triplet<std::vector<int>, std::vector<int>, std::vector<int>> vtrip2;
	
	for (int i = 0; i < 10; ++i)
	{
		vtrip2.first.push_back(i);
		vtrip2.second.push_back(i * 2);
		vtrip2.third.push_back(i * 3);
	}
	
	
	std::cout << "first item :" << std::endl;
	for (auto& x : vtrip2.first)
		std::cout << x << ' ' ;
	std::cout << std::endl;
	
	std::cout << "second item :" << std::endl;
	for (auto& x : vtrip2.second)
		std::cout << x << ' ' ;
	std::cout << std::endl;
	
	std::cout << "third item :" << std::endl;
	for (auto& x : vtrip2.third)
		std::cout << x << ' ' ;
	std::cout << std::endl;

	triplet<std::vector<int>, std::vector<int>, std::vector<int>> vtrip3 {std::move(vtrip2)};
	
	std::cout << "after move construction :" << std::endl;
	
	
	std::cout << "first item :" << std::endl;
	for (auto& x : vtrip2.first)
		std::cout << x << ' ' ;
	std::cout << std::endl;
	
	std::cout << "second item :" << std::endl;
	for (auto& x : vtrip2.second)
		std::cout << x << ' ' ;
	std::cout << std::endl;
	
	std::cout << "third item :" << std::endl;
	for (auto& x : vtrip2.third)
		std::cout << x << ' ' ;
	std::cout << std::endl;
	
	
	std::cout << "first item :" << std::endl;
	for (auto& x : vtrip3.first)
		std::cout << x << ' ' ;
	std::cout << std::endl;
	
	std::cout << "second item :" << std::endl;
	for (auto& x : vtrip3.second)
		std::cout << x << ' ' ;
	std::cout << std::endl;
	
	std::cout << "third item :" << std::endl;
	for (auto& x : vtrip3.third)
		std::cout << x << ' ' ;
	std::cout << std::endl;
	
}