#!/bin/bash

{
  echo "╭───────────────────────────────╮"
  echo "│Installing dependencies (clang)│"
  echo "╰───────────────────────────────╯"
  xcode-select --install
} &> /dev/null

echo "╭────────────────────────────────────────────────╮"
echo "│Creating bah directory and creating bah std-libs│"
echo "╰────────────────────────────────────────────────╯"

# Moving std-libs
{
cd ./installer
sudo mkdir /opt
sudo mkdir /opt/bah
sudo mkdir /opt/bah/libs
sudo mkdir /opt/bah/libs/darwin
sudo mkdir /opt/bah/libs/windows
sudo mkdir /opt/bah/libs/linux
sudo cp -r ./libs/darwin/libs/* /opt/bah/libs/darwin
sudo cp -r ./libs/windows/libs/* /opt/bah/libs/windows
sudo cp -r ./libs/linux/libs/* /opt/bah/libs/linux

#sudo cp -r ./libs/darwin/* /opt/bah/
sudo cp ./libs/common/* /opt/bah/
sudo chmod 777 /opt/bah/*

# Compilling because binaries are not maintained for darwin
clang -I "/opt/bah/libs/darwin/include/" -L "/opt/bah/libs/darwin/" darwin.c  -O1 -w  -lgc -lpthread -lm -o "../bin/darwin_amd64"

# Moving bah exec
sudo cp ../bin/darwin_amd64 /opt/bah/bah
sudo ln -s /opt/bah/bah /bin/bah
sudo chmod 777 /opt/bah
sudo chmod +x /bin/bah
export PATH="/opt/bah/:$PATH"

cd ../

} &> /dev/null

echo -e "\033[1;32m╭─────────────────────────────────────────────────────────────╮"
echo              "│                            Done!                            │"
echo              "│             Bah is now installed on your system.            │"
echo              "│To test if the installation was successful, execute 'bah -v'.│"
echo              "╰─────────────────────────────────────────────────────────────╯"
echo -e "\033[0m"
