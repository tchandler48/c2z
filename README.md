
****** NOTICE **************
c2z is being overhauled with a lot of changes/fixes/updates.  MAYBE UNSTABLE
from time to time.  Working on it daily.  TC
*****************************


04/7/2022
c2z is being modified and has some support for the 3270 support using tput/tget.
the c2z_fs.c is the module that supports this code.  It now can produce screen
based I/O under "C".  The documentation manual is being updated with the
new "C" functions.
		fsdefine
		fsfield
		fsdisplay
		fsread
		fsaid



c2z is a parser written in "C" and it parses "C" source code into "base-register free" z390.mlc

The z390.mlc then can be compiled/executed by the z390 emulator found at
www.z390.org

c2z runs under Linux and/or MinGW under Windows.  Below is the command line to compile.


Linux   (gcc)

    gcc -fno-stack-protector -falign-functions=16 -falign-jumps -falign-labels -falign-loops -o c2z c2z.c

Windows  (minGW)

    gcc -o c2z c2z.c



c2z is release under GPL 2.0

examples (sub-directory) contains sample "C" programs.

bxbasic (sub_directory) contains the "C" source code that when processed by the c2z program
        will genterate z390.mlc code.  Compile this code and you have a simple working
        basic p-code program.  Sample basic programs are included in this directory.


Any questions/comments/suggestions contact tchandler48@gmail.com


