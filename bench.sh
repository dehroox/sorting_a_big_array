#!/bin/env bash

if ! command -v hyperfine >/dev/null 2>&1; then
    echo "install hyperfine bro"
    exit 1
fi

echo "benchmark release build 20 times:\n\n"
hyperfine --runs 20 'make run release'