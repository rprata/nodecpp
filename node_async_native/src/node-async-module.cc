#include <iostream>
#include <string>
#include <nan.h>
#include "streaming-worker.h"

#define MESSAGE_INPUT "node-async-module"
#define MILLIS_SLEEP_TIME 5

class ASyncModule : public StreamingWorker {
  public:
    ASyncModule(Callback *data, Callback *complete, Callback *error_callback,  v8::Local<v8::Object> & options) 
          : StreamingWorker(data, complete, error_callback){ }
     
    void send_message(const AsyncProgressWorker::ExecutionProgress& progress, int value) {
        Message tosend(MESSAGE_INPUT, to_string(value).c_str());
        writeToNode(progress, tosend);
    }

    void Execute (const AsyncProgressWorker::ExecutionProgress& progress) {
      int counter = 0;
      while (!closed()) {
        send_message(progress, counter++);
        std::this_thread::sleep_for(chrono::milliseconds(MILLIS_SLEEP_TIME));
      }
    }
  private:

};

StreamingWorker * create_worker(Callback *data
    , Callback *complete
    , Callback *error_callback, v8::Local<v8::Object> & options) {
 return new ASyncModule(data, complete, error_callback, options);
}

NODE_MODULE(node_async_module, StreamWorkerWrapper::Init)
