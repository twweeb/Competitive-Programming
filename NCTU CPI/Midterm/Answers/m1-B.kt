var fire = 0L
val odd = (0..56 step 14).map{0x7FL shl it}.reduce{x, y -> x or y}
val even = 0L.inv() xor odd
val row = (0..2).map{0x1FFFFFL shl (it * 21)}
val col = (0..2).map{0x1FC000FE0007FL shl (it * 7)}
val fail = 0L.inv()

fun nxt(s: Long, pat: Int) = when(pat) {
    2 -> row[2].and(s).or(row[0].and(s).shl(21)).or(row[1].and(s).shr(21))
    3 -> row[1].and(s).or(row[0].and(s).shl(42)).or(row[2].and(s).shr(42))
    4 -> row[0].and(s).or(row[1].and(s).shl(21)).or(row[2].and(s).shr(21))
    5 -> col[2].and(s).or(col[0].and(s).shl(7)).or(col[1].and(s).shr(7))
    6 -> col[1].and(s).or(col[0].and(s).shl(14)).or(col[2].and(s).shr(14))
    7 -> col[0].and(s).or(col[1].and(s).shl(7)).or(col[2].and(s).shr(7))
    else -> s
}

fun burn(s: Long, trans: Int): Long {
    var newOdd = odd and s
    var newEven = even and s
    if (trans > 0) {
        newOdd += odd and fire
        newEven += even and fire
    } else {
        newOdd -= odd and fire
        newEven -= even and fire
    }
    if (newOdd.and(even)!=0L || odd.and(newEven)!=0L) 
        return fail
    return newOdd or newEven
}

fun solve() {
    val qf = java.util.ArrayDeque<Long>()
    val qb = java.util.ArrayDeque<Long>()
    var buf = (1..3).map{readLine()!!.split(" ")}.flatMap{it.toList()}
    fire = buf.filter{it!=""}.map{it.toLong()}.reduce{x, y -> x.shl(7) or y}
    buf = (1..3).map{readLine()!!.split(" ")}.flatMap{it.toList()}
    val goal = buf.filter{it!=""}.map{it.toLong()}.reduce{x, y -> x.shl(7) or y}
    val visitedF = HashSet<Long>()
    val visitedB = HashSet<Long>()
    qf.add(0L)
    qb.add(goal)
    visitedF.add(0L)
    visitedB.add(goal)
    var step = 1
    while (true) {
        var f = qf.size
        var b = qb.size
        for (rnd in 1..f) {
            var state = qf.removeFirst()
            state = burn(state, 1)
            if (fail==state) continue
            for (i in 1..7) {
                var newState = nxt(state, i)
                if (newState in visitedB) {
                    println(step)
                    return
                }
                if (newState !in visitedF) {
                    visitedF.add(newState)
                    qf.add(newState)
                }
            }
        }
        if (step==15) break
        step++
        for (rnd in 1..b) {
            var state = qb.removeFirst()
            for (i in 1..7) {
                var newState = nxt(state, i)
                newState = burn(newState, -1)
                if (fail==newState) continue
                if (newState in visitedF) {
                    println(step)
                    return
                }
                if (newState !in visitedB) {
                    visitedB.add(newState)
                    qb.add(newState)
                }
            }
        }
        step++
    }
    println("NA IS HARD, SO IS LIFE.")
}

fun main() = (1..readLine()!!.toInt()).forEach{solve()}
