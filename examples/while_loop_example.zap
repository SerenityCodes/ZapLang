func main() -> void {
    let i: u64 = 0;
    while (i < 10000) {
        i = i + 1;
        if (i % 1000 == 0) {
            print(i);
        }
    }
    print(10 * 20);
}
