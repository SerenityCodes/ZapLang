func main() -> void {
    let a: u32 = 10;
    let b: u32 = 20;
    let c: u32 = 0;
    if (a > b) {
        c = a + b;
        print(c);
    } else {
        c = a - b;
        print(c);
    }
    let d: u32 = (a * a + b * b) / (a - b);
    print(-c);
}
