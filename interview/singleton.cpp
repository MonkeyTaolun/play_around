class Singleton {
public:
	static Singleton& getInstance() {
		static Singleton	instance;
		return instance;
	}
private:
	Singleton() {}
	Singleton(Singleton const&);
	void operator=(Singleton const&);
};

/*
use singleton need have one and only one object of a type in system.

How to create the best singleton:
The smaller, the better.
make sure it is thread safe.
make sure it is never null.
make sure it is create only once.
*/