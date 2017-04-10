{
  "targets": [
    {
      "target_name": "hello",
      "sources": [ "hello.cc", "functions.cc" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}