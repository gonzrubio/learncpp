#include <iostream>

template <class T>
class Pair1 {
 private:
	T m_first, m_second;
public:
	Pair1(const T& first, const T& second) : m_first{ first }, m_second{ second } {}
	const T& first() const;
	const T& second() const;
};

template<class T>
const T& Pair1<T>::first() const {
	return m_first;
}

template<class T>
const T& Pair1<T>::second() const {
	return m_second;
}

template <class T1, class T2>
class Pair {
private:
	T1 m_first;
	T2 m_second;
public:
	Pair(const T1& first, const T2& second) : m_first{ first }, m_second{ second } {}
	const T1& first() const;
	const T2& second() const;
};

template <class T1, class T2>
const T1& Pair<T1, T2>::first() const {
	return m_first;
}

template <class T1, class T2>
const T2& Pair<T1, T2>::second() const {
	return m_second;
}

template <class S>
class StringValuePair : public Pair<std::string, S> {
public:
	StringValuePair(const std::string& key, const S& value)
		: Pair<std::string, S>(key, value)
	{
	}
};

int main() {
	Pair1<int> p1(5, 8);
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair1<double> p2(2.3, 4.5);
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	Pair<int, double> pair1(5, 6.7);
	std::cout << "Pair: " << pair1.first() << ' ' << pair1.second() << '\n';

	const Pair<double, int> pair2(2.3, 4);
	std::cout << "Pair: " << pair2.first() << ' ' << pair2.second() << '\n';

	StringValuePair<int> svp("Hello", 5);
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
}
