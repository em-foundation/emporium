#!/bin/sh

echo
echo '⚠️  THIS WILL DELETE ALL $HOME/EM SUB-FOLDERS'
echo

printf 'Type RESET to continue: '
read ans
if [ "$ans" != "RESET" ]; then
    echo 'Aborted.'
    exit 1
fi

echo
echo 'Proceeding...'
echo

rm -rf $HOME/EM/data/* $HOME/EM/exts/* $HOME/EM/repo/*
code --install-extension the-em-foundation.embrowser --install-extension Wokwi.wokwi-vscode --extensions-dir exts
code --skip-welcome --user-data-dir "$HOME/EM/data" --extensions-dir "$HOME/EM/exts" 
