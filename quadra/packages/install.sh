#! /bin/sh

VERSION=1.1.1
PREFIX=""

if [ $(id -u) -ne 0 ]; then
	echo
	echo "You must be 'root' to install Quadra."
	echo
	echo "Use the 'su' command or contact your system administrator."
	echo
	exit
fi

echo
echo "Installing Quadra $VERSION..."
echo
echo "Installing quadra -> $PREFIX/usr/games/quadra"
mkdir -p $PREFIX/usr/games
install -s -m 4711 quadra $PREFIX/usr/games/quadra
echo "Installing quadra.res -> $PREFIX/usr/lib/games/quadra.res"
mkdir -p $PREFIX/usr/lib/games
install -m 644 quadra.res $PREFIX/usr/lib/games/quadra.res
echo
echo "Installation is finished!"
echo
echo "To run the game, type $PREFIX/usr/games/quadra"
echo
