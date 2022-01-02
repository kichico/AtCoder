use proconio::input;
use std::collections::HashMap;

fn solve() {
    input! {
        n : i32,
        t : [i32;n],
        m : i32,
        drink : [(i32,i32);m],
    }
    let mut mp = HashMap::new();
    for i in &drink {
        mp.insert(i.0, i.1);
    }
    let mut sum: i32 = 0;
    for i in &t {
        sum += i;
    }
    for i in &drink {
        sum -= t[(i.0 - 1) as usize];
        println!("{}", sum + i.1);
        sum += t[(i.0 - 1) as usize];
    }
}

fn main() {
    solve();
}
