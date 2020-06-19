fun main() {
    val (n, m) = readLine()!!.split(" ").map{ it.toInt()}
    val N = 1 shl n
    val grid = Array<BooleanArray>(n){BooleanArray(n){false}}
    for (rnd in 1..m) {
        val (x, y) = readLine()!!.split(" ").map{ it.toInt()-1 }
        grid[x][y] = true
    }
    if ((n*n - m) % 2 == 1) return println("0")
    val dp = Array<Array<IntArray>>(n){Array<IntArray>(n){IntArray(N)}}
    if (grid[0][0]) dp[0][0][N-1] = 1 else dp[0][0][N-2] = 1
    for (x in 0 until n) {
        if (x > 0) {
            for (z in 0 until 1.shl(n)) {
                if (z.and(1)==0) {
                    dp[x][0][z] = if (grid[x][0]) 0 else dp[x-1][n-1][z.or(1)]
                } else {
                    dp[x][0][z] = if (grid[x][0]) dp[x-1][n-1][z] else dp[x-1][n-1][z.xor(1)]
                }
            }
        }
        for (y in 1 until n) {
            for (z in 0 until N) {
                val Y = (z.and(1 shl y) != 0)
                if (grid[x][y]) {
                    dp[x][y][z] = if (Y) dp[x][y-1][z] else 0
                } else if (Y) {
                    val U = dp[x][y-1][z xor 1.shl(y)]
                    val L = 1.shl(y-1).let{ if (z.and(it)!=0) dp[x][y-1][z xor it] else 0 }
                    dp[x][y][z] = (U + L) % 1_000_000_007
                } else {
                    dp[x][y][z] = dp[x][y-1][z or 1.shl(y)]
                }
            }
        }
    }
    println(dp[n-1][n-1][N-1])
}
