#!/usr/bin/env bash

rm -rf $HOME/EM/data/* $HOME/EM/exts/* $HOME/EM/repo/*
code --install-extension the-em-foundation.embrowser --install-extension Wokwi.wokwi-vscode --extensions-dir exts
code --skip-welcome --user-data-dir "$HOME/EM/data" --extensions-dir "$HOME/EM/exts" 
