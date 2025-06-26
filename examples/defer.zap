func main() -> void {
    defer {
        print("Deferring");
    }
    let a: u32 = 10;
    print(a);
}
