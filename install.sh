#!/usr/bin/env bash

# DISCLAIMER: This installation script was generated with the assistance of AI (Gemini).
# Change it the way you'd like it to behave.

set -e

APP_NAME="memo"
SRC_FILE="main.c"
INSTALL_DIR="$HOME/.local/bin"
DATA_DIR="$HOME/.reminders"

if [ ! -d "$DATA_DIR" ]; then
    mkdir -p "$DATA_DIR"
fi

mkdir -p "$INSTALL_DIR"

gcc -O2 -Wall "$SRC_FILE" -o "$INSTALL_DIR/$APP_NAME"

if [[ ":$PATH:" != *":$INSTALL_DIR:"* ]]; then
    SHELL_CONFIG=""
    if [ -f "$HOME/.zshrc" ]; then
        SHELL_CONFIG="$HOME/.zshrc"
    elif [ -f "$HOME/.bashrc" ]; then
        SHELL_CONFIG="$HOME/.bashrc"
    fi

    if [ -n "$SHELL_CONFIG" ]; then
        echo 'export PATH="$HOME/.local/bin:$PATH"' >> "$SHELL_CONFIG"
    fi
fi
