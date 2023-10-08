#!/bin/bash

# 检查是否提供了参数
if [ $# -ne 1 ]; then
    echo "请提供安装目录的相对路径作为参数。"
    exit 1
fi

# 获取当前脚本所在目录的绝对路径
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# 获取 $1 的绝对路径
ABSOLUTE_PATH="$SCRIPT_DIR/$1"

# 检查 $1 是否为有效的目录
if [ ! -d "$ABSOLUTE_PATH" ]; then
    echo "提供的目录路径 '$ABSOLUTE_PATH' 无效。"
    exit 1
fi

# 打印绝对路径
echo "安装目录: $ABSOLUTE_PATH"

# 运行 configure 命令
./configure --prefix="$ABSOLUTE_PATH" --target-list=riscv64-softmmu --enable-gtk --enable-virtfs
