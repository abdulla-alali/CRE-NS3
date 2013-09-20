#!/bin/bash

find src -name "*.cc" | xargs grep -Hn $1 --color=always
