
****** NOTICE **************
c2z is being overhauled with a lot of changes/fixes/updates.  MAYBE UNSTABLE
from time to time.  Working on it daily.  TC
*****************************



c2z is a parser written in "C" that parses "C" source code into "base-register free" z390.mlc

The z390.mlc then can be compiled/executed by the z390 emulator found at
www.z390.org

c2z runs under Linux.  Below is the command line to compile.


Linux   (gcc)

    gcc -fno-stack-protector -falign-functions=16 -falign-jumps -falign-labels -falign-loops -o c2z c2z.c

c2z is release under GPL 2.0

examples (sub-directory) contains sample "C" programs.

bxbasic (sub_directory) contains the "C" source code that when processed by the c2z program
        will genterate z390.mlc code.  Compile this code and you have a simple working
        basic p-code program.  Sample basic programs are included in this directory.


Any questions/comments/suggestions contact tchandler48@gmail.com


