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

echo 'Remove existing folders...'
rm -rf $HOME/EM/data $HOME/EM/exts $HOME/EM/repo
echo 'Create new folders...'
mkdir -p $HOME/EM/data $HOME/EM/exts $HOME/EM/repo
echo 'Install em-builder and wokwi extensions...'
code --install-extension the-em-foundation.em-builder --install-extension Wokwi.wokwi-vscode --extensions-dir "$HOME/EM/exts"
echo 'Start Code...'
code --skip-welcome --user-data-dir "$HOME/EM/data" --extensions-dir "$HOME/EM/exts" 
