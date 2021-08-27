#!/bin/bash
if command -v apt &> /dev/null
then
    echo "╭─────────────────────────────╮"
    echo "│Installing dependencies (apt)│"
    echo "╰─────────────────────────────╯"
    {
    sudo apt-get install gcc build-essential libgc-dev checkinstall zlib1g-dev libssl-dev -y
    } &> /dev/null
    
else
    if command -v pacman &> /dev/null
    then
        echo "╭────────────────────────────────╮"
        echo "│Installing dependencies (pacman)│"
        echo "╰────────────────────────────────╯"
        {
        yes | sudo pacman -Sy gcc gc openssl
        } &> /dev/null
        
    else
        echo "Could not install dependencies, no package manager found (pacman or apt)."
        echo "Please install: "
        echo "- gcc"
        echo "- build-essential (for gcc) (or equivalent)"
        echo "- libgc (dev branch) (or equivalent)"
        echo "- libssl (dev branch) (or equivalent)"
        echo "- zlib (dev branch) (or equivalent)"
        exit
    fi
fi


# Compilling source code
echo "╭──────────────────────╮"
echo "│Compilling source code│"
echo "╰──────────────────────╯"
cd ./installer
line=$(head -n 1 ./main.c)
line=$(echo ${line::-1} | cut -b 18-)
$line

# Moving bah exec
echo "╭────────────────────────────────────────────────╮"
echo "│Creating bah directory and creating bah std-libs│"
echo "╰────────────────────────────────────────────────╯"
{
sudo mkdir /opt/bah
sudo cp ./a.out /opt/bah/bah
sudo cp -s /opt/bah/bah /bin/bah
sudo chmod 777 /opt/bah
sudo chmod +x /bin/bah
rm ./a.out

# Moving std-libs
cp ./libs/linux_amd64/* /opt/bah/
cp ./libs/common/* /opt/bah/
sudo chmod 777 /opt/bah/*
} &> /dev/null
echo -e "\033[1;32m╭─────────────────────────────────────────────────────────────╮"
echo              "│                            Done!                            │"
echo              "│             Bah is now installed on your system.            │"
echo              "│To test if the installation was successful, execute 'bah -v'.│"
echo              "╰─────────────────────────────────────────────────────────────╯"
