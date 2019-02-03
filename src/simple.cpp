#include <simple/simple.hpp>

#include <iostream>

simple::simple()
{

}

simple::simple(const simple &)
{

}

simple::simple(simple &&)
{

}

simple::~simple()
{

}

simple &simple::operator=(const simple &)
{
	return *this;
}

simple &simple::operator=(simple &&)
{
	return *this;
}

void simple::print()
{
	std::cout << "Hello, World";
}
