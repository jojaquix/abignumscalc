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
in other shell run bncl like this:

bncl port 80|8080 data_nums_full_path

example:

bncl 80 ../data_nums.txt





