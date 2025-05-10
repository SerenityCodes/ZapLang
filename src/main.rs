use std::{io::Write, str::FromStr};

struct VM {
    registers: [u64],
}

#[derive(Debug, PartialEq)]
enum Opcode {
    MOV,
    ADD,
    NOT,
    AND,
    MUL,
    NOOP,
}

impl FromStr for Opcode {
    type Err = ();

    fn from_str(s: &str) -> Result<Self, Self::Err> {
        match s {
            "MOV" => Ok(Opcode::MOV),
            "ADD" => Ok(Opcode::ADD),
            "NOT" => Ok(Opcode::NOT),
            "AND" => Ok(Opcode::AND),
            "MUL" => Ok(Opcode::MUL),
            "NOOP" => Ok(Opcode::NOOP),
            _ => Err(()),
        }
    }
}

#[derive(Debug)]
struct Instruction {
    op: Opcode,
    dest: u8,
    src1: u8,
    src2: u8,
    arg: u64,
}

fn parse_instruction_repl() -> Result<Instruction, ()> {
    print!("> ");
    std::io::stdout()
        .flush()
        .expect("Using for testing. Remove if this fails");
    let mut buffer = String::new();
    std::io::stdin()
        .read_line(&mut buffer)
        .expect("No line found");
    let (opcode_str, num_str) = match buffer.split_once(" ") {
        Some(v) => v,
        None => ("NOOP", "0, 0, 0"),
    };
    let opcode_str: String = opcode_str.trim().replace(" ", "");
    println!("Opcode: {opcode_str}");
    let mut nums: Vec<u64> = Vec::new();
    let binding = num_str.trim().replace(" ", "");
    let num_arr = binding.split(",");
    num_arr.for_each(|val| nums.push(val.parse::<u64>().unwrap_or(0)));
    if nums.len() != 3 {
        ()
    }
    Ok(Instruction {
        op: match Opcode::from_str(&opcode_str) {
            Ok(o) => o,
            _ => Opcode::NOOP,
        },
        dest: nums[0] as u8,
        src1: nums[1] as u8,
        src2: nums[2] as u8,
        arg: nums[1],
    })
}

fn main() {
    loop {
        match parse_instruction_repl() {
            Ok(i) => {
                println!("Instruction Parsed: {:?}", i);
            }
            err => {
                println!("Parsing of the instruction failed. Error: {:?}", err);
            }
        }
    }
}
