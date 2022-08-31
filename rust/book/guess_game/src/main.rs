use std::io::Write;
use std::io;
use rand::Rng;
use std::cmp::Ordering;
// use range_check::Check;

fn main() {
    
    let secret_number: u8 = rand::thread_rng().gen_range(1..=10);
    
    loop {
        print!("Enter a number (1-10): ");
        // this prints the same line without line buffer
        io::stdout().flush().unwrap();

        let mut guess = String::new();

        io::stdin()
            .read_line(&mut guess)
            .expect("Failed to read line!");

        

        
        let response;
       

        let guess: u8 = match guess
                                .trim()
                                .parse() {
                                    Ok(num) => num, 
                                    Err(_) => {
                                        println!("Invalid input!");
                                        continue;
                                    },
                                };
                                

        println!("\tYou guessed: {guess}");

        if !(1..=10).contains(&guess) {
            println!("Your number is outside range 1-10!");
            continue;
        }

        match guess.cmp(&secret_number) {
            Ordering::Less    => {
                response = "\t\tToo small!"; 
            },
            Ordering::Greater => {
                response = "\t\tToo big!";
            },
            Ordering::Equal   => {
                response = "\t\tYou win!";

            }
        }
        println!("{response}");

        if response.eq("\t\tYou win!")  {
            println!("GG");
            break;
        }
    }
}
