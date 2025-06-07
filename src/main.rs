use lalrpop_util::lalrpop_mod;
use std::env;
use std::io::Write;

pub mod ast;

// Include the generated parser
lalrpop_mod!(pub zap);

use ast::*;
use zap_lang::parse_file;

fn parse_zap_repl() -> Result<Program, Box<dyn std::error::Error>> {
    print!("> ");
    std::io::stdout()
        .flush()
        .expect("Using for testing. Remove if this fails");
    let mut buffer = String::new();
    std::io::stdin()
        .read_line(&mut buffer)
        .expect("No line found");

    let input = buffer.trim();

    // Use the generated parser
    let parser = zap::ProgramParser::new();
    match parser.parse(input) {
        Ok(program) => Ok(program),
        Err(e) => Err(Box::new(std::io::Error::new(
            std::io::ErrorKind::InvalidData,
            format!("Parse error: {:?}", e),
        ))),
    }
}

fn main() {
    let args: Vec<String> = env::args().collect();

    // Check if a file path was provided
    if args.len() > 1 {
        let file_path = &args[1];

        // Parse the file and print the program statements
        match parse_file(file_path) {
            Ok(program) => {
                println!("File parsed successfully: {}", file_path);
                println!("Program statements:");
                for (i, statement) in program.statements.iter().enumerate() {
                    println!("  {}: {:#?}", i + 1, statement);
                }
            }
            Err(err) => {
                eprintln!("Error parsing file '{}': {}", file_path, err);
                std::process::exit(1);
            }
        }
    } else {
        // Run REPL mode if no file is provided
        println!("ZapLang Parser REPL");
        println!("Enter ZapLang code to parse (Ctrl+C to exit)");

        loop {
            match parse_zap_repl() {
                Ok(program) => {
                    println!("Program Parsed: {:#?}", program);
                }
                Err(err) => {
                    println!("Parsing failed. Error: {:?}", err);
                }
            }
        }
    }
}
