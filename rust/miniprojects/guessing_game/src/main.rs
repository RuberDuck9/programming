use std::io;
use std::cmp::Ordering;
use rand::Rng;

fn main() {

    let rand = rand::thread_rng()
        .gen_range(1..=100);

    let mut guess = String::new();

    loop {

        guess.clear();

        println!("Guess a number.");

        io::stdin()
            .read_line(&mut guess)
            .expect("Failed to read line");

        let guess: u32 = match guess
            .trim() //remove \n
            .parse() { //convert to u32
                Ok(num) => num,
                Err(_) => continue,
            };

        match guess.cmp(&rand) {
            Ordering::Less => println!("Too Low"),
            Ordering::Greater => println!("Too High"),
            Ordering::Equal => {
                println!("Correct");
                break;
            },

        }

    }

}
