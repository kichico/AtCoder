use proconio::input;
fn solve() {
    input! {
        mut a:i64,
        mut b:i64,
    }
    let mut vec: Vec<i64> = vec![1];
    for i in 1..1000 {
        let v = vec[i - 1];
        vec.push(v + i as i64 + 1);
    }
    let mut ans = 0;
    for i in 1..1000 {
        let diff = vec[i] - vec[i - 1];
        //println!("diff:{},vec[{}]:{}", diff, i, vec[i]);

        if diff == b - a {
            ans = i;
            break;
        }
    }
    println! {"{}",vec[ans]-b};
}

fn main() {
    solve();
}
