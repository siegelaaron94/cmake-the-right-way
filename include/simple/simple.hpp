#pragma once

class simple {
public:
	simple();

	simple(const simple &);
	
	simple(simple &&);

	virtual ~simple();

	simple &operator=(const simple &);
	
	simple &operator=(simple &&);

	void print();
private:
};