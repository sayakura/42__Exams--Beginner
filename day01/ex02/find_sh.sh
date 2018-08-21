#!/bin/bash
find . -name "*.sh"| sed 's/\(.*\)\///g' | sed 's/\.sh//g'
