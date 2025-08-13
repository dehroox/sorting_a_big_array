#!/bin/env bash

if ! command -v hyperfine >/dev/null 2>&1; then
    echo "install hyperfine bro"
    exit 1
fi

echo "benchmark release build 10 times:\n\n"
hyperfine -r 10 -w 3 'make run release'