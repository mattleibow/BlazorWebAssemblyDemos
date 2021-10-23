#include "library.h"


// the C++ class

MyClass::MyClass()
	: value(0)
	, callback(nullptr)
	, callbackState(nullptr)
{
}

MyClass::~MyClass()
{
}

int MyClass::getValue()
{
	return this->value;
}

void MyClass::setValue(int value)
{
	this->value = value;

	if (this->callback) {
		auto is10x = this->value == 10;
		this->callback(is10x, this->callbackState);
	}
}

void MyClass::setCallback(MyCallback callback, void* state)
{
	this->callback = callback;
	this->callbackState = state;
}


// the C interop methods

void* my_class_new()
{
	return new MyClass();
}

void my_class_delete(void* obj)
{
	delete (MyClass*)obj;
}

int my_class_get_value(void* obj)
{
	return ((MyClass*)obj)->getValue();
}

void my_class_set_value(void* obj, int value)
{
	((MyClass*)obj)->setValue(value);
}

void my_class_set_callback(void* obj, MyCallback callback, void* state)
{
	((MyClass*)obj)->setCallback(callback, state);
}