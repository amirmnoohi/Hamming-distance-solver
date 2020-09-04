# Welcome to Hamming Distance Solver!

This repository contains files which solve Hammin Distance Problem by Reduce it to max clique problem.
in this code's we use pmc as parallel max clique solver. first we generate data's and input's then we pass these data's to pmc solver. we run pmc solver multiple time to find ideal result....


# Files

we have 3 type of compiled file's:
1- solver : which is Files/pmc.* compiled file
2- run : which is Files/run.cpp compiled file
3- check : which is Files/check.cpp compiled file

# RoadMap
first we create our input using ./run file. then we pass this file to ./solver which comes from pmc solver. after that we save that initial result on the answer.txt file. then we run multiple time's pmc on the answer to find better answer....
after finding nearly ideal answer we check the result for consistency and not to be repeated by ./check file
