func main() -> void {
    let a: u32 = 10;
    let b: u32 = 20;
    if (a > b) {
        print(a + b);
    } else {
        print(a - b);
    }
    let c: u32 = (a * a + b * b) / (a - b);
    print(-c);
}
