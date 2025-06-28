func main() -> void {
    let a: u32 = 10;
    let b: u32[] = 50;
    for (let i: i32 = 0; i < 20; i = i + 1) {
        b[i] = i + 1;
    }
    for (let i: i32 = 0; i < 20; i = i + 1) {
        let c: u32 = b[i];
        print(c);
    }
}
