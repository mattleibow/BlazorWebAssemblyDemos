#pragma once

#ifdef __cplusplus
#    define CPP_BEGIN_GUARD    extern "C" {
#    define CPP_END_GUARD      }
#else
#    define CPP_BEGIN_GUARD
#    define CPP_END_GUARD
#endif

#define PUBLIC_API __attribute__((visibility("default")))


// the C++ class

typedef void (*MyCallback)(bool is10x, void* state);

class MyClass
{
public:
	MyClass();
	~MyClass();

	int getValue();
	void setValue(int value);

	void setCallback(MyCallback callback, void* state);

private:
	int value;
	MyCallback callback;
	void* callbackState;
};


// the C interop methods

typedef void* my_class_ptr;

CPP_BEGIN_GUARD

PUBLIC_API my_class_ptr my_class_new();
PUBLIC_API void my_class_delete(my_class_ptr obj);
PUBLIC_API int my_class_get_value(my_class_ptr obj);
PUBLIC_API void my_class_set_value(my_class_ptr obj, int value);
PUBLIC_API void my_class_set_callback(my_class_ptr obj, MyCallback callback, void* state);

CPP_END_GUARD
