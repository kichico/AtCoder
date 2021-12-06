use proconio::input;

fn main() {
    input! {
        N:String,
    }
    let s = N;
    let mut sum: i32 = 0;
    for x in s.chars() {
        sum += x as i32;
        sum -= '0' as i32;
    }
    let mut ans: &str = "Yes";
    if sum % 9 != 0 {
        ans = "No";
    }
    println!("{}", ans);
}
