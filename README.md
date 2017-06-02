# abignumscalc
a big nums calcs


Create the following folder structure:

big_nums:
    src:
        All code and cmake files
    build:
        generate scripts

       
in windowd edit generate.bat to adjust boost libraries root folder.
in linux boost libraries must be installed.

open a shell in build diretory run generate (bat or sh)

in windows open solution with visual studio

in linux do make

As result of compilation there must be
bncl -> client
bnsrv -> server
test -> unit test

run the server, listening in 80 and 8080
in other shell run bncl at moment it uses just one port (8080), to change edit in source code and do make again.





