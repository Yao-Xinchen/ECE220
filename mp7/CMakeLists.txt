include_directories(sort primeNumber printRev)

add_executable(mp7_prime primeNumber/primeNumber.c primeNumber/isPrime.o)
add_executable(mp7_rev printRev/prmain.c printRev/pr_buggy.c)
add_executable(mp7_sort sort/sort.c sort/sortMain.o)