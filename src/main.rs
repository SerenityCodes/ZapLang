use std::{io::Write};
use lalrpop_util::lalrpop_mod;

pub mod ast;

// Include the generated parser
lalrpop_mod!(pub zap);

use ast::*;

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
            format!("Parse error: {:?}", e)
        )))
    }
}

fn main() {
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