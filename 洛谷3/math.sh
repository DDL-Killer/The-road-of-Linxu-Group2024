#!/bin/bash
# 检查是否提供了源文件作为参数
if [ $# -eq 0 ]; then
    echo "Usage: ./build.sh <source_file.c>"
    exit 1
fi

# 编译 C 程序并链接数学库
gcc "$1" -o "${1%.c}" -lm

# 检查编译是否成功
if [ $? -eq 0 ]; then
    echo "Compilation successful! Executable: ${1%.c}"
else
    echo "Compilation failed!"
fi