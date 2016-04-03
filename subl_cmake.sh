#!/bin/bash

# Absolute path to this script
SCRIPT=$(readlink -f "$0")
# Absolute path this script is in
SCRIPTPATH=$(dirname "$SCRIPT")
cd $SCRIPTPATH/build/ 
cmake .. -G "Sublime Text 2 - Unix Makefiles" 
subl3 pong.sublime-project
