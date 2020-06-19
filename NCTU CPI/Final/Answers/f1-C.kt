fun cor(s: String, t: String, b: Int, e: Int): Boolean {
    if (e-b <= 1) return s[b] == t[b]
    if ((b until e).count{s[it] != t[it]} <= 1) return true
    return cor(s, t, b, (b+e+1) / 2) && cor(s, t, (b+e+1)/2, e)
}

fun main() {
    val n = readLine()!!.toInt()
    val s = readLine()!!
    val t = readLine()!!
    println(if(cor(s,t,0,n)) "True" else "False")
}
