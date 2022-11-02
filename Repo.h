#pragma once
#include <vector>
#include "Event.h"
#include <iostream>

class RepoException:public std::exception{
};

class Repo {
	std::vector<Event> v;
public:

	Repo();

	Repo(const Repo& r);

	~Repo();

	Repo& operator= (const Repo& r);

	void initialize();

	void initializeRealEvents();

	void add(const Event& e);

	void remove(int index);

	void update(int index, const Event& e);

	int getSize();

	Event getElem(int i);

	std::vector<Event> getAll();

};

