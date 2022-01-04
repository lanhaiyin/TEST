#!/bin/bash
chmod 777 *
ulimit -s 102400
rm -rf lib*plugin.so
export LD_LIBRARY_PATH=./
./vstest

