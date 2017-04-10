const worker = require("streaming-worker");
const path = require("path");

const addon_path = path.join(__dirname, "build/Release/node_async_module");
const node_async_module = worker(addon_path);

node_async_module.from.on('node-async-module', function(data) {
  console.log("----------- Event -----------");
  console.log(data);
  if (data == 10) {
    node_async_module.close();
    console.log("close application")
  }
});

// infinity loop
function start() {
  setTimeout(start, 10000);
}
start();
