use proconio::input;

fn solve() {
    input! {
        _n:i32,
        x:i32,
        t:i32,
    }
    let mut N = _n;
    let mut ans: i32 = 0;
    while N > 0 {
        N -= x;
        ans += t;
    }
    println!("{}", ans);
}
