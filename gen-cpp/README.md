William O'neil China Api
================
API support of cpp

client.cpp is a demo

Please modify the file client.cpp according to the actual requirement.

Table of Contents
-----------------

  * [Requirements](#requirements)
  * [Usage](#usage)


Requirements
------------
requires the following to run:

  * [thrift](http://thrift.apache.org/download)

Usage
-------
THRIFT_DIR = /usr/local/include/thrift
LIB_DIR = /usr/local/lib

```
//compile
g++ -g -Wall -I./ -I{THRIFT_DIR} ApiService.cpp won_types.cpp won_constants.cpp client.cpp -L{LIB_DIR} -lthrift -o client -std=c++11 -lssl -lcrypto
//run
./client
```

