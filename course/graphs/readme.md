
check acyclic : dfs with 2 visited list :- global [to get unvisited nodes], cur[to check cycle]

negative cycle : do V iterations of floyd warshall , check if distances change in each iteration ( if change even in last itr, negative cycle exsits)