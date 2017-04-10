#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <iostream>
#include <unistd.h>
#include <v8.h>
#include <nan.h>

NAN_METHOD(nothing);
NAN_METHOD(aString);
NAN_METHOD(aBoolean);
NAN_METHOD(aNumber);
NAN_METHOD(anObject);
NAN_METHOD(anArray);
NAN_METHOD(callback);

// Wrapper Impl


class MyObject : public Nan::ObjectWrap {
  public:
    static NAN_MODULE_INIT(Init);

	class MyAsyncWorker : public Nan::AsyncWorker {
	 public:
	  MyAsyncWorker(Nan::Callback *callback, int milliseconds)
	    : Nan::AsyncWorker(callback), milliseconds(milliseconds) {}
	  ~MyAsyncWorker() {}

	  void Execute () {
	    usleep(milliseconds*1000);
	    SetErrorMessage("Error Message");
	  }

	 private:
	  int milliseconds;
	};

  private:
    explicit MyObject(double value = 0);
    ~MyObject();

    static NAN_METHOD(New);
    static NAN_METHOD(PlusOne);
    static NAN_METHOD(Add);
    static NAN_METHOD(PrintName);
    static NAN_METHOD(WakeUp);
    static Nan::Persistent<v8::Function> constructor;
	double value_;

};

#endif