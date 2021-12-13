use proconio::input;
fn solve() {
    input! {
        mut n:i64,
    }
    if n >= 1000 {
        n %= 999;
        println!("ABD{:03}", n);
    } else {
        println!("ABC{:03}", n);
    }
}

fn main() {
    solve();
}
