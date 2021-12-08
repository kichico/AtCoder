fn solve() {
    input! {
        n:usize,
        mut vec:[i64;n],
    }
    let mut ans: i64 = 0;
    let mut high: i64 = vec[0];
    for i in 1..n {
        high = std::cmp::max(high, vec[i]);
        if high > vec[i] {
            ans += high - vec[i];
            vec[i] = high;
        }
        //println! {"high:{}",high};
    }
    println!("{}", ans);
}
