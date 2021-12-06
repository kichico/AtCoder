use proconio::input;
 
fn main() {
    input! {
        _n : i32,
        X : i32,
        T : i32,
 
    }
  	let mut N:i32 = _n;
    let mut ans: i32 = 0;
    while N > 0 {
        ans += T;
        N -= X;
    }
    println!("{}", ans);
}