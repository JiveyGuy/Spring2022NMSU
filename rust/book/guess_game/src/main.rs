use std::io::Write;
use std::io;

fn main() {
    println!("Guess the number!");

    print!("Input a number(1-10): ");
    
    io::stdout().flush().unwrap();    
    let mut guess = String::new();

    io::stdin()
        .read_line(&mut guess)
        .expect("Failed to read the line.");

    println!("You guessed {guess}");
}