import java.util.ArrayDeque

val goal = 0x0123456789ABCDEFL
val cell = (3 downTo 0).map{ ((4*it + 3) downTo 4*it).map{ 0xFL.shl(4*it) } }
val mask = (0..2).map{ r -> 
    (0..2).map{ c -> 
        (cell[r][c] or cell[r+1][c] or cell[r+1][c+1] or cell[r][c+1]).inv()
    }
}

fun clockwise(s: Long, r: Int, c: Int) =
    s.and(mask[r][c])
     .or(cell[r][c].and(s).ushr(4))
     .or(cell[r][c+1].and(s).ushr(16))
     .or(cell[r+1][c+1].and(s).shl(4))
     .or(cell[r+1][c].and(s).shl(16))

fun counter(s: Long, r: Int, c: Int) =
    s.and(mask[r][c])
     .or(cell[r][c].and(s).ushr(16))
     .or(cell[r][c+1].and(s).shl(4))
     .or(cell[r+1][c+1].and(s).shl(16))
     .or(cell[r+1][c].and(s).ushr(4))

fun nextStates(s: Long, rot: (Long, Int, Int) -> Long) = 
    listOf(rot(s,0,0), rot(s,0,1), rot(s,0,2), rot(s,1,0), rot(s,1,1), 
           rot(s,1,2), rot(s,2,0), rot(s,2,1), rot(s,2,2))

fun solve() {
    val source = (1..4).map{readLine()!!.split(" ")}.flatMap{it.toList()}
               .filter{it!=""}.map{it.toLong()-1}.reduce{x, y -> x.shl(4) or y}
    if (source == goal) return println("0")
    val rotate = listOf(::clockwise, ::counter)
    val queue = listOf(ArrayDeque<Long>(), ArrayDeque<Long>())
    queue[0].add(source)
    queue[1].add(goal)
    val visited = listOf(HashSet<Long>(), HashSet<Long>())
    visited[0].add(source)
    visited[1].add(goal)
    for (step in 1..10) {
        val dir = 1 - 1.and(step)
        val size = queue[dir].size
        for (rnd in 1..size) {
            var state = queue[dir].removeFirst()
            for (newState in nextStates(state, rotate[dir])) {
                if (newState in visited[1 - dir])
                    return println(step)
                if (newState !in visited[dir]) {
                    visited[dir].add(newState)
                    queue[dir].add(newState)
                }
            }
        }
    }
    println("HARD ARIES")
}

fun main() = (1..readLine()!!.toInt()).forEach{solve()}
