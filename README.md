# Fuzz-Test
Randomized URL testing was done with the code in fuzz_target.cpp, and the executable file is fuzz_target

Randomized URL testing with random binary data was done with the code in fuzz_target2.cpp, and the executable file is fuzz_target2


# Testing

The 50 popular sites fuzz test with just randomized URLs and sequential data was done with input "test" in the "tests" directory.

The 50 popular sites fuzz test with random binary data was done with inputs in the "tests2" directory.

The 50 fraudlent sites fuzz test with random binary data was with inputs in the "tests3" directory.

The outdirs correspond to the output produced by each fuzz test, i.e. outdir for test, outdir2 for test2, and outdir3 for test3.