set pagination off

set $counter = 1

dprintf 13, "@@@%d, %d, %d, %d\n", M, N, S, i
condition 1 ($counter++ >= 28 && $counter <= 36)

run -100 100 3 > /dev/null

quit