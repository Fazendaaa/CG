#!/bin/sh
bindir=$(pwd)
cd /home/farm/Documents/CG/lessons/first/src/
export 

if test "x$1" = "x--debugger"; then
	shift
	if test "xYES" = "xYES"; then
		echo "r  " > $bindir/gdbscript
		echo "bt" >> $bindir/gdbscript
		/usr/bin/gdb -batch -command=$bindir/gdbscript --return-child-result /home/farm/Documents/CG/lessons/first/build/run 
	else
		"/home/farm/Documents/CG/lessons/first/build/run"  
	fi
else
	"/home/farm/Documents/CG/lessons/first/build/run"  
fi
