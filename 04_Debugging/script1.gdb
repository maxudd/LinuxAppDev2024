set pagination off

dprintf 13, "@@@%d, %d, %d, %d\n", M, N, S, i
condition 1 (i % 5 == 0)

run 1 12 > /dev/null

quit