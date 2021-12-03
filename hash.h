#ifndef HASH_H_
#define HASH_H_

#include <string>
#include <sstream>

template <class Key, class Value>
class HashTable {
private:
	unsigned int (*func) (const Key);
	unsigned int size;
	unsigned int count;

	Key *keys;
	Key initialValue;
	Value *values;

	long indexOf(const Key) const;

public:
	HashTable(unsigned int, Key, unsigned int (*f) (const Key));
	~HashTable();
	bool full() const;
	bool put(Key, Value);
	bool contains(const Key) const;
    void crear(); 
	Value get(const Key);
	void clear();
	std::string toString() const;
};

template <class Key, class Value>
HashTable<Key, Value>::HashTable(unsigned int sze, Key init, unsigned int (*f) (const Key)) {
	size = sze;
	keys = new Key[size];

	initialValue = init;
	for (unsigned int i = 0; i < size; i++) {
		keys[i] = init;
	}

	values = new Value[size];
	for (int i = 0; i  < sze; i++){
        values[i] = 0;
    }

	func = f;
	count = 0;
}

template <class Key, class Value>
HashTable<Key, Value>::~HashTable() {
	delete [] keys;
	keys = 0;
	delete [] values;
	values = 0;
	size = 0;
	func = 0;
	count = 0;
}

template <class Key, class Value>
bool HashTable<Key, Value>::full() const {
	return (count > size);
}

template <class Key, class Value>
long HashTable<Key, Value>::indexOf(const Key k) const {
	unsigned int i, start;

	start = i = func(k) % size;
	do {
		if (keys[i] == k) {
			return i;
		}
		i = (i + 1) % size;
	} while (start != i);
	return -1;
}

template <class Key, class Value>
bool HashTable<Key, Value>::put(Key k, Value v) {
	unsigned int i, start;
	long pos;


	pos = indexOf(k);
	if (pos != -1) {
		values[pos] = v;
		return true;
	}

	start = i = func(k) % size;
	do {
		if (keys[i] == initialValue) {
			keys[i] = k;
			values[i] = v;
			count++;
			return true;
		}
		i = (i + 1) % size;
	} while (start != i);
	return false;
}

template <class Key, class Value>
bool HashTable<Key, Value>::contains(const Key k) const {
	long pos;

	pos = indexOf(k);
	return (pos != -1);
}

template <class Key, class Value>
Value HashTable<Key, Value>::get(const Key k) {
	unsigned int i, start;
	long pos;

	pos = indexOf(k);
	if (pos != -1) {
		return values[pos];
	}
}

template <class Key, class Value>
void HashTable<Key, Value>::clear() {
	count = 0;
	for (unsigned int i = 0; i < size; i++) {
		keys[i] = initialValue;
	}
}

template <class Key, class Value>
std::string HashTable<Key, Value>::toString() const {
	std::stringstream aux;

	for (unsigned int i = 0; i < size; i++) {
		aux << "[ " << i << ", " << keys[i] << ", " << values[i] << "]\n";
	}
	return aux.str();
}

template <class Key, class Value>
void HashTable<Key, Value>::crear(){
    
    put(string("PE"), 11);
    put(string("PA"), 18);
    put(string("PV"), 7);
    put(string("LC"), 20);
    put(string("PM"), 15);
    put(string("SC"), 16);
    put(string("PN"), 23);
    put(string("MP"), 14);
    put(string("PL"), 12);
    put(string("SR"), 10);
}

#endif 
