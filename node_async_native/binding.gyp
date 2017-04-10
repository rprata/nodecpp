{
  "targets": [
    {
      "target_name": "node_async_module",
      "sources": [ "src/node-async-module.cc" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")", "streaming-worker/"
      ]
    }
  ]
}